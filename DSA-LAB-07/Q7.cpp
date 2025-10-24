#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for seeding rand()
#include <algorithm> // for swap
using namespace std;

int comparisonCount = 0;

int partition(int arr[], int low, int high, int pivotIndex) {
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int firstPivot(int low, int high) {
    return low; 
}

int randomPivot(int low, int high) {
    return low + rand() % (high - low + 1); 
}

int middlePivot(int low, int high) { 
    return (low + high) / 2; 
}

int medianOfThreePivot(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];

    if ((a > b) != (a > c))
        return low;
    else if ((b > a) != (b > c))
        return mid;
    else
        return high;
}

void quickSort(int arr[], int low, int high, int pivotType) {
    if (low < high) {
        int pivotIndex;

        if (pivotType == 1)
            pivotIndex = firstPivot(low, high);
        else if (pivotType == 2)
            pivotIndex = randomPivot(low, high);
        else if (pivotType == 3)
            pivotIndex = middlePivot(low, high);
        else
            pivotIndex = medianOfThreePivot(arr, low, high);

        int pivot = partition(arr, low, high, pivotIndex);

        quickSort(arr, low, pivot - 1, pivotType);
        quickSort(arr, pivot + 1, high, pivotType);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main() {
    srand(time(0));

    int n = 10;
    int sortedArr[] = {1,2,3,4,5,6,7,8,9,10};
    int reverseArr[] = {10,9,8,7,6,5,4,3,2,1};
    int randomArr[] = {8,3,10,1,6,9,2,7,5,4};

    int testArr[10];

    cout << "Quick Sort Comparison" << endl;

    string types[4] = {
        "First Element Pivot",
        "Random Pivot",
        "Middle Element Pivot",
        "Median-of-Three Pivot"
    };

    int arraysTested = 3;
    string arrayNames[3] = {"Sorted", "Reverse-sorted", "Random"};

    int (*inputs[3])[10] = {&sortedArr, &reverseArr, &randomArr};

    for (int t = 0; t < arraysTested; t++) {
        cout << endl;
        cout << "Array Type: " << arrayNames[t] << endl;

        for (int p = 1; p <= 4; p++) {
            copyArray(testArr, *inputs[t], n);
            comparisonCount = 0;

            quickSort(testArr, 0, n - 1, p);

            cout << types[p - 1] << ": Comparisons: " << comparisonCount << endl;
        }
    }

    return 0;
}
