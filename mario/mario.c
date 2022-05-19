#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int steps;
    do
    {
        steps = get_int("How many steps in the pyramid? ");
    }
    while (steps < 1 || steps > 8);
    //get total width of each row
    int x = steps * 2 + 2;
    //midpoint of each row. each row will have the midpoint and the column to the right of the midpoint empty
    int mid = x / 2;
    for (int i = 1; i <= steps; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            //print spaces in the middle two columns
            if (j == mid || j == mid + 1)
            {
                printf(" ");
            }

            //print spaces when we're not yet at the bottom row
            else if (j < mid - i)
            {
                printf(" ");
            }
            else if (j >= mid - i && j < mid)
            {
                printf("#");
            }
            else if (j > mid + 1 && j <= mid + i + 1)
            {
                printf("#");
            }

            //below could replace the two else if statements if acceptable to have white
            //space on end of the rows that come before the final row
            // else if (j < mid - i || j > mid + i + 1)
            // {
            //     printf(" ");
            // } else
            // {
            //     printf("#");
            // }
        }
        printf("\n");
    }
}