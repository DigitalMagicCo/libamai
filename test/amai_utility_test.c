#include "amai_utility_test.h"

#include "DMUnit.h"

#include <amai_utility.h>

int testForwardSlashesToBackSlashes()
{
    const char* path = "./my/test/path/file.txt";
    const char* newPath = "";

    newPath = amaiConvertSlashes(path);

    ASSERT_STR_EQUALS(newPath, ".\\my\\test\\path\\file.txt");

    return TEST_SUCCESS;
}

void runAmaiUtilityTests()
{
    printf("Testing Amai Utility methods...\n");

    runTest(testForwardSlashesToBackSlashes, "Convert path with forward-slashes to backslashes");
}
