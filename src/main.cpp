#include <iostream>
#include <locale>
#include <fstream>
#include <sstream>
#include <vector>

#include "instancia.hpp"
#include "pair.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    Instancia instancia;

    instancia.read_File("instances/Geo/Geo_n010_ds_01.txt");

    // Para verificar se os dados foram lidos corretamente
    instancia.to_String();
    return 0;
}
