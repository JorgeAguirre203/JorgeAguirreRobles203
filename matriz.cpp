#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

bool isNumber(const std::string& str) {
    std::istringstream ss(str);
    int num;
    ss >> num;
    return !ss.fail() && ss.eof();
}

void saveDataToFile(int data[10][10], int rows, int columns, const char* operation, int result[10][10]) {
    ofstream file("result.txt", ios::app);

    if (file.is_open()) {
        file << "Operación: " << operation << endl;

        file << "Datos de entrada:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                file << data[i][j] << " ";
            }
            file << endl;
        }

        file << "Resultado:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                file << result[i][j] << " ";
            }
            file << endl;
        }

        file << "----------------------------------" << endl;

        cout << "Datos guardados en el archivo 'result.txt'." << endl;

        file.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

int getValidLevel(const std::string& message, int min, int max) {
    int level;
    while (true) {
        std::cout << message;
        if (std::cin >> level && level >= min && level <= max) {
            break;
        } else {
            std::cout << "Ingresa un numero entre (" << min << "-" << max << "): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return level;
}

void captureData(int data[10][10], int rows, int columns) {
    cout << "Ingresa los elementos de la matriz:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << "Ingresa el elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> data[i][j];
        }
    }
}

void displayData(int data[10][10], int rows, int columns) {
    cout << "Resultados:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << setw(5) << data[i][j];
        }
        cout << endl;
    }
}

void saveDataToFile(int data[10][10], int rows, int columns, const char* fileName) {
    ofstream file(fileName);

    if (file.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                file << data[i][j] << " ";
            }
            file << endl;
        }

        cout << "Datos guardados en el archivo '" << fileName << "'." << endl;

        file.close();
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }
}

void addData(int data1[10][10], int data2[10][10], int result[10][10], int rows, int columns) {
    cout << "Realizando la suma de matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = data1[i][j] + data2[i][j];
            cout << data1[i][j] << " + " << data2[i][j] << " = " << result[i][j] << endl;
        }
    }

    saveDataToFile(data1, rows, columns, "Suma", result);
}

void subtractData(int data1[10][10], int data2[10][10], int result[10][10], int rows, int columns) {
    cout << "Realizando la resta de matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result[i][j] = data1[i][j] - data2[i][j];
            cout << data1[i][j] << " - " << data2[i][j] << " = " << result[i][j] << endl;
        }
    }

    saveDataToFile(data1, rows, columns, "Resta", result);
}

void multiplyData(int data1[10][10], int data2[10][10], int result[10][10], int rowsA, int columnsA, int rowsB, int columnsB) {
    if (columnsA != rowsB) {
        cout << "No se pueden multiplicar matrices con estas dimensiones." << endl;
        return;
    }

    cout << "Realizando la multiplicación de matrices:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < columnsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < columnsA; ++k) {
                result[i][j] += data1[i][k] * data2[k][j];
                cout << data1[i][k] << " * " << data2[k][j] << " + ";
            }
            cout << " = " << result[i][j] << endl;
        }
    }

    saveDataToFile(data1, rowsA, columnsA, "Multiplicacion", result);
}

void divideData(int data1[10][10], int data2[10][10], int result[10][10], int rows, int columns) {
    cout << "Realizando la división de matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (data2[i][j] != 0) {
                result[i][j] = data1[i][j] / data2[i][j];
                cout << data1[i][j] << " / " << data2[i][j] << " = " << result[i][j] << endl;
            } else {
                cout << "División por cero en la posición [" << i + 1 << "][" << j + 1 << "]." << endl;
            }
        }
    }

    saveDataToFile(data1, rows, columns, "Division", result);
}

