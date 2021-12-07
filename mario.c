#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //declare the varibale i
    int i;
    
    //do-while loop, while i is true, get_int, executes do while loop at least once
    do
    {
        i = get_int("height: ");
    }
    while (i < 1 || i > 8);

    for (int x = 0; x < i; x++)  //in a loop declared a variable, and said while x is less than i, increment x by 1
    {
        for (int f = 0; f < i; f++)  //this loops to print a sequence of rows which contain sequences of characters
        {
            if (x + f < i - 1)  //used a conditional statement where if x + f is less than i -1 you print " ", otherwise you print a '#'
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");  //this breakline applies to the outermost loop,it stacks each row on top of each other making a column
    }

}
