#include <stdio.h>

int main() {
    int a = 1, i;
    for (i = 1; i < 10; i++)
        a = 2 * (a + 1);
    printf("%d", a);
    return 1;
}
