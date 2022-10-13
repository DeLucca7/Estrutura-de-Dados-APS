#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *Data;
    int data[5000], i;
    clock_t start, end;
    double cpu_time_used;

    Data = fopen("data.txt", "r");

    for (i = 0; i < 5000; i++){
        fscanf(Data, "%d,", &data[i] );
    }

    fclose(Data);

    int size = sizeof(data) / sizeof(data[0]);

    start = clock();
    insertionSort(data, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de Execução = %f\n", cpu_time_used);

    // bubbleSort(data, size);
    return 0;
}

void bubbleSort(int data[], int size)
{
 int i, aux, count, movements;
 for (count = 1; count < size; count++) {
   for (i = 0; i < size - 1; i++) {
     if (data[i] > data[i + 1]) {
       movements += 1;
       aux = data[i];
       data[i] = data[i + 1];
       data[i + 1] = aux;
     }
   }
 }
for (i = 0; i < size; i++) {
 printf("%4d\n", data[i]);
}
printf("\n");
printf("Movements: ");
printf("%i", movements);
printf("\n");
}

void insertionSort(int data[], int size)
{
    int i, key, j, movements;
    for (i = 1; i < size; i++) {
        key = data[i];
        j = i - 1;
  
        while (j >= 0 && data[j] > key) {
            movements += 1;
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }

    for (i = 0; i < size; i++) {
      printf("%4d\n", data[i]);
    }
    printf("\n");
    printf("Movements: ");
    printf("%i", movements);
    printf("\n");
}
