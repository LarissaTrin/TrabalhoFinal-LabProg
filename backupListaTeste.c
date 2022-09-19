#include <stdio.h>  /*lista_imprime    */
#include <stdlib.h> /*malloc()         */

static char tabuleiro1[5][4] = {
    {'a', 'D', 'D', 'b'},
    {'a', 'D', 'D', 'b'},
    {'c', 'd', 'd', 'e'},
    {'c', 'g', 'h', 'e'},
    {'f', ' ', ' ', 'i'}};

typedef struct _lista_no
{
  int dado;
  struct _lista_no *prox;
} lista_no;

lista_no *lista_cria(void)
{
  lista_no *cabeca = malloc(sizeof(lista_no));
  cabeca->prox = NULL;
  return cabeca;
}

void lista_insere(lista_no *lista, int val)
{
  lista_no *novo_no = malloc(sizeof(lista_no));
  novo_no->dado = val;
  novo_no->prox = lista->prox;
  lista->prox = novo_no;
}

void lista_imprime(lista_no *lista)
{
  lista = lista->prox;
  while (lista)
  {
    printf("[%d]->", lista->dado);
    lista = lista->prox;
  }
  printf("NULL\n");
}

int main(void)
{
  lista_no *lista = lista_cria();
  lista_insere(lista, 2);
  lista_insere(lista, 1);
  lista_insere(lista, 4);

  lista_imprime(lista);
}