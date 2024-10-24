// Manejo de una excepción y reactivación:

#include <iostream>
#include <stdexcept>

void func3() {
    throw std::runtime_error("Error en func3");
}


int main() {
    try {
        func3();
    } catch (const std::runtime_error& e) {
        std::runtime_error error("Error en main");
        throw; //Aqui se reactiva el error
    }

    catch (const std::runtime_error& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }
}
