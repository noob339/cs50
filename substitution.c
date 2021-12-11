#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
    
int main(int argc, string argv[])
{
    int n = 0, tLength = 0;
    string text; 
    
    //here we check if the command line receives 2 arguments, if it does not we display and error, for each time it passes without error it dives further
    
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else 
    {
        //here we get the legnth of the string
        n = strlen(argv[1]);
        
    }
        
    //Here we are checking if the key has a length of 26, if it does not, we display an error message
    if (n != 26)
    {
        printf("Error, must contain 26 characters\n");
        return 1;
    }
    else
    {
        //Here we loop through the array to check if its a digit or not, we only want letters, so if its a digit, an error message is displayed
                
        for (int i = 0; i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                printf("Error, must contain only characters\n");
                return 1;
            }
        }
        
        //Here we check to see if there are letters that repeat, boy this was a tricky one, but solved it with pen a paper and the ole noggin, felt good
        
        for (int j = 0; j < n - 1; j++)
        {
            for (int f = 1; f < n - j; f++)
            {
                if (argv[1][j] == argv[1][f + j])
                {
                    printf("Error, characters cannot repeat\n");
                    return 1;
                }
            }
            
        }
        
        
        text = get_string("Plaintext: ");
        
        int position;
    
        tLength = strlen(text);
        
        //here we encipher the text and perform several checks before actually enchiphering
        
        for (int i = 0; i < tLength; i++)
        {
            if (isalpha(text[i]) && isupper(text[i]))
            {
                text[i] = text[i] - 65;
                position = (int)(text[i]);
                text[i] = argv[1][position];
                text[i] = toupper(text[i]);
            }
            else if (isalpha(text[i]) && islower(text[i]))
            {
                text[i] = text[i] - 97;
                position = (int)(text[i]);
                text[i] = argv[1][position];
                text[i] = tolower(text[i]);
            }
        }
        
        printf("ciphertext: ");
    
        for (int i = 0; i < tLength; i++)
        {
            printf("%c", text[i]);
        }
        printf("\n");
        
    }
    
    return 0;
}
