#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences (string text);

int main(void)
{
    string text = get_string("Write your Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / (float) words) * 100.0;
    float S = ((float) sentences / (float) words) * 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) round(index);

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

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 0;
    bool in_word = false;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isspace(text[i]))
        {
            if (!in_word)
            {
                words++;
                in_word = true;
            }
        }
        else
        {
            in_word = false;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}