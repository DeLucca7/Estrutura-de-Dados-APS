#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> // for atoi

int calcularTempoExecucao(clock_t inicioDoCronometro)
{
    clock_t fimDoCronometro;
    double tempoDeExecução;

    fimDoCronometro = clock();
    tempoDeExecução = ((double) (fimDoCronometro - inicioDoCronometro)) / CLOCKS_PER_SEC;
    printf("Tempo de Execução = %f\n\n", tempoDeExecução);
    return 0;
}

int bubbleSort(int dadosIniciais[], int quantidadeDados, clock_t inicioDoCronometro)
{
 int i, aux, contador;
 for (contador = 1; contador < quantidadeDados; contador++) {
   for (i = 0; i < quantidadeDados - 1; i++) {
     if (dadosIniciais[i] > dadosIniciais[i + 1]) {
       aux = dadosIniciais[i];
       dadosIniciais[i] = dadosIniciais[i + 1];
       dadosIniciais[i + 1] = aux;
     }
   }
 }
 calcularTempoExecucao(inicioDoCronometro);
 return 0;
}

int insertionSort(int dadosIniciais[], int quantidadeDados, clock_t inicioDoCronometro)
{
    int i, chave, j;
    for (i = 1; i < quantidadeDados; i++) {
        chave = dadosIniciais[i];
        j = i - 1;
  
        while (j >= 0 && dadosIniciais[j] > chave) {
            dadosIniciais[j + 1] = dadosIniciais[j];
            j = j - 1;
        }
        dadosIniciais[j + 1] = chave;
    }
    calcularTempoExecucao(inicioDoCronometro);

    return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int selectionSort(int dadosIniciais[], int quantidadeDados, clock_t inicioDoCronometro)
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

    calcularTempoExecucao(inicioDoCronometro);

    return 0;
}

int main()
{
    const int quantidadeDados = 10000;

    FILE * arquivoDeDados;

    arquivoDeDados = fopen("data.txt", "r");

    int dadosIniciais[quantidadeDados],
    i;

    clock_t inicioDoCronometro;

    // extraindo os dados do arquivo e passando para o vetor dadosIniciais
    for (i = 0; i < quantidadeDados; i++){
        fscanf(arquivoDeDados, "%d,", &dadosIniciais[i] );
    }

    printf("Insertion Sort: \n\n");
    inicioDoCronometro = clock();
    insertionSort(dadosIniciais, quantidadeDados, inicioDoCronometro);
    printf("-----------------------------------------------------\n");

    printf("Bubble Sort: \n\n");
    inicioDoCronometro = clock();
    bubbleSort(dadosIniciais, quantidadeDados, inicioDoCronometro);
    printf("-----------------------------------------------------\n");

    printf("Selection Sort: \n\n");
    inicioDoCronometro = clock();
    selectionSort(dadosIniciais, quantidadeDados, inicioDoCronometro);
    printf("-----------------------------------------------------\n");
}
