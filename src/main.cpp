#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <omp.h>

#include "instance.hpp"
#include "pair.hpp"
#include "solution.hpp"

using namespace std;

#define NUM_THREADS 12

// Imprime os resultados.
void resultados(Instance instance)
{
    Funcoes funcoes;
    Solution solution(instance);

    vector<Grupo> grupos1 = solution.calcular_resultado();
    vector<Grupo> grupos3 = solution.calcular_resultado2();
    vector<Grupo> grupos2 = solution.calcular_resultado3();
    vector<Grupo> grupos4 = solution.calcular_resultado4();
    vector<Grupo> grupos5 = solution.calcular_resultado5();

    double resultado1 = funcoes.get_total(grupos1, instance.arr_Pair);
    double resultado2 = funcoes.get_total(grupos2, instance.arr_Pair);
    double resultado3 = funcoes.get_total(grupos3, instance.arr_Pair);
    double resultado4 = funcoes.get_total(grupos4, instance.arr_Pair);
    double resultado5 = funcoes.get_total(grupos5, instance.arr_Pair);

    cout << "resultado 1: " << resultado1 << endl;
    cout << "resultado 2: " << resultado2 << endl;
    cout << "resultado 3: " << resultado3 << endl;
    cout << "resultado 4 (em fase de teste): " << resultado4 << endl;
    cout << "resultado 5 (em fase de teste): " << resultado5 << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");


    vector<string> fileNames = {
        "instances/Geo/Geo_n010_ds_01.txt",
        "instances/Geo/Geo_n010_ds_02.txt",
        "instances/Geo/Geo_n010_ds_03.txt",
        "instances/Geo/Geo_n010_ds_04.txt",
        "instances/Geo/Geo_n010_ds_05.txt",

        "instances/Geo/Geo_n010_ss_01.txt",
        "instances/Geo/Geo_n010_ss_02.txt",
        "instances/Geo/Geo_n010_ss_03.txt",
        "instances/Geo/Geo_n010_ss_04.txt",
        "instances/Geo/Geo_n010_ss_05.txt",

        "instances/Geo/Geo_n060_ds_01.txt",
        "instances/Geo/Geo_n060_ds_02.txt",
        "instances/Geo/Geo_n060_ds_03.txt",
        "instances/Geo/Geo_n060_ds_04.txt",
        "instances/Geo/Geo_n060_ds_05.txt",

        "instances/Geo/Geo_n060_ss_01.txt",
        "instances/Geo/Geo_n060_ss_02.txt",
        "instances/Geo/Geo_n060_ss_03.txt",
        "instances/Geo/Geo_n060_ss_04.txt",
        "instances/Geo/Geo_n060_ss_05.txt",

        "instances/Geo/Geo_n960_ds_01.txt",
        "instances/Geo/Geo_n960_ds_02.txt",
        "instances/Geo/Geo_n960_ds_03.txt",
        "instances/Geo/Geo_n960_ds_04.txt",
        "instances/Geo/Geo_n960_ds_05.txt",

        "instances/Geo/Geo_n012_ds_01.txt",
        "instances/Geo/Geo_n012_ds_02.txt",
        "instances/Geo/Geo_n012_ds_03.txt",
        "instances/Geo/Geo_n012_ds_04.txt",
        "instances/Geo/Geo_n012_ds_05.txt"
    };

    // vector<Instance> instances[fileNames.size()];
    Instance instances[fileNames.size()];

    double start_time, end_time;
    start_time = omp_get_wtime(); // Marca o início do tempo
    
    #pragma omp parallel for
    for (size_t i = 0; i < fileNames.size(); ++i) {
        instances[i].read_File(fileNames[i]);
    }

    // #pragma parallel for
    for(size_t i = 0; i < fileNames.size(); i++) {
        if(i == 0)
            cout<<"\t\t ### INSTANCIAS CURTAS: ### "<<endl;
        if(i == 5)
            cout << "\n\t\t ### INSTANCIAS PEQUENAS COM GRUPOS COM MESMO TAMANHO: ###" << endl;
        if(i == 10)
            cout<<"\n\t\t ### INSTANCIAS GRANDES: ###"<<endl;
        if(i == 15)
            cout<<"\n\t\t ### INSTANCIAS GRANDES COM GRUPOS COM MESMO TAMANHO: ###"<<endl;
        if(i == 20)
            cout<<"\n\t\t ### INSTANCIAS EXTREMAMENTES GIGANTES: ###"<<endl;
        if(i == 25)
            cout<<"\n\t\t ### INSTANCIAS MAIS CURTAS: ###"<<endl;

        cout << endl;
        resultados(instances[i]);
    }

    end_time = omp_get_wtime(); // Marca o fim do tempo

    cout << "\n=================================\n";
    cout << "Tempo de execucao: " << (end_time - start_time) << " segundos\n"
         << endl;
    cout << "=================================\n";
    
    return 0;
}
