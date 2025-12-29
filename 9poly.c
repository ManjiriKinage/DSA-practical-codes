#include <stdio.h>

int main() {
    int p1[10] = {0}, p2[10] = {0}, sum[10] = {0};
    int d1, d2, max;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &d1);

    printf("Enter coefficients of first polynomial:\n");
    for (int i = 0; i <= d1; i++)
        scanf("%d", &p1[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &d2);

    printf("Enter coefficients of second polynomial:\n");
    for (int i = 0; i <= d2; i++)
        scanf("%d", &p2[i]);

    max = (d1 > d2) ? d1 : d2;

    for (int i = 0; i <= max; i++)
        sum[i] = p1[i] + p2[i];

    printf("\nResultant Polynomial:\n");
    for (int i = max; i >= 0; i--) {
        if (sum[i] != 0) {
            printf("%dx^%d", sum[i], i);
            if (i != 0)
                printf(" + ");
        }
    }

    return 0;
}
