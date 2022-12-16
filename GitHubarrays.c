// O objetivo deste trabalho  é  implementar  um programa que peça ao utilizador 20
// números inteiros e os guarde num vetor, para  posteriormente  providenciar forma
// de calcular algumas estatísticas ou fazer operações sobre esses valores.
// Os valores pedidos devem estar compreendidos entre -5 e 11.
// Deve ser feita a VALIDAÇÃO DE ENTRADA!

// Após terem sido pedidos os valores, deve  ser mostrado um menu ao utilizador que
// lhe permita calcular cada  uma  das  estatísticas referidas em baixo, exatamente
// pela  ordem  colocadas  neste  enunciado.  Depois de  se  escolher  uma opção, o
// resultado deve ser mostrado no ecrã, e o menu deve voltar a ser exibido.
// As funcionalidades mínimas a disponibilizar são as seguintes:

//   1 - Devolução dos valores em posições múltiplas de três do vetor;
//   2 - Cálculo do seno (sin) de todos os elementos no vetor;
//   3 - Cálculo da divisão de todos os elementos no vetor por 2;
//   4 - Identificação do valor mais próximo de 15;
//   5 - Construção de uma matriz 20 por 20, em que cada linha é composta pelo vetor
//       lido (primeira linha) e por permutações dos seus valores (outras linhas);
//   6 - Devolução do vetor ordenado por ordem decrescente.

// Uma  versão  mais elaborada  do projeto  deve exibir adicionalmente as seguintes
// características e funcionalidades:

//   1 - Leitura de um novo vetor, cálculo  e  devolução  do  produto  interno com o
//       vetor inicial;
//   2 - Cálculo do mínimo múltiplo comum de cada dois números seguidos do vetor;
//   3 - Leitura  de  um novo vetor  1x20,  cálculo  e  devolução  da  matriz 20x20
//       resultante do produto do vetor inicial com o novo vetor gerado;
//   4 - Cálculo e apresentação da matriz transposta referida no ponto anterior;
//   5 - O programa apresenta  adicionalmente  uma  página de ajuda, acessível como
//       sendo a entrada 7 no menu.
//   6 - O programa  mostra  alguma  ajuda  quando é executado a partir da linha de
//       comandos com a flag --help.


// O programa deve ser implementado em C, e deve ser entregue no formato de um único
// ficheiro, com o nome arrays.c, que deve ser submetido no Moodle.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>

void help()
{
    printf("\n \n \n Menu de ajuda: \n");
    printf("Este menu pode ser utilizado para esclarecer algumas duvidas do utilizador.\n");
    printf("\n");
    printf("O objetivo deste programa e pedir ao utilizador 20\n");
    printf("numeros inteiros que seram guardados num vetor. Posteriormente seram utilizados para \n");
    printf("calcular algumas estatisticas ou fazer operacoes sobre esses valores.\n");
    printf("\n");
    printf("Para utilizar este programa deve de introduzida uma matriz de 1 dimensão com \n");
    printf("vinte elementos com um intervalo de -5 a 11");
    printf("\n");
    printf("Por exemplo:\n");
    printf("Introduza um numero: 5.\n");
    printf("Introduza um numero: 6.\n");
    printf("\n");
    printf("Ao introduzir a matriz ira ser impresso no seu ecra um menu com varias funcionalidade\n");
    printf("Para utilizar uma dessas funcionalidade apenas tem de introduzir o numero da funcionalidade\n");
    printf("que pretende utilizar.\n");
    printf("\n");
    printf("Por exemplo:\n");
    printf("6 - Devolucao do vetor ordenado por ordem decrescente.\n");
    printf("Introduza um numero: 6.\n");
    printf("De seguida o programa ira realizar a funcionalidade que foi pedida pelo utilizador.\n");
    printf("Por exemplo:\n");
    printf("4\n5\n6\n");
    printf("5\n7\n8\n");
    printf("Se pretender utilizar outra funcionalidade apenas tem de introduzir o numero da funcionalidade\n");
    printf("que pretende utilizar.\n");
    printf("\n");
    printf("Por exemplo:\n");
    printf("4 - Identificação do valor mais proximo de 15.\n");
    printf("Introza um numero: 4.\n");
    printf("\n");
    printf("Se nao pretender utilizar mais o programa apenas pressiona 12.\n");
    printf("O programa ira terminar automaticamente\n");
    printf("\n");
    printf("Por exemplo:\n");
    printf("12 - Sair do programa.\n");
    printf("Introduza um numero: 12\n");
    printf("\n");
    printf("Espero que tenha ajudado. Se pretender pedir ajuda outra vez pressione no menu principal 7.");
}

void multiplyArrays( int array2[], int n)
{
    int i;
    int array[20];
    int arrayT[20];
    for (i = 0; i < 20; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }
    for (i = 0; i < 20; i++)
    {
        arrayT[i] = array[i] * array2[i];
    }
    for (i = 0; i < 20; i++)
    {
        printf("%3d ", arrayT[i]);
    }
    printf("\n");
}

