#pragma once

#include <iostream>
#include "instance.hpp"
#include "Pair.hpp"
#include <algorithm>

using namespace std;


class Grupo{

    public:

    int i;

    double tam_minimo;
    double tam_maximo;

    vector<int> elementos = {}; 
    //int quantidade_elementos;//PERIGO! use elementos.size() no lugar

    void imprimir(){

        cout<<"tamanho mínimo: "<<tam_minimo<<endl;
        cout<<"tamanho máximo: "<<tam_maximo<<endl;        
        
        for(int i = 0; i<elementos.size();i++){
            cout<<"elemento "<<i<<" :"<<elementos[i]<<endl;
        }
        cout<<endl;
    }

    int get_quantidade_elementos(){
        return this->elementos.size();
    }

};

class Lista_elementos{
    
    private:
     
    int quantidade;

    public:

    vector<bool> elementos;  

    Lista_elementos(int quantidade1){
        for(int i=0;i<quantidade1;i++){
            this->elementos.push_back(true);
        }
        this->quantidade = quantidade1;
    }

    void remove(int i){
        if(elementos[i]==true){
            elementos[i] = false;
            this->quantidade-=1;
        }
        else{
            cout<<"ELEMENTO JÁ FOI REMOVIDO!!"<<endl;
            cout<<"elemento: "<<i<<endl;
        }
    }

    int get_tamanho(){
        return this->quantidade;
    }
};


bool operator<(Pair const & a, Pair const & b){
    return a.distance_Element < b.distance_Element;
}

bool comparar_distancias(Pair &a, Pair &b){
    return a.distance_Element < b.distance_Element;
}
bool comparar_tam_maximo(Grupo grupo1, Grupo grupo2){
    return grupo1.tam_maximo < grupo2.tam_maximo;
}
bool comparar_tam_minimo(Grupo grupo1, Grupo grupo2){
    return grupo1.tam_minimo < grupo2.tam_minimo;
}



class Funcoes{


    public:  
       
    void ordenar_distancias(vector<Pair> &distances){
        std::sort(distances.begin(),distances.end(),comparar_distancias);
    }

    void ordenar_tam_maximo(vector<Grupo> &grupos){
        std::sort(grupos.begin(),grupos.end(),comparar_tam_maximo);
    }

    void ordenar_tam_minimo(vector<Grupo> &grupos){
        std::sort(grupos.begin(),grupos.end(),comparar_tam_minimo);
    }
  

    double media(vector<Pair> &distances){
        double soma = 0.0;
        for(long long unsigned int i = 0;i <distances.size();i++){
            soma += distances[i].distance_Element;
        }
        double resultado = soma/(double)distances.size();

        return resultado;
    }

    //adicionamos um elemento em um grupo
    //não confere se grupo está cheio
    void alocar_elemento(Grupo &grupo, vector<int> &elementos,int i){
        if(grupo.get_quantidade_elementos() == grupo.tam_maximo ){
            cout<<"ERRO!!!!! TENTOU ADICIONAR ELEMENTO EM UM GRUPO CHEIO!!"<<endl;
        }

        //grupo.quantidade_elementos+=1;
        grupo.elementos.push_back(elementos[i]);

        elementos.erase(elementos.begin()+i);

    }

    //usa a classe Lista_elementos
    void alocar_elemento2(Grupo &grupo, Lista_elementos &lista_elementos,int elemento){
        
        if(grupo.get_quantidade_elementos() == grupo.tam_maximo ){
            cout<<"ERRO!!!!! TENTOU ADICIONAR ELEMENTO EM UM GRUPO CHEIO!!"<<endl;
            cout<<"elemento: "<<elemento<<endl;
        }

        if(lista_elementos.elementos[elemento] == true){
            lista_elementos.remove(elemento);    
            grupo.elementos.push_back(elemento);
        }
        else{
            cout<<"elemento já alocado para algum grupo."<<endl;
        }


    }


