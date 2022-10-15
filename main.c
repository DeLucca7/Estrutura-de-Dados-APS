#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int v[10] = {270,324,45,42,55,123,339,112,10, 99};
    int size = sizeof(v) / sizeof(v[0]);
    clock_t start, end;

    printf("Insertion Sort: \n\n");
    start = clock();
    insertionSort(v, size, start);
    printf("-----------------------------------------------------\n");

    printf("Bubble Sort: \n\n");
    start = clock();
    bubbleSort(v, size, start);
    printf("-----------------------------------------------------\n");

    printf("Selection Sort: \n\n");
    start = clock();
    selectionSort(v, size, start);
    printf("-----------------------------------------------------\n");
}

void calcTime(clock_t start)
{
    clock_t end;
    double cpu_time_used;

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de Execução = %f\n\n", cpu_time_used);
}

void bubbleSort(int v[], int size, clock_t start)
{
 int i, aux, count;
 for (count = 1; count < size; count++) {
   for (i = 0; i < size - 1; i++) {
     if (v[i] > v[i + 1]) {
       aux = v[i];
       v[i] = v[i + 1];
       v[i + 1] = aux;
     }
   }
 }
 calcTime(start);
 printArray(v, size);
}

void insertionSort(int v[], int size, clock_t start)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = v[i];
        j = i - 1;
  
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    calcTime(start);
    printArray(v, size);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int v[], int size, clock_t start)
{
    int i, j, idx;
 
    for (i = 0; i < size-1; i++)
    {
        idx = i;
        for (j = i+1; j < size; j++) {
          if (v[j] < v[idx]) {
            idx = j;
          }
        }
 
        if(idx != i) {
            swap(&v[idx], &v[i]);
        }
    }

    calcTime(start);
    printArray(v, size);
}

void printArray(int v[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
      printf("%4d\n\n", v[i]);
    }
}
