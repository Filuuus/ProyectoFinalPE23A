//Bibliotecas utilizadas y uso del cout sin std.
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib> // Para la función std::system()
//Void para realizar la limpieza de la pantalla (Funcion para los distintos sistemas operativos).
void limpiarPantalla() {
    #ifdef _WIN32
        std::system("cls"); // Para Windows
    #else
        std::system("clear"); // Para Linux y macOS
    #endif
}


// Definición de estructuras.
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

//En este void se realiza el registro del alumno, pidiendo nombre, cuenta y carrera.
void registrar_alumno(Alumno alumnos[], int &num_alumnos) {
    cout << "Registro de alumno\n";
    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin, alumnos[num_alumnos].nombre);
    //Validacion de la entrada.
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

//Void para el registro de la materia, pidiendo nombre de la materia, clave y nombre del maestro.
void registrar_materia(Materia materias[], int &num_materias) {
    cout << "Registro de materia\n";
    cout << "Ingrese el nombre de la materia: ";
    cin.ignore();
    getline(cin, materias[num_materias].nombre);
    //Validacion de la entrada.
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
//Void para el registro de las calificaciones.
void registrar_calificacion(Calificacion calificaciones[], int &num_calificaciones, Materia materias[], int num_materias, Alumno alumnos[], int num_alumnos) {
    int clave_materia, num_cuenta_alumno;
    bool materia_encontrada = false, alumno_encontrado = false;
    float calificacion;
    //Valida que la clave de la materia sea valida.
    cout << "Registro de calificación\n";
    cout << "Ingrese la clave de la materia: ";
    while (!(cin >> clave_materia)) {
        cout << "Entrada inválida. Por favor, ingrese un número entero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Realiza la busqueda de la materia en el registro.
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave_materia) {
            materia_encontrada = true;
            break;
        }
    }
    //Informa en caso de no encontrar la materia.
    if (!materia_encontrada) {
        cout << "Materia no encontrada.\n";
        return;
    }
    //Valida que el nombre del alumno sea valido.
    cout << "Ingrese el número de cuenta del alumno: ";
    while (!(cin >> num_cuenta_alumno)) {
        cout << "Entrada inválida. Por favor, ingrese un número entero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Realiza la busqueda del alumno en el registro.
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta_alumno) {
            alumno_encontrado = true;
            break;
        }
    }
    //Informa en caso de no encontrar el nombre del alumno. 
    if (!alumno_encontrado) {
        cout << "Alumno no encontrado.\n";
        return;
    }
    //Realiza la validacion de la calificacion ingresada.
    cout << "Ingrese la calificación: ";
    while (!(cin >> calificacion)) {
        cout << "Entrada inválida. Por favor, ingrese un número válido.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Asigna la calificacion y realiza el movimiento en la lista.
    calificaciones[num_calificaciones].clave_materia = clave_materia;
    calificaciones[num_calificaciones].num_cuenta_alumno = num_cuenta_alumno;
    calificaciones[num_calificaciones].calificacion = calificacion;
    num_calificaciones++;
}

