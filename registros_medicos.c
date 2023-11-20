// registros_medicos.c
#include <stdio.h>
#include "registros_medicos.h"

// Función para comparar dos cadenas de caracteres manualmente
int compararCadenas(const char *cadena1, const char *cadena2) {
    while (*cadena1 && *cadena2 && *cadena1 == *cadena2) {
        cadena1++;
        cadena2++;
    }

    return (*cadena1 - *cadena2);
}

// Función para agregar un paciente al sistema
void agregarRegistroPaciente(RegistroPaciente *registros, int *numRegistros) {
    printf("Ingrese el RUT del paciente: ");
    scanf("%s", registros[*numRegistros].rut);

    printf("Ingrese el nombre del paciente: ");
    scanf("%s", registros[*numRegistros].nombre);

    printf("Ingrese la direccion del paciente: ");
    scanf("%s", registros[*numRegistros].direccion);

    printf("Ingrese el correo electronico del paciente: ");
    scanf("%s", registros[*numRegistros].email);

    printf("Ingrese el numero de telefono del paciente: ");
    scanf("%s", registros[*numRegistros].telefono);

    (*numRegistros)++;
}

// Función para buscar un paciente por su RUT y nombre
void buscarPacientePorRutNombre(RegistroPaciente *registros, int numRegistros, const char *rut, const char *nombre) {
    for (int i = 0; i < numRegistros; i++) {
        if (compararCadenas(registros[i].rut, rut) == 0) {
            printf("Paciente encontrado:\n");
            printf("RUT: %s\nNombre: %s\nDireccion: %s\nCorreo electronico: %s\nTelefono: %s\n",
                   registros[i].rut, registros[i].nombre,
                   registros[i].direccion, registros[i].email, registros[i].telefono);
            return; // Termina la función después de encontrar al paciente
        }
    }
    printf("Paciente no encontrado.\n");
}

// Función para mostrar todos los registros de pacientes
void mostrarRegistrosPacientes(RegistroPaciente *registros, int numRegistros) {
    printf("\nLista de pacientes:\n");
    for (int i = 0; i < numRegistros; i++) {
        printf("RUT: %s | Nombre: %s | Direccion: %s | Correo electronico: %s | Telefono: %s\n",
               registros[i].rut, registros[i].nombre,
               registros[i].direccion, registros[i].email, registros[i].telefono);
    }
}

// Función para eliminar un paciente por su RUT y nombre
void eliminarRegistroPaciente(RegistroPaciente *registros, int *numRegistros, const char *rut, const char *nombre) {
    int encontrado = 0;

    // Buscar el índice del paciente con el RUT y nombre dados
    for (int i = 0; i < *numRegistros; i++) {
        if (compararCadenas(registros[i].rut, rut) == 0) {
            encontrado = 1;
            // Mover todos los registros siguientes hacia atrás para llenar el espacio
            for (int j = i; j < *numRegistros - 1; j++) {
                registros[j] = registros[j + 1];
            }
            (*numRegistros)--;
            break; // Termina el bucle después de encontrar al paciente
        }
    }

    if (encontrado) {
        printf("Paciente con RUT %s\n", rut);
    } else {
        printf("Paciente con RUT %s\n", rut);
    }
}
