#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>



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
        Alumno(const std::string& nombrecompleto,const std::string& dni,const std::string& correo, const std::string& grado,const std::string& uni,const std::string& destino,const std::string& planinscrito);

        std::string GetNombre()const{return nombrecompleto;}
        std::string GetDni()const{return dni;}
        std::string GetCorreo()const{return correo;}
        std::string GetGrado()const{return grado;}
        std::string GetUni()const{return uni;}
        std::string GetDestino()const{return destino;}
        std::string GetPlanIns()const{return planinscrito;}

        std::string MatricularAlumno(){
            return nombrecompleto + "," + dni + "," + correo + "," + grado + "," + uni + "," + destino + "," + planinscrito;
        }
        
};

#endif