#include <iostream>
#include <stdexcept>

class Memoria {
private:
    int* memoria; // Recurso

public:
    Memoria() { // Constructor
        memoria = new int[1000000]; // Si no se puede adquirir el recurso, se lanza std::bad_alloc
    }

    ~Memoria() { // Destructor
        delete[] memoria;
    }
};

int main() {
    try {
        Memoria m;
        std::cout << "Memoria creada exitosamente" << std::endl;
    } catch (const std::bad_alloc& e) {
        // Si no se puede adquirir la memoria
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
        // No se produce una fuga de recursos
    }
}