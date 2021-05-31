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

#include <iostream>
#include <string.h>
using namespace std;

typedef char str30[30];
typedef char str100[100];

typedef struct
{
    int dia;
    int mes;
    int anio;
} tFecha;

typedef struct
{
    str30 nombre;
    tFecha fechaNac;
} tPersona;

//declaracion de funciones
float diferenciaFechas(int dia1, int mes1, int anio1, int dia2, int mes2, int anio2);

int main()
{

    int menores20 = 0;
    int entre21y30 = 0;
    int mayores30 = 0;
    float edad;
    float edadMayor = 0;
    float edadMenor = 0;
    bool esElPrimeroRegistro = true;
    char personaMayor[20];
    char personaMenor[20];
    tPersona persona;
    tFecha hoy;
    int dia, mes, anio;

    cout << "Ingrese el dia, mes y anio actuales" << endl;
    cin >> hoy.dia >> hoy.mes >> hoy.anio;

    char continuar = 'n';

    do
    {
        cout << "Ingresar nombre: " << endl;
        cin >> persona.nombre;
        cout << "Ingrese el dia, mes y anio separados" << endl;
        cin >> dia >> mes >> anio;

        edad = diferenciaFechas(hoy.dia, hoy.mes, hoy.anio, dia, mes, anio);

        if (edad > 30)
        {
            mayores30 = mayores30 + 1;
        }
        else
        {
            if (edad < 21)
            {
                menores20 = menores20 + 1;
            }
            else
            {
                entre21y30 = entre21y30 + 1;
            }
        }

        if (esElPrimeroRegistro)
        {
            strcpy(personaMayor, persona.nombre);
            strcpy(personaMenor, persona.nombre);
            edadMayor = edad;
            edadMenor = edad;
            esElPrimeroRegistro = false;
        }
        else
        {
            if (edadMayor < edad)
            {
                strcpy(personaMayor, persona.nombre);
            }
            if (edad < edadMenor)
            {
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

// funciones
float diferenciaFechas(int dia1, int mes1, int anio1, int dia2, int mes2, int anio2)
{
    float dif;

    dif = (((anio1 - anio2) * 12 + (mes1 - mes2)) * 30 + dia1 - dia2) / 360.0;
    return dif;
}