    //quando alocamos um elemento em um grupo precisamos ter certeza de que 
    //ainda poderemos preencher o mínimo de elementos de todos os grupos. 
    int alocar_elemento3(Grupo &grupo, Lista_elementos &lista_elementos, vector<int> elementos,int elemento,int &quantidade_elementos_minimos){

        cout<<elemento<<endl;
        if(grupo.get_quantidade_elementos() == grupo.tam_maximo ){
            cout<<"ERRO!!!!! TENTOU ADICIONAR ELEMENTO EM UM GRUPO CHEIO!!"<<endl;
        }
        if(lista_elementos.elementos[elemento] == false){
            cout<<"ELEMENTO JÁ FOI REMOVIDO!!!!!!!!!!!!"<<endl;
            cout<<"elemento: "<<elemento<<endl;
        }
        else{
            //removemos o elemento da lista_elementos
            lista_elementos.remove(elemento);

            //se o elemento estiver no final do vector<elementos> podemos
            //atualizar o vector<elementos> sem riscos
            if(elemento = elementos.back()){
                elementos.pop_back();
            }

            //coloca o elemento no grupo
            grupo.elementos.push_back(elemento);
            grupo.elementos.push_back(elemento);
            grupo.elementos.push_back(elemento);
            cout<<"elemento do final: "<<grupo.elementos.back()<<endl;

            
            if(grupo.elementos.size()<=grupo.tam_minimo){
                quantidade_elementos_minimos =quantidade_elementos_minimos- 1;
            }

            //com a classe lista_elementos nós podemos "remover" elementos 
            //do nosso vector<elementos> enquanto os mantemos no vector.
            //Para isso, basta atualizarmos o tamanho de lista_elementos sempre
            //que mudamos o tamanho do vector (o remove faz isso), 
            //e verificar se o elemento está
            //presente em lista elementos antes de removê-lo de vector.
            //também precisamos remover o elemento da lista elementos se
            //o removermos do vector<elementos> 
        }

        return quantidade_elementos_minimos;

    }

    vector<int> get_elementos(vector<Pair> distances){
        vector<int> elementos;
        int tamanho;
        tamanho = distances[distances.size()-1].second_Element + 1;
        for(int i =0;i<tamanho;i++){
            elementos.push_back(i);
        }
        return elementos;
    }

    vector<Grupo> get_grupos(Instance instance){

        vector<Grupo> grupos;

        for(int i =0; i < instance.quant_Grup;i++){
            Grupo grupo;
            grupo.i = i;
            grupo.tam_maximo=instance.arr_Tam_Max_Grup[i];
            grupo.tam_minimo=instance.arr_Tam_Min_Grup[i];
            grupos.push_back(grupo);
        }

        return grupos;

    }


/*
    int busca_binaria1(int elemento1, int element2, vector<Pair> &pares, ){
                                    
    }
    int busca_binaria2(int elemento1, int element2, vector<Pair> &pares){

    }
    */

   void imprimir_grupos(vector<Grupo> grupos){
        for(int i = 0; i<grupos.size();i++){
            cout<<endl;
            cout<<"grupo "<<grupos[i].i<<endl;
            grupos[i].imprimir();

            if(grupos[i].get_quantidade_elementos() == 0){
                cout<<"grupo sem elementos"<<endl;
            }

            cout<<endl;
        }     

   }

  

    Pair get_pair(int elemento1, int elemento2, vector<Pair> &pares, int quantidade){

        elemento1+=1;
        elemento2+=1;

        int maior = elemento1;
        int menor = elemento2;
        if(elemento2 >elemento1){
            maior= elemento2;
            menor= elemento1;
        }        

        int position = (quantidade*(quantidade-1)/2) - (quantidade-menor)*(quantidade-menor-1)/2;
      
        position-=1;

        while(pares[position].second_Element >= maior ){
            position-=1;
        }

        //cout<<position<<endl;
        //cout<<pares.size()<<endl;
        //cout<<"elemento 1: "<<pares[position].first_Element<<endl;
        //cout<<"elemento 2: "<<pares[position].second_Element<<endl;
        //cout<<pares[position].distance_Element<<endl;   

        return pares[position];     

    }

    
    double get_total_grupo(Grupo grupo, vector<Pair> distances){

        int quantidade = grupo.elementos.size();
        double total = 0;
        Pair par;
        int quantidade_elementos;

        //cout<<"elementos do grupo: "<<endl;
        //for(int i = 0;i<grupo.elementos.size();i++){
        //    cout<<grupo.elementos[i]<<endl;
        //}
        //cout<<endl;
      
        //soma todos os pares de elementos

        //cout<<"quantidade: "<< quantidade<<endl<<endl;
        for(int i=0; i<quantidade-1; i++){
            for(int i2 = i+1;i2<quantidade;i2++){

                //cout<<grupo.elementos[i2]<<endl;

                quantidade_elementos = distances[distances.size()-1].second_Element +1;
                                
                par = get_pair(grupo.elementos[i],grupo.elementos[i2],distances,quantidade_elementos);
               

                //cout<<i<<endl;
                //cout<<"elemento "<<i<<" "<<grupo.elementos[i]<<endl;
                //cout<<i2<<endl;
                //cout<<"elemento "<<i2<<" "<<grupo.elementos[i2]<<endl;

                //cout<<"elemento 1: "<<par.first_Element<<endl;
                //cout<<"elemento 2: "<<par.second_Element<<endl;
                //cout<<"distância: "<<par.distance_Element<<endl<<endl;

                //cout<<"total antes: "<<total<<endl<<endl;
                
                total = total + (double)par.distance_Element; 

                //cout<<"total depois: "<<total<<endl<<endl;
            }
        }
        //cout<<"total do grupo: "<<total<<endl<<endl;
        return total;
    }
    double get_total(vector<Grupo> grupos, vector<Pair> distances){
        double total = 0;
        double a;
        for(int i=0; i<grupos.size();i++){
            a = get_total_grupo(grupos[i], distances);
            total+=a;
        }

        return total;
    }


