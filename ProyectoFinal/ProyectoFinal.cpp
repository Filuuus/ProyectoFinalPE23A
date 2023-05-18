#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> // Para la función std::system()

void limpiarPantalla() {
    #ifdef _WIN32
        std::system("cls"); // Para Windows
    #else
        std::system("clear"); // Para Linux y macOS
    #endif
}

using namespace std;

// Definición de estructuras
struct Alumno {
    string nombre;
    int num_cuenta;
    string carrera;
};

struct Materia {
    string nombre;
    int clave;
    string maestro;
};

struct Calificacion {
    int clave_materia;
    int num_cuenta_alumno;
    float calificacion;
};


void registrar_alumno(Alumno alumnos[], int &num_alumnos) {
    cout << "Registro de alumno\n";
    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin, alumnos[num_alumnos].nombre);
    
    bool validNumCuenta = false;
    while (!validNumCuenta) {
        cout << "Ingrese el número de cuenta del alumno: ";
        if (cin >> alumnos[num_alumnos].num_cuenta) {
            validNumCuenta = true;
        } else {
            cout << "Entrada inválida. Por favor, ingrese un número de cuenta válido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    cout << "Ingrese la carrera del alumno: ";
    cin.ignore();
    getline(cin, alumnos[num_alumnos].carrera);
    num_alumnos++;
}


void registrar_materia(Materia materias[], int &num_materias) {
    cout << "Registro de materia\n";
    cout << "Ingrese el nombre de la materia: ";
    cin.ignore();
    getline(cin, materias[num_materias].nombre);

    bool validClave = false;
    while (!validClave) {
        cout << "Ingrese la clave de la materia: ";
        if (cin >> materias[num_materias].clave) {
            validClave = true;
        } else {
            cout << "Entrada inválida. Por favor, ingrese una clave válida.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Ingrese el nombre del maestro: ";
    cin.ignore();
    getline(cin, materias[num_materias].maestro);
    num_materias++;
}

void registrar_calificacion(Calificacion calificaciones[], int &num_calificaciones, Materia materias[], int num_materias, Alumno alumnos[], int num_alumnos) {
    int clave_materia, num_cuenta_alumno;
    bool materia_encontrada = false, alumno_encontrado = false;
    float calificacion;

    cout << "Registro de calificación\n";
    cout << "Ingrese la clave de la materia: ";
    while (!(cin >> clave_materia)) {
        cout << "Entrada inválida. Por favor, ingrese un número entero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave_materia) {
            materia_encontrada = true;
            break;
        }
    }

    if (!materia_encontrada) {
        cout << "Materia no encontrada.\n";
        return;
    }

    cout << "Ingrese el número de cuenta del alumno: ";
    while (!(cin >> num_cuenta_alumno)) {
        cout << "Entrada inválida. Por favor, ingrese un número entero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta_alumno) {
            alumno_encontrado = true;
            break;
        }
    }

    if (!alumno_encontrado) {
        cout << "Alumno no encontrado.\n";
        return;
    }

    cout << "Ingrese la calificación: ";
    while (!(cin >> calificacion)) {
        cout << "Entrada inválida. Por favor, ingrese un número válido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    calificaciones[num_calificaciones].clave_materia = clave_materia;
    calificaciones[num_calificaciones].num_cuenta_alumno = num_cuenta_alumno;
    calificaciones[num_calificaciones].calificacion = calificacion;
    num_calificaciones++;
}

// Funciones para editar datos
void editar_alumno(Alumno alumnos[], int num_alumnos) {
    int num_cuenta;
    cout << "Edición de alumno\n";
    cout << "Ingrese el número de cuenta del alumno a editar: ";
    cin >> num_cuenta;

    int indice = -1;
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "Alumno no encontrado.\n";
        return;
    }

    cout << "Ingrese el nuevo nombre del alumno: ";
    cin.ignore();
    getline(cin, alumnos[indice].nombre);
    cout << "Ingrese la nueva carrera del alumno: ";
    cin.ignore();
    getline(cin, alumnos[indice].carrera);

    cout << "Alumno actualizado con éxito.\n";
}

void editar_materia(Materia materias[], int num_materias) {
    int clave;
    cout << "Edición de materia\n";
    cout << "Ingrese la clave de la materia a editar: ";
    cin >> clave;

    int indice = -1;
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "Materia no encontrada.\n";
        return;
    }

    cout << "Ingrese el nuevo nombre de la materia: ";
    cin.ignore();
    getline(cin, materias[indice].nombre);
    cout << "Ingrese el nuevo nombre del maestro: ";
    cin.ignore();
    getline(cin, materias[indice].maestro);

    cout << "Materia actualizada con éxito.\n";
}

