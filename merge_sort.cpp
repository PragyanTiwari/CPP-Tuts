    #include <iostream>
    using namespace std;

    void merge(int arr[], int left, int mid, int right){
        
        // calculating the size of sub-arrays i.e two halves of arrays
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // declaring the sub-arrays
        int L[n1], R[n2];

        // filling the elements in the sub-arrays from the arr
        for (int i=0; i<n1; i++){
            L[i] = arr[left+i];
        }

        for (int j=0; j<n2; j++){
            R[j] = arr[mid + 1 + j];
        }

        // sorting the arr 

        int i=0, j=0, k=left; // here k represents the index of original arr

        while (i < n1 && j < n2){
            if (L[i] <= R[j]){
                arr[k] = L[i]; // take from L if smaller
                i++;
            }
            else {
                arr[k] = R[j]; // else take from R if smaller
                j++;
            }
            k++;
        }


        // copy the rest of the elements, if left.
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }


    // function to recursively split    
    void mergeSort(int arr[], int left, int right){
        /*
        Here we'll use the condition (left < right) to recursively split until only 1 element is left in arr.
        */

        if (left < right){
            int mid = left + (right - left) / 2;

            // splitting starts from here
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);

            // merging the sorted arrays i.e. from left to mid & mid to right
            /*
            here the merge function isn't recursive, it just called my `mergeSort` for many times.
            */
            merge(arr, left, mid, right);


        }
    }


    int main(){
        int x[] = {5,3,6,2,1};
        int length = sizeof(x) / sizeof(x[0]);

        // sorting the array
        mergeSort(x,0,length-1);

        for (int i = 0; i<length; i++){
            cout << x[i] << endl;
        }

        return 0;
    }