#include <stdio.h>
#include <stdlib.h>

// Dividimos a lista no meio (tem que ser ordenada)
// Meio = (Inicio + Fim) / 2
// Depois de obter o meio, vamos comparar se o nosso elemento está no meio da lista
// Se o elemento estiver ali, retornamos o índice
// Se o elemento não estiver ali, retornamos um índice impossível (-1)
// Caso o elemento esteja mais pra frente, será inicio = meio + 1;
// Caso esteja mais para tras, será fim = meio - 1;

int binary_search(int *vetor, int valor, int fim)
{
  int inicio = 0;
  int meio = (inicio + fim) / 2;

  while (inicio <= fim)
  {
    if (valor == vetor[meio])
    {
      return meio;
    }
    else
    {
      if (valor < vetor[meio])
      {
        fim = meio - 1;
      }
      else
      {
        inicio = meio + 1;
      }
    }
    meio = (inicio + fim) / 2;
  }
  return -1;
}

int main(int argc, char const *argv[])
{
  int vetor[10] = {10, 22, 30, 42, 50, 62, 70, 82, 90, 102};
  int valor, opcao;

  do
  {
    printf("Digite um valor a ser buscado: ");
    scanf("%d", &valor);

    printf("Resultado: Índice: %d\n", binary_search(vetor, valor, 9));
    if (binary_search(vetor, valor, 9) == -1)
    {
      printf("Não achei\n");
    }

    printf("\n0 - Sair\n1 - Nova busca\n");
    scanf("%d", &opcao);

  } while (opcao != 0);

  return 0;
}
