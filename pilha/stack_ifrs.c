#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

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
	int topo;
	int array[MAX];
} Pilha;

bool empilhamento(Pilha *p, int valor)
{ // PODE FUNCIONAR OU NAO, POR ISSO UM BOOL
	if (p->topo == MAX)
	{
		printf("STACK OVERFLOW!\n");
		return false;
	}

	p->array[p->topo] = valor;
	p->topo++;
	printf("Empilhei: %d\n", valor);

	return true;
}

bool desempilhar(Pilha *p, int *valor)
{
	*valor = p->array[p->topo - 1];
	p->topo--;
	return true;
}

int main(int argc, char *argv[])
{
	Pilha p;
	p.topo = 0;

	empilhamento(&p, 10);

	int i;
	for (i = 0; i < 100; i += 10)
	{
		empilhamento(&p, i);
	}

	for (i = 0; i < 5; i++)
	{
		int v;
		if (desempilhar(&p, &v))
		{
			printf("Desempilhei: %d\n", v);
		}
		else
		{
			printf("FALHA AO DESEMPILHAR!\n");
		}
	}

	return 0;
}