    //ATENÇÃO. não força a inserção em grupo que ainda não tem o tamanho mínimo cheio
    int get_best_group(vector<Grupo> grupos, int elemento, vector<Pair> distances){
        
        
        //criamos um array resultados com quantidade de grupos tamanho
        //cada posição do array contém um inteiro
        //para cada grupo compara a distância do elemento com x elementos do grupo
        //calcula a média
        //salva o resultado no array resultados
        //retornar o índice da posição que tem o maior valor

        //atenção! grupos ordenados não tem correspondência de índices com grupos desordenados
        //usar o atributo i da classe Grupo para resolver o problema


        //esse array contém, para cada grupo, um valor representando o quão vantajoso é colocar o elemento nesse grupo
        double* resultados = new double[grupos.size()];
        
        bool todos_grupos_cheios=true;
        
        //aqui fica o maior valor do array resultados
        int maior;
        //aqui fica a posição desse valor no array resultados, indicando qual o grupo
        int maior_position;

        int quantidade_elementos;
        quantidade_elementos = distances[distances.size()-1].second_Element +1;

        Pair par;

        //grupos se refere aos grupos disponíveis para alocar elementos. Não ao total de grupos
        //percorremos cada grupo, atribuindo um valor para a posição correspondente no vetor no final
        for(int i = 0; i<grupos.size(); i++){

            resultados[i] = 0;

            if(grupos[i].get_quantidade_elementos()>0){

                for(int i2 = 0; i2 < grupos[i].get_quantidade_elementos();i2++){
                                    
                    par = get_pair(elemento,grupos[i].elementos[i2],distances,quantidade_elementos);
                    resultados[i]+=(double)par.get_distance_Element();
                
                }

                resultados[i] = resultados[i]/(double) grupos[i].get_quantidade_elementos();
            
            }

            if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                resultados[i] =resultados[i]*2;
            }           

            if(grupos[i].get_quantidade_elementos() == grupos[i].tam_maximo){
                resultados[i] = -10;
            }

            else{
                todos_grupos_cheios = false;
            }

        }

        //podemos adicionar um elemento em um grupo vazio, mas não em um grupo cheio
        maior = -5;
        for(int i = 0; i<grupos.size(); i++){
            if(resultados[i] > maior){
                maior = resultados[i];
                maior_position = i;
            }
        }

        if(todos_grupos_cheios){
            cout<<endl<<endl;
            cout<<"ERRO!! NÃO HÁ ESPAÇO"<<endl;
            cout<<endl<<endl;
        }

        delete resultados;       
    
