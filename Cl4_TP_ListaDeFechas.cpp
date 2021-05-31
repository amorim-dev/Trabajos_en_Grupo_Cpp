/*Ejercicio con una lista de fechas

Procesar las edades de un conjunto de personas de las cuales nos informan su nombre y fecha de nacimiento.
Se debe mostrar por pantalla:
- el nombre de la persona mayor;
- el nombre de la persona menor;
- cuántas personas tienen hasta 20 años;
- cuántas personas tienen entre 21 y 30 años;
- cuántas personas tienen más de 30 años

Supongan que no hay dos personas que hayan nacido el mismo día.
*/

#include <string.h>

#include <iostream>

using namespace std;

typedef struct {
    int dia;
    int mes;
    int anio;
} tFecha;

typedef struct {
    char nombre[30];
    tFecha fechaNac;
} tPersona;

float diferenciaFechas(tFecha fecha1, tFecha fecha2);

int main() {
    int menores20 = 0, entre21y30 = 0, mayores30 = 0;
    float edad, edadMayor = 0, edadMenor = 0;
    char personaMayor[20], personaMenor[20];
    tPersona persona;
    bool esElPrimeroRegistro = true;
    tFecha hoy, fecha;

    cout << "Ingrese el dia, mes y anio actuales" << endl;
    cin >> hoy.dia >> hoy.mes >> hoy.anio;

    char continuar = 'n';
    do {
        cout << "Ingresar nombre: " << endl;
        cin >> persona.nombre;
        cout << "Ingrese el dia, mes y anio separados" << endl;
        cin >> fecha.dia >> fecha.mes >> fecha.anio;

        edad = diferenciaFechas(hoy, fecha);

        if (edad > 30) {
            mayores30++;
        } else if (edad < 21) {
            menores20++;
        } else {
            entre21y30++;
        }

        if (esElPrimeroRegistro) {
            strcpy(personaMayor, persona.nombre);
            strcpy(personaMenor, persona.nombre);
            edadMayor = edad;
            edadMenor = edad;
            esElPrimeroRegistro = false;
        } else {
            if (edadMayor < edad) {
                strcpy(personaMayor, persona.nombre);
            }
            if (edad < edadMenor) {
                strcpy(personaMenor, persona.nombre);
            }
        }
        cout << "quiere ingresar otra presona?(s o n): " << endl;
        cin >> continuar;
    } while (continuar != 'n');

    cout << "el nombre de la persona mayor: " << personaMayor << endl;
    cout << "el nombre de la persona menor: " << personaMenor << endl;
    cout << "cuántas personas tienen hasta 20 años: " << menores20 << endl;
    cout << "cuántas personas tienen entre 21 y 30 años: " << entre21y30 << endl;
    cout << "cuántas personas tienen más de 30 años: " << mayores30 << endl;
}

float diferenciaFechas(tFecha fecha1, tFecha fecha2) {
    float dif = (((fecha1.anio - fecha2.anio) * 12 + (fecha1.mes - fecha2.mes)) * 30 + fecha1.dia - fecha2.dia) / 360.0;
    return dif;
}
