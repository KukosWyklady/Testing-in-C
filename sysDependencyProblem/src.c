#include <src.h>

#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

size_t get_file_size(const char* const file_path)
{
    if (file_path == NULL)
    {
        fprintf(stderr, "[ERROR] file_path == NULL\n");
        return 0;
    }

    struct stat st = {0};
    if (stat(file_path, &st) != 0)
    {
        fprintf(stderr, "[ERROR] stat(%s) error: %s\n", file_path, strerror(errno));
        return 0;
    }

    return (size_t)st.st_size;
}

size_t get_sysfile_meminfo_size(void)
{
    if (file_path == NULL)
    {
        fprintf(stderr, "[ERROR] file_path == NULL\n");
        return 0;
    }

    register const char* const file_path = "/proc/meminfo";
    enum {SYS_FILE_MIN_CHUNK_SIZE = 1024};

    char* buffer = malloc(SYS_FILE_MIN_CHUNK_SIZE * sizeof(*buffer));
    if (buffer == NULL)
    {
        fprintf(stderr, "[ERROR] malloc error on alloc size: %d\n", SYS_FILE_MIN_CHUNK_SIZE);
        return 0;
    }

    size_t buffer_size = SYS_FILE_MIN_CHUNK_SIZE;
    size_t bytes_read_from_file = 0;

    while (true)
    {
        register FILE* const fp = fopen(file_path, "r");
        if (fp == NULL)
        {
            fprintf(stderr, "[ERROR] fopen on file %s failed, error: %s\n", file_path, strerror(errno));
            free(buffer);

            return 0;
        }

        bytes_read_from_file = fread(buffer, sizeof(buffer[0]), buffer_size, fp);
        register const bool is_eof = !!feof(fp);
        register const bool is_error = !!ferror(fp);

        fclose(fp);

        if (bytes_read_from_file < buffer_size && is_eof && !is_error)
        {
            free(buffer);

            return bytes_read_from_file;
        }

        buffer_size *= 2;
        buffer = realloc(buffer, buffer_size * sizeof(*buffer));
        if (buffer == NULL)
        {
            fprintf(stderr, "[ERROR] realloc error on alloc size: %d\n", SYS_FILE_MIN_CHUNK_SIZE);
            return 0;
        }
    }
}
