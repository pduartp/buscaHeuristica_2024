#include <iostream>
#include <locale>
#include <fstream>
#include <sstream>
#include <vector>

#include "instance.hpp"
#include "pair.hpp"
#include "solution.hpp"

using namespace std;

void resultados(Instance instance){

    Funcoes funcoes;

    Solution solution(instance);


    vector<Grupo> grupos1 =solution.calcular_resultado();
    vector<Grupo> grupos2 =solution.calcular_resultado3();

    vector<Grupo> grupos3 =  solution.calcular_resultado2();

    vector<Grupo> grupos4 =  solution.calcular_resultado4();

    vector<Grupo> grupos5 =  solution.calcular_resultado5();

    //vector<Grupo> grupos = funcoes.get_grupos(instance);

    //for(unsigned i =0;i<grupos3.size();i++){
    //    grupos3[i].imprimir();
    //}

    double resultado1 = funcoes.get_total(grupos1,instance.arr_Pair);
    double resultado2 = funcoes.get_total(grupos2,instance.arr_Pair);
    double resultado3 = funcoes.get_total(grupos3,instance.arr_Pair);
    double resultado4 = funcoes.get_total(grupos4,instance.arr_Pair);
    double resultado5 = funcoes.get_total(grupos5,instance.arr_Pair);

    //cout<<"elementos dos grupos: "<<endl;
    //cout<<endl<<endl;
    //for(unsigned i =0;i<grupos5.size();i++){
    //    grupos5[i].imprimir();
    //}
    //cout<<endl<<endl;

    cout<<"resultado 1: "<<resultado1<<endl;
    cout<<"resultado 2: "<<resultado2<<endl;
    cout<<"resultado 3: "<<resultado3<<endl;
    cout<<"resultado 4 (em fase de teste): "<<resultado4<<endl;
    cout<<"resultado 5 (em fase de teste): "<<resultado5<<endl;

}


