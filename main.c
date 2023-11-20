// main.c
#include <stdio.h>
#include "registros_medicos.h"

void imprimirMenu() {
    printf("\n1. Agregar paciente\n");
    printf("2. Buscar paciente por RUT\n");
    printf("3. Mostrar todos los pacientes\n");
    printf("4. Eliminar paciente por RUT\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    const int maxRegistros = 100; 
    RegistroPaciente registros[maxRegistros];
    int numRegistros = 0;

    int opcion;

    do {
        printf("\n----------------------------------------\n");
        imprimirMenu();

        // Leer la opción del usuario
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Agregar paciente
                agregarRegistroPaciente(registros, &numRegistros);
                break;
            case 2:
                // Buscar paciente por RUT y nombre
                {
                    char buscarRUT[15];
                    char buscarNombre[50];
                    printf("Ingrese el RUT del paciente a buscar: ");
                    scanf("%s", buscarRUT);

                    buscarPacientePorRutNombre(registros, numRegistros, buscarRUT, buscarNombre);
                }
                break;
            case 3:
                // Mostrar todos los pacientes
                mostrarRegistrosPacientes(registros, numRegistros);
                break;
            case 4:
                // Eliminar paciente por RUT y nombre
                {
                    char eliminarRUT[15];
                    char eliminarNombre[50];
                    printf("Ingrese el RUT del paciente a eliminar: ");
                    scanf("%s", eliminarRUT);

                    eliminarRegistroPaciente(registros, &numRegistros, eliminarRUT, eliminarNombre);
                }
                break;
            case 5:
                // Salir del programa
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intentelo de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}
