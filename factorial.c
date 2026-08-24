//factorial without recursion
#include<stdio.h>

int main(){
    int n;
    int factorial = 1;
    printf("enter the number : ");
    scanf("%d",&n);

    if (n<0){
        printf("factorial of a negative number is not possible");
    }else{
        for(int i=1; i<=n;i++){
            factorial = factorial *i;
        }
        printf("factorial of %d is %d" , n , factorial);
    }
    return 0;

}
