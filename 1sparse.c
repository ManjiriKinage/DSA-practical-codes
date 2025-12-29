#include<stdio.h>
int main(){
    int users,i,j;
    printf("Enter number of users: ");
    scanf("%d", &users);
  int matrix[10][10];
    int sparse[50][3];  
    int k = 0;
    printf("\nEnter friendship matrix (1 = friend, 0 = not friend):\n");
    for (i = 0; i < users; i++) {
        for ( j = 0; j < users; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j]==1){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=1;
                k++;
            }
        }
    }
     printf("\nSparse Matrix (row col value):\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    
    int user1, user2;
    printf("\nEnter two users to find mutual friends: ");
    scanf("%d %d", &user1, &user2);


for(i=0;i<k;i++){
    if(sparse[i][0]==user1){
        for(j=0;j<k;j++){
            if(sparse[j][0]==user2 && sparse[i][1]==sparse[j][1]){
                printf("user %d \n",sparse[i][1]);
            }
        }
    }
}

}
