#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h> 

/*
Função que calcula tempo de execução de cada algoritmo.
Recebe como parametro uma variavel do tipo clock_t armazenando o inicio da execução.
Retorna um printf com o tempo de execução
*/

int calcularTempoExecucao(clock_t inicioDoCronometro)
{
    clock_t fimDoCronometro;
    double tempoDeExecução;

    fimDoCronometro = clock();
    tempoDeExecução = ((double) (fimDoCronometro - inicioDoCronometro)) / CLOCKS_PER_SEC;
    printf("Tempo de Execução = %f\n\n", tempoDeExecução);
    return 0;
}

/*
Função que executa a ordenação BubbleSort
Recebe como parametros:
- um vetor de inteiros com os dados iniciais, 
- um inteiro com o numero de dados 
- um clock_t com o valor do inicio do cronometro
Após executar o algoritmo, calcula o tempo de execução do mesmo chamando a função calcularTempoExecucao()
*/

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
Função que executa a ordenação SelectionSort
Recebe como parametros:
- um vetor de inteiros com os dados iniciais, 
- um inteiro com o numero de dados 
- um clock_t com o valor do inicio do cronometro
Após executar o algoritmo, calcula o tempo de execução do mesmo chamando a função calcularTempoExecucao()
*/

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
    insertionSort(dadosIniciais, quantidadeDados);
    calcularTempoExecucao(inicioDoCronometro);
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
