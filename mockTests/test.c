// MOCK all functions
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> // stat already included, so include in src.c wont be copy pasted
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static size_t mock_stat_counter = 0;
static inline int mock_stat(const char* restrict const file_path, struct stat* restrict st)
{
    if (file_path == NULL)
        return 1;

    if (stat(file_path, st) != 0)
        return 1;

    const off_t mock_st_size_arr[] = {0, 100};

    st->st_size = mock_st_size_arr[mock_stat_counter];

    mock_stat_counter++;

    return 0;
}

#define stat(file, st) mock_stat(file, st)

#include <src.c> // copy paste CODE

static void test_get_file_size(void)
{
    mock_stat_counter = 0;

    assert(get_file_size(NULL) == 0);
    assert(get_file_size("no_such_file") == 0);

    mock_stat_counter = 0;

    // empty file
    {
        register const char* const file_path = "./test_file.txt";
        register FILE* const fp = fopen(file_path, "w");
        assert(fp != NULL);
        fclose(fp);

        assert(get_file_size(file_path) == 0);

        remove(file_path);
    }

    // file with content
    {
        register const char* const file_path = "./test_file.txt";
        register FILE* const fp = fopen(file_path, "w");
        assert(fp != NULL);

        const char test_content[] = "Alice and Bob\n";
        register const size_t test_content_len = sizeof(test_content) - 1;

        fwrite(test_content, sizeof(test_content[0]), test_content_len, fp);
        fclose(fp);

        assert(get_file_size(file_path) == 100);

        remove(file_path);
    }
}

int main(void)
{
    test_get_file_size();

    return 0;
}
