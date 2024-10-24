#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>
#include <string>

// Ejercicio 1
bool Errores = false;

int division(int a, int b) {
    if (b == 0) {
        Errores = true;
        return 0;
    } else {
        return a / b;
    }
}

// Ejercicio 2
int divisionexcepcion(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Error: Division por 0");
    } else {
        return a / b;
    }
}

// Ejercicio 3
class Excepcion : public std::exception {
private:
    std::string mensaje;

public:
    explicit Excepcion(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

void func3() {
    throw Excepcion("Error en func3");
}

void func2() {
    func3();
}

void func1() {
    func2();
}

// Ejercicio 4
void escribirarchivo(std::ofstream& file) {
    if (!file.is_open()) {
        throw std::runtime_error("No se puede escribir en el archivo");
    }
    file << "Hola mundo!";
}

// Ejercicio 5
void func3_reactivacion() {
    throw std::runtime_error("Error en func3");
}

// Ejercicio 6
void func3_no_interceptada() {
    throw std::runtime_error("Error en func3");
}

// Ejercicio 7
class Memoria {
private:
    int* memoria; // Recurso

public:
    Memoria() { // Constructor
        memoria = new int[1000000];
        if (memoria == nullptr) { // Si no se puede adquirir el recurso
            throw std::runtime_error("Error al adquirir la memoria");
        }
    }

    ~Memoria() { // Destructor
        delete[] memoria;
    }
};

// Ejercicio 8
void escribirarchivo_ej8(std::ofstream& file) {
    if (!file.is_open()) { // Si no se puede abrir el archivo
        throw std::runtime_error("No se puede escribir en el archivo");
    }
    file << "Hola mundo!"; // Escribir en el archivo
}

int main() {
    // Ejercicio 1
    int resultado = division(10, 0);
    if (Errores) {
        std::cout << "Error: Division por 0" << std::endl;
        Errores = false; // Resetear errores
    }

    // Ejercicio 2
    try {
        int resultadoexcepcion = divisionexcepcion(20, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }

    // Ejercicio 3
    try {
        func1();
    } catch (const Excepcion& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }

    // Ejercicio 4
    std::ofstream file("archivo.txt");
    try {
        file.close(); // Cerrar el archivo
        escribirarchivo(file); // Intentar escribir en el archivo
    } catch (const std::runtime_error& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }
    if (file.is_open()) {
        file.close(); // Cerrar el archivo
    }

    // Ejercicio 5
    try {
        func3_reactivacion();
    } catch (const std::runtime_error& e) {
        std::runtime_error error("Error en main");
        throw; // Reactivar el error
    } catch (const std::runtime_error& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }

    // Ejercicio 6
    try {
        func3_no_interceptada();
    } catch (const std::runtime_error& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }

    // Ejercicio 7
    try {
        Memoria m;
    } catch (const std::runtime_error& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }

    // Ejercicio 8
    std::ofstream file_ej8("archivo_ej8.txt");
    try {
        file_ej8.close(); // Cerrar el archivo
        escribirarchivo_ej8(file_ej8); // Intentar escribir en el archivo
    } catch (const std::runtime_error& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }
    if (file_ej8.is_open()) {
        file_ej8.close(); // Cerrar el archivo
    }

    return 0;
}