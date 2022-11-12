#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> 

/*
Função que calcula tempo de execução de cada algoritmo.
Recebe como parametro uma variavel do tipo clock_t armazenando o inicio da execução.
Retorna um printf com o tempo de execução
*/

void calcularTempoExecucao(clock_t inicioDoCronometro)
{
    clock_t fimDoCronometro;
    double tempoDeExecução;

    fimDoCronometro = clock();
    tempoDeExecução = ((double) (fimDoCronometro - inicioDoCronometro)) / CLOCKS_PER_SEC;
    printf("Tempo de Execução = %f\n\n", tempoDeExecução);
    return;
}

/*
Função de swap utilizada nas execuções de SelectionSort
Recebe como parametros dois ponteiros. (xp e yp)
*/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*
Função que executa a ordenação BubbleSort utilizando recursividade
Recebe como parametros:
- um vetor de inteiros com os dados iniciais, 
- um inteiro com o numero de dados 
*/

void bubbleSort(int dadosIniciais[], int quantidadeDados)
{
    if (quantidadeDados == 1)
        return;
 
    int contador = 0;

    for (int i=0; i<quantidadeDados-1; i++)
        if (dadosIniciais[i] > dadosIniciais[i+1]){
            swap(&dadosIniciais[i], &dadosIniciais[i+1]);
            contador++;
        }
 
      if (contador==0)
           return;
 
    bubbleSort(dadosIniciais, quantidadeDados-1);
}
/*
Função que executa a ordenação InsertionSort utilizando recursividade
Recebe como parametros:
- um vetor de inteiros com os dados iniciais, 
- um inteiro com o numero de dados 
*/

void insertionSort(int dadosIniciais[], int quantidadeDados)
{
    if (quantidadeDados <= 1)
        return;
 
    insertionSort(dadosIniciais, quantidadeDados - 1);
 
    int ultimoElemento = dadosIniciais[quantidadeDados - 1];
    int j = quantidadeDados - 2;
 
    while (j >= 0 && dadosIniciais[j] > ultimoElemento) {
        dadosIniciais[j + 1] = dadosIniciais[j];
        j--;
    }
    dadosIniciais[j + 1] = ultimoElemento;
}

/*
Função que executa a ordenação SelectionSort
Recebe como parametros:
- um vetor de inteiros com os dados iniciais, 
- um inteiro com o numero de dados 
*/

void selectionSort(int dadosIniciais[], int quantidadeDados)
{
    int i, j, idx;
 
    for (i = 0; i < quantidadeDados-1; i++)
    {
        idx = i;
        for (j = i+1; j < quantidadeDados; j++) {
          if (dadosIniciais[j] < dadosIniciais[idx]) {
            idx = j;
          }
        }
 
        if(idx != i) {
            swap(&dadosIniciais[idx], &dadosIniciais[i]);
        }
    }

    return;
}

/*
Função que inicia os vetores
Recebe como parametros:
- um inteiro com o numero de dados,
- um vetor de inteiros
*/
void iniciarVetor(int quantidadeDados, int dadosIniciais[])
{
  FILE * arquivoDeDados;

  int i;

  arquivoDeDados = fopen("data.txt", "r");

  // extraindo os dados do arquivo e passando para o vetor dadosIniciais
  for (i = 0; i < quantidadeDados; i++){
      fscanf(arquivoDeDados, "%d,", &dadosIniciais[i] );
  }

  return;
}

int main()
{
    const int quantidadeDados = 10000;

    int dadosIniciaisBubbleSort[quantidadeDados],
    dadosIniciaisSelectionSort[quantidadeDados],
    dadosIniciaisInsertionSort[quantidadeDados];

    clock_t inicioDoCronometro;

    printf("Bubble Sort: \n\n");
    iniciarVetor(quantidadeDados, dadosIniciaisBubbleSort);
    inicioDoCronometro = clock();
    bubbleSort(dadosIniciaisBubbleSort, quantidadeDados);
    calcularTempoExecucao(inicioDoCronometro);
    printf("-----------------------------------------------------\n");

    printf("Insertion Sort: \n\n");
    iniciarVetor(quantidadeDados, dadosIniciaisInsertionSort);
    inicioDoCronometro = clock();
    insertionSort(dadosIniciaisInsertionSort, quantidadeDados);
    calcularTempoExecucao(inicioDoCronometro);
    printf("-----------------------------------------------------\n");

    printf("Selection Sort: \n\n");
    iniciarVetor(quantidadeDados, dadosIniciaisSelectionSort);
    inicioDoCronometro = clock();
    selectionSort(dadosIniciaisSelectionSort, quantidadeDados);
    calcularTempoExecucao(inicioDoCronometro);
    printf("-----------------------------------------------------\n");
}
