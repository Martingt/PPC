#include <stdio.h>

int main() {
    int i;

    #pragma omp parallel
    {
        printf("Hola mundo\n");
        for(i = 0; i < 10; i++)
            printf("Iteracion: %d\n", i);
    }
    printf("Adios\n");

    return 0;
}