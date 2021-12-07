#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//This program will determine the grade level of your text based on an index the coleman lieu index


//our prototypes
int countLetters(string letters);
int countWords(string words);
int countSentences(string sentence);

int main(void)
{
    //we get the string
    string x = get_string("Enter text: ");
    
    //we set up the calculation for the coleman index
    float L = ((float) countLetters(x) / countWords(x) * 100);
    float S = ((float) countSentences(x) / countWords(x) * 100);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    
    
    //we set 3 paths, one for below 1st grade and one for grade 16 and above
    //everything in between is just printed out
    if (index < 1.00)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16.00)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
    
}
//This function checks for letters using the isalpha function from the ctype library as cs50 hinted lol
//The function does all the heavy lifting, if the statement is true it adds it to the running total
int countLetters(string letters)
{
    
    int n = strlen(letters);
    int letterSum = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (isalpha(letters[i]))
        {
            letterSum++;
        }
    }
    
    //printf("%i letters \n", letterSum);
    
    return letterSum;
}

//This function counds the amount of words in the string, and assumes it ends with either a letter of punctuation mark
//We use the spaces to determine the amount of words and add 1 more at the end to our running total
//Checks the elements off the array to search for spaces
int countWords(string words)
{
    int n = strlen(words), j = 0;
    char space = ' ';
    
    
    for (int i = 0; i < n; i++)
    {
        if (space == words[i])
        {
            j++;
        }
    }
    
    j++;
    
    //printf("%i words \n", j);
    
    return j;
}

//this function loops through the elements of the array of the string and checks for 3 punctuaton marks
//for each punctuation we can assume for these purposes the sentence has ended

int countSentences(string sentence)
{
    int n = strlen(sentence), f = 0;
    
    
    
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')
        {
            f++;
        }
    }
    
    return f;
}
