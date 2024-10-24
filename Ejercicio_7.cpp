// Adquisición de recursos

// Ejercicio: Implementa una clase que adquiere un recurso (como memoria dinámica o un archivo) en su constructor y libera el recurso en su destructor. Haz que el constructor lance una excepción si no se puede adquirir el recurso. Demuestra que, a pesar de la excepción, no se produce una fuga de recursos.

#include <iostream>
#include <stdexcept>

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

int main() {

    try {
        Memoria m;
    } catch (const std::runtime_error& e) {
        // Si no se puede adquirir la memoria
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
        // No se produce una fuga de recursos
    }
}