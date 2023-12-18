#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char *create_buffer(void);
void close_file(int fd);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    char *buffer = create_buffer();

    int from = open(argv[1], O_RDONLY);
    if (from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        free(buffer);
        exit(98);
    }

    struct stat st;
    if (stat(argv[2], &st) == 0 && !(st.st_mode & S_IWUSR))
    {
    
        dprintf(STDERR_FILENO, "Error: Can't write to %s. Destination file exists and has no write permissions.\n", argv[2]);
        close_file(from);
        free(buffer);
        exit(99);
    }

    int to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[2]);
        close_file(from);
        free(buffer);
        exit(99);
    }

    ssize_t rd, wr;
    do
    {
        rd = read(from, buffer, 1024);
        if (rd == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
            break;
        }

        wr = write(to, buffer, rd);
        if (wr == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            break;
        }
    } while (rd > 0);

    close_file(from);
    close_file(to);
    free(buffer);

    if (rd == -1 || wr == -1)
    {
        
        exit(98);
    }

    return 0;
}

char *create_buffer(void)
{
    char *buffer = malloc(sizeof(char) * 1024);
    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Can't allocate buffer\n");
        exit(99);
    }
    return buffer;
}

void close_file(int fd)
{
    int c = close(fd);
    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}
