#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float change;
    int coin_used = 0;
    printf("Let's calculate your change!\n");
    do
    {
        change = get_float("input change (in dollars): ");
    }
    while (change < 0);
    change = round (change * 100);
    printf("your change in 'cent' is:%.0f cents\n", change);
    while (change >= 25)
    {
        coin_used++;
        change = change - 25;
    }
    while (change >= 10)
    {
        coin_used++;
        change = change - 10;
    }
    while (change >= 5)
    {
        coin_used++;
        change = change - 5;
    }
    while (change >= 1)
    {
        coin_used++;
        change = change - 1;
    }
    printf("Number of coins used to make change:\n");
    printf("%d\n", coin_used);
}
