#include <stdio.h>

int main() {
    int users, i, j;
    int matrix[10][10];
    int sparse[50][3];
    int k = 0;

    printf("Enter number of users: ");
    scanf("%d", &users);

    printf("Enter friendship matrix (1 = friend, 0 = not friend):\n");
    for (i = 0; i < users; i++) {
        for (j = 0; j < users; j++) {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nNon-Zero Entries (Sparse Matrix):\n");
    printf("Row  Col  Value\n");
    for (i = 0; i < k; i++) {
        printf("%3d  %3d  %3d\n",
               sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
