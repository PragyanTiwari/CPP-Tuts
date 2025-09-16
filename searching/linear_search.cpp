
#include <iostream>
using namespace std;


// searching iteratively
int linearSearch(int arr[], int size, int target){
    
    for (int i=0; i<size; i++){
        if (arr[i] == target){return i;}
    }

    return -1;
}

// searching recursively
int linearSearchRec(int arr[], int size, int target, int index=0){

    // base case - if we've reached the end of array
    if (index == size){return -1;}

    // if found
    if (arr[index] == target){return index;}

    return linearSearchRec(arr, size, target, index+1);
}



int main(){
    int arr[] = {4,3,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int res = linearSearch(arr, size, 5);
    int res = linearSearchRec(arr, size, 5);

    (res == -1) ? cout << "element not found!" : cout << "element found at : " << res;

    return 0;
}