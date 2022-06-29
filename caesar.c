#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string str);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string text = get_string("plaintext: ");
    //ciphertext and individually printed letters will all land on the same line
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        printf("%c", rotate(text[i], key));
    }
    printf("\n");
    return 0;
}

//checks to make sure command line argument is a number
bool only_digits(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

//completes the rotation of an individual character
char rotate(char letter, int key)
{
    if (!isalpha(letter))
    {
        return letter;
    }
    //should never rotate by more than 26 characters
    key = key % 26;
    //capital letters
    if (letter >= 65 && letter <= 90)
    {
        letter += key;
        if (letter > 90)
        {
            letter -= 26;
        }
    }
    else //lowercase letters
    {
        if (letter + key <= 122)
        {
            letter += key;
        }
        else //subtracting first for letters that exceed 122 when the key is added to the letter value
        {
            letter = letter - 26 + key;
        }
    }
    return letter;
}