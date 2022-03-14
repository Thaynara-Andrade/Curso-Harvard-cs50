#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{

    // ENTRADA DE TEXTO
    string s = get_string("TEXT: ");
    int letter = 0;
    int word = 1;
    int sentence = 0;

    // CONTAR O NÚMERO DE LETRAS, PALAVRAS E SENTENÇAS
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letter++;
        }
        else if (s[i] == ' ')
        {
            word++;
        }
        else if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
            sentence++;
        }
    }

    // CALCULA O NÚMERO MÉDIO DE LETRAS, PALAVRAS E SENTENÇAS POR 100 PALAVARAS
    // CALCULA O ÍNDICE DE COLEMAN-LIAU
    printf("\n%s", s);
    printf("\nletter:%i word: %i sentence %i", letter, word, sentence);

    float L =    100 * ((float)letter / (float)word);
    float S =    100 * ((float)sentence / (float) word);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);


    // RETORNA O RESULTADO
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", grade); // here we all number between 15 to 1
    }

    else if (grade >= 16) // its means the number will move arount between 16
    {
        printf("Grade 16+\n");

    }
    else
    {
        printf("Before Grade 1\n");
    }


}