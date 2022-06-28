#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

//index = 0.0588 * L - 0.296 * S - 15.8
//L is the average number of letters per 100 words in the text
//S is the average number of sentences per 100 words in the text

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    //divide #letters by #words and multiply by 100 to get number of letters per 100 words
    float letters_per = letters / words * 100;
    //divide #sentences by #words and multiply by 100 to get number of sentences per 100 words
    float sentences_per = sentences / words * 100;
    int grade_level = round((0.0588 * letters_per) - (0.296 * sentences_per) - 15.8);
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
    return 0;
}

float count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            letter_count++;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            letter_count++;
        }
    }
    return letter_count;
}

float count_words(string text)
{
    int word_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        //32 corresponds with a space
        if (text[i] == 32)
        {
            word_count++;
        }
    }
    //add 1 since the last word will not have a space after it
    return word_count + 1;
}

float count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++)
//! = 33, . = 46, ? = 63
//the numerical codes for punctuation indicating the end of a sentence

    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence_count++;
        }
    }
    return sentence_count;
}