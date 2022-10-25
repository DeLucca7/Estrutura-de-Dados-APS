#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int dataSize = 10000;
    FILE * DataArchive;
    DataArchive = fopen("data.txt", "r");
    int initialData[dataSize],
        sizeOfData = sizeof(initialData) / sizeof(initialData[0]),
        i;

    clock_t startTime;

    for (i = 0; i < dataSize; i++){
        fscanf(DataArchive, "%d,", &initialData[i] );
    }

    printf("Insertion Sort: \n\n");
    startTime = clock();
    insertionSort(initialData, sizeOfData, startTime);
    printf("-----------------------------------------------------\n");

    printf("Bubble Sort: \n\n");
    startTime = clock();
    bubbleSort(initialData, sizeOfData, startTime);
    printf("-----------------------------------------------------\n");

    printf("Selection Sort: \n\n");
    startTime = clock();
    selectionSort(initialData, sizeOfData, startTime);
    printf("-----------------------------------------------------\n");
}


//Função que calcula a diferência de tempo inicial e final
int calcTime(clock_t startTime)
{
    clock_t endTime;
    double timeDiff;

    endTime = clock();
    timeDiff = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Tempo de Execução = %f\n\n", timeDiff);
    return 0;
}

int bubbleSort(int initialData[], int sizeOfData, clock_t startTime)
{
 int i, aux, count;
 for (count = 1; count < sizeOfData; count++) {
   for (i = 0; i < sizeOfData - 1; i++) {
     if (initialData[i] > initialData[i + 1]) {
       aux = initialData[i];
       initialData[i] = initialData[i + 1];
       initialData[i + 1] = aux;
     }
   }
 }
 calcTime(startTime);
 return 0;
}

int insertionSort(int initialData[], int sizeOfData, clock_t startTime)
{
    int i, key, j;
    for (i = 1; i < sizeOfData; i++) {
        key = initialData[i];
        j = i - 1;
  
        while (j >= 0 && initialData[j] > key) {
            initialData[j + 1] = initialData[j];
            j = j - 1;
        }
        initialData[j + 1] = key;
    }
    calcTime(startTime);

    return 0;
}

swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int selectionSort(int initialData[], int sizeOfData, clock_t startTime)
{
    int i, j, idx;
 
    for (i = 0; i < sizeOfData-1; i++)
    {
        idx = i;
        for (j = i+1; j < sizeOfData; j++) {
          if (initialData[j] < initialData[idx]) {
            idx = j;
          }
        }
 
        if(idx != i) {
            swap(&initialData[idx], &initialData[i]);
        }
    }

    calcTime(startTime);

    return 0;
}
