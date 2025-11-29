#include <iostream>
using namespace std;


// quick sort
void swap(int &a, int &b);
int partition(int low, int high, int arr[]);
void quickSort(int low, int high, int arr[]);

// selection sort
void swap(int &a, int &b);
void selectionSort(int arr[], int n);

// bubble sort
void swap(int &a, int &b);
void bubbleSort(int arr[], int n);

// merge sort
void merge(int left, int mid, int right, int arr[]);
void mergeSort(int left, int right, int arr[]);
