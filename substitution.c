//MATRÍCULA: 20202045050315
//NOME: THAYNARA DA SILVA ANDRADE
//USUÁRIO: Thaynara-Andrade

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void subs(char *, char *);

int main(int argc, char *argv[])
{
//VALIDA A CHAVE
    if (argc != 2)
    {
        printf("Use: ./substitution key\n");
        return 1;
    }
    if (strlen(argv [1]) != 26)
    {
        printf(" A CHAVE DEVE CONTER 26 CARACTERES\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
//PRIMEIRO VERIFICA SE CHAR É ALFABÉTICO, LOGO EM SEGUIDA USA UM LOOP PARA VERIFICAR AS REPETIÇÕES
        if (isalpha(argv[1][i]) == 0)
        {
            printf(" A CHAVE DEVE CONTER APENAS CARACTERES ALFABÉTICOS \n");
            return 1;
        }
        for (int r = i + 1; r < strlen(argv[1]); r++)
        {
            if (toupper(argv[1][r]) == toupper(argv[1][i]))
            {
                printf("A CHAVE DEVE CONTER APENAS UM DE CADA CARACTERE ALFABÉTICO \n");
                return 1;
            }
        }
    }
    string text = get_string("Plaintext: ");
    subs(text, argv[1]);
}
//SE CERTIFICA EM MANTER O MESMO CASO PARA CADA LETRA DADA PELO USUÁRIO E INSERE O VALOS ASCII de 'a' de t [i], QUE CORRESPONDE AO INDICE CHAVE A POSIÇÃO
void subs(char *t, char *k)
{
    printf("ciphertext: ");

    for (int i = 0; i < strlen(t); i++)
    {
        if (isalpha(t[i]) != 0)
        {
            if (isupper(t[i]) != 0)
            {
                int index = t[i] - 'A';
                printf("%c", toupper(k[index]));
            }
            else
            {
                int index = t[i] - 'a';
                printf("%c", tolower(k[index]));
            }
        }
        else
        {
            printf("%c", t[i]);
        }
    }
    printf("\n");
}