#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int low, int high){

    // here pivot is the last element (not last index)
    int pivot = arr[high];
    // i carries the absolute position of sorting to place the elements sorted
    int i = low-1;       

    for(int j=low; j<high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // put the pivot between its lowers & highers
    swap(arr[high], arr[i+1]);
    
    // return the pos of pivot
    return (i+1);
}


void quickSort(int arr[], int low, int high){
    if (low<high){
        int pi = partition(arr, low, high); // partition index
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


int main(){
    int x[] = {3,2,33,0,-1};
    int size = sizeof(x) / sizeof(x[0]);

    quickSort(x, 0, size-1);

    for (int i=0; i<size; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}