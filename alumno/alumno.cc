#include "alumno.h"

// Constructor clase Alumno
Alumno::Alumno(const std::string &nombrecompleto, 
                const std::string &dni,
                const std::string &correo, 
                const std::string &grado,
                const std::string &uni, 
                const std::string &destino,
                const std::string &planinscrito) : nombrecompleto(nombrecompleto),dni(dni),correo(correo),grado(grado),uni(uni),destino(destino),planinscrito(planinscrito){}


//Funcion para matricular a un alummo
std::string Alumno::MatricularAlumno(){
    return nombrecompleto + "," + dni + "," + correo + "," + grado + "," + uni + "," + destino + "," + planinscrito;
}

