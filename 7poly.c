#include <stdio.h>

struct poly {
    int coeff;
    int power;
};

int main() {
    struct poly p[10];
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power of term %d: ", i + 1);
        scanf("%d %d", &p[i].coeff, &p[i].power);
    }

    printf("\nPolynomial is:\n");

    for (int i = 0; i < n; i++) {
        printf("%dx^%d", p[i].coeff, p[i].power);
        if (i != n - 1)
            printf(" + ");
    }

    return 0;
}
