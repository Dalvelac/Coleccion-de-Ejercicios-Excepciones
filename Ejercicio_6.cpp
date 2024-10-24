// Excepciones no interceptadas:
#include <iostream>
#include <stdexcept>

void func3 () {
    throw std::runtime_error("Error en func3");
}

int main() {

    func3 ();

    return 0;

}

// terminate called after throwing an instance of 'std::runtime_error'
// what(): Error en func3
