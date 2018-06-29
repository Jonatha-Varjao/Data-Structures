#include <stdio.h>
#include "Hanoi.h"

void main(void) {
    int qtd_Discos;
    stack A,B,C;
    // Inicialização das torres A B C 
    createStack(&A, 1);
    createStack(&B, 2);
    createStack(&C, 3);
    // Quantidade de Discos recebida pelo usuario
    printf("Quantos Discos? 3, 5 ou 7? \n");
    scanf("%d", &qtd_Discos);
    // Preenche a Pilha A de acordo a qtd de Discos 3 5 ou 7 
    preenchePilha(&A, qtd_Discos);
    // Torre de Hanoi Recursiva usando 3 torres
    towerHanoi(qtd_Discos, &A, &C, &B);
    // Printando a Torre com o Final do Jogo
    printStack(&C);


}