        return grupos[maior_position].i;
        
    }


    //para inserir em grupos que ainda não preencheram o tamanho mínimo
    int get_best_group2(vector<Grupo> grupos, int elemento, vector<Pair> distances){
        
        
        //criamos um array resultados com quantidade de grupos tamanho
        //cada posição do array contém um inteiro
        //para cada grupo compara a distância do elemento com x elementos do grupo
        //calcula a média
        //salva o resultado no array resultados
        //retornar o índice da posição que tem o maior valor

        //atenção! grupos ordenados não tem correspondência de índices com grupos desordenados
        //usar o atributo i da classe Grupo para resolver o problema


        //esse array contém, para cada grupo, um valor representando o quão vantajoso é colocar o elemento nesse grupo
        double* resultados = new double[grupos.size()];
        
        bool todos_grupos_cheios=true;
        
        //aqui fica o maior valor do array resultados
        int maior;
        //aqui fica a posição desse valor no array resultados, indicando qual o grupo
        int maior_position;

        int quantidade_elementos;
        quantidade_elementos = distances[distances.size()-1].second_Element +1;

        Pair par;

        //grupos se refere aos grupos disponíveis para alocar elementos. Não ao total de grupos
        //percorremos cada grupo, atribuindo um valor para a posição correspondente no vetor no final
        for(int i = 0; i<grupos.size(); i++){

            resultados[i] = 0;

            if(grupos[i].get_quantidade_elementos()>0){

                for(int i2 = 0; i2 < grupos[i].get_quantidade_elementos();i2++){
                                    
                    par = get_pair(elemento,grupos[i].elementos[i2],distances,quantidade_elementos);
                    resultados[i]+=(double)par.get_distance_Element();
                
                }

                resultados[i] = resultados[i]/(double) grupos[i].get_quantidade_elementos();
            
            }

            if(grupos[i].get_quantidade_elementos() >=grupos[i].tam_minimo){
                resultados[i] = -10;
            }           

            if(grupos[i].get_quantidade_elementos() == grupos[i].tam_maximo){
                resultados[i] = -20;
            }

            else{
                todos_grupos_cheios = false;
            }

        }

        //podemos adicionar um elemento em um grupo vazio, mas não em um grupo cheio
        maior = -5;
        for(int i = 0; i<grupos.size(); i++){
            if(resultados[i] > maior){
                maior = resultados[i];
                maior_position = i;
            }
        }

        if(todos_grupos_cheios){
            cout<<endl<<endl;
            cout<<"ERRO!! NÃO HÁ ESPAÇO"<<endl;
            cout<<endl<<endl;
        }

        delete resultados;       
    
        return grupos[maior_position].i;
        
    }



    //igual o get_best_group, mas aumenta o valor para um grupo proporcionalmente
    //ao tamanho máximo do grupo
    int get_best_group3(vector<Grupo> grupos, int elemento, vector<Pair> distances){
        
        
        //criamos um array resultados com quantidade de grupos tamanho
        //cada posição do array contém um inteiro
        //para cada grupo compara a distância do elemento com x elementos do grupo
        //calcula a média
        //salva o resultado no array resultados
        //retornar o índice da posição que tem o maior valor

        //atenção! grupos ordenados não tem correspondência de índices com grupos desordenados
        //usar o atributo i da classe Grupo para resolver o problema


        //esse array contém, para cada grupo, um valor representando o quão vantajoso é colocar o elemento nesse grupo
        double* resultados = new double[grupos.size()];
        
        bool todos_grupos_cheios=true;
        
        //aqui fica o maior valor do array resultados
        int maior;
        //aqui fica a posição desse valor no array resultados, indicando qual o grupo
        int maior_position;

        int quantidade_elementos;
        quantidade_elementos = distances[distances.size()-1].second_Element +1;

        Pair par;

        //grupos se refere aos grupos disponíveis para alocar elementos. Não ao total de grupos
        //percorremos cada grupo, atribuindo um valor para a posição correspondente no vetor no final
        for(int i = 0; i<grupos.size(); i++){

            resultados[i] = 0;

            if(grupos[i].get_quantidade_elementos()>0){

                for(int i2 = 0; i2 < grupos[i].get_quantidade_elementos();i2++){
                                    
                    par = get_pair(elemento,grupos[i].elementos[i2],distances,quantidade_elementos);
                    resultados[i]+=(double)par.get_distance_Element();
                
                }

                resultados[i] = resultados[i]/(double) grupos[i].get_quantidade_elementos();
            
            }

            resultados[i] = resultados[i] * ( (double)      ( 1.0 + (double)(   ((double)grupos[i].tam_maximo)/ ((double)quantidade_elementos/10.0)  )   )  ) ;

            if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                resultados[i] =resultados[i]*2;
            }           

            if(grupos[i].get_quantidade_elementos() == grupos[i].tam_maximo){
                resultados[i] = -10;
            }

            else{
                todos_grupos_cheios = false;
            }

        }

        //podemos adicionar um elemento em um grupo vazio, mas não em um grupo cheio
        maior = -5;
        for(int i = 0; i<grupos.size(); i++){
            if(resultados[i] > maior){
                maior = resultados[i];
                maior_position = i;
            }
        }

        if(todos_grupos_cheios){
            cout<<endl<<endl;
            cout<<"ERRO!! NÃO HÁ ESPAÇO"<<endl;
            cout<<endl<<endl;
        }

        delete resultados;       
    
        return grupos[maior_position].i;
        
    }




};






class Solution
{
public:
    Instance instance;
    double resultado;
    vector<Grupo> solucao;
    
    Solution() {
        cout << "SOLUTION INICIADA";
    }
    Solution(Instance instance)
    {
        this->instance = instance;
    }

