#include "alumno.h"
#include "data.h"
#include <vector>
#include <iostream>

void mostrarMenu(){
    std::cout << "\n======= Menu Matriculacion ======\n";
    std::cout << "1. Visualizar Inscritos\n";
    std::cout << "2. Matricular Alumnos\n";
    std::cout << "3. Visualizas Alummos Matriculados\n";
    std::cout << "4. Salir\n";
    std::cout << "\nSeleccione una opcion: \n";
}

int main(){
    const std::string rutaPreins = "data/preinscritos.txt";
    const std::string rutaMatri = "data/matriculaciones.txt";

    std::vector<Alumno> preins = Data::leerAlumnos(rutaPreins);

    if(preins.empty()){
        std::cerr<<"ERROR: no se han encontrado alumnos preinscritos\n";
        return 1;
    }

    std::vector<Alumno> matriculas;
    for(const auto& alumno : preins){
        if(alumno.GetPlanIns()=="PLAN INFORMATICA"||alumno.GetPlanIns()=="PLAN BIOTECNOLOGIA"||alumno.GetPlanIns()=="PLAN MATEMATICAS"){
            matriculas.push_back(alumno);
        }
    }

    if(matriculas.empty()){
        std::cerr<<"ERROR: no se han encontrado alumnos con los planes: INFORMATICA,BIOTECNOLOGIA o MATEMATICAS en el fichero\n";
        return 1;
    }

    int opcion;
    bool salir = false;

    do{
        mostrarMenu();
        std::cin>>opcion;
        std::cin.ignore();

        switch (opcion){
            case 1://visualizamos preinscritos
                std::cout<<"\nEstos son los alumnos preinscritos:\n";
                for(const Alumno& alumno : preins){
                    std::cout<<"*******************************************\n";
                    std::cout<<"Nombre: "<< alumno.GetNombre()<<"\n";
                    std::cout<<"DNI: "<< alumno.GetDni()<<"\n";
                    std::cout<<"Correo: "<< alumno.GetCorreo()<<"\n";
                    std::cout<<"Grado: "<< alumno.GetGrado()<<"\n";
                    std::cout<<"Centro: "<< alumno.GetUni()<<"\n";
                    std::cout<<"Universidad de Destino: "<< alumno.GetDestino()<<"\n";
                    std::cout<<"Plan de Convalidacion: "<< alumno.GetPlanIns()<<"\n";
                }
                break;
            case 2://matriculacion del alumnado
                std::cout<<"\nSe estan estan seleccionando las matriculas aptas.....\n";
                std::cout<<"Realizando la matriculacion de los alumnos....\n";
                Data::VerterMatriculas(rutaMatri,matriculas);
                break;
            case 3://listar matriculados
                std::cout<<"\nMatriculas realizadas:\n";
                Data::listarMatriculas(rutaMatri);
                break;
            case 4:
                std::cout<<"Saliendo del programa\n";
                salir = true;
                break;
            default:
                std::cout<<"Opcion no valida, intente de nuevo\n";
        }
    }while(!salir);
    return 0;
}