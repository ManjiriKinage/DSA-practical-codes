#include<stdio.h>
#define MAX 5

int q[MAX],f=-1,r=-1;
int main(){
int ch,x;
do{
    printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
     printf("Enter choice: ");
    scanf("%d", &ch);

      switch (ch) {

        case 1:   // Insert
        if(r==MAX-1)
        printf("Queue Full\n");
        else{
            if(f==-1)f=0;

            printf("insert value :");
            scanf("%d", &x);
            q[++r]=x;
        }
        break;

        case 2:
        if(f==-1 || f > r) printf("Queue Empty\n");
        else{
            printf("Deleted %d\n",q[f++]);
            if(f>r) f=r=-1;
        }
        break;

        case 3:   // Display
            if (f == -1)
                printf("Queue Empty\n");
            else{
                for(int i=f;i<=r;i++)
                printf("%d ", q[i]);
            }

        break;
        case 4:
            printf("Exit\n");
            break;
         default:
            printf("Invalid choice\n");
      }



}while(ch!=4);

}