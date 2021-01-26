#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string article = get_string("What's the article?: ");
    int letterscount = 0;
    int wordcount = 1;
    int sentencecount = 0;

    for (int i = 0; i < strlen(article);  i++)
    {
        if ((article[i] >= 'a' && article[i] <= 'z') || (article[i] >= 'A' && article[i] <= 'Z'))
        {
            letterscount++;
        }
        else if (article[i] == ' ')
        {
            wordcount++;
        }
        else if (article[i] == '!' || article[i] == '?' || article[i] == '.')
        {
            sentencecount++;
        }
    }
    float grade = 0.0588 * (100 * letterscount / wordcount) - 0.296 * (100 * sentencecount / wordcount) - 15.8;

    //printf("Letters: %i\n Words: %i\n Sentences: %i\n", letter, word, sentence);

// print result
    
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n",(int) round (grade));
    }
    else
    {
        printf("Grade 16+\n");
    }
}
