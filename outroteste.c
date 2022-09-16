#include <stdio.h>
#include <stdlib.h>

typedef struct elemento_s elemento_t;
typedef struct matriz_s matriz_t;

struct elemento_s
{
  int valor;
  elemento_t *abaixo;
  elemento_t *direita;
};

struct matriz_s
{
  elemento_t *inicio;
  int linhas;
  int colunas;
};

matriz_t *matriz_criar(int linhas, int colunas)
{
  int l = 0;
  int c = 0;
  elemento_t *esq = NULL;
  elemento_t *prim = NULL;
  elemento_t *ant = NULL;
  elemento_t *inicio = NULL;

  for (l = 0; l < linhas; l++)
  {
    esq = NULL;

    for (c = 0; c < colunas; c++)
    {
      elemento_t *el = (elemento_t *)calloc(1, sizeof(elemento_t));

      el->valor = 0;

      if (!inicio)
        inicio = el;

      if (esq)
        esq->direita = el;

      esq = el;

      if (ant)
      {
        int i = 0;
        elemento_t *aux = ant;

        for (i = 0; i < c; i++)
          aux = aux->direita;

        aux->abaixo = el;
      }

      if (c == 0)
        prim = el;
    }

    ant = prim;
  }

  matriz_t *m = (matriz_t *)calloc(1, sizeof(matriz_t));

  m->inicio = inicio;
  m->colunas = colunas;
  m->linhas = linhas;

  return m;
}

void matriz_destruir(matriz_t *m)
{
  elemento_t *ec = m->inicio;
  elemento_t *el = NULL;
  elemento_t *aux = NULL;

  while (ec)
  {
    el = ec->direita;

    while (el)
    {
      aux = el->direita;
      free(el);
      el = aux;
    }

    aux = ec->abaixo;
    free(ec);
    ec = aux;
  }

  free(m);
}

elemento_t *matriz_obter_elemento(matriz_t *m, int col, int linha)
{
  int i = 0;
  elemento_t *e = m->inicio;

  for (i = 0; i < linha; i++)
    e = e->abaixo;

  for (i = 0; i < col; i++)
    e = e->direita;

  return e;
}

void matriz_setar_elemento(matriz_t *m, int col, int linha, int valor)
{
  elemento_t *e = matriz_obter_elemento(m, col, linha);
  e->valor = valor;
}

void matriz_debug(matriz_t *m)
{
  int l = 0;
  int c = 0;

  // printf("matriz=%p, colunas=%d, linhas=%d, inicio=%p\n", m, m->colunas, m->linhas, m->inicio);
  int cont = 0;
  for (l = 0; l < m->linhas; l++)
  {
    for (c = 0; c < m->colunas; c++)
    {
      elemento_t *e = matriz_obter_elemento(m, c, l);
      if (cont <= 3)
      {
        printf("%d ,", e->valor);
        cont++;
      }
      else
      {
        printf("%d \n", e->valor);
        cont = 0;
      }
    }
  }
  printf("\n\n");
}

int main(void)
{
  int qtd_linhas = 3;
  int qtd_colunas = 5;

  /* Criando Matriz */
  matriz_t *m = matriz_criar(qtd_linhas, qtd_colunas);

  /* Preenchendo Elementos da Linha 0 */
  matriz_setar_elemento(m, 0, 0, 9);
  matriz_setar_elemento(m, 1, 0, 5);
  matriz_setar_elemento(m, 2, 0, 3);
  matriz_setar_elemento(m, 3, 0, 2);
  matriz_setar_elemento(m, 4, 0, 7);

  /* Preenchendo Elementos da Linha 1 */
  matriz_setar_elemento(m, 0, 1, 4);
  matriz_setar_elemento(m, 1, 1, 8);
  matriz_setar_elemento(m, 2, 1, 6);
  matriz_setar_elemento(m, 3, 1, 3);
  matriz_setar_elemento(m, 4, 1, 7);

  /* Preenchendo Elementos da Linha 2 */
  matriz_setar_elemento(m, 0, 2, 6);
  matriz_setar_elemento(m, 1, 2, 4);
  matriz_setar_elemento(m, 2, 2, 0);
  matriz_setar_elemento(m, 3, 2, 1);
  matriz_setar_elemento(m, 4, 2, 9);

  /* Debug da Matriz */
  matriz_debug(m);

  /* Destruindo Matriz */
  matriz_destruir(m);
  matriz_t *n = matriz_criar(qtd_linhas, qtd_colunas);

  /* Preenchendo Elementos da Linha 0 */
  matriz_setar_elemento(n, 0, 0, 1);
  matriz_setar_elemento(n, 1, 0, 7);
  matriz_setar_elemento(n, 2, 0, 3);
  matriz_setar_elemento(n, 3, 0, 2);
  matriz_setar_elemento(n, 4, 0, 5);

  /* Preenchendo Elementos da Linha 1 */
  matriz_setar_elemento(n, 0, 1, 9);
  matriz_setar_elemento(n, 1, 1, 7);
  matriz_setar_elemento(n, 2, 1, 6);
  matriz_setar_elemento(n, 3, 1, 0);
  matriz_setar_elemento(n, 4, 1, 7);

  /* Preenchendo Elementos da Linha 2 */
  matriz_setar_elemento(n, 0, 2, 1);
  matriz_setar_elemento(n, 1, 2, 3);
  matriz_setar_elemento(n, 2, 2, 0);
  matriz_setar_elemento(n, 3, 2, 1);
  matriz_setar_elemento(n, 4, 2, 0);

  /* Debug da Matriz */
  matriz_debug(n);

  /* Destruindo Matriz */
  matriz_destruir(n);

  return 0;
}