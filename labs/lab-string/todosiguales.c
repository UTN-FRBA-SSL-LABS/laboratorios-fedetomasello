#include <stdio.h>
#include "String.h"

int main(int argc, char *argv[]) {
    (void)argc;
    if (argv[1] == NULL) {
        printf("1\n");
        return 0;
    }
    for (char **arg = argv + 2; *arg != NULL; arg++)
        if (!AreEqual(*arg, argv[1])) {
            printf("0\n");
            return 0;
        }
    printf("1\n");
    return 0;
}