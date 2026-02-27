#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (!valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");;
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 'A';
                printf("%c", toupper(key[index]));
            }
            else
            {
                int index = plaintext[i] - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}

bool valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                return false;
            }
        }
    }

    return true;
}