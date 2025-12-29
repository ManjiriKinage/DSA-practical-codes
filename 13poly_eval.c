#include <stdio.h>
#include <math.h>
int main(){
    int degree, i;
    float x, result = 0;
    float coef[20];
      printf("Enter degree of polynomial: ");
    scanf("%d", &degree);
    printf("Enter coefficients from highest degree to constant term:\n");
    for(i=degree;i>=0;i--){
        printf("Coefficient of x^%d: ", i);
        scanf("%f",&coef[i]);
    }
    printf("Enter value of x: ");
    scanf("%f", &x);
    for(i=degree;i>=0;i--){
        result += coef[i] * pow(x,i);

    }
printf("\nValue of polynomial %.2f \n",result);
}