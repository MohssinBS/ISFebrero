#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <list>

class Alumno{
    private:
        std::string nombrecompleto;
        std::string dni;
        std::string correo;
        std::string grado;
        std::string uni;
        std::list<std::string> planesinscritos;
    public:
        Alumno(const std::string& nombrecompleto,const std::string& dni,const std::string& correo,const std::string& grado,const std::string& uni);
    sipnmp
};

#endif