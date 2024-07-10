#include <stdio.h>

int main() {
    float a = 5.7, b = 4.8;
    float* pa = &a;
    float* pb = &b;

    printf("\nDia chi cua a: %p", (void*)pa);
    printf("\nDia chi cua b: %p", (void*)pb);

    return 0;
}
