#include <iostream>
using namespace std;

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; 
        
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0; 
    j = 0;  
    k = beg;
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
} 

int main(void){
    int arr1[10] = {23, 4, 15, 8, 42, 16, 9, 55, 3, 10};
    int arr2[10] = {12, 7, 19, 33, 5, 28, 40, 1, 21, 14};

    int combined[20];

    for (int i = 0; i < 10; i++){
        combined[i] = arr1[i];
        combined[10 + i] = arr2[i];
    }

    int size = 20;

    cout << "Before sorting:" << endl;
    for (int i = 0; i < size; i++)
        cout << combined[i] << " ";
    cout << endl;

    mergeSort(combined, 0, size - 1);

    cout << endl;

    cout << "After sorting:" << endl;
    for (int i = 0; i < size; i++)
        cout << combined[i] << " ";
    cout << endl;

    return 0;
}