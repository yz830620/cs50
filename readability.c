#include<cs50.h>
#include<stdio.h>
#include <string.h>

int main(void)
{
    string st = get_string("Input is:");
    int wcount = 1;
    int scount = 0;
    int lcount = 0;
    /*the strlen will count all the individule in the string mark "OOXXX" 5 "OOO XX O" 8 */
    int ltotal = strlen(st);
    for (int i = 0; i < ltotal; i++)
    {
        if (st[i] == 33 || st[i] == 46 || st[i] == 63)
        {
            scount += 1;
        }
        else if (st[i] == 32)/* || st[i] == 39 || st[i] == 45*/
        {
            wcount += 1;
        }
        else if ((st[i] >= 65 && st[i] <= 90) || (st[i] >= 97 && st[i] <= 122))
        {

            lcount += 1;
        }
    }
    /*This code is just for step check*/
    /*printf("words: %i, sentances: %i, length: %i\n",wcount,scount,lcount);*/
    float l = (float)100 * lcount / wcount;
    float s = (float)100 * scount / wcount;
    float findex = (0.0588 * l - 0.296 * s - 15.8);
    /*printf("f:%f",findex);*/
    int index = (int)(findex + 0.5);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index <= 16 && index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