void editar_calificacion(Calificacion calificaciones[], int num_calificaciones) {
    int indice = -1;
    int clave_materia, num_cuenta_alumno;
    cout << "Edición de calificación\n";
    cout << "Ingrese la clave de la materia: ";
    cin >> clave_materia;
    cout << "Ingrese el número de cuenta del alumno: ";
    cin >> num_cuenta_alumno;

    for (int i = 0; i < num_calificaciones; i++) {
        if (calificaciones[i].clave_materia == clave_materia && calificaciones[i].num_cuenta_alumno == num_cuenta_alumno) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "Calificación no encontrada.\n";
        return;
    }

    float nueva_calificacion;
    cout << "Ingrese la nueva calificación: ";
    cin >> nueva_calificacion;
    calificaciones[indice].calificacion = nueva_calificacion;

    cout << "Calificación actualizada con éxito.\n";
}

// Funciones para registro, edición y eliminación de datos (continuación)
void eliminar_alumno(Alumno alumnos[], int& num_alumnos) {
    int num_cuenta;
    bool encontrado = false;
    cout << "Eliminación de datos de alumno\n";
    cout << "Ingrese el número de cuenta del alumno a eliminar: ";
    cin >> num_cuenta;
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta) {
            encontrado = true;
            for (int j = i; j < num_alumnos - 1; j++) {
                alumnos[j] = alumnos[j + 1];
            }
            num_alumnos--;
            break;
        }
    }
    if (encontrado) {
        cout << "Alumno eliminado correctamente.\n";
    } else {
        cout << "Alumno no encontrado.\n";
    }
}

void eliminar_materia(Materia materias[], int& num_materias) {
    int clave;
    bool encontrado = false;
    cout << "Eliminación de datos de materia\n";
    cout << "Ingrese la clave de la materia a eliminar: ";
    cin >> clave;
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave) {
            encontrado = true;
            for (int j = i; j < num_materias - 1; j++) {
                materias[j] = materias[j + 1];
            }
            num_materias--;
            break;
        }
    }
    if (encontrado) {
        cout << "Materia eliminada correctamente.\n";
    } else {
        cout << "Materia no encontrada.\n";
    }
}

// Funciones para registro, edición y eliminación de datos (continuación)
void eliminar_calificacion(Calificacion calificaciones[], int& num_calificaciones, Materia materias[], int num_materias, Alumno alumnos[], int num_alumnos) {
    int clave_materia, num_cuenta_alumno;
    bool materia_encontrada = false, alumno_encontrado = false, encontrado = false;
    cout << "Eliminación de calificación\n";
    cout << "Ingrese la clave de la materia: ";
    cin >> clave_materia;
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave_materia) {
            materia_encontrada = true;
            break;
        }
    }
    if (!materia_encontrada) {
        cout << "Materia no encontrada.\n";
        return;
    }
    cout << "Ingrese el número de cuenta del alumno: ";
    cin >> num_cuenta_alumno;
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta_alumno) {
            alumno_encontrado = true;
            break;
        }
    }
    if (!alumno_encontrado) {
        cout << "Alumno no encontrado.\n";
        return;
    }
    for (int i = 0; i < num_calificaciones; i++) {
        if (calificaciones[i].clave_materia == clave_materia && calificaciones[i].num_cuenta_alumno == num_cuenta_alumno) {
            encontrado = true;
            for (int j = i; j < num_calificaciones - 1; j++) {
                calificaciones[j] = calificaciones[j + 1];
            }
            num_calificaciones--;
            break;
        }
    }
    if (encontrado) {
        cout << "Calificación eliminada correctamente.\n";
    } else {
        cout << "Calificación no encontrada.\n";
    }
}

