// Crear un programa en OpenMP que informe
// - la cantidad de hilos que se pidió al ejecutar el programa (lo solicitamos desde la línea de comandos),
// - la cantidad de procesadores disponibles y que muestre el modelo fork/join mostrando en pantalla que está ejecutando un solo hilo,
// - a continuación, que se ingresa a la región paralela mostrando que se abre la ejecución de n hilos
// - y por último se cierra la región paralela y sigue con 1 hilo de ejecución para finalizar.
// Escribir en un archivo de texto el programa, cuáles son las directivas openMP que se utiliza en cada paso con sus parámetros o cláusulas. Subirlo al Campus con su apellido-Tarea1. Utilizar las funciones que se muestran a continuación.
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