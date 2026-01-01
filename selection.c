#include<stdio.h>
int main(){
    int n,a[15],i,j,min,temp;

    printf("enter number of element : ");
    scanf("%d",&n);

    printf("enter elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min])
                min = j;
        }

        if(min!= i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            
        }
    }
    
    for(i=0;i<n;i++){
          printf("%d\t",a[i]);
    }

}