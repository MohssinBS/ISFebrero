#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <map>
#include "data.h"

class Alumno{
    private:
        std::string nombrecompleto;
        std::string dni;
        std::string correo;
        std::string grado;
        std::string uni;
        std::string destino;
        std::string planinscrito;
    public:
        Alumno(const std::string& nombrecompleto,const std::string& dni,const std::string& correo,const std::string& grado,const std::string& uni,const std::string& destino,const std::string& planinscrito);

        std::string GetNombre(){return nombrecompleto;}
        std::string GetDni(){return dni;}
        std::string GetCorreo(){return correo;}
        std::string GetGrado(){return grado;}
        std::string GetUni(){return uni;}
        std::string GetDestino(){return destino;}
        std::string GetPlanIns(){return planinscrito;}

        std::string MatricularAlumno(){}
        
};

#endif