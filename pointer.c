#include <stdio.h>
int main()
{
int num, *pnum;
pnum = &num;
num = 5;
printf("\n The number that was entered is : %d \n", *pnum);
printf("\n The number that was entered is : %d \n", pnum);
int num1 = 2, num2 = 3, sum = 0, mul = 0, div = 0;
int *ptr1, *ptr2;
ptr1 = &num1;
ptr2 = &num2;
sum = *ptr1 + *ptr2;
mul = sum * (*ptr1);
*ptr2 += 1;
div = 9 + (*ptr1)/(*ptr2);
printf("sum = %d   mul  = %d  ptr = %d \n ",sum,mul,div);
return 0;
}