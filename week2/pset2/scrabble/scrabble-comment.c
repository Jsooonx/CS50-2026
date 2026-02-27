#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// POINTS array stores the Scrabble score for each letter A–Z.
// Index 0 = A, 1 = B, 2 = C, ..., 25 = Z.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype: computes the score of a given word
int compute_score(string word);

int main(void)
{
    // Prompt Player 1 for input
    string word1 = get_string("Player 1: ");

    // Prompt Player 2 for input
    string word2 = get_string("Player 2: ");

    // Compute each player's score using the helper function
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Compare scores and print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Computes and returns the Scrabble score of a word
int compute_score(string word)
{
    // Variable to store total score
    int score = 0;

    // Loop through each character in the string
    // We store strlen(word) in 'len' to avoid recalculating it each iteration
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // If the character is uppercase (A-Z)
        if (isupper(word[i]))
        {
            /*
             Why does word[i] - 'A' work?

             In ASCII:
             'A' = 65
             'B' = 66
             'C' = 67
             ...
             'Z' = 90

             So if word[i] = 'C':
             'C' - 'A' = 67 - 65 = 2

             That means:
             A → 0
             B → 1
             C → 2
             ...
             Z → 25

             Which perfectly matches the index of the POINTS array.
            */
            score += POINTS[word[i] - 'A'];
        }
        // If the character is lowercase (a-z)
        else if (islower(word[i]))
        {
            /*
             Same logic for lowercase letters.

             In ASCII:
             'a' = 97
             'b' = 98
             ...
             'z' = 122

             Example:
             'c' - 'a' = 99 - 97 = 2

             Again, this maps letters to 0–25,
             which matches our POINTS array.
            */
            score += POINTS[word[i] - 'a'];
        }

        // Non-alphabetical characters (numbers, symbols, spaces)
        // are ignored and do not affect the score.
    }

    // Return the total calculated score
    return score;
}