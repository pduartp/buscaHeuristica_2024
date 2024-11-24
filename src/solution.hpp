#pragma once

#include <iostream>
#include <algorithm>

#include "instance.hpp"
#include "pair.hpp"
#include "grupo.hpp"
#include "lista_elementos.hpp"
#include "funcoes.hpp"

using namespace std;
class Solution
{
public:
    Instance instance;
    double resultado;
    vector<Grupo> solucao;

    Solution()
    {
        cout << "SOLUTION INICIADA";
    }
    Solution(Instance instance)
    {
        this->instance = instance;
    }

    // distribui os elementos aleatoriamente para ter um resultado ruim para comparar com a heurística
    vector<Grupo> calcular_resultado_ruim()
    {

        Funcoes funcoes;

        vector<int> elementos;
        elementos = funcoes.get_elementos(instance.arr_Pair);

        vector<Grupo> grupos;
        grupos = funcoes.get_grupos(instance);

        while (elementos.size() > 0)
        {
            for (int i = 0; i < instance.quant_Grup; i++)
            {
                if (grupos[i].elementos.size() < grupos[i].tam_minimo)
                {
                    grupos[i].elementos.push_back(elementos[elementos.size() - 1]);
                    elementos.pop_back();
                }
            }
            for (int i = 0; i < instance.quant_Grup; i++)
            {
                if (elementos.size() == 0)
                {
                    break;
                }
                if (grupos[i].elementos.size() < grupos[i].tam_maximo)
                {
                    grupos[i].elementos.push_back(elementos[elementos.size() - 1]);
                    elementos.pop_back();
                }
            }
        }

        return grupos;
    }

    vector<Grupo> calcular_resultado()
    {

        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        int space = 0;

        // nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        while (while1)
        {
            while1 = false;
            for (int i = 0; i < grupos.size(); i++)
            {
                if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                {
                    funcoes.alocar_elemento(grupos[i], elementos, elementos.back());
                    while1 = true;
                }
            }
        }

        // adiciona os elementos restantes nas melhores posições
        while (elementos.size() > 0)
        {
            int position = funcoes.get_best_group(grupos, elementos.back(), instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
        }

        return grupos;
    }

    vector<Grupo> calcular_resultado2()
    {

        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        int space = 0;
        for (int i = 0; i < grupos.size(); i++)
        {
            space += grupos[i].tam_minimo;
        }

        bool while1 = true;
        bool primeira_vez_no_while = true;

        while (while1)
        {
            while1 = false;

            if (space == elementos.size() or primeira_vez_no_while)
            {

                primeira_vez_no_while = false;

                for (int i = 0; i < grupos.size(); i++)
                {
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {

                        funcoes.alocar_elemento(grupos[i], elementos, elementos.back());
                        space -= 1;
                        while1 = true;
                    }
                }
            }
            else
            {

                for (int i = 0; i < grupos.size(); i++)
                {
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {
                        while1 = true;
                    }
                }

                int position = funcoes.get_best_group(grupos, elementos.back(), instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
                if (grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo)
                {
                    space -= 1;
                }
            }
        }

        while (elementos.size() > 0)
        {
            int position = funcoes.get_best_group(grupos, elementos.back(), instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
        }

        return grupos;
    }

    vector<Grupo> calcular_resultado3()
    {

        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);
        int space = 0;

        for (int i = 0; i < grupos.size(); i++)
        {
            space += grupos[i].tam_minimo;
        }

        // nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;

        while (while1)
        {
            while1 = false;

            // se espaço é igual a quantidade restante de elementos, então
            // necessariamente precisamos alocar elementos em grupos
            // que ainda não tiveram o tamanho mínimo preenchido
            if (space == elementos.size())
            {

                // cout<<"caso 1"<<endl;

                for (int i = 0; i < grupos.size(); i++)
                {

                    // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    // e adicionamos um elemento no grupo que não tem o
                    // tamanho mínimo preenchido
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {

                        funcoes.alocar_elemento(grupos[i], elementos, elementos.back());
                        space -= 1;
                        while1 = true;
                    }
                }
            }
            else
            {
                for (int i = 0; i < grupos.size(); i++)
                {
                    // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {
                        while1 = true;
                    }
                }

                int position = funcoes.get_best_group(grupos, elementos.back(), instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
                if (grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo)
                {
                    space -= 1;
                }
            }
        }

        // adiciona os elementos restantes nas melhores posições
        while (elementos.size() > 0)
        {
            int position = funcoes.get_best_group(grupos, elementos.back(), instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
        }

        return grupos;
    }

    vector<Grupo> calcular_resultado4()
    {

        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);

        int space = 0;
        for (int i = 0; i < grupos.size(); i++)
        {
            space += grupos[i].tam_minimo;
        }

        // nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        bool primeira_vez_no_while = true;

        while (while1)
        {
            while1 = false;

            // se espaço é igual a quantidade restante de elementos, então
            // necessariamente precisamos alocar elementos em grupos
            // que ainda não tiveram o tamanho mínimo preenchido
            if (space == elementos.size() or primeira_vez_no_while)
            {

                if (primeira_vez_no_while)
                {
                    for (int i = 0; i < grupos.size(); i++)
                    {

                        // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                        if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                        {

                            funcoes.alocar_elemento(grupos[i], elementos, elementos.back());
                            space -= 1;
                            while1 = true;
                        }
                    }
                }

                primeira_vez_no_while = false;

                for (int i = 0; i < grupos.size(); i++)
                {

                    // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {

                        int position = funcoes.get_best_group2(grupos, elementos.back(), instance.arr_Pair);
                        funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());

                        space -= 1;
                        while1 = true;
                    }
                }
            }
            else
            {

                for (int i = 0; i < grupos.size(); i++)
                {
                    // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {
                        while1 = true;
                    }
                }

                int position = funcoes.get_best_group(grupos, elementos.back(), instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
                if (grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo)
                {
                    space -= 1;
                }
            }
        }

