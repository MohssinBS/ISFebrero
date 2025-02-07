#include "data.h"

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

        if(std::getline(stream,nombrecompleto,",") && std::getline(stream,dni,",") && 
            std::getline(stream,correo,",") && std::getline(stream,grado,",") &&
            std::getline(stream,uni,",") && std::getline(stream,destino,",") && std::getline(stream,plansinscrito,",")){
                preins.emplace_back(nombrecompleto,dni,correo,grado,uni,destino,plansinscrito);
            }
    }
    archv.close();
    return preins;
}

void Data::VerterMatriculas(const std::string &rt, const std::vector<Alumno> &matriculados)
{
}

void Data::listarMatriculas(const std::string &rt)
{
}