// Funciones para cálculo de promedio y evaluación de calificaciones
float calcular_promedio(Calificacion calificaciones[], int num_calificaciones, int num_cuenta_alumno) {
    float sumatoria = 0;
    int num_calificaciones_alumno = 0;
    for (int i = 0; i < num_calificaciones; i++) {
        if (calificaciones[i].num_cuenta_alumno == num_cuenta_alumno) {
            sumatoria += calificaciones[i].calificacion;
            num_calificaciones_alumno++;
        }
    }
    if (num_calificaciones_alumno == 0) {
        return 0;
    }
    return sumatoria / num_calificaciones_alumno;
}

void evaluar_calificaciones(Calificacion calificaciones[], int num_calificaciones, Alumno alumnos[], int num_alumnos) {
    cout << "Evaluación de calificaciones\n";
    for (int i = 0; i < num_alumnos; i++) {
        float promedio = calcular_promedio(calificaciones, num_calificaciones, alumnos[i].num_cuenta);
        cout << "El alumno con número de cuenta " << alumnos[i].num_cuenta << " tiene un promedio de " << promedio << ", ";
        if (promedio < 60) {
            cout << "lo que equivale a una calificación de Reprobado.\n";
        } else if (promedio < 80) {
            cout << "Lo que equivale a una calificación de Bien.\n";
// Funciones para cálculo de promedio y evaluación de calificaciones (continuación)
        } else if (promedio < 90) {
            cout << "lo que equivale a una calificación de Muy bien.\n";
        } else {
            cout << "lo que equivale a una calificación de Excelente.\n";
        }
    }
}

void guardar_datos(string archivo, Alumno alumnos[], int num_alumnos, Materia materias[], int num_materias, Calificacion calificaciones[], int num_calificaciones)
{
    ofstream file(archivo);

    // Guardar datos de alumnos
    file << "ALUMNOS\n";
    for (int i = 0; i < num_alumnos; i++)
    {
        file << alumnos[i].num_cuenta << "," << alumnos[i].nombre << "," << alumnos[i].carrera << "\n";
    }

    // Guardar datos de materias
    file << "MATERIAS\n";
    for (int i = 0; i < num_materias; i++)
    {
        file << materias[i].clave << "," << materias[i].nombre << "," << materias[i].maestro << "\n";
    }

    // Guardar datos de calificaciones
    file << "CALIFICACIONES\n";
    for (int i = 0; i < num_calificaciones; i++)
    {
        file << calificaciones[i].num_cuenta_alumno << "," << calificaciones[i].clave_materia << "," << calificaciones[i].calificacion << "\n";
    }

    file.close();

    cout << "Datos guardados en " << archivo << "\n";
}

