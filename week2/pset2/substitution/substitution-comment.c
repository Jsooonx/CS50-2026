#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototype to validate the substitution key
bool valid_key(string key);

int main(int argc, string argv[])
{
    // ==================================================
    // 1. Check command-line argument count
    // The program must be executed as:
    // ./substitution KEY
    // Therefore argc must be exactly 2
    // ==================================================
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;  // return 1 indicates an error
    }

    // Store the key from command-line argument
    string key = argv[1];

    // ==================================================
    // 2. Validate the key
    // The key must:
    // - Contain exactly 26 characters
    // - Contain only alphabetic characters
    // - Contain no duplicate letters (case-insensitive)
    // ==================================================
    if (!valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // ==================================================
    // 3. Prompt user for plaintext input
    // ==================================================
    string plaintext = get_string("Plain Text: ");

    printf("Cipher Text: ");

    // ==================================================
    // 4. Encrypt each character of plaintext
    // ==================================================
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if character is alphabetic
        if (isalpha(plaintext[i]))
        {
            // If uppercase letter
            if (isupper(plaintext[i]))
            {
                // Determine alphabetical index:
                // 'A' - 'A' = 0
                // 'B' - 'A' = 1
                // 'C' - 'A' = 2
                int index = plaintext[i] - 'A';

                // Print corresponding character from key
                // Convert to uppercase to preserve case
                printf("%c", toupper(key[index]));
            }
            else
            {
                // If lowercase letter
                // 'a' - 'a' = 0
                // 'b' - 'a' = 1
                int index = plaintext[i] - 'a';

                // Print corresponding character from key
                // Convert to lowercase to preserve case
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            // If character is NOT alphabetic
            // (numbers, spaces, punctuation)
            // Print it unchanged
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}


// ==================================================
// Function to validate the substitution key
// ==================================================
bool valid_key(string key)
{
    // 1. Key must contain exactly 26 characters
    if (strlen(key) != 26)
    {
        return false;
    }

    // 2. Check each character in the key
    for (int i = 0; i < 26; i++)
    {
        // Must be alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }

        // 3. Check for duplicate letters
        // Compare current character with the remaining characters
        for (int j = i + 1; j < 26; j++)
        {
            // Use tolower() to make comparison case-insensitive
            if (tolower(key[i]) == tolower(key[j]))
            {
                return false;
            }
        }
    }

    // If all checks pass, key is valid
    return true;
}