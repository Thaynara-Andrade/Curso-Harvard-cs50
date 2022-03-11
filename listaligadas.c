//MATRÍCULA: 20202045050315
//NOME: THAYNARA DA SILVA ANDRADE
//USUÁRIO: Thaynara-Andrade


#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include "lista.h"
int duplicados[20], k = 0;

int main(void)
{
    node_t *lista;
    lista = cria_no(1);

    //Adiciona vários nós, deveria ser alterado para um laço
    adiciona_no_final(lista, 2);
    adiciona_no_final(lista, 5);
    adiciona_no_final(lista, 42);
    adiciona_no_final(lista, 3);
    adiciona_no_final(lista, 10);
    adiciona_no_final(lista, 7);
    adiciona_no_final(lista, 15);
    adiciona_no_final(lista, 10);
    adiciona_no_final(lista, 20);
    adiciona_no_final(lista, 10);
    adiciona_no_final(lista, 10);

    //exibe os nós
    listar(lista);
}

void listar(node_t *lista)
{
    node_t *temp = lista;

    // Imprime um nó por vez até chegar ao final da lista (NULL)
    printf("LISTA / INCIDENTES\n");
    while (temp != NULL)
    {
        int cont = 1;
        for(int i = 0; i < k; i++){
            if(temp->valor == duplicados[i]){
                cont = cont + 1;
            }
        }
        printf("%2i    | %i \n", temp->valor, cont);
        temp = temp->prox;
    }
    printf("\n");
}

node_t *cria_no(valor_t valor)
{
    // Declara e aloca espaço para um nó
    node_t *lista = malloc(sizeof(node_t));

    // Se o nó não for nulo, preenche o mesmo e retorna
    // seu endereço
    if (lista != NULL)
    {
        lista->valor = valor;
        lista->prox = NULL;
        return lista;
    }
    return NULL;
}

bool adiciona_no_final(node_t *lista, valor_t valor)
{

    node_t *nova = lista;
    int cont;
    while (nova != NULL)
    {
        if(nova->valor == valor){
            cont = nova->valor;
        }
        nova = nova->prox;
    }
    if(valor == cont){
        duplicados[k] = valor;
        k++;
    }else{
        node_t *novo = cria_no(valor);
        if (novo == NULL)
        {
            return false;
        }

        // Segue os itens da lista até encontrar
        // um ponteiro nulo
        while (lista->prox != NULL)
        {
            lista = lista->prox;
        }
        lista->prox = novo;
    }

    return true;
}
