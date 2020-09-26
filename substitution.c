#include<cs50.h>
#include<stdio.h>
#include <string.h>
#include <ctype.h>

//string p_result(string str);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string key_d = argv[1];
        int lenkey = strlen(key_d);
        bool error1 = 0;
        if (strlen(key_d) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int i = 0; i < lenkey; i++)
        {
            if (!((key_d[i] >= 65 && key_d[i] <= 90)||(key_d[i] >= 97 && key_d[i] <= 122)))
            {
                error1 = 1;
            }
            key_d[i] = toupper(key_d[i]);
            for (int j = 0; j < 26; j++)
            {
                if ((key_d[i] == key_d[j]) && (i != j))
                {
                    //printf("Duplicate character in key");
                    return 1;
                }
            }
        }
        if (error1 == 1)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else
        {
            string input = get_string("plaintext:  ");
            int stl= strlen(input);
            printf("ciphertext: ");
            for (int i = 0; i< stl; i++)
            {
                if (input[i] >= 65 && input[i] <= 90)
                {
                    int key = input[i] - 65;
                    printf("%c",argv[1][key]);
                }
                else if (input[i] >= 97 && input[i] <= 122)
                {
                    int key = input[i] - 97;
                    printf("%c",argv[1][key]+32);
                }
                else
                {
                    printf("%c",input[i]);
                }
            }
            printf("\n");
        }
    }
}