void cargar_datos(string archivo, Alumno alumnos[], int& num_alumnos, Materia materias[], int& num_materias, Calificacion calificaciones[], int& num_calificaciones) {
    ifstream file(archivo);

    if (!file.is_open()) {
        cout << "Error al abrir archivo " << archivo << "\n";
        return;
    }

    string linea;
    string seccion;

    while (getline(file, linea)) {
        if (linea == "ALUMNOS") {
            seccion = "ALUMNOS";
        } else if (linea == "MATERIAS") {
            seccion = "MATERIAS";
        } else if (linea == "CALIFICACIONES") {
            seccion = "CALIFICACIONES";
        } else {
            stringstream ss(linea);
            string dato;

            if (seccion == "ALUMNOS") {
                getline(ss, dato, ',');
                int num_cuenta = stoi(dato);

                getline(ss, dato, ',');
                string nombre = dato;

                getline(ss, dato, ',');
                string carrera = dato;

                alumnos[num_alumnos].nombre = nombre;
                alumnos[num_alumnos].num_cuenta = num_cuenta;
                alumnos[num_alumnos].carrera = carrera;
                num_alumnos++;
            } else if (seccion == "MATERIAS") {
                getline(ss, dato, ',');
                int clave = stoi(dato);

                getline(ss, dato, ',');
                string nombre = dato;

                getline(ss, dato, ',');
                string maestro = dato;

                materias[num_materias].nombre = nombre;
                materias[num_materias].clave = clave;
                materias[num_materias].maestro = maestro;
                num_materias++;
            } else if (seccion == "CALIFICACIONES") {
                getline(ss, dato, ',');
                int num_cuenta_alumno = stoi(dato);

                getline(ss, dato, ',');
                int clave_materia = stoi(dato);

                getline(ss, dato, ',');
                float calificacion = stof(dato);

                calificaciones[num_calificaciones].clave_materia = clave_materia;
                calificaciones[num_calificaciones].num_cuenta_alumno = num_cuenta_alumno;
                calificaciones[num_calificaciones].calificacion = calificacion;
                num_calificaciones++;
            }
        }
    }

    file.close();

    cout << "Datos cargados desde " << archivo << "\n";
}

int main() {
    // Declaración de variables
    const int MAX_ALUMNOS = 100;
    const int MAX_MATERIAS = 50;
    const int MAX_CALIFICACIONES = 1000;
    Alumno alumnos[MAX_ALUMNOS];
    int num_alumnos = 0;
    Materia materias[MAX_MATERIAS];
    int num_materias = 0;
    Calificacion calificaciones[MAX_CALIFICACIONES];
    int num_calificaciones = 0;
    int opcion;


    string archivo = "datos.txt";
    cargar_datos("datos.txt", alumnos, num_alumnos, materias, num_materias, calificaciones, num_calificaciones);

    // Menú de opciones
    do {
        cout << "\nMenú de opciones\n";
        cout << "1. Registrar alumno\n";
        cout << "2. Registrar materia\n";
        cout << "3. Registrar calificación\n";
        cout << "4. Editar alumno\n";
        cout << "5. Editar materia\n";
        cout << "6. Editar calificación\n";
        cout << "7. Eliminar alumno\n";
        cout << "8. Eliminar materia\n";
        cout << "9. Eliminar calificación\n";
        cout << "0. Evaluar calificaciones\n";
        cout << "10. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        // Validar el tipo de entrada para la opción
        if (cin.fail()) {
            cout << "Error: entrada inválida. Por favor, ingrese un número.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcion) {
            case 1:
                limpiarPantalla();
                registrar_alumno(alumnos, num_alumnos);
                break;
            case 2:
                limpiarPantalla();
                registrar_materia(materias, num_materias);
                break;
            case 3:
                limpiarPantalla();
                registrar_calificacion(calificaciones, num_calificaciones, materias, num_materias, alumnos, num_alumnos);
                break;
            case 4:
                limpiarPantalla();
                editar_alumno(alumnos, num_alumnos);
                break;
            case 5:
                limpiarPantalla();
                editar_materia(materias, num_materias);
                break;
            case 6:
                limpiarPantalla();
                editar_calificacion(calificaciones, num_calificaciones);
                break;
            case 7:
                limpiarPantalla();
                eliminar_alumno(alumnos, num_alumnos);
                break;
            case 8:
                limpiarPantalla();
                eliminar_materia(materias, num_materias);
                break;
            case 9:
                limpiarPantalla();
                eliminar_calificacion(calificaciones, num_calificaciones, materias, num_materias, alumnos, num_alumnos);
                break;
            case 0:
                limpiarPantalla();
                evaluar_calificaciones(calificaciones, num_calificaciones, alumnos, num_alumnos);
                break;
            case 10:
                limpiarPantalla();
            guardar_datos(archivo, alumnos, num_alumnos, materias, num_materias, calificaciones, num_calificaciones);
                cout << "¡Hasta luego!\n";
                break;
            default:
                limpiarPantalla();
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
                // Limpiar el buffer de entrada
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (opcion != 10);

    return 0;
}
