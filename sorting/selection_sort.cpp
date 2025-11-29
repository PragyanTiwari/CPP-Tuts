#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void SelectionSort(int arr[], int n){
    int min_i;
    // i loop controls the sorted list
    for (int i=0; i<n-1; i++){
        min_i = i;
        // j loop controls the unsorted list (actual sub-list)
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[min_i]){
                min_i = j;
            }
        }
        // swap the min element with the first element of unsorted list
        swap(arr[i], arr[min_i]);
    }
}


int main(){
    int x[] = {3,4,22,0,1};
    int size = sizeof(x) / sizeof(x[0]);

    SelectionSort(x, size);

    for (int i=0; i<size; i++){
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}