    //distribui os elementos aleatoriamente para ter um resultado ruim para comparar com a heurística
    vector<Grupo> calcular_resultado_ruim(){

        Funcoes funcoes;

        vector<int> elementos;        
        elementos = funcoes.get_elementos(instance.arr_Pair);      

        vector<Grupo> grupos;
        grupos = funcoes.get_grupos(instance);

        while(elementos.size()>0){
            for(int i = 0; i<instance.quant_Grup;i++){
                if(grupos[i].elementos.size() <grupos[i].tam_minimo){
                    grupos[i].elementos.push_back(elementos[elementos.size()-1]);
                    elementos.pop_back();
                }
            } 
            for(int i = 0; i<instance.quant_Grup;i++){
                if(elementos.size()==0){break;}
                if(grupos[i].elementos.size() <grupos[i].tam_maximo){
                    grupos[i].elementos.push_back(elementos[elementos.size()-1]);
                    elementos.pop_back();
                }
            } 
        }    
        return grupos;      
/*
        vector<Grupo> grupos_restantes = grupos;
        int tamanho_grupos_restantes = this->instance.quant_Grup;

        vector<int> elementos_restantes = elementos;
        int tamanho_elementos_restantes = instance.quant_Elem;

        //vector<int> elementos2;

        int random;

        int random_grupo;

        //nessa etapa preenchemos os grupos até todos terem o tamanho mínimo 
        bool fase1 = true;

        bool passando = false;

        //nessa etapa preenchemos os grupos até colocarmos todos os elementos em algum grupo
        bool fase2 = false;

        //distribui todos os elementos pelos grupos
        while(tamanho_elementos_restantes>0){

            random = rand()%tamanho_elementos_restantes -1;

            if(random<0){random = 0;}

            //cout<<elementos_restantes[random]<<endl;
            //elementos2.push_back(elementos_restantes[random]);

            //caso todos os grupos já tem a quantidade de elementos do tamanho mínimo 
            if(tamanho_grupos_restantes == 0 and fase1){
                cout<<"todos os grupos tem tamanho mínimo preenchido"<<endl;
                fase1 = false;
                passando = true;

            }

            //preenchemos os grupos garantindo que todos tenham o tamanho mínimo preenchido
            if(fase1){
                //coloca o elemento em um grupo
                random_grupo= rand()%tamanho_grupos_restantes;

                if(random_grupo<0){random_grupo=0;}            

                //cout<<"elementos no grupo: "<< grupos_restantes[random_grupo].quantidade_elementos<<endl;


                //adiciona o elemento no grupo cujo índice corresponde ao grupo da lista de grupos que ainda não estão cheios
                funcoes.alocar_elemento(grupos[grupos_restantes[random_grupo].i],elementos_restantes,random);  
            
                grupos_restantes[random_grupo].quantidade_elementos+=1;                  

                //se o grupo tiver passado o tamanho mínimo tiramos ele da lista de grupos restantes
                if(grupos_restantes[random_grupo].quantidade_elementos >= grupos_restantes[random_grupo].tam_minimo){
                    cout<<"grupo passou o tamanho mínimo"<<endl;
                    cout<<"tamanho mínimo: "<<grupos_restantes[random_grupo].tam_minimo<<endl;
                    cout<<"quantidade de elementos: "<<grupos_restantes[random_grupo].quantidade_elementos<<endl;
                    grupos_restantes.erase(grupos_restantes.begin()+random_grupo);
                    tamanho_grupos_restantes-=1;
                }  
                         

                tamanho_elementos_restantes -=1;
                //elementos_restantes.erase(elementos_restantes.begin()+random);

            }

            if(passando){

                tamanho_grupos_restantes = instance.quant_Grup;
                grupos_restantes = grupos;

                //removemos os grupos cujo tamanho mínimo é igual ao tamanho máximo
                for(int i = 0; i<instance.quant_Grup;i++){
                    if(grupos[i].tam_minimo == grupos[i].tam_maximo){

                        grupos_restantes.erase(grupos_restantes.begin()+i);
                        tamanho_grupos_restantes-=1;

                    }
                }



                //restam os grupos onde ainda é possível adicionar elementos

                passando = false;
                fase2 = true;

            }

            if(fase2){                
                
                if(tamanho_grupos_restantes >0){
                    //adicionar elementos até ter adicionado todos os elementos em algum grupo

                    //coloca o elemento em um grupo
                    random_grupo= rand()%tamanho_grupos_restantes;

                    if(random_grupo<0){random_grupo=0;}            

                    //cout<<"elementos no grupo: "<< grupos_restantes[random_grupo].quantidade_elementos<<endl;


                    //adiciona o elemento no grupo cujo índice corresponde ao grupo da lista de grupos que ainda não estão cheios
                    funcoes.alocar_elemento(grupos[grupos_restantes[random_grupo].i],elementos_restantes,random);  
            
                    grupos_restantes[random_grupo].quantidade_elementos+=1;                  

                    //se o grupo tiver cheio tiramos ele da lista de grupos restantes
                    if(grupos_restantes[random_grupo].quantidade_elementos >= grupos_restantes[random_grupo].tam_maximo){
                        cout<<"grupo passou o tamanho mínimo"<<endl;
                        cout<<"tamanho mínimo: "<<grupos_restantes[random_grupo].tam_maximo<<endl;
                        cout<<"quantidade de elementos: "<<grupos_restantes[random_grupo].quantidade_elementos<<endl;
                        grupos_restantes.erase(grupos_restantes.begin()+random_grupo);
                        tamanho_grupos_restantes-=1;
                    }                           

                    tamanho_elementos_restantes -=1;
                    //elementos_restantes.erase(elementos_restantes.begin()+random);

                }
                else{
                    break;
                }

            }

        }      

        return grupos; 

        //cout<<"elementos distribuídos: "<<endl;
        //elementos distribuídos
        //for(int i = 0;i<instance.quant_Elem;i++){
        //    cout<<elementos2[i]<<endl;
        //}


        */
        
    }

