/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Simulación de un estudiante
struct Estudiante {
    string nombre;
    bool presente;
    string plato_elegido;
};

// Función que determina si hoy es un día hábil
bool esDiaHabil() {
    // Para simplificar, asumimos que siempre es día hábil
    return true;
}

// Función que obtiene el menú del día
vector<string> obtenerMenuDelDia() {
    return {"Arroz con pollo", "Sopa de verduras", "Pasta con queso"};
}

// Función que simula la recolección de elecciones por parte de estudiantes
void registrarElecciones(vector<Estudiante>& estudiantes, const vector<string>& menu,
                         unordered_map<string, int>& contador_platos) {
    for (auto& est : estudiantes) {
        if (!est.presente) continue;

        // Aquí simulamos la elección de un plato (selección por índice)
        int eleccion = rand() % menu.size();
        est.plato_elegido = menu[eleccion];
        contador_platos[menu[eleccion]]++;
    }
}

int main() {
    // Paso 1: Cargar lista de estudiantes registrados
    vector<Estudiante> estudiantes = {
        {"Ana", true}, {"Luis", true}, {"Pedro", false}, {"Carla", true}
    };

    // Paso 2: Verificar si es día hábil
    if (!esDiaHabil()) {
        cout << "Hoy no es un día hábil. Fin del proceso." << endl;
        return 0;
    }

    // Paso 3: Obtener menú del día
    vector<string> menu = obtenerMenuDelDia();

    // Paso 4 y 5: Registrar elecciones por tipo de plato
    unordered_map<string, int> contador_platos;
    registrarElecciones(estudiantes, menu, contador_platos);

    // Paso 6: Mostrar resultados
    cout << "Cantidad de estudiantes por plato:" << endl;
    for (const auto& plato : menu) {
        cout << plato << ": " << contador_platos[plato] << " estudiante(s)" << endl;
    }

    return 0;
}


