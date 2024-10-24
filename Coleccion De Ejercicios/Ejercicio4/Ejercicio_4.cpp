// Los enfoques de bajo nivel: Banderas e interrupciones y tratamiento de los errores en lenguaje C:

#include<iostream>
#include<exception>
#include<string>

class Excepcion: public std::exception {
private:
        std::string mensaje;

public:
        explicit Excepcion(const std::string&msg): mensaje(msg) {}
        const char* what() const noexcept override {
                return mensaje.c_str();
        }
};

void func3() {
        throw Excepcion("Error en func3a");
}

int main() {

        try {
                func3();
        }catch (const Excepcion& e) {
                std::cout << "Esta es la excepcion: " << e.what() << std::endl;
        }

return 0;

}