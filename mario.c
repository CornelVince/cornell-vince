#include <cs50.h> 
#include <stdio.h> 
int main(void)
{
    int n;
    int m;
    do
    {
        n = get_int("Size: ");
        //m = n - 1;
    }
    while (n < -1 || n > 8);
    for (int i = 0; i < n; i++)
    { 
        for (int j = n - i; j > 1; j--)
        {
            printf(" ");
        }
        for (int hashes = 0; hashes < i ; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}
