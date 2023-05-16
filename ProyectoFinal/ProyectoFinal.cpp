#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


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

// Funciones para registro, edición y eliminación de datos
void registrar_alumno(Alumno alumnos[], int &num_alumnos) {
    cout << "Registro de alumno\n";
    cout << "Ingrese el nombre del alumno: ";
    cin >> alumnos[num_alumnos].nombre;
    cout << "Ingrese el número de cuenta del alumno: ";
    cin >> alumnos[num_alumnos].num_cuenta;
    cout << "Ingrese la carrera del alumno: ";
    cin >> alumnos[num_alumnos].carrera;
    num_alumnos++;
}

void registrar_materia(Materia materias[], int &num_materias) {
    cout << "Registro de materia\n";
    cout << "Ingrese el nombre de la materia: ";
    cin >> materias[num_materias].nombre;
    cout << "Ingrese la clave de la materia: ";
    cin >> materias[num_materias].clave;
    cout << "Ingrese el nombre del maestro: ";
    cin >> materias[num_materias].maestro;
    num_materias++;
}

void registrar_calificacion(Calificacion calificaciones[], int &num_calificaciones, Materia materias[], int num_materias, Alumno alumnos[], int num_alumnos) {
    int clave_materia, num_cuenta_alumno;
    bool materia_encontrada = false, alumno_encontrado = false;
    float calificacion;
    cout << "Registro de calificación\n";
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
    cout << "Ingrese la calificación: ";
    cin >> calificacion;
    calificaciones[num_calificaciones].clave_materia = clave_materia;
    calificaciones[num_calificaciones].num_cuenta_alumno = num_cuenta_alumno;
    calificaciones[num_calificaciones].calificacion = calificacion;
    num_calificaciones++;
}

// Funciones para registro, edición y eliminación de datos (continuación)
void editar_alumno(Alumno alumnos[], int num_alumnos) {
    int num_cuenta;
    bool encontrado = false;
    cout << "Edición de datos de alumno\n";
    cout << "Ingrese el número de cuenta del alumno a editar: ";
    cin >> num_cuenta;
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta) {
            encontrado = true;
            cout << "Ingrese el nuevo nombre del alumno: ";
            cin >> alumnos[i].nombre;
            cout << "Ingrese la nueva carrera del alumno: ";
            cin >> alumnos[i].carrera;
            break;
        }
    }
    if (!encontrado) {
        cout << "Alumno no encontrado.\n";
    }
}

void editar_materia(Materia materias[], int num_materias) {
    int clave;
    bool encontrado = false;
    cout << "Edición de datos de materia\n";
    cout << "Ingrese la clave de la materia a editar: ";
    cin >> clave;
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave) {
            encontrado = true;
            cout << "Ingrese el nuevo nombre de la materia: ";
            cin >> materias[i].nombre;
            cout << "Ingrese el nuevo nombre del maestro: ";
            cin >> materias[i].maestro;
            break;
        }
    }
    if (!encontrado) {
        cout << "Materia no encontrada.\n";
    }
}

void editar_calificacion(Calificacion calificaciones[], int num_calificaciones, Materia materias[], int num_materias, Alumno alumnos[], int num_alumnos) {
    int clave_materia, num_cuenta_alumno;
    bool materia_encontrada = false, alumno_encontrado = false, encontrado = false;
    cout << "Edición de calificación\n";
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
            cout << "Ingrese la nueva calificación: ";
            cin >> calificaciones[i].calificacion;
            break;
        }
    }
    if (!encontrado) {
        cout << "Calificación no encontrada.\n";
    }
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

// void cargar_datos(string archivo, Alumno alumnos[], int& num_alumnos, Materia materias[], int& num_materias, Calificacion calificaciones[], int& num_calificaciones) {
//     ifstream file(archivo);

//     if (!file.is_open()) {
//         cout << "Error al abrir archivo " << archivo << "\n";
//         return;
//     }

//     string linea;

//     while (getline(file, linea)) {
//         if (linea == "ALUMNOS") {
//             while (getline(file, linea) && linea != "MATERIAS") {
//                 stringstream ss(linea);
//                 string matricula, nombre, carrera;

//                 getline(ss, matricula, ',');
//                 getline(ss, nombre, ',');
//                 getline(ss, carrera, ',');

//                 // Crear nuevo alumno y agregarlo al arreglo
//                 alumnos[num_alumnos] = Alumno(num_cuenta, nombre, carrera);
//                 num_alumnos++;
//             }
//         } else if (linea == "MATERIAS") {
//             while (getline(file, linea) && linea != "MAESTROS") {
//                 stringstream ss(linea);
//                 string clave, nombre, maestro;

//                 getline(ss, clave, ',');
//                 getline(ss, nombre, ',');
//                 getline(ss, maestro, ',');

//                 // Crear nueva materia y agregarla al arreglo
//                 materias[num_materias] = Materia(clave, nombre, maestro);
//                 num_materias++;
//             }
//         } else if (linea == "CALIFICACIONES") {
//             while (getline(file, linea)) {
//                 stringstream ss(linea);
//                 string matricula, clave_materia, calificacion;

//                 getline(ss, matricula, ',');
//                 getline(ss, clave_materia, ',');
//                 getline(ss, calificacion, ',');

//                 // Crear nueva calificación y agregarla al arreglo
//                 calificaciones[num_calificaciones] = Calificacion(matricula, clave_materia, stoi(calificacion));
//                 num_calificaciones++;
//             }
//         }
//     }

//     cout << "Datos cargados exitosamente desde el archivo: " << archivo << "\n";
//     file.close();
// }

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




// Función principal
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
        switch (opcion) {
            case 1:
                registrar_alumno(alumnos, num_alumnos);
                break;
            case 2:
                registrar_materia(materias, num_materias);
                break;
            case 3:
                registrar_calificacion(calificaciones, num_calificaciones, materias, num_materias, alumnos, num_alumnos);
                break;
            case 4:
                editar_alumno(alumnos, num_alumnos);
                break;
            case 5:
                editar_materia(materias, num_materias);
                break;
            case 6:
                editar_calificacion(calificaciones, num_calificaciones, materias, num_materias, alumnos, num_alumnos);
                break;
            case 7:
                eliminar_alumno(alumnos, num_alumnos);
                break;
            case 8:
                eliminar_materia(materias, num_materias);
                break;
            case 9:
                eliminar_calificacion(calificaciones, num_calificaciones, materias, num_materias, alumnos, num_alumnos);
                break;
            case 0:
                evaluar_calificaciones(calificaciones, num_calificaciones, alumnos, num_alumnos);
                break;
            case 10:
            guardar_datos(archivo, alumnos, num_alumnos, materias, num_materias, calificaciones, num_calificaciones);
                cout << "¡Hasta luego!\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 10);

    return 0;
}
