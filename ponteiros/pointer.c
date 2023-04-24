#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *valor, valor_dois = 50;
  // "*valor" armazena um ENDEREÇO DE MEMÓRIA da RAM que irá armazenar um inteiro
  // ponteiros armazenam ENDEREÇOS DE MEMÓRIA
  valor = &valor_dois;
  // valor recebe o endereço de memória de valor_dois
  // valor é um apontador para o tipo INT

  char *letra, letra_dois = "a";
  // "*letra" armazena um ENDEREÇO DE MEMÓRIA na RAM que irá armazenar um char
  letra = &letra_dois;
  // letra recebe o endereço de memória de letra_dois
  // letra é um apontador para o tipo CHAR

  printf("Valor de valor_dois: %d\n", valor_dois);
  printf("Endereço de valor_dois: %p\n", &valor_dois);
  printf("Conteudo da variavel valor: %p\n", valor);
  printf("Conteudo apontado pela variavel valor: %d\n", *valor);

  return 0;
}