// Funciones para editar datos del alumno
void editar_alumno(Alumno alumnos[], int num_alumnos) {
    int num_cuenta;
    cout << "Edición de alumno\n";
    EA:
    cout << "Ingrese el número de cuenta del alumno a editar: ";
    if(float(scanf("%d",& num_cuenta)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto EA;}
    //Realiza la busqueda del alumno y verifica si fue encontrado o no.
    int indice = -1;
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta) {
            indice = i;
            break;
        }
    }
    //Informa si el alummno no es encontrado.
    if (indice == -1) {
        cout << "Alumno no encontrado.\n";
        return;
    }
    //Pide ingresar los nuevos datos al finalizar señala que los datos se actualizaron con exito.
    cout << "Ingrese el nuevo nombre del alumno: ";
    cin.ignore();
    getline(cin, alumnos[indice].nombre);
    cout << "Ingrese la nueva carrera del alumno: ";
    cin.ignore();
    getline(cin, alumnos[indice].carrera);

    cout << "Alumno actualizado con éxito.\n";
}
//Funcion para editar datos de materia.
void editar_materia(Materia materias[], int num_materias) {
    int clave;
    cout << "Edición de materia\n";
    EM:
    cout << "Ingrese la clave de la materia a editar: ";
    if(float(scanf("%d",& clave)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto EM;}
    //Realiza la busqueda de la materia y verifica si fue encontrada.
    int indice = -1;
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave) {
            indice = i;
            break;
        }
    }
    //Informa en caso de no encontrar la materia.
    if (indice == -1) {
        cout << "Materia no encontrada.\n";
        return;
    }
    //Pide ingresar los nuevos datos y señala que los datos se actializaron con exito.
    cout << "Ingrese el nuevo nombre de la materia: ";
    cin.ignore();
    getline(cin, materias[indice].nombre);
    cout << "Ingrese el nuevo nombre del maestro: ";
    cin.ignore();
    getline(cin, materias[indice].maestro);

    cout << "Materia actualizada con éxito.\n";
}
//Funcion para la edicion de calificaciones.
void editar_calificacion(Calificacion calificaciones[], int num_calificaciones) {
    int indice = -1;
    int clave_materia, num_cuenta_alumno;
    cout << "Edición de calificación\n";
    ECM:
    cout << "Ingrese la clave de la materia: ";
    if(float(scanf("%d",& clave_materia)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto ECM;}
        ECA:
    cout << "Ingrese el número de cuenta del alumno: ";
    if(float(scanf("%d",& num_cuenta_alumno)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto ECA;}
    //Realiza la busqueda de la calificacion por materia y alumno, despues verifica si fue encontrada.
    for (int i = 0; i < num_calificaciones; i++) {
        if (calificaciones[i].clave_materia == clave_materia && calificaciones[i].num_cuenta_alumno == num_cuenta_alumno) {
            indice = i;
            break;
        }
    }
    //Informa en caso de no esncontrar la calificacion.
    if (indice == -1) {
        cout << "Calificación no encontrada.\n";
        return;
    }
    //Pide ingresar la nueva calificacion y señala que fue actualizada con exito.
    float nueva_calificacion;
    NC:
    cout << "Ingrese la nueva calificación: ";
    if(float(scanf("%d",& nueva_calificacion)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto NC;}
    calificaciones[indice].calificacion = nueva_calificacion;

    cout << "Calificación actualizada con éxito.\n";
}

// Funcion para la eliminacion de alumnos. 
void eliminar_alumno(Alumno alumnos[], int& num_alumnos) {
    int num_cuenta;
    bool encontrado = false;
    //Pide ingresar el numero de cuenta y realiza la busqueda.
    cout << "Eliminación de datos de alumno\n";
    CAE:
    cout << "Ingrese el número de cuenta del alumno a eliminar: ";
    if(float(scanf("%d",& num_cuenta)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto CAE;}
    //Si encuentra el alumno, elimina su informacion y realiza el movimineto en el registro.
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta) {
            encontrado = true;
            for (int j = i; j < num_alumnos - 1; j++) {
                alumnos[j] = alumnos[j + 1];
            }
            num_alumnos--;
            break;
        }
    }//Informa si el alumno se elimino correctamente o si el alumno no fue encontrado.
    if (encontrado) {
        cout << "Alumno eliminado correctamente.\n";
    } else {
        cout << "Alumno no encontrado.\n";
    }
}
//Funcion para la eliminacion de materias.
void eliminar_materia(Materia materias[], int& num_materias) {
    int clave;
    bool encontrado = false;
    //Pide ingresar la clave de la materia y realiza la busqueda.
    cout << "Eliminación de datos de materia\n";
    CME:
    cout << "Ingrese la clave de la materia a eliminar: ";
    if(float(scanf("%d",& clave)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto CME;}
    //Si encintra la materia la elimina y realiza el movimiento en el registro.
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave) {
            encontrado = true;
            for (int j = i; j < num_materias - 1; j++) {
                materias[j] = materias[j + 1];
            }
            num_materias--;
            break;
        }
    }//Informa si la materia se elimino con exito o si no fue encontrada.
    if (encontrado) {
        cout << "Materia eliminada correctamente.\n";
    } else {
        cout << "Materia no encontrada.\n";
    }
}

// Funcion para la eliminacion de calificaciones.
void eliminar_calificacion(Calificacion calificaciones[], int& num_calificaciones, Materia materias[], int num_materias, Alumno alumnos[], int num_alumnos) {
    int clave_materia, num_cuenta_alumno;
    bool materia_encontrada = false, alumno_encontrado = false, encontrado = false;
    //Pide la clave de la materia y realiza la busqueda.
    cout << "Eliminación de calificación\n";
    ECMM:
    cout << "Ingrese la clave de la materia: ";
    if(float(scanf("%d",& clave_materia)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto ECMM;}
    for (int i = 0; i < num_materias; i++) {
        if (materias[i].clave == clave_materia) {
            materia_encontrada = true;
            break;
        }
    }//Informa en caso de no encontrar la materia.
    if (!materia_encontrada) {
        cout << "Materia no encontrada.\n";
        return;
    }//Pide el numero de cuenta del alumno.
    ECAM:
    cout << "Ingrese el número de cuenta del alumno: ";
    if(float(scanf("%d",& num_cuenta_alumno)) !=1){
            cout <<"Solo utiliza numeros para poder continuar. :'(" <<endl;
            system("pause");
            fflush(stdin);
            goto ECAM;}
    for (int i = 0; i < num_alumnos; i++) {
        if (alumnos[i].num_cuenta == num_cuenta_alumno) {
            alumno_encontrado = true;
            break;
        }
    }//Informa en caso de no encontrar el alumno.
    if (!alumno_encontrado) {
        cout << "Alumno no encontrado.\n";
        return;
    }//Elimina la calificacion y realiza el movimiento en el registro.
    for (int i = 0; i < num_calificaciones; i++) {
        if (calificaciones[i].clave_materia == clave_materia && calificaciones[i].num_cuenta_alumno == num_cuenta_alumno) {
            encontrado = true;
            for (int j = i; j < num_calificaciones - 1; j++) {
                calificaciones[j] = calificaciones[j + 1];
            }
            num_calificaciones--;
            break;
        }
    }//Informa si la calificacion se elimino correctamente o si no fue encontrada.
    if (encontrado) {
        cout << "Calificación eliminada correctamente.\n";
    } else {
        cout << "Calificación no encontrada.\n";
    }
}

// Funcion para cálculo de promedio.
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
//evaluación de calificaciones segun promedio.
void evaluar_calificaciones(Calificacion calificaciones[], int num_calificaciones, Alumno alumnos[], int num_alumnos) {
    cout << "Evaluación de calificaciones\n";
    for (int i = 0; i < num_alumnos; i++) {
        float promedio = calcular_promedio(calificaciones, num_calificaciones, alumnos[i].num_cuenta);
        cout << "El alumno con número de cuenta " << alumnos[i].num_cuenta << " tiene un promedio de " << promedio << ", ";
        if (promedio < 60) {
            cout << "lo que equivale a una calificación de Reprobado.\n";
        } else if (promedio < 80) {
            cout << "Lo que equivale a una calificación de Bien.\n";
        } else if (promedio < 90) {
            cout << "lo que equivale a una calificación de Muy bien.\n";
        } else {
            cout << "lo que equivale a una calificación de Excelente.\n";
        }
    }
}
//Funcion para guardar los datos en el archivo TXT.
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
    //Cierra el archivo.
    file.close();
    //Informa en donde fueron guardados los archivos.
    cout << "Datos guardados en " << archivo << "\n";
}
//Funcion para cargar los datos desde el archivo TXT.
void cargar_datos(string archivo, Alumno alumnos[], int& num_alumnos, Materia materias[], int& num_materias, Calificacion calificaciones[], int& num_calificaciones) {
    ifstream file(archivo);
    //Señala si hay algun error al abrir el archivo.
    if (!file.is_open()) {
        cout << "Error al abrir archivo " << archivo << "\n";
        return;
    }

    string linea;
    string seccion;
    //Obtiene los datos y los ordena en su respectivo luagar.
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
    //Cierra el archivo
    file.close();
    //Informa desde donde se cargaron los archivos.
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

    //LLama a la funcion para cargar los datos.
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
