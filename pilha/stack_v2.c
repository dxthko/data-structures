#include <stdio.h>
#include <stdlib.h>

/* LIFO = LAST IN, FIRST OUT
ÚLTIMO A ENTRAR, PRIMEIRO A SAIR */

/* EMPILHAR:
- Pra começar, temos "nós", que são os dados
- O dado mais recente sempre será o topo da pilha e o primeiro dado sempre será a base */

/* DESEMPILHAR:
- Criar ponteiro auxiliar para o topo
- Variável topo vai apontar para o ponteiro seguinte (o dado anterior a ele)
- Usar um free para remover o nó */

typedef struct
{
  int dia, mes, ano;
} Data;

typedef struct
{
  char nome[50];
  Data data;
} Pessoa;

typedef struct no
{
  Pessoa p;
  struct no *proximo;
} No;

typedef struct
{
  No *topo;
  int tam;
} Pilha;

void cria_pilha(Pilha *p)
{
  p->topo = NULL;
  p->tam = 0;
}

Pessoa ler_pessoa()
{
  Pessoa p;
  printf("Digite o nome: ");
  scanf("%[^\n]s", p.nome);

  printf("Digite a data de nascimento dd mm aaaa: ");
  scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);

  return p;
}

void imprimir_pessoa(Pessoa p)
{
  printf("\nNome: %s || Data: %d %d %d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void empilhar(Pilha *p)
{
  No *novo = malloc(sizeof(No));

  if (novo)
  {
    novo->p = ler_pessoa();
    novo->proximo = p->topo;
    p->topo = novo;
    p->tam++;
  }
  else
  {
    printf("Erro ao alocar memoria\n");
  }
}

No *desempilhar(Pilha *p)
{
  if (p->topo)
  {
    No *remover = p->topo;
    p->topo = remover->proximo;
    p->tam--;
    return remover;
  }
  else
  {
    printf("Pilha vazia!\n");
  }
  return NULL;
}

void imprimir_pilha(Pilha *p)
{
  No *aux = p->topo;
  printf("\n--------- PILHA TAMANHO:%d ---------\n", p->tam);
  while (aux)
  {
    imprimir_pessoa(aux->p);
    aux = aux->proximo;
  }
  printf("\n------ FIM DA PILHA ---------\n");
}

int main()
{
  Pilha p;
  No *remover;
  int opcao;

  cria_pilha(&p);

  do
  {
    printf("0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
      empilhar(&p);
      break;

    case 2:
      remover = desempilhar(&p);
      if (remover != NULL)
      {
        printf("Dado removido com sucesso!\n");
        imprimir_pessoa(remover->p);

        free(remover);
      }
      else
      {
        printf("Sem nada para remover!\n");
      }
      break;

    case 3:
      imprimir_pilha(&p);
      break;

    default:
      if (opcao != 0)
      {
        printf("Non existe!\n");
      }
    }
  } while (opcao != 0);
}