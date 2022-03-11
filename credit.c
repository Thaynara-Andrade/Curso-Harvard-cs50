//MATRÍCULA: 20202045050315
//NOME: THAYNARA DA SILVA ANDRADE
//USUÁRIO: Thaynara-Andrade

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//COMPRIMENTO MÁXIMO DO CARTÃO DE CRÉDITO
#define MAXLENGTH 16

int main(void)
{

// PEDIR O USUÁRIO O NÚMERO DO CARTÃO DE CRÉDITO
    printf("DIGITE O NÚMERO DO CARTÃO DE CRÉDITO:");
    long long CCNumber = get_long_long("");


// INSERE O NÚMERO DO CARTÃO DE CRÉDITO E ARMAZENA O SEU COMPRIMENTO EM SEQUÊNCIA
    char s[MAXLENGTH];
    sprintf(s, "%lld", CCNumber);
    int len = strlen(s);

// QUANDO O COMPRIMENTO NÃO FOR VÁLIDO, RETORNARÁ ERRO
    if (len < 13 || len > 16 || len == 14)
    {
        printf("INVALID\n");
        return 0;
    }

//INSERE O NÚMERO NA MATRIZ, USANDO S [i] - '0' PARA A CONVERSÃO ASCII
    int number[len];
    for (int i = 0; i < len; i++)
    {
        number[i] = s[i] - '0';
    }

//MULTIPLICA TODOS OS OUTROS DÍGITOS POR 2, COMEÇANDO COM O PENÚLTIMO E FAZ AS SOMAS DOS DÍGITOS EM SEQUÊNCIA
//ADICIONA NÚMEROS NÃO MULTIPLICADOS PARA SOMAR
    int sum = 0, j = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (j % 2 == 0)
        {
            sum += number[i] * 2 % 10;
            if (number[i] * 2 >= 10)
            {
                sum += 1;
            }
        }

        else
        {
            sum += number[i];
        }

        j++;
    }

// VERIFICA OS MÓDULOS E NÚMEROS INICIAIS E IMPRIME O TIPO DE CARTÃO
    if (number[0] == 3 && (number[1] == 4 || number[1] == 7) && sum % 10 == 0)
    {
        printf("AMEX\n");
    }


    else if (number[0] == 5 && number[1] > 0 && number[1] < 6 && sum % 10 == 0)
    {
        printf("MASTERCARD\n");
    }

    else if (number[0] == 4 && sum % 10 == 0)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");

        return 0;
    }
}
