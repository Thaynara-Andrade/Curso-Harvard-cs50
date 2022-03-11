//MATRÍCULA: 20202045050315
//NOME: THAYNARA DA SILVA ANDRADE
//USUÁRIO: Thaynara-Andrade

#include <stdio.h>
#include <math.h>
#include <cs50.h>

float getValue(void);
int coins(int cents);

int main(void)
{

    //CERTIFICA SE O USUÁRIO SOLICITA UM VALOR VÁLIDO
    float owed = getValue();

    //CONVERTE DÓLAR EM CENTAVOS
    int cents = round(owed * 100);

    //IMPRIME A QUANTIDADE DE MOEDAS NECESSÁRIAS E QUEBRA A LINHA
    printf("%d\n", coins(cents));
}

// CONTA O MENOR NÚMEROS DE MOEDAS NECESSÁRIAS PARA COBRIR O TROCO
int coins(int cents)
{
    int count = 0;

    //DIMINUI CENTAVOS PELA MAIOR MOEDA POSSÍVEL, ATÉ CENTAVOS SER = 0
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            count++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            count++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            count++;
        }
        else
        {
            cents -= 1;
            count++;
        }
    }
    return count;
}

// SOLICITA O USUÁRIO UM VALOR DE ALTERAÇÃO VÁLIDO
float getValue(void)
{
    // A MUDANÇA É FEITA ANTES DO LOOP, CASO CONTRÁRIO NÃO IRÁ CONSEGUIR
    float change;
    do
    {
        //FUNÇÃO DA BIBLIOTECA CS50
        change = get_float(" MUDANÇA DEVIDA: ");
    }
    while (change < 0.00);

    return change;
}