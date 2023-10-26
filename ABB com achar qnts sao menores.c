#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

no* criar_no(int valor) {
    no *novo_no = (no*) malloc(sizeof(no));
    novo_no->valor = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    return novo_no;
}

no* inserir_no(no *raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir_no(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir_no(raiz->dir, valor);

    return raiz;
}

int contarMenores(no *raiz, int valor) {
    if (raiz == NULL)
        return 0;

    int count = 0;

    if (raiz->valor < valor)
        count += 1;

    count += contarMenores(raiz->esq, valor);
    count += contarMenores(raiz->dir, valor);

    return count;
}

int main() {
    int opcao, valor;
    no *raiz = NULL;

    while (1) {
        printf("\n\nEscolha uma opcao:\n");
        printf("1 - Inserir valor\n");
        printf("9 - Contagem de elementos menores que um valor\n");
        printf("0 - Sair\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir_no(raiz, valor);
                break;
            }
            case 9: {
                printf("\nDigite o valor a ser comparado: ");
                scanf("%d", &valor);
                int count = contarMenores(raiz, valor);
                printf("\nA arvore possui %d elementos menores que %d.\n", count, valor);
                break;
            }
            case 0: {
                printf("\nEncerrando o programa...\n");
                exit(0);
            }
            default: {
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
            }
        }
    }

    return 0;
}
