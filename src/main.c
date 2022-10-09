#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[] = {-2, 45, 0, 11, -9};
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
 printf("%4d", data[i]);
}
printf("\n");
printf("Movements: ");
printf("%i", movements);
printf("\n");
}