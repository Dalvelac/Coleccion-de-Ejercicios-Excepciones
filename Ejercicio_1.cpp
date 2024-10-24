// Los enfoques de bajo nivel: Banderas e interrupciones y tratamiento de los errores en lenguaje C:

#include <iostream>

bool Errores = false;

int division(int a, int b) {
    if (b == 0) {
        Errores = true;
        return 0;
    }
    else{
        return a / b;
    }

}

int main() {

    int resultado = division(10,0);

    if (Errores){
        std::cout << "Error: Division por 0" << std::endl;

        Errores = false; // Resetear errores
    }

    return 0;
}