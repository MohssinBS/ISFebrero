#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "../data/data.h"

void testLeerPreins(){
    const std::string rutatest = "tests/test1.txt";

    std::ofstream archv(rutatest,std::ios::trunc);
    assert(archv && "ERROR no se ha podido crear el fichero test1.txt:");

    archv<< "Mohssin Bassat,04780813X,o22basim@uco.es,Grado Ing.Informatica,Universidad de Cordoba,Universidad de Granada,PLAN INFORMATICA\n"
        << "Miriam Lopez,5690396L,b23logam@uma.es,Grado Biotecnologia,Universidad de Malaga,Universidad de Cordoba,PLAN BIOTECNOLOGIA\n";
    archv.close();

    std::vector<Alumno> preins = Data::leerAlumnos(rutatest);
    assert(preins.size()==2&&"ERROR no se ha leido correctamente los preinscritos. VALOR ESPERADO: 2\n");
    assert(preins[0].GetNombre()=="Mohssin Bassat" && "ERROR: no se ha leido correctamente a los inscritos. VALOR ESPERADO: Mohssin Bassat\n");
    assert(preins[1].GetDestino()=="Universidad de Cordoba" && "ERROR: no se ha leido correctamente a los inscritos. VALOR ESPERADO: Universidad de Cordoba\n");

    std::cout<<"TEST 1 PASADO EXITOSAMENTE\n";
}

void testGuardarMatri(){
    const std::string rutatest = "tests/test2.txt";

    std::vector<Alumno> matriculados = {
        Alumno("Mohssin Bassat","04780813X","o22basim@uco.es","Grado Ing.Informatica","Universidad de Cordoba","Universidad de Granada","PLAN INFORMATICA"),
        Alumno("Miriam Lopez","5690396L","b23logam@uma.es","Grado Biotecnologia","Universidad de Malaga","Universidad de Cordoba","PLAN BIOTECNOLOGIA")
    };

    Data::VerterMatriculas(rutatest,matriculados);

    std::ifstream archv(rutatest);
    assert(archv && "ERROR No se ha podido abrir el fichero para guardar matriculas\n");

    std::string line;
    std::vector<std::string> nlineas;
    while(std::getline(archv,line)){
        nlineas.push_back (line);
    }
    archv.close();

    assert(nlineas.size()==2&&"ERROR numero de lineas leidas incorrecto. VALOR ESPERADO: 2\n");
    assert(nlineas[0]=="Mohssin Bassat,04780813X,o22basim@uco.es,Grado Ing.Informatica,Universidad de Cordoba,Universidad de Granada,PLAN INFORMATICA" && "ERROR: No coincide la 1 matricula leida");
    assert(nlineas[1]=="Miriam Lopez,5690396L,b23logam@uma.es,Grado Biotecnologia,Universidad de Malaga,Universidad de Cordoba,PLAN BIOTECNOLOGIA" && "ERROR: No coincide la 2 matricula leida");

    std::cout<<"TEST 2 PASADO EXITOSAMENTE\n";
}

int main(){
    testLeerPreins();
    testGuardarMatri();
    std::cout<<"TODOS LOS TEST PASARON EXITOSAMENTE\n";
    return 0;
}