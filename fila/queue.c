#include <stdlib.h>
#include <stdio.h>

// FILA = FIFO = FIRST IN, FIRST OUT
// INSERÇÃO OCORRE SEMPRE NO FINAL DA FILA (EXCETO POR FILAS DE PRIORIDADE)
// REMOÇÃO OCORRE NO INÍCIO DA FILA (FIRST IN, FIRST OUT)

/* INSERIR
- INICIALMENTE É NULO POIS NÃO HÁ DADOS
- QUANDO ADICIONAMOS UM PRIMEIRO NÓ, ELE É O PRIMEIRO DA FILA E O SEU PONTEIRO APONTA PARA NULL
- QUANDO ADICIONAMOS O SEGUNDO NÓ, ELE VAI PARA TRÁS DO PRIMEIRO NÓ
- O PONTEIRO DO PRIMEIRO NÓ APONTA PARA O SEGUNDO NÓ, E O PONTEIRO DO SEGUNDO NÓ APONTA PARA NULL (ATÉ QUE HAJA INSERÇÃO DE OUTRO NÓ) */

/* REMOVER
- REMOVEMOS O PRIMEIRO DA FILA, O PRIMEIRO NÓ
- A FILA PRECISA APONTAR PARA O SEGUNDO NÓ
- LIBERAR O ESPAÇO (USANDO FREE) */

/* ESTRUTURA
typedef struct no
{
  Pessoa p; AQUI PODE SER QUALQUER TIPO DE DADO, NÃO NECESSARIAMENTE UMA STRUCT
  struct no *proximo;
}No; */

typedef struct no
{
  int valor;
  struct no *proximo;
} No;

void inserir(No **fila, int num)
{
  No *aux, *novo = malloc(sizeof(No)); // TEMOS DOIS NÓS, O NOVO E O AUXILIAR E VAMOS ALOCAR MEMÓRIA PARA OS DOIS

  if (novo) // if (novo != NULL)
  {
    novo->valor = num;    // VALOR DO NÓ É NUM
    novo->proximo = NULL; // NULL POIS A INSERÇÃO É SEMPRE NO FINAL DA FILA

    if (*fila == NULL) // VERIFICA SE A FILA ESTÁ VAZIA, PORÉM SÓ SERÁ VERDADEIRO NA PRIMEIRA INSERÇÃO
    {
      *fila = novo; // PRIMEIRO NÓ DA FILA
    }
    else
    {
      aux = *fila;         // AUX RECEBE O CONTEÚDO DO PONTEIRO FILA
      while (aux->proximo) // while (aux->proximo != NULL), PERCORRENDO A FILA
      {
        aux = aux->proximo;
      }
      aux->proximo = novo; // CASO A CONDIÇÃO DO WHILE FOR FALSA (O AUX SER O ÚLTIM NÓ)
    }
  }
  else
  {
    printf("Erro ao alocar memoria\n");
  }
}

No *remover(No **fila)
{
  No *remover = NULL;

  if (*fila) // SE FILA != NULL
  {
    remover = *fila;
    *fila = remover->proximo; // CONTEÚDO DA FILA RECEBE O PRÓXIMO ELEMENTO
  }
  else
  {
    printf("Fila vazia!\n");
  }
  return remover;
}

void imprimir(No *fila)
{
  printf("\t ------ FILA ------\n\t");
  while (fila) // ENQUANTO FILA != NULL
  {
    printf("%d ", fila->valor);
    fila = fila->proximo;
  }
  printf("\n\t --- FIM DA FILA ------\n");
}

int main()
{
  No *r, *fila = NULL;
  int opcao, valor;

  do
  {
    printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite um numero: ");
      scanf("%d", &valor);

      inserir(&fila, valor);
      break;

    case 2:
      r = remover(&fila);
      if (r)
      {
        printf("Removido: %d\n", r->valor);
        free(r);
      }
      break;

    case 3:
      imprimir(fila);
      break;

    default:
      if (opcao != 0)
      {
        printf("Opçao invalida!\n");
      }
    }

  } while (opcao != 0);

  return 0;
}