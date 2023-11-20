// registros_medicos.h
#ifndef REGISTROS_MEDICOS_H
#define REGISTROS_MEDICOS_H

// Definición de la estructura para representar la información del paciente
typedef struct {
    char rut[15];
    char nombre[50];
    char direccion[100];
    char email[50];
    char telefono[15];
} RegistroPaciente;

// Funciones
void agregarRegistroPaciente(RegistroPaciente *registros, int *numRegistros);
void buscarPacientePorRutNombre(RegistroPaciente *registros, int numRegistros, const char *rut, const char *nombre);
void mostrarRegistrosPacientes(RegistroPaciente *registros, int numRegistros);
void eliminarRegistroPaciente(RegistroPaciente *registros, int *numRegistros, const char *rut, const char *nombre);

#endif // REGISTROS_MEDICOS_H
