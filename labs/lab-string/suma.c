#include <stdio.h>
#include "Conversion.h"

int main(int argc, char *argv[]) {
    (void)argc;
    int total = 0;
    for (char **arg = argv + 1; *arg != NULL; arg++)
        total += ToInteger(*arg);
    printf("%d\n", total);
    return 0;
}