void leerDatosGuardados() {
    ifstream archivo("result.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    string linea;
    cout << "Datos almacenados en el archivo:\n";
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}
int main() {
    int data1[10][10], data2[10][10], result[10][10];
    int rowsA, columnsA, rowsB, columnsB;

    cout<<" A continuacion, introduce el numero de filas y columas de las matrices sujetas a operaciones:\n";
    cout<<"--------------------------------------------------------------------------\n";
    cout<<"-           Número de filas para la matriz 1 (0 - 10)                    -\n";
    cout<<"-                                                                        -\n";
    cout<<"--------------------------------------------------------------------------\n";
    cin>> rowsA; 
      cout<<" A continuacion, introduce el numero de filas y columas de las matrices sujetas a operaciones:\n";
    cout<<"--------------------------------------------------------------------------\n";
    cout<<"-               Número de columnas de la matriz 1  (0 - 10)              -\n";
    cout<<"-                                                                        -\n";
    cout<<"--------------------------------------------------------------------------\n";
    cin>> columnsA; 
    
    captureData(data1, rowsA, columnsA);

   cout<<" A continuacion, introduce el numero de filas y columas de las matrices sujetas a operaciones:\n";
    cout<<"--------------------------------------------------------------------------\n";
    cout<<"-           Número de filas para la matriz 2 (0 - 10)                    -\n";
    cout<<"-                                                                        -\n";
    cout<<"--------------------------------------------------------------------------\n";
    cin>> rowsB; 
      cout<<" A continuacion, introduce el numero de filas y columas de las matrices sujetas a operaciones:\n";
    cout<<"--------------------------------------------------------------------------\n";
    cout<<"-               Número de columnas de la matriz 2  (0 - 10)              -\n";
    cout<<"-                                                                        -\n";
    cout<<"--------------------------------------------------------------------------\n";
    cin>> columnsB; 
    
    captureData(data2, rowsB, columnsB);

    int option;
    do {
        cout<<"--------------------------------------------------------------------------\n";
    cout<<"-              -------------Calculadora de matrices-------------         -\n";
    cout<<"-                 Seleccione la opcion de su eleccion:                   -\n";
    cout<<"-    1. Suma de matrices                                                 -\n";
    cout<<"-    2. Resta  de matrices                                               -\n";
    cout<<"-    3. Multiplicación de matrices                                       -\n";                                 
    cout<<"-    4. División de matrices                                             -\n";
    cout<<"-    5. Mostrar contenido del archivo                                    -\n";
    cout<<"-    6. Salir                                                            -\n";
    cout<<"-                                                                        -\n";
    cout<<"--------------------------------------------------------------------------\n";
        

        string choice;
        cin >> choice;
        if (isNumber(choice)) {
            option = std::stoi(choice);

            switch (option) {
                case 1:
                    if (rowsA == rowsB && columnsA == columnsB) {
                        addData(data1, data2, result, rowsA, columnsA);
                        displayData(result, rowsA, columnsA);
                    } else {
                        cout << "No se pueden sumar matrices de dimensiones diferentes." << endl;
                    }
                    break;
                case 2:
                    if (rowsA == rowsB && columnsA == columnsB) {
                        subtractData(data1, data2, result, rowsA, columnsA);
                        displayData(result, rowsA, columnsA);
                    } else {
                        cout << "No se pueden restar matrices de dimensiones diferentes." << endl;
                    }
                    break;
                case 3:
                    if (columnsA == rowsB) {
                        multiplyData(data1, data2, result, rowsA, columnsA, rowsB, columnsB);
                        displayData(result, rowsA, columnsB);
                    } else {
                        cout << "No se pueden multiplicar matrices con estas dimensiones." << endl;
                    }
                    break;
                case 4:
                    if (rowsA == rowsB && columnsA == columnsB) {
                        divideData(data1, data2, result, rowsA, columnsA);
                        displayData(result, rowsA, columnsA);
                    } else {
                        cout << "No se pueden dividir matrices de dimensiones diferentes." << endl;
                    }
                    break;
                    case 5:{
                         cout << "Mostrando contenido del archivo txt..." << endl;
                          leerDatosGuardados();
                            break;
                    }
                 
                case 6:
                    cout << "Cerrando calculadora..." << endl;
                    break;
                default:
                    cout << "Opción no válida. Ingresa una opción entre 1 y 5." << endl;
            }
        } else {
            std::cout << "Ingresa una opción válida en numeros" << std::endl;
            option = 0;
        }

    } while (option != 6);

    return 0;
}
