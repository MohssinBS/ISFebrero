#include "alumno.h"

// Constructor clase Alumno
Alumno::Alumno(const std::string &nombrecompleto, 
                const std::string &dni,
                const std::string &correo, 
                const std::string &grado, 
                const std::string &uni) : nombrecompleto(nombrecompleto),dni(dni),correo(correo),grado(grado),uni(uni){}

//Funcion para mostrar las inscripciones del alumno
void Alumno::MostrarIns(){}

//Funciopn para inscribir al alumno en un plan SICUE
void Alumno::AnadirIns(){}

//Funcion para matricular a un alummo
void Alumno::MatricularAlumno(std::string nombredni,std::string id,std::string destino){}