
//MATRÍCULA: 20202045050315
//NOME: THAYNARA DA SILVA ANDRADE
//USUÁRIO: Thaynara-Andrade

#include <stdio.h>
#include <cs50.h>
void print(char c, int n);

int main(void)
{
    int n;
    do
        //SOLICITA A ALTURA AO USUÁRIO
    {
        n = get_int(" DIGITE A ALTURA: ");
    }
    // VERIFICA O INTERVALO CERTO ENTRE 1 E 8
    while (n < 1 || n > 8);

    // FORMAÇÃO DA PIRÂMIDE
    for (int i = 0; i < n; i++)
    {
        print(' ', n - 1 - i);
        print('#', i + 1);
        print(' ', 2);
        print('#', i + 1);

        printf("\n");
    }
}
// DEFINE UM VALOR INTEIRO
void print(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}