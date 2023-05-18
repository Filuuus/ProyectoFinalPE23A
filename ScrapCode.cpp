
// // Funciones para registro, edición y eliminación de datos
// void registrar_alumno(Alumno alumnos[], int &num_alumnos) {
//     cout << "Registro de alumno\n";
//     cout << "Ingrese el nombre del alumno: ";
//     cin.ignore();
//     getline(cin, alumnos[num_alumnos].nombre);
//     cout << "Ingrese el número de cuenta del alumno: ";
//     cin >> alumnos[num_alumnos].num_cuenta;
//     cout << "Ingrese la carrera del alumno: ";
//     cin.ignore();
//     getline(cin, alumnos[num_alumnos].carrera);
//     num_alumnos++;
// }


// void registrar_materia(Materia materias[], int &num_materias) {
//     cout << "Registro de materia\n";
//     cout << "Ingrese el nombre de la materia: ";
//     cin.ignore();
//     getline(cin, materias[num_materias].nombre);
//     cout << "Ingrese la clave de la materia: ";
//     cin >> materias[num_materias].clave;
//     cout << "Ingrese el nombre del maestro: ";
//     cin.ignore();
//     getline(cin, materias[num_materias].maestro);
//     num_materias++;
// }


// void registrar_calificacion(Calificacion calificaciones[], int &num_calificaciones, Materia materias[], int num_materias, Alumno alumnos[], int num_alumnos) {
//     int clave_materia, num_cuenta_alumno;
//     bool materia_encontrada = false, alumno_encontrado = false;
//     float calificacion;
//     cout << "Registro de calificación\n";
//     cout << "Ingrese la clave de la materia: ";
//     cin >> clave_materia;
//     for (int i = 0; i < num_materias; i++) {
//         if (materias[i].clave == clave_materia) {
//             materia_encontrada = true;
//             break;
//         }
//     }
//     if (!materia_encontrada) {
//         cout << "Materia no encontrada.\n";
//         return;
//     }
//     cout << "Ingrese el número de cuenta del alumno: ";
//     cin >> num_cuenta_alumno;
//     for (int i = 0; i < num_alumnos; i++) {
//         if (alumnos[i].num_cuenta == num_cuenta_alumno) {
//             alumno_encontrado = true;
//             break;
//         }
//     }
//     if (!alumno_encontrado) {
//         cout << "Alumno no encontrado.\n";
//         return;
//     }
//     cout << "Ingrese la calificación: ";
//     cin >> calificacion;
//     calificaciones[num_calificaciones].clave_materia = clave_materia;
//     calificaciones[num_calificaciones].num_cuenta_alumno = num_cuenta_alumno;
//     calificaciones[num_calificaciones].calificacion = calificacion;
//     num_calificaciones++;
// }