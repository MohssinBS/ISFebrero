#ifndef DATA_H
#define DATA_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <iomanip>
#include "alumno.h"

class Data{
    public:
        static std::vector<Alumno> leerAlumnos(const std::string& ruta_archv);
        static void VerterMatriculas(const std::string& rt,const std::vector<Alumno>& matriculados);
        static void listarMatriculas(const std::string& rt);
};

#endif