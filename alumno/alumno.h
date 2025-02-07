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
        std::map<std::string,std::string> planesinscritos;
    public:
        Alumno(const std::string& nombrecompleto,const std::string& dni,const std::string& correo,const std::string& grado,const std::string& uni);

        std::string GetNombre(){return nombrecompleto;}
        std::string GetDni(){return dni;}
        std::string GetCorreo(){return correo;}
        std::string GetGrado(){return grado;}
        std::string GetUni(){return uni;}

        void MostrarIns(){}
        void AnadirIns(std::string id,std::string destino){}
        void MatricularAlumno(){}
        
};

#endif