#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void SelectionSort(int arr[], int n){
    int min_i;
    for (int i=0; i<n-1; i++){
        min_i = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[min_i]){
                min_i = j;
            }
        }
    if (min_i != i){
        swap(arr[i], arr[min_i]); // always remember not to swap the indices only
        }
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