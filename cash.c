#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed: $");
    }
    while (change < 0);

    // variables
    int cents = round(change * 100);
    int quarter = cents / 25;
    int dime = cents % 25 / 10;
    int nickel = cents % 25 % 10 / 5;
    int penny = cents % 25 % 10 % 5 / 1;

    // print coins needed
    printf("Number of quarters: %i\n", quarter);
    printf("Number of dimes: %i\n", dime);
    printf("Number of nickels: %i\n", nickel);
    printf("Number of pennies: %i\n", penny);
    printf("Minimum number of coins: %i\n", quarter + dime + nickel + penny);
}
