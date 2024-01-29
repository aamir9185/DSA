#include <stdio.h>
int main()
{
    int n, arr[20], key, found = 0;
    printf("Enter the number of elements of array \n");
        scanf("%d", &n);
    printf("Enter the elements of array \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the search element \n");
        scanf("%d", &key);
int *ptr = arr;
for (int i = 0; i < n; i++)
{
    if (*ptr == key)
    {
        printf("Element %d found at %d ",key,i);
        found = 1;
        break;

    }
    ptr++;
}

if (!found)
{
  printf("Elements not found");
}
}