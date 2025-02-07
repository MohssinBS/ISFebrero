#include "data.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>

std::vector<Alumno> Data::leerAlumnos(const std::string &ruta_archv){
    std::vector<Alumno> preins;
    std::ifstream archv(ruta_archv);
    
    if(!archv.is_open()){
        std::cerr << "Error: No se pudo abrir el archivo" << ruta_archv <<"\n";
        return preins;
    }

    std::string linea;
    while(std::getline(archv,linea)){
        std::istringstream stream(linea);
        std::string nombrecompleto,dni,correo,grado,uni,destino,plansinscrito;

        if(std::getline(stream,nombrecompleto,',') && std::getline(stream,dni,',') && 
            std::getline(stream,correo,',') && std::getline(stream,grado,',') &&
            std::getline(stream,uni,',') && std::getline(stream,destino,',') && std::getline(stream,plansinscrito,',')){
                preins.emplace_back(nombrecompleto,dni,correo,grado,uni,destino,plansinscrito);
            }
    }
    archv.close();
    return preins;
}

void Data::VerterMatriculas(const std::string &rt, const std::vector<Alumno> &alumnos){
    std::unordered_set<std::string> matriculas;
    std::ifstream archv(rt);
    if(archv.is_open()){
        std::string linea;
        while(std::getline(archv,linea)){
            matriculas.insert(linea);
        }
        archv.close();
    }

    std::ofstream archv2(rt,std::ios::app);
    if(!archv2.is_open()){
        std::cerr<<"ERROR intentando guardar los matriculados\n";
        return;
    }

    for(const auto& alumno : alumnos){
        if((alumno.GetPlanIns() == "PLAN INFORMATICA" || alumno.GetPlanIns() == "PLAN BIOTECNOLOGIA" || alumno.GetPlanIns() == "PLAN MATEMATICAS")){
            std::ostringstream datosmatricula;
            datosmatricula << alumno.GetNombre() << "," << alumno.GetDni() << "," << alumno.GetCorreo() << ","
                            << alumno.GetGrado() << "," << alumno.GetUni() << "," << alumno.GetDestino() << "," << alumno.GetPlanIns();
            if(matriculas.find(datosmatricula.str())==matriculas.end()){
                archv2<<datosmatricula.str()<<"\n";
                matriculas.insert(datosmatricula.str());
            }
        }
    }
    archv2.close();
    std::cout<<"Se han guardado las matriculas con exito en el fichero " << rt << "\n";
}

void Data::listarMatriculas(const std::string &rt){
    std::ifstream archv(rt);
    if(!archv.is_open()){
        std::cerr<<"ERROR accediendo a los datos de las matriculas guardadas\n";
        return;
    }

    std::cout<<"\n ------ MATRICULADOS ------ \n";
    std::cout<<"Los datos mostrados son los siguientes en este orden: \n";
    std::cout<<"Nombre\n"
            << "DNI\n"
            << "Correo\n"
            << "Grado\n" 
            << "Centro\n" 
            << "Universidad de Destino\n" 
            << "Plan de convalidacion\n"; 
    std::cout<<"------------------------------\n";

    std::string line;
    while(std::getline(archv,line)){
        std::istringstream stream(line);
        std::string nombre,dni,correo,grado,uni,destino,plan;

        if(std::getline(stream,nombre,',') &&
            std::getline(stream,dni,',') &&
            std::getline(stream,correo,',') &&
            std::getline(stream,grado,',') &&
            std::getline(stream,uni,',') &&
            std::getline(stream,destino,',') &&
            std::getline(stream,plan,',')){
            std::cout<<nombre<<"\n"<<dni<<"\n"<<correo <<"\n"<<grado<<"\n"<<uni<<"\n"<<destino<<"\n"<<plan<<"\n";
            std::cout<<"*************************\n";

            
        }
    }
    std::cout<<"------------------------------------------------------------\n";
    archv.close();
}


