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
//Function Name: orderByMergeSort;
//Parameters: int array[] -> an array; int sizeArray -> the size of the array being received;
//Complexity: ;
void orderByMergeSort(int array[], int sizeArray){
    
}
//-------------------------------------------------------------------


int main(){
    int isOrdered = 0;
    int decision = 1;

    while(decision != 0){
    int sizeArray;
    cin >> sizeArray;
    int array[sizeArray];
        for(int i = 0; i < sizeArray; ++i){
            cin >> array[i];
        }
        isOrdered = isOrder(array, sizeArray);
        if(isOrdered == 0){
            orderByInsertion(array, sizeArray);
            isOrdered = isOrder(array, sizeArray);
            printArray(array, sizeArray);
        }
        cout << isOrdered << endl;
    }
}