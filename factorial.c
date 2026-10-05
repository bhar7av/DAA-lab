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

#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial = %d\n", factorial(n));

    return 0;
}