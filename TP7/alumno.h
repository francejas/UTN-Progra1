#ifndef ALUMNO_H
#define ALUMNO_H

#define MAX_NOMBRE 100

typedef struct {
    int legajo;
    char nombreYapellido[MAX_NOMBRE];
    int edad;
    int anio;
} stAlumno;

// Declaraciones de funciones para manejo de alumnos
stAlumno cargaAlumno();


#endif
