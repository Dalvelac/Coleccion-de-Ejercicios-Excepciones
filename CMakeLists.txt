cmake_minimum_required(VERSION 3.10)
project(Coleccion_de_Ejercicios_Excepciones)

set(CMAKE_CXX_STANDARD 14)

# Add the "Coleccion De Ejercicios" subdirectories
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio1)
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio2)
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio3)
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio4)
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio5)
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio6)
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio7)
add_subdirectory(Coleccion\ De\ Ejercicios/Ejercicio8)
add_executable(main.cpp
        main.cpp)
