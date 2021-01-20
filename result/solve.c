#include <stdio.h>

int main() {
    int a, b;
    while(1) {
        scanf("%d %d%*c", &a, &b);
        if (a == 0 && b == 0) break;
        printf("%d %d\n", a*b, 2*(a+b));
    }
    return 0;
}
