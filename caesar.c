#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

//this program will shift letters and rotate them so that Z becomes A if shifted by 1 and essentially encrypts a message by a certain number which is the key


int main(int argc, string argv[])
{   
    //declaring our values
    
    int j = 0, f = 0, n;
    
    //here we check to see if they key is valid, and the key must only accept numbers
    
    if (argc == 2)
    {
        n = strlen(argv[1]);
        
        for (int i = 0; i < n; i++)
        {   
            if (isalpha(argv[1][i]) == 0 && isdigit(argv[1][i])) 
            {
                j++;
            }
        }
    }
    else
    {
        //this is returned if the key is invalid
        printf("Usage:./caesar key \n");
        return 1;
    }
    
    
    //here we start to encipher the code itself, by shifting the letters, but first by shifting to a base of 0 to 25 for all letters
    if (j == n && argc == 2) 
    {
        string plainText = get_string("Enter text you wish to encode: ");
        int b = strlen(plainText);
        printf("plaintext: %s\n", plainText);
        
        for (int i = 0; i < b; i++)
        {
            f = atoi(argv[1]);
            if (isalpha(plainText[i]) && isupper(plainText[i]))
            {
                plainText[i] = plainText[i] - 65;
                plainText[i] = (plainText[i] + f) % 26;
                plainText[i] = plainText[i] + 65;
            }
            else if (isalpha(plainText[i]) && islower(plainText[i]))
            {
                plainText[i] = plainText[i] - 97;
                plainText[i] = (plainText[i] + f) % 26;
                plainText[i] = plainText[i] + 97;
            }
        }
        
        //here we begin to print out the text after shifting it
        printf("ciphertext: ");
        for (int i = 0; i < b; i++)
        {
            printf("%c", plainText[i]);
        }
        printf("\n");
    }
    else 
    {
        //this is returned if the key is invalid
        printf("Usage:./caesar key \n");
        return 1;
    }
}
