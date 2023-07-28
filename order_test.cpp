#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "order_Array.h"

const int SELECAO = 1;
const int INSERCAO = 2;
const int MERGE_SORT = 3;

void print_usage() {
    std::cout << "Programa para ordenação de números inteiros.\n\n";
    std::cout << "\tUso: teste_ordenacao [Opção]\n\n";
    std::cout << "Onde 'Opção' é uma das opções a seguir:\n\n";
    std::cout << "\t -s: ordenação por seleção (padrão).\n";
    std::cout << "\t -i: ordenação por inserção.\n";
    std::cout << "\t -h: Mostra instruções de uso do programa.\n\n";
}

int define_metodo(int argc, char** argv) {
    int metodo = MERGE_SORT;
    if (argc > 2) {
        std::cerr << "*** Quantidade de parâmetros inválidos *** \n\n";
        print_usage();
        exit(1);
    }
    if (argc == 2) {
        std::string arg = argv[1];
        if (arg == "-h") {
            print_usage();
            exit(0);
        }
        else if (arg == "-s") {
            metodo = SELECAO;
            std::cerr << "Método seleção usado para ordenação.\n";
        }
        else if (arg == "-i") {
            metodo = INSERCAO;
            std::cerr << "Método inserção usado para ordenação.\n";
        }
        else {
            print_usage();
            exit(2);
        }
    }
    return metodo;
}

int main(int argc, char** argv) {
    int size, i, metodo = define_metodo(argc, argv);

    double inicio, fim, tempo_passado;   
    std::cin >> size;

    int array[size];

    for (i = 0; i < size; ++i)
        std::cin >> array[i];

    inicio = clock();
    switch (metodo) {
        case 1:
            orderBySelection(array, size);
            break;
        case 2:
            orderByInsertion(array, size);
            break;
        case 3:
            orderByMergeSort(array, 0, size-1);
    }
    fim = clock();
    tempo_passado = (fim - inicio) / static_cast<double>(CLOCKS_PER_SEC); // Convertendo para segundos
    std::cerr << "Tempo usado para ordenação: " << tempo_passado << " segundos.\n";

    if (!isOrder(array, size)) {
        std::cerr << "\033[0;31mErro:\033[0m Array não ordenado. Saindo...\n";
        exit(-1);
    }

    //printArray(array, size);
    return 0;
}
