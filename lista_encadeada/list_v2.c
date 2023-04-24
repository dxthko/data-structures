#include <stdio.h>
#include <stdlib.h>

/* LISTA
- A ESTRUTURA LISTA TERÁ DOIS CAMPOS:
1 - PONTEIRO DE INÍCIO, QUE APONTA PARA O PRÓXIMO NÓ
2 - UM CAMPO COM O TAMANHO DA LISTA
- LEMBRE-SE: PRECISAMOS DE UM PONTEIRO AUXILIAR PARA O PRIMEIRO NÓ DA LISTA */

/* INSERÇÃO
- DÁ PRA INSERIR EM QUALQUER LUGAR, INÍCIO, MEIO OU FIM KKJJ :(
- PRIMEIRO, TEMOS QUE LINKAR O NOSSO NOVO NÓ COM A NOSSA LISTA
- O NOVO NÓ VAI APONTAR PARA O PONTEIRO AUXILIAR, PORÉM O AUXILIAR AINDA ESTÁ APONTANDO PARA OUTRO NÓ
- TEREMOS QUE FAZER COM QUE O AUXILIAR APONTE PARA O NOVO NÓ */

/* A REMOÇÃO EH DE LASCAR POIS DEPENDE DE ONDE ESTÁ O DADO (INÍCIO, MEIO OU FIM)
- PRECISAMOS SEMPRE IDENTIFICAR O NÓ QUE ESTÁ ANTES DESSE QUE VOCÊ QUER REMOVER (EXCLUINDO O PRIMEIRO)
- VOCÊ MARCA O NÓ ANTERIOR, USANDO UM AUXILIAR (REMOVER POR EX.)
- PEGA O REMOVER E APONTA ELE PARA O NÓ PRÓXIMO */

typedef struct no
{
  int valor;
  struct no *proximo;
} No;

typedef struct
{
  No *inicio;
  int tam;
} Lista;

void cria_lista(Lista *lista)
{
  lista->inicio = NULL;
  lista->tam = 0;
}

void inserir_inicio(Lista *lista, int num)
{
  No *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserir_fim(Lista *lista, int num) // RECEBE UM PONTEIRO PRA LISTA E UM DADO PRA INSERIR
{
  No *aux, *novo = malloc(sizeof(No)); // DECLARAMOS O NÓ, FAZENDO A ALOCAÇÃO PRA ELE, E TAMBÉM DECLARA O AUXILIAR
  if (novo)
  {
    novo->valor = num;    // CAMPO VALOR RECEBE O DADO
    novo->proximo = NULL; // É O ÚLTIMO NÓ DA LISTA

    /*--- SE FOR O PRIMEIRO NÓ SENDO INSERIDO ---*/
    if (lista->inicio == NULL)
    {
      lista->inicio = novo;
    }
    else // SE JÁ HOUVER UM NÓ ANTES
    {
      aux = lista->inicio; // USAMOS O AUXILIAR PARA NÃO PERDER A NOSSA LISTA NO CAMINHO
      while (aux->proximo) // aux->proximo != NULL
      {
        aux = aux->proximo;
      }
      aux->proximo = novo; // QUANDO O PRÓXIMO FOR NULO, RECEBEMOS O NOVO NÓ
    }
    lista->tam++;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}

void inserir_meio(Lista *lista, int num, int ant) // ANT = ANTERIOR
{
  No *aux, *novo = malloc(sizeof(No));
  if (novo)
  {
    novo->valor = num;
    /*--- SE FOR O PRIMEIRO NÓ SENDO INSERIDO ---*/
    if (lista->inicio == NULL)
    {
      novo->proximo = NULL;
      lista->inicio = novo;
    }
    else // A LISTA NÃO ESTÁ VAZIA
    {
      aux = lista->inicio;
      while (aux->valor != ant && aux->proximo)
      {
        aux = aux->proximo;
      }
      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
    lista->tam++;
  }
  else
  {
    printf("Erro ao alocar memória!\n");
  }
}
void imprimir(Lista lista)
{
  No *no = lista.inicio; // QUANDO ACESSAMOS UM PONTEIRO, USAMOS A SETA. QUANDO USAMOS PONTO, ESTAMOS ACESSANDO A CÓPIA DO ELEMENTO
  printf("LISTA e TAMANHO: %d\n", lista.tam);
  while (no)
  {
    printf("%d\n", no->valor);
    no = no->proximo;
  }
}

int main()
{
  int opcao, valor, anterior;
  Lista lista;

  cria_lista(&lista); // DIZ QUE LISTA.INICIO = NULL E LISTA.TAM = 0

  do
  {
    printf("0 - Sair\n1 - Inserir inicio\n2 - Inserir fim\n3 - Inserir meio\n4 - Imprimir\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite um valor para inserir no inicio: ");
      scanf("%d", &valor);

      inserir_inicio(&lista, valor);
      break;

    case 2:
      printf("Digite um valor para inserir no final: ");
      scanf("%d", &valor);

      inserir_fim(&lista, valor);
      break;

    case 3:
      printf("Digite um valor para inserir no meio e um valor de referencia: ");
      scanf("%d %d", &valor, &anterior);

      inserir_meio(&lista, valor, anterior);
      break;

    case 4:
      imprimir(lista);
      break;

    default:
      if (opcao != 0)
      {
        printf("Opcao invalida!\n");
      }
    }
  } while (opcao != 0);

  return 0;
}