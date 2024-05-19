#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_strings(string argv);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_strings(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int n = atoi(argv[1]);

    string plaintxt = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; plaintxt[i] != '\0'; i++)
    {
        char c = plaintxt[i];
        c = rotate(c, n);
        printf("%c", c);
    }
    printf("\n");
    return 0;
}

bool only_strings(string argv)
{
    for (int i = 0; argv[i] != '\0'; i++)
    {
        char c = argv[i];
        if (isdigit(c) == false)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = ((c - 'A' + n) % 26) + 'A';
        }
        else if (islower(c))
        {
            c = ((c - 'a' + n) % 26) + 'a';
        }
    }
    return c;
}
