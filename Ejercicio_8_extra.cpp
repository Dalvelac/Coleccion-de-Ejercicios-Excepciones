// Ejercicio 8: Implementa un programa que abra un archivo de texto para escritura (usando std::ofstream). Luego, en un bloque try/catch, intenta escribir en el archivo. Si ocurre un error (puedes simularlo cerrando el archivo antes de intentar escribir en él), lanza y maneja una excepción. Asegúrate de cerrar el archivo correctamente en todos los casos.

#include <iostream>
#include <fstream>
#include <stdexcept>

void escribirarchivo(std::ofstream& file) {
    if (!file.is_open()) { // Si no se puede abrir el archivo
        throw std::runtime_error("No se puede escribir en el archivo");
    }

    file << "Hola mundo!"; // Escribir en el archivo

}

int main () {

std::ofstream file ("archivo.txt");

    try {
        file.close(); // Cerrar el archivo
        escribirarchivo(file); // Intentar escribir en el archivo
    }

    catch (const std::runtime_error& e) { // Manejar la excepción
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }

    if (file.is_open()) {
        file.close(); // Cerrar el archivo
    }

    return 0;

}
