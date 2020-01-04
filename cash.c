#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: $");
    }
    while (dollars < 0);
    int cents = round(dollars * 100);
    int quarters, dimes, nickels, pennies;
    quarters = cents / 25;
    dimes = (cents % 25) / 10;
    nickels = ((cents % 25) % 10) / 5;
    pennies = ((cents % 25) % 10) % 5;
    printf("%i\n", quarters + dimes + nickels + pennies);
}
