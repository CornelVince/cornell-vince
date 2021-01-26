
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// encrypt user's word by number in command line
int main(int argc, string argv[])
{
    // declare variables
    int key;
    int result;

    // only accept two command line arguments - key, s string
    if (argc != 2)
    {
        printf("You didn't enter a key. Run program and enter key.\n");
        return 1;
    }

    // get the plain text
   string text = get_string("text: ");

    // convert the string/second command line argument (number) to integer
    key = atoi(argv[1]);

    // if key >= 26, use modulo 26 to wrap back to Aa after Za
    if (key >= 26)
    {
        key = (key % 26);
    }

    // encrypt - iterate over characters in string
    // print each one one at a time
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        // test - printf("In calculating %c + %d...\n", text[i], key);

        // encryption
        result = (text[i] + key);

        // wrapping after Z for uppercase letters
        if (isupper(text[i]) && (result > 'Z'))
        {
            result = (result - 26);
        }

        // wrapping after z for lowercase letters
        if (islower(text[i]) && (result > 'z'))
        {
            result = (result - 26);
        }

        // test - printf("The ASCII value of %c is %d.\n\n", result, result);

        // if character is alphabetical, print encrypted result
        if (isalpha(text[i]))
        {
            printf("%c", result);
        }

       // if non-alphabetical character, print as is
        else
        {
            printf("%c", text[i]);
        }

    }

    printf("\n");
    return 0;
}
