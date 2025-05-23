/**********************************************************************************************************
	*Pontificia Universidad Javeriana
	*Autor:Natalia Ramirez Romero 
	*Fecha: 22 de mayo 2025
	*Materia: Sistemas Operativos 
	*Topico: Uso de OMP OpenMP
	*Descripcion:* Este programa demuestra el uso de la librería OpenMP para la paralelización de un bucle 
	`for`. Se establece un número de hilos determinado por el usuario, y se ejecuta una operación paralela 
	sobre una variable local `a` y una compartida `b`. El objetivo es observar el comportamiento de 
	las variables privadas y compartidas dentro de una región paralela.
***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]){
    //Validar la entrada de argumentos de la consola 
    if(argc < 2){
        printf("Entrada por consola \n\t $./ejecutable NumHilos\n");
        exit(0);// Termina el programa si no hay suficientes argumentos
    }

    int hilos = atoi(argv[1]);  // Convierte el argumento a entero (número de hilos)
    int i;
    int a = 50;     // Variable base para el cálculo (esperamos que permanezca en 50)
    int b = 0;      // Variable que se actualizará en el bucle paralelo
    const int N = 1000;  // Número de iteraciones del ciclo
    int maxHilos = omp_get_max_threads();  // Número máximo de hilos disponibles
    omp_set_num_threads(hilos);  // Fijar el número de hilos a usar según el argumento

    printf("MaxHilos = %d \t Equipo de hilos impuesto = %d\n", maxHilos, hilos);

    // Bucle paralelo: se paraleliza el for y se indica que 'i' y 'a' serán privadas para cada hilo
    // La variable 'b' es compartida por defecto (lo cual es riesgoso sin manejo adecuado)
#pragma omp parallel for private(i, a)
    for(i = 0; i < N; i++){
        b = a + i;  // Operación que depende de 'a' e 'i'; b puede presentar condiciones de carrera
    }

    // Imprimir valores finales de las variables
    printf("El valor de a = %d \t el valor de b = %d (se espera que sea a = 50, b = 1049)\n", a, b);

    return 0;
}
    
/**********************************************************************************************************
* Conclusiones:
* 1. Paralelización con OpenMP:
*    El programa utiliza la directiva `#pragma omp parallel for` para dividir la ejecución del ciclo 
     entre varios hilos, mejorando el aprovechamiento de los núcleos del procesador.
*
* 2. Manejo de variables privadas y compartidas:
*    La variable `a` es privada en cada hilo, mientras que `b` es compartida entre todos, lo que puede 
     causar condiciones de carrera si no se maneja adecuadamente.
*
* 3. Condiciones de carrera:
*    Como varios hilos escriben sobre `b` sin sincronización, su valor final no está garantizado.
     Aunque se espera que termine en 1049, esto puede no ocurrir siempre.
*
* 4. Recomendación:
*    Para evitar resultados no deterministas, se recomienda utilizar directivas como `reduction`, `critical`
      o declarar `b` como privada según el objetivo deseado.
***********************************************************************************************************/
