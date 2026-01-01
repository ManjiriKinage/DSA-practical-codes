#include<stdio.h>
int main(){
    int n,a[15],i,j,key;
    printf("enter number of element : ");
    scanf("%d",&n);
    printf("enter elements : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

   for(i=1;i<n;i++){
        
    key=a[i];
    j=i-1;

        while(j>=0 && a[j]> key){
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=key;

   }

 printf("sorted elements : ");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

}