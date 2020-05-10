#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // declare variables
    long input, ccno1, ccno2, ccno3; 
    int count, checksum1, checksum2, checksum; 
    
    input = get_long("Number: "); 
    ccno1 = input; 
    ccno2 = input; 
    ccno3 = input; 
    
    // count digits
    count = 0;
    while (input > 0)
    {
        count++; 
        input /= 10; 
    }
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0; 
    }
    
    // declare arrays 
    int second[count/2], multsecond[count/2], nonsecond[count-count/2]; 
    
    // checksum1
    checksum1 = 0; 
    for (int i = 0; i < count/2; i++)
    {
        second[i] = ccno1 % 100 / 10; 
        ccno1 /= 100; 
        multsecond[i] = second[i] * 2; 
        checksum1+= multsecond[i] % 10 + multsecond[i] / 10; 
    }
    
    // checksum2
    checksum2 = 0; 
    for (int j = 0; j < count-count/2; j++)
    {
        nonsecond[j] = ccno2 % 10; 
        ccno2 /= 100; 
        checksum2 += nonsecond[j];
    }
    
    // checksum
    checksum = checksum1 + checksum2; 
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0; 
    }
    else 
    {
        // VISA
        if (count == 13)
        {
            ccno3 /= pow(10, 12);
            if (ccno3 == 4)
            {
                printf("VISA\n");
                return 0; 
            }
            else 
            {
                printf("INVALID\n"); 
                return 0; 
            }
        }
        
        // AMEX
        if (count == 15)
        {
            ccno3 /= pow(10, 13);
            if (ccno3 == 34 || ccno3 == 37)
            {
                printf("AMEX\n");
                return 0; 
            }
            else
            {
                printf("INVALID\n");
                return 0; 
            }
        }
        
        // MASTERCARD or VISA
        if (count == 16)
        {
            ccno3 /= pow(10, 14);
            
            // MASTERCARD
            if (ccno3 == 51 || ccno3 == 52 || ccno3 == 53 || ccno3 == 54 || ccno3 == 55)
            {
                printf("MASTERCARD\n");
                return 0; 
            }
            
            //VISA 
            if (ccno3/10 == 4)
            {
                printf("VISA\n");
                return 0;
            }
            
            else
            {
                printf("INVALID\n");
                return 0; 
            }
        }
    }
}
