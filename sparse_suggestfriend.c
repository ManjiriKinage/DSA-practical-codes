#include<stdio.h>
int main(){
    int users,i,j;
    int matrix[10][10];
    int sparse[50][3];
    int k=0;

     printf("Enter number of users: ");
    scanf("%d", &users);
     printf("\nEnter friendship matrix (1 = friend, 0 = not friend):\n");
    for (i = 0; i < users; i++) {
        for (j = 0; j < users; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j]==1){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=matrix[i][j];
                k++;
              }
        }
    }
    printf("\nSparse Matrix (row col value):\n");
    for(i=0;i<k;i++){
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
    int user;
  printf("\nEnter user to suggest new friend: ");
    scanf("%d", &user);
 int mutualCount[10] = {0};

    printf("\nMutual Friends:\n");
    int found=0;
    for(i=0;i<k;i++){
        if(sparse[i][0]==user){
            int friend= sparse[i][1];

            for(j=0;j<k;j++){
                if(sparse[j][0]==friend && sparse[j][1] != user && matrix[user][sparse[j][1]]==0){
                   mutualCount[sparse[j][1]]++;
                }
            }
        }
    }
    int max=0,suggest=-1;
    for (i = 0; i < users; i++){
        if(mutualCount[i]>max){
            max=mutualCount[i];
            suggest=i;
        }
    }
    if (suggest != -1)
        printf("\nSuggested Friend for User %d is User %d (Mutual Friends: %d)\n",
               user, suggest, max);
    else
        printf("\nNo friend suggestion found.\n");
        
        return 0;
}