#include <src.h>

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

static void test_get_file_size(void);
static void test_get_sysfile_meminfo_size_user_call(void);
static void test_get_sysfile_meminfo_size(void);


static void test_get_file_size(void)
{
    assert(get_file_size(NULL) == 0);
    assert(get_file_size("no_such_file") == 0);

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

        assert(get_file_size(file_path) == test_content_len);

        remove(file_path);
    }
}

static void test_get_sysfile_meminfo_size_user_call(void)
{
    assert(get_sysfile_meminfo_size() > 0); // user call check
}

#undef get_sysfile_meminfo_size
static void test_get_sysfile_meminfo_size(void)
{
    assert(get_sysfile_meminfo_size(NULL) == 0);
    assert(get_sysfile_meminfo_size("no_such_file") == 0);

    // empty file
    {
        register const char* const file_path = "./test_file.txt";
        register FILE* const fp = fopen(file_path, "w");
        assert(fp != NULL);
        fclose(fp);

        assert(get_sysfile_meminfo_size(file_path) == 0);

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

        assert(get_sysfile_meminfo_size(file_path) == test_content_len);

        remove(file_path);
    }
}

int main(void)
{
    test_get_file_size();
    test_get_sysfile_meminfo_size_user_call();
    test_get_sysfile_meminfo_size();

    return 0;
}
