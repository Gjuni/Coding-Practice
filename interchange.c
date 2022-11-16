#include <stdio.h>

void interchange(char *arr, int index)
{
    char * ptr1 = &arr[0];
    char * ptr2 = &arr[index-1];
    char change;


    for(int i =0; i<index/2; i++)
    {
        change = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = change;

        ptr1++;
        ptr2--;
    }

    for(int i =0; i<index; i++)
    {
        printf("%c", arr[i]);
    }
}   


int main(void)
{
    char arr[100];
    int index;

    printf("interchange word : ");
    scanf("%s", arr);

    while (arr[index] != '\0')
    {
        index++;
    }


    interchange(arr, index);
    

    

    return 0;
}