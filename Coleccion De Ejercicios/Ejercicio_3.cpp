// Propagación explícita:Crea un programa que demuestre cómo se propaga una excepción a través de varias funciones Asegúrate de que algunas funciones no manejen la excepción,de modo que tenga que propagarse hasta una función que la maneje


#include <iostream>

void func3() {
    std::runtime_error error("Error en func3");
}

void func2() {
    func3();
}

void func1() {
    func2();
}

int main() {

    try {
        func1();
    } catch (const std::runtime_error& e) {
        std::cout << "Esta es la excepcion: " << e.what() << std::endl;
    }

    return 0;

}
