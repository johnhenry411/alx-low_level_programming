#include "main.h" 
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: Text file to be read.
 * @letters: Number of letters to read.
 * Return: The number of bytes read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buf;        
    ssize_t fd;       
    ssize_t bytes_read; 
    ssize_t bytes_written; 
    fd = open(filename, O_RDONLY);
    if (fd == -1) 
        return (0);
    buf = malloc(sizeof(char) * letters);
    if (buf == NULL) 
    {
        close(fd);
return (0);
    }
    bytes_read = read(fd, buf, letters);
    if (bytes_read == -1) 
    {
        free(buf);
        close(fd);
        return (0);
    }
    bytes_written = write(STDOUT_FILENO, buf, bytes_read);
    if (bytes_written == -1) 
    {
        free(buf);
        close(fd);
        return (0);
    }
    free(buf);
    close(fd);
    return (bytes_written);
}

