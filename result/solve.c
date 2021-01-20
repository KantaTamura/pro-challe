#include <stdio.h>

int main() {
    int x;
    while(1) {
        scanf("%d%*c", &x);
        if (x == 0) break;
        printf("%d\n", x*x*x);
    }
    return 0;
}