    vector<Grupo> calcular_resultado(){


        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        //Lista_elementos lista_elementos(quantidade_elementos);

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl;
        //}

        int space = 0;
        

        //nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        while(while1){
            while1 = false;
            for(int i = 0;i<grupos.size();i++){
                if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                    funcoes.alocar_elemento(grupos[i],elementos,elementos.back());
                    while1=true;
                }

            }

        }

        //adiciona os elementos restantes nas melhores posições
        while(elementos.size()>0){
            int position = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());

        }
        

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl; 
        //}

      

        return grupos;



    }


    
    vector<Grupo> calcular_resultado2(){


        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        //Lista_elementos lista_elementos(quantidade_elementos);

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl;
        //}

        int space = 0;
        for(int i = 0; i <grupos.size(); i++){
            space+= grupos[i].tam_minimo;
        }

        //cout<<"espaço: "<<space<<endl<<endl;
        

        //nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        bool primeira_vez_no_while = true;

        while(while1){
            while1 = false;

            //se espaço é igual a quantidade restante de elementos, então
            //necessariamente precisamos alocar elementos em grupos
            //que ainda não tiveram o tamanho mínimo preenchido
            if(space == elementos.size() or primeira_vez_no_while){

                primeira_vez_no_while = false;

                //cout<<"caso 1"<<endl;

                for(int i = 0;i<grupos.size();i++){

                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){

                        funcoes.alocar_elemento(grupos[i],elementos,elementos.back());
                        space-=1;
                        //cout<<"espaço agora: "<<space<<endl;
                        //cout<<"quantidade de elementos para alocar: "<< elementos.size()<<endl<<endl;
                        while1=true;
                    }
                }
            }
            else{

                for(int i = 0;i<grupos.size();i++){
                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                        while1=true;
                    }
                }

                int position = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());
                if(grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo){
                    space-=1;
                }

            }
            

        }

        //adiciona os elementos restantes nas melhores posições
        while(elementos.size()>0){
            int position = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());

        }
        

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl; 
        //}

        //cout<<"espaço no final: "<<space<<endl;

      

        return grupos;



    }








    vector<Grupo> calcular_resultado3(){


        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        //Lista_elementos lista_elementos(quantidade_elementos);

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl;
        //}

        int space = 0;
        for(int i = 0; i <grupos.size(); i++){
            space+= grupos[i].tam_minimo;
        }

        //cout<<"espaço: "<<space<<endl<<endl;
        

        //nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        //bool primeira_vez_no_while = true;

        while(while1){
            while1 = false;

            //se espaço é igual a quantidade restante de elementos, então
            //necessariamente precisamos alocar elementos em grupos
            //que ainda não tiveram o tamanho mínimo preenchido
            if(space == elementos.size() ){
            
                //cout<<"caso 1"<<endl;

                for(int i = 0;i<grupos.size();i++){

                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    //e adicionamos um elemento no grupo que não tem o
                    //tamanho mínimo preenchido
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){

                        funcoes.alocar_elemento(grupos[i],elementos,elementos.back());
                        space-=1;
                        //cout<<"espaço agora: "<<space<<endl;
                        //cout<<"quantidade de elementos para alocar: "<< elementos.size()<<endl<<endl;
                        while1=true;
                    }
                }
            }
            else{

                for(int i = 0;i<grupos.size();i++){
                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                        while1=true;
                    }
                }

                int position = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());
                if(grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo){
                    space-=1;
                }
            }           

        }

        //adiciona os elementos restantes nas melhores posições
        while(elementos.size()>0){
            int position = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());

        }        

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl; 
        //}

        //cout<<"espaço no final: "<<space<<endl;      

        return grupos;

    }












    vector<Grupo> calcular_resultado4(){


        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        //Lista_elementos lista_elementos(quantidade_elementos);

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl;
        //}

        int space = 0;
        for(int i = 0; i <grupos.size(); i++){
            space+= grupos[i].tam_minimo;
        }

        //cout<<"espaço: "<<space<<endl<<endl;
        

        //nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        bool primeira_vez_no_while = true;

        while(while1){
            while1 = false;

            //se espaço é igual a quantidade restante de elementos, então
            //necessariamente precisamos alocar elementos em grupos
            //que ainda não tiveram o tamanho mínimo preenchido
            if(space == elementos.size() or primeira_vez_no_while){

                if(primeira_vez_no_while){
                    for(int i = 0;i<grupos.size();i++){

                        //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                        if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){

                            funcoes.alocar_elemento(grupos[i],elementos,elementos.back());
                            space-=1;
                            //cout<<"espaço agora: "<<space<<endl;
                            //cout<<"quantidade de elementos para alocar: "<< elementos.size()<<endl<<endl;
                            while1=true;
                        }
                    }

                }

                primeira_vez_no_while = false;

                //cout<<"caso 1"<<endl;

                for(int i = 0;i<grupos.size();i++){

                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){

                        int position = funcoes.get_best_group2(grupos,elementos.back(),instance.arr_Pair);
                        funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());                               
                    
                        space-=1;
                        //cout<<"espaço agora: "<<space<<endl;
                        //cout<<"quantidade de elementos para alocar: "<< elementos.size()<<endl<<endl;
                        while1=true;
                    }
                }
            }
            else{

                for(int i = 0;i<grupos.size();i++){
                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                        while1=true;
                    }
                }

                int position = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());
                if(grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo){
                    space-=1;
                }

            }
            

        }

        //adiciona os elementos restantes nas melhores posições
        while(elementos.size()>0){
            int position = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());

        }
        

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl; 
        //}

        //cout<<"espaço no final: "<<space<<endl;

      

        return grupos;



    }





    vector<Grupo> calcular_resultado5(){


        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        //Lista_elementos lista_elementos(quantidade_elementos);

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl;
        //}

        int space = 0;
        for(int i = 0; i <grupos.size(); i++){
            space+= grupos[i].tam_minimo;
        }

        //cout<<"espaço: "<<space<<endl<<endl;
        

        //nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        bool primeira_vez_no_while = true;

        while(while1){
            while1 = false;

            //se espaço é igual a quantidade restante de elementos, então
            //necessariamente precisamos alocar elementos em grupos
            //que ainda não tiveram o tamanho mínimo preenchido
            if(space == elementos.size() or primeira_vez_no_while){

                if(primeira_vez_no_while){
                    for(int i = 0;i<grupos.size();i++){

                        //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                        if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){

                            funcoes.alocar_elemento(grupos[i],elementos,elementos.back());
                            space-=1;
                            //cout<<"espaço agora: "<<space<<endl;
                            //cout<<"quantidade de elementos para alocar: "<< elementos.size()<<endl<<endl;
                            while1=true;
                        }
                    }

                }

                primeira_vez_no_while = false;

                //cout<<"caso 1"<<endl;

                for(int i = 0;i<grupos.size();i++){

                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){

                        int position = funcoes.get_best_group3(grupos,elementos.back(),instance.arr_Pair);
                        funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());                               
                    
                        space-=1;
                        //cout<<"espaço agora: "<<space<<endl;
                        //cout<<"quantidade de elementos para alocar: "<< elementos.size()<<endl<<endl;
                        while1=true;
                    }
                }
            }
            else{

                for(int i = 0;i<grupos.size();i++){
                    //se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                        while1=true;
                    }
                }

                int position = funcoes.get_best_group3(grupos,elementos.back(),instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());
                if(grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo){
                    space-=1;
                }

            }
            

        }

        //adiciona os elementos restantes nas melhores posições
        while(elementos.size()>0){
            int position = funcoes.get_best_group3(grupos,elementos.back(),instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i],elementos,elementos.back());

        }
        

        //for(int i = 0;i <quantidade_elementos;i++){
        //    cout<<elementos[i]<<endl; 
        //}

        //cout<<"espaço no final: "<<space<<endl;      

        return grupos;


    }
    

};








