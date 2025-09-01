#include <iostream>
using namespace std;

/*
Assumption: array is sorted here.
*/

int binarySearch(int arr[], int low, int high , int target){

    // here `low` will get incremented itself; hence no need of low++.
    while (low <= high){

        int mid = low + (high-low) / 2;

        if (arr[mid] == target){
            return mid;
        }

        if (target > arr[mid]){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }
    
    return -1;
}

// recursive method
int binarySearchRec(int arr[], int low, int high, int target){
    // Base case: if low > high, element not found
    if (low > high) {
        return -1;
    }

    int mid = low + (high-low)/2;

    // Element found at mid
    if (arr[mid] == target){
        return mid;
    }

    // Search in right half
    if (target > arr[mid]){
        return binarySearchRec(arr, mid+1, high, target);
    }
    
    // Search in left half
    return binarySearchRec(arr, low, mid-1, target);
}

int main(){
    int arr[] = {4,66,77,88};
    int size = sizeof(arr) / sizeof(arr[0]);

    int res = binarySearch(arr, 0, size-1, 77);

    (res == -1) ? cout << "element not found!" : cout << "element found at: " << res;

    return 0;
}