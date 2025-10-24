#include <iostream>  
using namespace std;
  
int getMax(int a[], int n) {  
    int max = a[0];  
    for(int i = 1; i<n; i++) {  
        if(a[i] > max)  
            max = a[i];  
    }  
    return max;
}  
  
void countingSort(int a[], int n, int place, bool isAscending) 
{  
    int output[n + 1];  
    int count[10] = {0};    

    for (int i = 0; i < n; i++)  
        count[(a[i] / place) % 10]++;  

    if(isAscending){
        for (int i = 1; i < 10; i++)  
            count[i] += count[i - 1];  
    }else{
        for (int i = 8; i >= 0; i--)  
            count[i] += count[i + 1];  
    }

    for (int i = n - 1; i >= 0; i--) {  
        output[count[(a[i] / place) % 10] - 1] = a[i];  
        count[(a[i] / place) % 10]--;  
    }  

    for (int i = 0; i < n; i++)  
        a[i] = output[i];  
}  

void radixsort(int a[], int n, bool isAscending) {  
    int max = getMax(a, n);  

    for (int place = 1; max / place > 0; place *= 10)  
        countingSort(a, n, place, isAscending);  
}

int main(void){
    int arr[] = {5, 96, 46, 82, 51, 36, 27, 73};
    int size = sizeof(arr) / sizeof(int);

    int asc[size], dec[size];
    for(int i = 0; i < size; i++){
        asc[i] = arr[i];
        dec[i] = arr[i];
    }

    cout << "Ascending: " << endl;
    radixsort(asc, size, true);
    for(int i = 0; i < size; i++){
        cout << asc[i] << " ";
    }
    cout << endl;

    cout << "Descending: " << endl;
    radixsort(dec, size, false);
    for(int i = 0; i < size; i++){
        cout << dec[i] << " ";
    }
    cout << endl;
}