/*


        
        Funcoes funcoes;

        vector<int> elementos = funcoes.get_elementos(this->instance.arr_Pair);
        Lista_elementos lista_elementos(elementos.size());

        vector<Grupo> grupos = funcoes.get_grupos(instance);


        int quantidade_minimo_elementos = 0;   
        int total_space = 0;  

        int position_grupo;
        for(int i =0; i<grupos.size();i++){
            quantidade_minimo_elementos+=grupos[i].tam_minimo;
        }
        cout<<quantidade_minimo_elementos<<endl<<endl<<endl<<endl;
        for(int i =0; i<grupos.size();i++){
            total_space+=grupos[i].tam_maximo;
        }
 
        vector<Pair> distancias_ordenadas = this->instance.arr_Pair;
               
        vector<Grupo> grupos_ordenados_por_tamanho_maximo = grupos;
        vector<Grupo> grupos_ordenados_por_tamanho_minimo = grupos;       

        vector<Grupo> solucao;

        double media;

        
       
      
        int tamanho = instance.arr_Pair.size();

        cout<<endl<<endl<<endl;
        cout<<"ordenando elementos por distância: "<<endl;

        funcoes.ordenar_distancias(distancias_ordenadas);

        for(int i = 0; i<tamanho-1;i++){
            cout<<distancias_ordenadas[i].first_Element<<endl;
            cout<<distancias_ordenadas[i].second_Element<<endl;
            cout<<distancias_ordenadas[i].distance_Element<<endl;               
                      
        }
        
        
        for(int i = 0; i<tamanho-1;i++){
            cout<<this->instance.arr_Pair[i].first_Element<<endl;
            cout<<this->instance.arr_Pair[i].second_Element<<endl;
            cout<<this->instance.arr_Pair[i].distance_Element<<endl;                                
        }
        
        cout<<"elementos ordenados."<<endl;

        cout<<"ordenando grupos por tamanho máximo"<<endl;

        funcoes.ordenar_tam_maximo(grupos_ordenados_por_tamanho_maximo);

        for(int i= 0; i <instance.quant_Grup;i++){
            cout<<grupos_ordenados_por_tamanho_maximo[i].tam_maximo<<endl;
        }

        cout<<"ordenando grupos por tamanho mínimo"<<endl;

        funcoes.ordenar_tam_minimo(grupos_ordenados_por_tamanho_minimo);

        for(int i= 0; i <instance.quant_Grup;i++){
            cout<<grupos_ordenados_por_tamanho_minimo[i].tam_minimo<<endl;
        }

        bool caso2 = false;


        //deixando cada grupo com pelo menos 1 elemento
        for(int i =0; i<grupos.size();i++){
            funcoes.alocar_elemento2(grupos[i],lista_elementos,lista_elementos.elementos[i]);
             
            if(grupos[i].elementos.size()<=grupos[i].tam_minimo){
                quantidade_minimo_elementos =quantidade_minimo_elementos- 1;
            }

        }



        while(lista_elementos.get_tamanho()>0){

            //nesse caso corremos o risco de não preencher os tamanhos mínimos
            if(lista_elementos.get_tamanho() == quantidade_minimo_elementos or caso2){
                caso2 = true;

                bool ainda_tem_grupo_sem_preencher_elementos_minimos = true;

                while(ainda_tem_grupo_sem_preencher_elementos_minimos){
                    ainda_tem_grupo_sem_preencher_elementos_minimos = false;
                    for(int i = 0;i<grupos.size();i++){
                        if(grupos[i].get_quantidade_elementos() <grupos[i].tam_minimo){
                            funcoes.alocar_elemento2(grupos[i],lista_elementos,elementos.back());
                            elementos.pop_back();
                            ainda_tem_grupo_sem_preencher_elementos_minimos = true;

                        }
                    }


                }




                break;
            }

            else{                
                               
                //verifica se o elemento já foi removido
                if(lista_elementos.elementos[elementos.back()] == false){
                    //elemento já foi alocado para algum grupo
                    elementos.pop_back();
                    continue;
                }

                else{

                    //cout<<quantidade_minimo_elementos<<endl;
                     

                        if(lista_elementos.elementos[elementos.back()] == false ){
                           
                            cout<<"elemento repetido: "<<elementos.back()<<endl;
                            elementos.pop_back();
                            continue;
                        }

                        position_grupo = funcoes.get_best_group(grupos,elementos.back(),instance.arr_Pair);
                        //quantidade_minimo_elementos = funcoes.alocar_elemento3(grupos[grupos[position_grupo].i],lista_elementos,elementos,elementos.back(),quantidade_minimo_elementos);
                        funcoes.alocar_elemento2(grupos[grupos[position_grupo].i],lista_elementos,elementos.back());
                        
                        if(grupos[grupos[position_grupo].i].elementos.size()<=grupos[grupos[position_grupo].i].tam_minimo){
                            quantidade_minimo_elementos =quantidade_minimo_elementos- 1;
                        }

                    
                    

                }

            }

        }

        return grupos;

    //ordenar elementos por distância

    //calcular média de distâncias (somar todas e dividir por M(M-1)/2)

    //ordenar grupos por tamanho máximo

    //para cada elemento a ser inserido em um grupo criar vector de inteiros que indica, 
    //para cada grupo, quantos elementos 
    //já inseridos nesse grupos tem uma distância maior que a média em relação ao elemento analizado

    //o valor maior indica o grupo em que o elemento será inserido

    */

