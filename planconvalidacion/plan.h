#ifndef PLAN_H
#define PLAN_H

#include <string>
#include <map>

class Plan{
    private:
        std::string id;
        std::string destino;
        std::string asignaturas;
        std::string duracion;
        int plazas;
    public:
        Plan(const std::string& id,const std::string& destino,const std::string& asignaturas,const std::string& duracion,const int& plazas);

        std::string GetId(){return id;}
        std::string GetDestino(){return destino;}
        std::string GetAsig(){return asignaturas;}
        std::string GetDuracion(){return duracion;}
        int GetPlazas(){return plazas;}


};

#endif