int main() {

    setlocale(LC_ALL, "Portuguese");
    
    Instance instance1;
    Instance instance2;
    Instance instance3;
    Instance instance4;
    Instance instance5;

    Instance instance6;
    Instance instance7;
    Instance instance8;
    Instance instance9;
    Instance instance10;

    Instance instance11;
    Instance instance12;
    Instance instance13;
    Instance instance14;
    Instance instance15;

    Instance instance16;
    Instance instance17;
    Instance instance18;
    Instance instance19;
    Instance instance20;


    Instance instance21;
    Instance instance22;
    Instance instance23;
    Instance instance24;
    Instance instance25;


    Instance instance26;
    Instance instance27;
    Instance instance28;
    Instance instance29;
    Instance instance30;


    instance1.read_File("instances/Geo/Geo_n010_ds_01.txt");
    instance2.read_File("instances/Geo/Geo_n010_ds_02.txt");
    instance3.read_File("instances/Geo/Geo_n010_ds_03.txt");
    instance4.read_File("instances/Geo/Geo_n010_ds_04.txt");
    instance5.read_File("instances/Geo/Geo_n010_ds_05.txt");


    instance6.read_File("instances/Geo/Geo_n010_ss_01.txt");
    instance7.read_File("instances/Geo/Geo_n010_ss_02.txt");
    instance8.read_File("instances/Geo/Geo_n010_ss_03.txt");
    instance9.read_File("instances/Geo/Geo_n010_ss_04.txt");
    instance10.read_File("instances/Geo/Geo_n010_ss_05.txt");


    instance11.read_File("instances/Geo/Geo_n060_ds_01.txt");
    instance12.read_File("instances/Geo/Geo_n060_ds_02.txt");
    instance13.read_File("instances/Geo/Geo_n060_ds_03.txt");
    instance14.read_File("instances/Geo/Geo_n060_ds_04.txt");
    instance15.read_File("instances/Geo/Geo_n060_ds_05.txt");
    

    instance16.read_File("instances/Geo/Geo_n060_ss_01.txt");
    instance17.read_File("instances/Geo/Geo_n060_ss_02.txt");
    instance18.read_File("instances/Geo/Geo_n060_ss_03.txt");
    instance19.read_File("instances/Geo/Geo_n060_ss_04.txt");
    instance20.read_File("instances/Geo/Geo_n060_ss_05.txt");



    instance21.read_File("instances/Geo/Geo_n960_ds_01.txt");
    instance22.read_File("instances/Geo/Geo_n960_ds_02.txt");
    instance23.read_File("instances/Geo/Geo_n960_ds_03.txt");
    instance24.read_File("instances/Geo/Geo_n960_ds_04.txt");
    instance25.read_File("instances/Geo/Geo_n960_ds_05.txt");



    instance26.read_File("instances/Geo/Geo_n012_ds_01.txt");
    instance27.read_File("instances/Geo/Geo_n012_ds_02.txt");
    instance28.read_File("instances/Geo/Geo_n012_ds_03.txt");
    instance29.read_File("instances/Geo/Geo_n012_ds_04.txt");
    instance30.read_File("instances/Geo/Geo_n012_ds_05.txt");

   

    //instance.read_File("instances/Geo/Geo_n010_ss_01.txt");
    //instance.read_File("instances/Geo/Geo_n010_ss_02.txt");
    //instance.read_File("instances/Geo/Geo_n010_ss_03.txt");


    //instance.read_File("instances/RanReal/RanReal_n012_ss_02.txt");
    //instance.read_File("instances/RanReal/RanReal_n120_ds_02.txt");
    //instance.read_File("instances/RanReal/RanReal_n012_ds_04.txt");
    //instance.read_File("instances/Geo/Geo_n012_ss_02.txt");

    // Para verificar se os dados foram lidos corretamente
    //instance.to_String();

    Funcoes funcoes;

    //Solution solution(instance);
/*
    vector<Grupo> grupos =  solution.calcular_resultado_ruim();    
    
    
    for(int i = 0; i<instance.quant_Grup;i++){     
        cout<<"grupo "<<i<<": "<<endl;   
        grupos[i].imprimir();
    }
    
    double a;

    for(int i = 0; i<instance.quant_Grup;i++){
        a =funcoes.get_total_grupo(grupos[i],instance.arr_Pair);
    }
    cout<<"a"<<endl;
    double a2= funcoes.get_total(grupos,instance.arr_Pair);
    cout<<a<<endl;
    cout<<a2<<endl;

   


    */

   /*
    vector<Grupo> grupos = solution.calcular_resultado();
    
    cout<<"elementos: "<<endl;
    vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
    for(int i =0;i<elementos.size();i++){
        cout<<elementos[i]<<endl;
    }

    cout<<"grupo 1: "<<endl;
    cout<<grupos[0].elementos[0]<<endl;

    cout<<"grupo 2: "<<endl;
    cout<<grupos[1].elementos[0]<<endl;


    cout<<"grupo 3: "<<endl;
    cout<<grupos[2].elementos[0]<<endl;
*/


/*

    vector<Grupo> grupos = funcoes.get_grupos(instance);

    //funcoes.imprimir_grupos(grupos);

    vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);

*/


    /*
    //adicionando elementos
    funcoes.alocar_elemento(grupos[0],elementos,11);
    funcoes.alocar_elemento(grupos[0],elementos,10);
    funcoes.alocar_elemento(grupos[1],elementos,9);
    funcoes.alocar_elemento(grupos[1],elementos,8);
    funcoes.alocar_elemento(grupos[1],elementos,7);
    funcoes.alocar_elemento(grupos[2],elementos,6);
    funcoes.alocar_elemento(grupos[2],elementos,5);
    funcoes.alocar_elemento(grupos[2],elementos,4);
    funcoes.alocar_elemento(grupos[3],elementos,3);
    funcoes.alocar_elemento(grupos[3],elementos,2);

    funcoes.imprimir_grupos(grupos);

    cout<<grupos[0].get_quantidade_elementos()<<endl;
    cout<<grupos[1].get_quantidade_elementos()<<endl;
    cout<<grupos[2].get_quantidade_elementos()<<endl;
    cout<<grupos[3].get_quantidade_elementos()<<endl;


    //inserindo elemento com heurística
    int i = funcoes.get_best_group(grupos,1,instance.arr_Pair);
    funcoes.alocar_elemento(grupos[i],elementos, 1);

    cout<<"a"<<endl;
    grupos[3].imprimir();
    */
/*


    //classe lista elementos

    cout<<"lista de elementos: "<<endl;
    //lista de elementos
    Lista_elementos lista_elementos(elementos.size());

    //adicionando elementos
    funcoes.alocar_elemento2(grupos[0],lista_elementos,11);
    funcoes.alocar_elemento2(grupos[0],lista_elementos,10);
    funcoes.alocar_elemento2(grupos[1],lista_elementos,9);
    funcoes.alocar_elemento2(grupos[1],lista_elementos,8);
    funcoes.alocar_elemento2(grupos[1],lista_elementos,7);
    funcoes.alocar_elemento2(grupos[2],lista_elementos,6);
    funcoes.alocar_elemento2(grupos[2],lista_elementos,5);
    funcoes.alocar_elemento2(grupos[2],lista_elementos,4);
    funcoes.alocar_elemento2(grupos[3],lista_elementos,3);
    funcoes.alocar_elemento2(grupos[3],lista_elementos,2);


    funcoes.imprimir_grupos(grupos);

    cout<<grupos[0].get_quantidade_elementos()<<endl;
    cout<<grupos[1].get_quantidade_elementos()<<endl;
    cout<<grupos[2].get_quantidade_elementos()<<endl;
    cout<<grupos[3].get_quantidade_elementos()<<endl;

*/

/*
    //inserindo elemento com heurística
    int i = funcoes.get_best_group(grupos,1,instance.arr_Pair);
    //funcoes.alocar_elemento2(grupos[i],lista_elementos, 1);

    cout<<"a"<<endl;
    grupos[3].imprimir();
*/


/*
    double total = funcoes.get_total(grupos,instance.arr_Pair);
    cout<<total<<endl;

*/
  
    //com a classe lista_elementos nós podemos "remover" elementos 
    //do nosso vector<elementos> enquanto os mantemos no vector.
    //Para isso, basta atualizarmos o tamanho de lista_elementos sempre
    //que mudamos o tamanho do vector, e verificar se o elemento está
    //presente em lista elementos antes de removê-lo de vector.
    //também precisamos remover o elemento da lista elementos se
    //o removermos do vector<elementos>

    //Isso será útil para removermos elementos do vector<elementos>
    //fora da ordem. Pois é bom pegar primeiro os elementos que
    //fazem pares que têm as melhores distâncias
    

    
/*
    vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);

    for(int i =0;i <elementos.size();i++){
        cout<<i<<endl;
    }
*/
/*
    vector<int> elementos2 = funcoes.get_elementos(instance.arr_Pair);
    vector<Grupo> grupos2 = funcoes.get_grupos(instance);
    Lista_elementos lista_elementos2(elementos2.size());

    int a =10;

    cout<<"a2: "<<endl;

    //funcoes.alocar_elemento3(grupos2[0],lista_elementos2,elementos2,3, a);
    funcoes.alocar_elemento2(grupos2[0],lista_elementos2,3);

    for(int i =0;i<grupos2.size();i++){
        grupos2[i].imprimir();
    }
*/




    cout<<"instâncias curtas: "<<endl;

    resultados(instance1);
    cout<<endl;    
    resultados(instance2);
    cout<<endl;
    resultados(instance3);
    cout<<endl;
    resultados(instance4);
    cout<<endl;
    resultados(instance5);

    cout<<"instâncias pequenas com grupos com mesmo tamanho:"<<endl;
    cout<<endl;
    resultados(instance6);
    cout<<endl;    
    resultados(instance7);
    cout<<endl;
    resultados(instance8);
    cout<<endl;
    resultados(instance9);
    cout<<endl;
    resultados(instance10);




    cout<<"instâncias maiores: "<<endl;
    cout<<endl;
    resultados(instance11);
    cout<<endl;
    resultados(instance12);
    cout<<endl;
    resultados(instance13);
    cout<<endl;
    resultados(instance14);
    cout<<endl;
    resultados(instance15);

    cout<<"instâncias grandes com grupos com mesmo tamanho: "<<endl;
    cout<<endl;
    resultados(instance16);
    cout<<endl;
    resultados(instance17);
    cout<<endl;
    resultados(instance18);
    cout<<endl;
    resultados(instance19);
    cout<<endl;
    resultados(instance20);


    cout<<"instâncias gigantescas: "<<endl;
    cout<<endl;
    resultados(instance21);
    cout<<endl;
    resultados(instance22);
    cout<<endl;
    resultados(instance23);
    cout<<endl;
    resultados(instance24);
    cout<<endl;
    resultados(instance25);

    cout<<"mais instâncias curtas: "<<endl;

    cout<<endl;
    resultados(instance26);
    cout<<endl;
    resultados(instance27);
    cout<<endl;
    resultados(instance28);
    cout<<endl;
    resultados(instance29);
    cout<<endl;
    resultados(instance30);

    //cout<<"total grupo 1: "<<funcoes.get_total_grupo(grupos3[0],instance.arr_Pair);
    //cout<<"total grupo 2: "<<funcoes.get_total_grupo(grupos3[1],instance.arr_Pair);







    return 0;

}
