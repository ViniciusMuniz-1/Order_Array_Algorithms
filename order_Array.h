#ifndef ORDER_ARRAY
#define ORDER_ARRAY

/*
  Função que retorna se um vetor 'a' de 't' elementos 
  está ordenado não decrescentemente

  Retorno: 0 Se 'a' não estiver ordenado
           1 caso contrário
*/
int isOrder(int array[], int sizeArray);

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por seleção.
  A ordenação é feita diretamente no vetor 'a'
*/
void orderBySelection(int array[], int sizeArray);

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por inserção.
  A ordenação é feita diretamente no vetor 'a'
*/
void orderByInsertion(int array[], int sizeArray);

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método merge sort.
  A ordenação é feita diretamente no vetor 'a'
*/
void orderByMergeSort(int array[], int sizeArray);

#endif