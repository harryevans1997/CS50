#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // if-else statements to check correct # of command line arguments
    if (argc < 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Too many command-line arguments\n");
        return 1;
    }
    printf("argument count: %i\n", argc);
    printf("argv[1] = %s\n",  argv[1]);



    // for loop to iterate over command-line argument
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]))
        {

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // converting from char to int e.g "1" to 1
    int key = atoi(argv[1]);
    printf("key = %i\n", key);

    // prompting user for plaintext
    string plaintext = get_string("plaintext: ");

    // for loop to iterate over plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            plaintext[i] -= 97;
            plaintext[i] = (plaintext[i] + key) % 26;
            plaintext[i] += 97;
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] -= 65;
            plaintext[i] = (plaintext[i] + key) % 26;
            plaintext[i] += 65;
        }
    }

    // ciphertext output
    printf("ciphertext: %s", plaintext);
    printf("\n");
    return 0;
}