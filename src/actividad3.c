#include <stdio.h>
#include <omp.h>

int main() {
    int numeroDeHilos;
    printf("Ingrese el numero de hilos: ");
    scanf("%d", &numeroDeHilos);

    int numeroDeProcesadores = omp_get_num_procs();
    omp_set_num_threads(numeroDeHilos);
    printf("Esta computadora usa: %d procesador/es\n", numeroDeProcesadores);
    printf("Se desea usar: %d hilo(s)\n", omp_get_max_threads());
    printf("En este momento se esta(n) ejecutando %d hilo(s)\n", omp_get_num_threads());
    printf("Ingresando a la seccion paralela\n");

    #pragma omp parallel
    {
        int idHilo = omp_get_thread_num();
        printf("Soy el hilo %d, en este momento se estan ejecutando %d hilo(s)\n", idHilo, omp_get_num_threads());
    }

    printf("Saliendo de la seccion paralela\n");
    printf("En este momento se estan ejecutando %d hilo(s)\n", omp_get_num_threads());

    return 0;
}