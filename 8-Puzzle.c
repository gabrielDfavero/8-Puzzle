#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMat(int m[3][3]){
    printf("\nEstado atual:\n");
    for(int i=0; i<3; i++){
            if(i>0){printf("\n");}
            printf("[");
        for(int j=0; j<3; j++){
            printf("%d", m[i][j]);
            if(j<2){ printf(", ");}
        }
        printf("]");
    }
}

int checkDone(int m[3][3]){
    int matrizFinal[3][3] = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 0}};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(m[i][j] != matrizFinal[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

void encontraVazio(int m[3][3], int* coluna, int* linha){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(m[i][j] == 0){
                *coluna = j;
                *linha = i;
            }
        }
    }
    return;
}

void funcSucessora(int m[3][3], char choice){
    int coluna;
    int linha;
    encontraVazio(m, &coluna, &linha);
    switch(choice){
        case 'w':
        case 'W'://pra cima!
            if(linha>0){
                m[linha][coluna] = m[linha - 1][coluna];
                m[linha - 1][coluna] = 0;
            }
            break;

        case 'a':
        case 'A':
            if(coluna>0){
                m[linha][coluna] = m[linha][coluna-1];
                m[linha][coluna - 1] = 0;
            }
            break;

        case 's':
        case 'S':
            if(linha<2){
                m[linha][coluna] = m[linha + 1][coluna];
                m[linha+1][coluna] = 0;
            }
            break;

        case 'd':
        case 'D':
            if(coluna<2){
                m[linha][coluna] = m[linha][coluna + 1];
                m[linha][coluna + 1] = 0;
            }
            break;

        default:
            printf("Comando Inválido!\n");

    }
}

int nRandom(){
    int numero;
    numero = rand() % 4 + 1;
    if(numero==1){return (int)'w';}
    if(numero==2){return (int)'a';}
    if(numero==3){return (int)'s';}
    if(numero==4){return (int)'d';}
}


void randomizeMatriz(int matriz[3][3]) {
    int numero;
    for(int i=0;i<100;i++){
        numero = nRandom();
        funcSucessora(matriz, (char)numero);
    }
}

int main(){
    srand(time(NULL));
    printf("Escolha seu Movimento: \n\tw - para cima \n\ta - para esquerda\n\td - para direita\n\ts - para baixo\n\n");
    char choice;
    int matriz[3][3]= {{5, 4, 2},
                       {1, 0, 3},
                       {7, 8, 6}};;
    randomizeMatriz(matriz);
    printMat(matriz);

    while(!checkDone(matriz)){
        printf("\n\n");
        scanf(" %c", &choice);
        funcSucessora(matriz, choice);
        printMat(matriz);
    }
    printf("\n\n\tCompleto!");
}
