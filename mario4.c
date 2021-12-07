#include <cs50.h>
#include <stdio.h>

/*I took the first two loops from mario3.c and then printed then I had to make the right side print 1 # and increment by 1 so figured that out.
Then I was confused about the space but it was simple, I wanted 2 spaces or 1 but def not n so I made a for loop to print 2 spaces m<=1 for [0,1]

Also I could've just printed two spaces*/

int main(void)
{
    int n; //declared the varable n
    
    //will get the user's height while n is true
    do 
    {
        n = get_int("height: ");
        //do and while are mutually exclusive if n is false in this case n won't get an int
    } 
    while (n < 1 || n > 8); //needs a condition that if true it executes once, so if I pick 9, n > 8 will make it prompt me for another number

    for (int i = 0; i < n; i++)//outer for loop with a counter, this loop will esentially execute for each stack
    {
        // for the blank spaces
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)  // var j is being overwritten with the value of 0
        {
            printf("#");
        }
        
        for (int m = 0; m <= 1; m++)
        {
            printf(" ");
        }
       
        for (int f = 0; f <= i; f++)
        {
            printf("#");
        }
        
        printf("\n");
       
    }

}
