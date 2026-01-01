#include<stdio.h>
#define MAX 5

int q[MAX], f = -1, r = -1;

int main(){
    int ch ,x,i;
    do{
         printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: //insert
                if((r+1) % MAX ==f)
                    printf("Queue Full\n");
                else{
                    if (f==-1)
                        f=r=0;
                    else
                        r=(r+1) % MAX;

                    
                    printf("Enter value: ");
                    scanf("%d", &x);
                    q[r]=x;
                }
                break;

             case 2 :   //delete
                if(f==-1)
                printf("Queue Empty\n");
                else{
                    printf("deleted node : %d\n",q[f]);

                    if(f==r)
                        f=r=-1;
                    else
                        f=(f+1)%MAX;

                }
            break;

            case 3: //display

            if (f == -1)
                printf("Queue Empty\n");
            else{
              printf("Queue: ");

              //for(i=f;i != (r+1 )%MAX ; i=(i+1)%MAX)
                 // printf("%d ", q[i]);
int i=f;
            do{
              printf("%d ", q[i]);
              i=(i+1)%MAX;
            }while (i != (r+1)% MAX);
            
            
             printf("\n"); 

            }





        }
    }while(ch != 4);
    return 0;
}