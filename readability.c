#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // get input string from user
    string text = get_string("Text: ");

    // initialising variables
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // for loop for counting letters, words and sentences from input string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            letters += 1;
        }
        // statement doesn't count contractions as two separate words
        else if (isspace(text[i]))
        {
            words += 1;
        }
        else if ((text[i] == '!') || (text[i] == '?') || (text[i] == '.'))
        {
            sentences += 1;
        }
    }

    // Coleman-Liau equations readability index
    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    // statements for showing reading grade
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

    // statements returning # of letters, words and sentences
    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sentences);
}
