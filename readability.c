#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters(string text);
int sentences(string text);
int words(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letter = letters(text);

    int word = words(text);

    int sentence = sentences(text);

    float L = (100 * letter) / (float) word;
    float S = (100 * sentence) / (float) word;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int rounded = round(index);

    if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded);
    }
}

int words(string text)
{

    int length = strlen(text);
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            counter++; // the number of the spaces
        }
    }
    return counter + 1; // the number of words = spaces +1
}

int sentences(string text)
{

    int length = strlen(text);
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33) // .  ?  !
        {
            counter++;
        }
    }
    return counter;
}

int letters(string text)
{

    int length = strlen(text);
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (('A' <= text[i] && text[i] <= 'Z') ||
            ('a' <= text[i] && text[i] <= 'z')) // if it is letter ?
        {
            counter++;
        }
    }
    return counter;
}