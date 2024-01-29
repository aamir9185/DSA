#include<stdio.h>
int fibonacci(int n){
    if(n<=1)
    return n;
    else
    return(fibonacci(n-1)+fibonacci(n-2));
}
int main(){
    int n;
    printf("enter the term to find in fibonacci series:");
    scanf("%d",&n);
    printf("The %dth term of fibonacci series is %d\n",n,fibonacci(n));
    return 0;
}