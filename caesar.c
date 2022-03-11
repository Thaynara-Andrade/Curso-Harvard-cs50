//MATRÍCULA: 20202045050315
//NOME: THAYNARA DA SILVA ANDRADE
//USUÁRIO: Thaynara-Andrade

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

void caesar(char *, int);

int main(int argc, char *argv[])
{
// IF E FOR SÃO USADOS PARA A VALIDAÇÃO DA CHAVE SOLICITADA PELO USUÁRIO
    if (argc != 2)
    {
        printf("Use: ./caesar key\n");
        return 1;
    }
    
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]) != 0)
        {
            printf("Use: ./caesar key\n");
            return 1;
        }
    }
// CONVERTE A CHAVE DE ALFA PARA NUMEROS INTEIROS
    int key = atoi(argv[1]);
// PEDE AO USUÁRIO A CHAVE QUE DESEJA CRIPTOGRAFAR   
    char *plaintext = get_string(" INSIRA O TEXTO QUE DESEJA CRIPTOGRAFAR: ");
    caesar(plaintext, key);
}
// REPETE AS LETRAS, VERIFICA SE ESTÁ EM ORDEM ALFABETICA, VERIFICA SE ESTA EM MAIÚSCULAS E APLICA A FORMA DA TABELA ASCII EM LETRAS MAIÚSCULAS.
void caesar(char *t, int k)
{
    printf("ciphertext: ");
    for (int i = 0; t[i] != '\0'; i++)
    {

        if (isalpha(t[i]) != 0)
        {

            if (isupper(t[i]) != 0)
            {

                printf("%c", ((t[i] - 'A' + k) % 26) + 'A');
            }

            else
            {
                printf("%c", ((t[i] - 'a' + k) % 26) + 'a');
            }
        }

        else
        {
            printf("%c", t[i]);
        }
    }
    printf("\n");
}