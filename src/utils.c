#include "utils.h"

/* Existing functions */
FILE *safeOpenFile(const char *filename, const char *mode)
{
    FILE *fp = fopen(filename, mode);
    if (!fp)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    }
    return fp;
}

int fileExists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp)
    {
        fclose(fp);
        return 1;
    }
    return 0;
}

char *readFile(const char *filename)
{
    FILE *fp = safeOpenFile(filename, "r");
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer)
    {
        fclose(fp);
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(buffer, 1, fileSize, fp);
    buffer[bytesRead] = '\0';
    fclose(fp);
    return buffer;
}

int writeFile(const char *filename, const char *data)
{
    FILE *fp = safeOpenFile(filename, "w");
    int result = fputs(data, fp);
    fclose(fp);
    return result;
}

/* New generic functions to write and read structures */

int writeStructToFile(const char *filename, const void *data, size_t size)
{
    FILE *fp = safeOpenFile(filename, "wb"); // Open file for binary writing
    size_t written = fwrite(data, size, 1, fp);
    fclose(fp);
    return (written == 1) ? 0 : EOF;
}

int readStructFromFile(const char *filename, void *data, size_t size)
{
    FILE *fp = safeOpenFile(filename, "rb"); // Open file for binary reading
    size_t read = fread(data, size, 1, fp);
    fclose(fp);
    return (read == 1) ? 0 : EOF;
}
