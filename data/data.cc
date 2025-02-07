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

    std::ofstream archv(rt,std::ios::app);
    if(!archivo.is_open()){
        std::cerr<<"ERROR intentando guardar los matriculados\n";
        return;
    }

    for(const auto& alumno : alumnos){
        if((alumno.GetPlanIns() == "PLAN INFORMATICA" || alumno.GetPlanIns() == "PLAN BIOTECNOLOGIA" || alumno.GetPlanIns() == "PLAN MATEMATICAS")){
            std::ostringstream datosmatricula;
            datosmatricula << alumno.GetNombre() << "," << alumno.GetDni() << "," << alumno.GetCorreo() << ","
                            << alumno.GetGrado() << "," << alumno.GetUni() << "," << alumno.GetDestino() << alumno.GetPlanIns();
            if(matriculas.find(datosmatricula.str())==matriculas.end()){
                matriculas.insert(datosmatricula.str());
            }
        }
    }
    archivo.close();
    std::cout<<"Se han guardado las matriculas con exito en el fichero" << rt << "\n";
}

void Data::listarMatriculas(const std::string &rt){
    std::ifstream archv(rt);
    if(!archv.is_open()){
        std::cerr<<"ERROR accediendo a los datos de las matriculas guardadas\n";
        return;
    }

    std::cout<<"\n ------ MATRICULADOS ------ \n";
    std::cout<<"Los datos mostrados son los siguientes en este orden: ";
    std::cout<<std::left<<std::setw(25) << "Nombre" << std::setw(25) <<std::setw(25) << "DNI" <<std::setw(25) << "Correo"
                        <<std::setw(25) << "Grado" <<std::setw(25) << "Centro" <<std::setw(25) << "Universidad de Destino" << "Plan de convalidacion\n" 
    std::cout<<"------------------------------\n";

    std::string line;
    while(std::getline(archivo,linea)){
        std::istringstream stream(linea);
        std::string nombre,dni,correo,grado,uni,destino,plan;

        if(std::getline(stream,nombre,",")&&std::getline(stream,dni,",")&&std::getline(stream,correo,",")&&
            std::getline(stream,grado,",")&&std::getline(stream,uni,",")&&std::getline(stream,destino,",")&&std::getline(stream,plan,",")){
            
            std::cout<<std::left<<std::setw(25)<<nombre<<std::setw(25)<<dni<<std::setw(25)<<correo
                                <<std::setw(25)<<grado<<std::setw(25)<<uni<<std::setw(25)<<destino
                                <<plan<<"\n";
        }
    }
    archv.close();
}


