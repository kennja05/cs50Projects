#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid_key(string key);
char match_letter(char letter, string key);

int main(int argc, string argv[])
{
    //check for presence of key
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    //create lowercase version of key
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }
    //valid key checks for length, alphabet only, and no duplicates
    if (!valid_key(key))
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            //preserve upper case letters
            if (isupper(text[i]))
            {
                printf("%c", toupper(match_letter(text[i], key)));
            }
            else
            {
                printf("%c", match_letter(text[i], key));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

//check if key is good - returns false for invalid key
bool valid_key(string key)
{
    //check for correct length
    if (strlen(key) != 26)
    {
        return false;
    }
    //check to make sure is alphabet only
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    //check for duplicates
    for (int i = 0; i < strlen(key) - 1; i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}

//lines up key with alphabet to give correct mapping to key
char match_letter(char letter, string key)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    while (alphabet[i] != tolower(letter))
    {
        i++;
    }
    return key[i];
}