        // adiciona os elementos restantes nas melhores posições
        while (elementos.size() > 0)
        {
            int position = funcoes.get_best_group(grupos, elementos.back(), instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
        }

        return grupos;
    }

    vector<Grupo> calcular_resultado5()
    {

        Funcoes funcoes;

        int quantidade_elementos = instance.quant_Elem;
        vector<int> elementos = funcoes.get_elementos(instance.arr_Pair);
        vector<Grupo> grupos = funcoes.get_grupos(instance);
        int space = 0;

        for (int i = 0; i < grupos.size(); i++)
        {
            space += grupos[i].tam_minimo;
        }

        // nessa etapa garantimos que todos os tamanhos mínimos foram preenchidos
        bool while1 = true;
        bool primeira_vez_no_while = true;

        while (while1)
        {
            while1 = false;

            if (space == elementos.size() or primeira_vez_no_while)
            {

                if (primeira_vez_no_while)
                {
                    for (int i = 0; i < grupos.size(); i++)
                    {

                        // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                        if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                        {

                            funcoes.alocar_elemento(grupos[i], elementos, elementos.back());
                            space -= 1;
                            while1 = true;
                        }
                    }
                }

                primeira_vez_no_while = false;

                for (int i = 0; i < grupos.size(); i++)
                {

                    // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {
                        int position = funcoes.get_best_group3(grupos, elementos.back(), instance.arr_Pair);
                        funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());

                        space -= 1;
                        while1 = true;
                    }
                }
            }
            else
            {

                for (int i = 0; i < grupos.size(); i++)
                {
                    // se ainda tem grupos sem tamanho mínimo preenchido continuamos no while
                    if (grupos[i].get_quantidade_elementos() < grupos[i].tam_minimo)
                    {
                        while1 = true;
                    }
                }

                int position = funcoes.get_best_group3(grupos, elementos.back(), instance.arr_Pair);
                funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
                if (grupos[grupos[position].i].get_quantidade_elementos() <= grupos[grupos[position].i].tam_minimo)
                {
                    space -= 1;
                }
            }
        }

        // adiciona os elementos restantes nas melhores posições
        while (elementos.size() > 0)
        {
            int position = funcoes.get_best_group3(grupos, elementos.back(), instance.arr_Pair);
            funcoes.alocar_elemento(grupos[grupos[position].i], elementos, elementos.back());
        }

        return grupos;
    }
};