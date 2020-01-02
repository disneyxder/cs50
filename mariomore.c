#include <cs50.h>
#include <stdio.h>

void pattern(int n);

int main(void)
{
    // Prompt user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    pattern(height);
}

void pattern(int n)
{
    int spaces, dashes, right;
    for (int rows = 1; rows < n + 1; rows++)
    {
        for (spaces = n - rows; spaces > 0; spaces--)
        {
            printf(" ");
        }
        for (dashes = 1; dashes < rows + 1; dashes++)
        {
            printf("#");
        }
        printf("  ");
        for (right = 1; right < rows + 1; right++)
        {
            printf("#");
        }
        printf("\n");
    }
}
