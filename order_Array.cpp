#include <iostream>

using namespace std;

int INF = 1e9;

//-------------------------------------------------------------------
//Function Name: printArray;
//Parameters: int array[] -> an array; int sizeArray -> the size of the array being received;
void printArray(int array[], int sizeArray){
    if(sizeArray > 0){
        cout << "[";
        for(int i = 0; i < sizeArray; ++i){
            cout << " " << array[i];
        }
        cout << " ]" << endl;
    }
}
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//Function Name: isOrder;
//Parameters: int array[] -> an array; int sizeArray -> the size of the array being received;
//Return: a boolean saying whether the array is sorted in ascending order or not;
int isOrder(int array[], int sizeArray){
    int isOrder = 1;                     
    for(int i = 1; i < sizeArray; ++i){
        if(array[i-1] > array[i]){
            isOrder = 0;
            break;
        }
    }
    return isOrder;
}
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//Function Name: orderBySelection;
//Parameters: int array[] -> an array; int sizeArray -> the size of the array being received;
//Complexity: O(n²);
void orderBySelection(int array[], int sizeArray){
    int indexLowestValue, aux;
    for(int index = 0; index < sizeArray; index++){
        indexLowestValue = index;
        for(int nextIndex = index+1; nextIndex < sizeArray; nextIndex++){
            if(array[nextIndex] < array[indexLowestValue]){
                indexLowestValue = nextIndex;
            }
        }
        if(array[index] != array[indexLowestValue]){
            aux = array[index];
            array[index] = array[indexLowestValue];
            array[indexLowestValue] = aux;
        }
    }
}
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//Function Name: orderByInsertion;
//Parameters: int array[] -> an array; int sizeArray -> the size of the array being received;
//Complexity: O(n²);
void orderByInsertion(int array[], int sizeArray){
    for (int index = 1; index < sizeArray; index++) {
        int currentValue = array[index];
        int previousIndex = index - 1;

        while (previousIndex >= 0 && array[previousIndex] > currentValue) {
            array[previousIndex + 1] = array[previousIndex];
            previousIndex--;
        }

        array[previousIndex + 1] = currentValue;
    }
}
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//Function Name: merge;
//Parameters: int array[] -> an array; int firstElem -> the first element of the array; int lastElem -> the last element of the array;
//Complexity: O(n);
void merge(int array[], int firstIndex, int mid1, int mid2, int lastIndex) {
    int size1 = (mid1 - firstIndex) + 1;
    int size2 = (lastIndex - mid2) + 1;
    int* temp = new int[size1 + size2];
    int i = firstIndex;
    int j = mid2;
    int k = 0;

    while (i <= mid1 && j <= lastIndex) {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid1)
        temp[k++] = array[i++];
    while (j <= lastIndex)
        temp[k++] = array[j++];

    for (i = 0, j = firstIndex; i < size1 + size2; i++, j++)
        array[j] = temp[i];

    delete[] temp;
}
//-------------------------------------------------------------------


//-------------------------------------------------------------------
//Function Name: orderByMergeSort;
//Parameters: int array[] -> an array; int firstIndex -> the first index of the array; int lastIndex -> the last index of the array;
//Complexity: O(n log n);
void orderByMergeSort(int array[], int firstIndex, int lastIndex){
    int mid;
    if(firstIndex<lastIndex) {
        mid=(firstIndex+lastIndex)/2;
        orderByMergeSort(array, firstIndex, mid);
        orderByMergeSort(array, mid+1, lastIndex);
        merge(array, firstIndex, mid, mid+1, lastIndex);
    }
}
//-------------------------------------------------------------------
