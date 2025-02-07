#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include "alumno.h"
#include "plan.h"

class Data{
    public:
        static std::vector<Alumno> leerAlumnos(const std::string& ruta_archv);
        static std::vector<Plan> leerPlanes(const std::string& ruta_archv);
        void MostrarPlanes();
};

#endif