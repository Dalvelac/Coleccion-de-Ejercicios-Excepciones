// Las excepciones son más seguras que los errores:

#include <iostream>
#include <stdexcept>

int division (int a, int b) {
    if (b == 0) {
        return -1; // Error
    }
    else {
        return a / b;
    }
}

int divisionexcepcion (int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Error: Division por 0");
    }
    else {
        return a / b;
    }
}

int main()
{
    int resultadoerror = division(20, 0);
    if (resultadoerror == -1) {
        std::cout << "Error: Division por 0" << std::endl;
    }

    try {
        int resultadoexcepcion = divisionexcepcion(20, 0);

    }   catch (const std::invalid_argument& e) {
        std::cout << "Esta es la excepcion" << e.what() << std::endl;
    }
}

