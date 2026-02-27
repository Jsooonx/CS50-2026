#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/*
    We will measure readability using the Coleman–Liau index.

    Steps:
    1) Count letters (alphabetic characters only)
    2) Count words
    3) Count sentences (., !, ?)
    4) Compute:
        L = average letters per 100 words
        S = average sentences per 100 words
        index = 0.0588 * L - 0.296 * S - 15.8
    5) Round index to the nearest integer -> grade
*/

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Ask the user for input text.
    // This can be a sentence, paragraph, etc.
    string text = get_string("Write your Text: ");

    // Count basic components needed for readability formula.
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Convert to "per 100 words" averages.
    // L = letters per 100 words
    // S = sentences per 100 words
    float L = ((float) letters / (float) words) * 100.0;
    float S = ((float) sentences / (float) words) * 100.0;

    // Coleman–Liau index formula.
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // round() returns the nearest integer as a floating value,
    // so we cast it to int.
    int grade = (int) round(index);

    // Print output format based on CS50 specification.
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

/*
    count_letters(text)

    Goal:
    - Return how many letters are in the text.

    What counts as a "letter"?
    - Only alphabetic characters A-Z or a-z.
    - NOT numbers, punctuation, spaces, symbols, etc.

    Approach:
    - Loop over each character in the string.
    - Use isalpha() (from <ctype.h>) to check if it is a letter.
    - If yes, increment a counter.
*/
int count_letters(string text)
{
    int letters = 0;

    // strlen(text) gives the number of characters in the string (not counting '\0').
    // We store it in n so we don't recompute strlen every loop iteration.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // isalpha() returns true for A-Z or a-z and false otherwise.
        // Example:
        // 'A' -> true
        // 'z' -> true
        // '3' -> false
        // '!' -> false
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

/*
    count_words(text)

    Goal:
    - Return how many words are in the text.

    Definition of a "word" (for this pset):
    - A sequence of non-whitespace characters separated by whitespace.
    - Whitespace includes spaces, tabs, and newlines.

    Why not just do "spaces + 1"?
    - Because input might contain multiple spaces, tabs, or newlines.
      Example: "Hi   there"
      spaces+1 would overcount if you don't handle multiple spaces properly.

    Approach (state machine style):
    - Track whether we are currently "inside a word" using a boolean flag in_word.
    - When we see a non-space char and we are NOT already in a word,
      that marks the start of a NEW word -> increase word count.
    - When we see whitespace, set in_word back to false, meaning the next
      non-space char will start another word.
*/
int count_words(string text)
{
    int words = 0;

    // in_word tells us whether we are currently reading characters that belong to a word.
    // Start false because we haven't seen any characters yet.
    bool in_word = false;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If current character is NOT whitespace, it could be part of a word.
        if (!isspace(text[i]))
        {
            // If we were previously NOT inside a word,
            // this character starts a new word.
            // Example: "Hello world"
            // When we hit 'H' -> in_word false -> new word -> words++.
            // Then letters continue until space.
            if (!in_word)
            {
                words++;
                in_word = true; // now we are inside a word
            }
        }
        else
        {
            // If the current character IS whitespace, then we are not inside a word anymore.
            // This prepares us for the next word start.
            in_word = false;
        }
    }

    return words;
}

/*
    count_sentences(text)

    Goal:
    - Return how many sentences are in the text.

    For this pset, a sentence is counted when we see:
    - '.'  (period)
    - '!'  (exclamation mark)
    - '?'  (question mark)

    Approach:
    - Loop through each character.
    - If character is one of those three punctuation marks, increment sentence count.

    Note:
    - This is a simplified rule (real language has more complexity),
      but it's exactly what the assignment expects.
*/
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If we encounter a sentence-ending punctuation mark,
        // count it as one sentence.
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}