void mdc(int array[], int n)
{
    int i;
    int j;
    int k;
    for (i=0; i < n - 1; i++)
    {
        k = array[i] * array[i+1];

        printf("O minimo multiplo comum entre Array[%d] e Array[%d] = %d. \n", array[i], array[i+1], k);
    
    }
}

int novamatriz(int A[], int n, int B[][20])
{
    int i;
    int j;
    int array2[20];
    int array3[20][20];

    for (i = 0; i < 20; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &array2[i]);
    }
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            array3[i][j] = A[i] * array2[j];
        }
    }
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            printf("%4d ", array3[i][j]);
        }
        printf("\n");
    }
        for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            B[i][j]  = array3[i][j];
        }
    }
}

void transpor(int array[][20], int n)
{
    int i, j, Arrayt[20][20];

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
         Arrayt[i][j] = array[j][i];
        }
    }
        
        for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
        printf("%d ", Arrayt[i][j]);
        }
        printf("\n");
    }
}

int sort(int array[], int n)
{
    int i;
    int j;
    int temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("Array[%d] = %d. \n", i, array[i]);
    }
}

int matriz(int array[], int n)
{
    int i;
    int j;
    int matriz[20][20];
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            matriz[i][j] = array[j];
        }
    }
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int near15(int array[], int n)
{
    int i;
    int near15 = 0;
    for (i = 0; i < n; i++)
    {
        if (abs(array[i] - 15) < abs(near15 - 15))
        {
            near15 = array[i];
        }
    }
    printf("O numero mais proximo de 15 e %d.\n", near15);
}

int div2(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Array[%d] = %d.\n ", i, array[i]/2);
    }
}

int seno(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Array [%d] = %f.\n", i, sin(array[i]));
    }
}

int mult3(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (array[i] != 0)
        {
            if (array[i] % 3 == 0)
            {
                printf("Array[%d] = %d. \n", i, array[i]);
            }
        }
    }
}

void * scan(int A[], int n)
{
    int i, k=0;
    do{
        printf("Introduza um numero entre -5 e 11: ");
        scanf("%d", &A[k]);
        if (A[k] >= -5 && A[k] <= 11) 
        {
            k++;
        }
        else
        {
           printf(" Numero invalido. \n "); 
        }
    }while(k<20);

        for (i = 0; i < 20; i++)
        {
        printf("%3d ", A[i]);
        }
        printf("\n");
}

int main()
{
    int opcao, i=0, j;
    int array[20];
    int array3[20][20];
    scan(array, 20);
    while(i == 0)
    {
        printf("\n");
        printf("Menu 1");
        printf("\n");
        printf("1 - Devolucao dos valores em posicoes multiplas de tres do vetor");
        printf("\n");
        printf("2 - Calculo do seno (sin) de todos os elementos no vetor");
        printf("\n");
        printf("3 - Calculo da divisão de todos os elementos no vetor por 2");
        printf("\n");
        printf("4 - Identificação do valor mais proximo de 15");
        printf("\n");
        printf("5 - Construcao de uma matriz 20 por 20, em que cada linha e composta pelo vetor lido (primeira linha) e por permutacoes dos seus valores (outras linhas)");
        printf("\n");
        printf("6 - Devolucao do vetor ordenado por ordem decrescente");
        printf("\n");
        printf("7 - Pedir ajuda");
        printf("\n");
        printf("\n");
        printf("Menu 2");
        printf("\n");
        printf("8 - Leitura de um novo vetor, calculo  e  devolucao  do  produto  interno como vetor inicial");
        printf("\n");
        printf("9 - Calculo do minimo multiplo comum de cada dois numeros seguidos do vetor");
        printf("\n");
        printf("10 - Leitura  de  um novo vetor  1x20,  calculo  e  devolucao  da  matriz 20x20 resultante do produto do vetor inicial com o novo vetor gerado");
        printf("\n");
        printf("11 - Calculo e apresentacao da matriz transposta referida no ponto anterior");
        printf("\n");
        printf("12 - Sair do programa");
        printf("\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);

 
        switch (opcao)
        {
        case 1:
        mult3(array, 20);
        break;
        case 2:
        seno(array, 20);
        break;
        case 3:
        div2(array, 20);
        break;
        case 4:
        near15(array, 20);
        break;
        case 5:
        matriz(array, 20);
        break;
        case 6:
        sort(array, 20);
        break;
        case 7:
        help();
        break;
        case 8:
        multiplyArrays(array, 20);
        break;
        case 9:
        mdc(array, 20);
        break;
        case 10:
        novamatriz(array, 20, array3);
        break;
        case 11:
        transpor(array3, 20);
        break;
        case 12:
        i = 1;
        break;
        }
    }
return 0;
}
