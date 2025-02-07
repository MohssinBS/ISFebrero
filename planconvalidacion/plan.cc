#include "plan.h"

//Constructor de la clase Plan
Plan::Plan(const std::string &id, 
            const std::string &destino, 
            const std::string &asignaturas, 
            const std::string &duracion, 
            const int &plazas) : id(id),destino(destino),asignaturas(asignaturas),duracion(duracion){}
