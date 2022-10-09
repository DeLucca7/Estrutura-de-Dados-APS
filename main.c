#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *Data;
    Data = fopen("data.txt", "r");

    int data[5000];
    int i;

    for (i = 0; i < 5000; i++){
        fscanf(Data, "%d,", &data[i] );
    }

    fclose(Data);

    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);
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