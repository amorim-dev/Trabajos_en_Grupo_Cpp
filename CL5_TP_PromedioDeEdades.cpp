/*Queremos conocer el promedio de edades de un conjunto de personas,
para lo cual nos informan la edad de cada una de ellas mediante una lista que finaliza en 0.
Además se debe calcular y mostrar cuántas personas tienen una edad mayor al promedio
y cuántas personas tienen una edad menor al promedio.
*/

#include <iostream>
using namespace std;

const int MAX_CANTIDAD_PERSONAS = 100;

struct tPersona {
    string name;
    int edad;
};

typedef tPersona tVectorPersona[MAX_CANTIDAD_PERSONAS];

//Declaracion de funciones
int pedirDatosPersona(tVectorPersona vectorDatosPersonas);
float calculoPromedio(tVectorPersona vectorDatosPersona, int cantidadDePersonas);
int calculoMayores(tVectorPersona todasLasPersonas, int cantidadDePersonas, float promedio, tVectorPersona personasMayores);

int main(int argc, char const *argv[]) {
    cout << "El programa calcula el promedio de Edades e ";
    cout << "informa cuantas son mayores y cuantas menores que el promedio" << endl;
    cout << endl;

    tVectorPersona vectorEdades;
    tVectorPersona mayoresPersonas;
    int cantidadEdades = MAX_CANTIDAD_PERSONAS;

    cantidadEdades = pedirDatosPersona(vectorEdades);

    if (cantidadEdades != 0) {
        float promedio = calculoPromedio(vectorEdades, cantidadEdades);

        int cantidadMayores = calculoMayores(vectorEdades, cantidadEdades, promedio, mayoresPersonas);
        int cantidadMenores = cantidadEdades - cantidadMayores;

        cout << "El promedio es: " << promedio << endl;
        cout << "Cantidad de personas mayores: " << cantidadMayores << endl;
        cout << "Cantidad de personas menores: " << cantidadMenores << endl;
    }

    return 0;
}

//funciones
int pedirDatosPersona(tVectorPersona vectorDatosPersonas) {
    int cantidadDePersonas = 0;
    int edad;

    while (cantidadDePersonas < MAX_CANTIDAD_PERSONAS) {
        cout << "Ingresar edad (fin = 0)" << endl;
        cin >> edad;
        if (edad == 0)
            break;

        vectorDatosPersonas[cantidadDePersonas].edad = edad;

        cout << "Ingresar nombre" << endl;
        cin >> vectorDatosPersonas[cantidadDePersonas].name;
        cantidadDePersonas++;
    }
    return cantidadDePersonas;
}

float calculoPromedio(tVectorPersona vectorDatosPersona, int cantidadDePersonas) {
    int suma = 0;
    for (int i = 0; i < cantidadDePersonas; i++)
        suma = suma + vectorDatosPersona[i].edad;
    return suma / (float)cantidadDePersonas;
}

int calculoMayores(tVectorPersona todasLasPersonas, int cantidadDePersonas, float promedio, tVectorPersona personasMayores) {
    int cantidadMayores = 0;
    for (int i = 0; i < cantidadDePersonas; i++) {
        if (todasLasPersonas[i].edad >= promedio) {
            personasMayores[cantidadMayores] = todasLasPersonas[i];
            cantidadMayores++;
        }
    }
    return cantidadMayores;
}
