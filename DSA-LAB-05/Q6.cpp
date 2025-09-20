#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim, int totalDim){
    if(dim >= totalDim){
        return 0;
    }

    int sum = 0;
    for(int i = 0; i < sizes[dim]; i++){
        sum += arr[dim][i];
    }

    return sum + recursiveArraySum(arr, sizes, dim + 1, totalDim);
}

int main(void){
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5};
    int row2[] = {6, 7, 8, 9};
    
    int* arr[] = {row0, row1, row2};
    
    int sizes[] = {3, 2, 4};
    
    int total = recursiveArraySum(arr, sizes, 0, 3);
    
    cout << "The sum of all elements in the jagged array is: " << total << endl;
    
    return 0;
}