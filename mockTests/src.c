#include <src.h>

#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

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
