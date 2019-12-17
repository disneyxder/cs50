#include <cs50.h>
#include <stdio.h>

void invalid(void);
int main(void)
{
    // prompt user for input
    long input1, input2, input3;
    input1 = get_long("Enter your credit card number: ");
    input2 = input1;
    input3 = input1; 
    
    int totaldigits = 0; 
    
    // count number of digits
    while (input3 > 0)
    {
        input3 /= 10;
        totaldigits++;
    }
    
int secondlastdigits[totaldigits / 2];
int multiplieddigits[totaldigits / 2];
int multipliedsum[totaldigits / 2];
int nonsecondlastdigits[totaldigits - totaldigits / 2];
int nonmultipliedsum[totaldigits - totaldigits / 2];
int sum1, sum2, totalsum;
    
    // check for valid number of digits
    if ((totaldigits !=  13) && (totaldigits != 15) && (totaldigits != 16))
    {
        invalid();
    }
    else
    {
        // for all second last digits
        for (int i = 0; i < totaldigits / 2; i++)
        {
            // obtain second last digit
            secondlastdigits[i] = (input2 / 10) % 10;
            input2 /= 100;
            
            // multiply second last digit by 2
            multiplieddigits[i] = secondlastdigits[i] * 2;
            
            // obtain sum of multiplied digits 
            if (i != 0)
            {
                multipliedsum[0] = multiplieddigits[0] / 10 + multiplieddigits[0] % 10;
                multipliedsum[i] = multiplieddigits[i] / 10 + multiplieddigits[i] % 100 + multipliedsum[i - 1]; 
                sum1 = multipliedsum[i];
            }
        }
        // for all non second last digits
        for (int j = 0; j < totaldigits - totaldigits / 2; j++)
        {
            // obtain non second last digit
            nonsecondlastdigits[j] = input1 % 10;
            input1 /= 100;
            
            // obtain sum of non second last digits
            if (j != 0)
            {
                nonmultipliedsum[0] = nonsecondlastdigits[0];
                nonmultipliedsum[j] = nonsecondlastdigits[j] + nonmultipliedsum[j - 1];
                sum2 = nonmultipliedsum[j];
            }
        }
        // add the two sums together
        totalsum = sum1 + sum2;
        
        if (totalsum % 10 == 0)
        {
            // check for 15 digit numbers [AMEX]
            if (totaldigits == 15)
            {
                if (nonsecondlastdigits[7] == 3)
                {
                    if ((secondlastdigits[6] == 4) || (secondlastdigits[6] == 7))
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        invalid();
                    }
                }
                else
                {
                    invalid();
                }
            }
            // check for 13 digit numbers [VISA]
            if (totaldigits == 13)
            {
                if (nonsecondlastdigits[6] == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    invalid();
                }
            }
            // check for 16 digit numbers [MASTERCARD / VISA]
            if (totaldigits == 16)
            {
                if (secondlastdigits[7] == 4)
                {
                    printf("VISA\n");
                }
                else if (secondlastdigits[7] == 5)
                {
                    if ((nonsecondlastdigits[7] == 1) || (nonsecondlastdigits[7] == 2) || (nonsecondlastdigits[7] == 3) || (nonsecondlastdigits[7] == 4) || (nonsecondlastdigits[7] ==5))
                        {
                            printf("MASTERCARD\n");
                        }
                    else
                        {
                            invalid();
                        }
                }
                else 
                    {
                        invalid();
                    }
            }
        }
        else
        {
            invalid();
        }
    }
}

void invalid(void)
{
    printf("INVALID\n");
}
