#include <iostream>
using namespace std;

class Runner{
    public:
        string name;
        int finishTime;

        Runner(string name, int time) : name(name), finishTime(time) {}
        Runner() : Runner("", 0) {}

        void display(){
            cout << name << " - " << finishTime << " seconds!" << endl;
        }
};

void merge(Runner runners[], int low, int mid, int high){
    int i, j, k;
    int n1 = mid - low + 1;    
    int n2 = high - mid;

    Runner LeftArray[n1], RightArray[n2];

    for (int i = 0; i < n1; i++)    
    LeftArray[i] = runners[low + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = runners[mid + 1 + j];

    i = 0; j = 0; k = low;
    while (i < n1 && j < n2){
        if(LeftArray[i].finishTime < RightArray[j].finishTime){
            runners[k++] = LeftArray[i++];
        }else{
            runners[k++] = RightArray[j++];
        }
    }

    while(i < n1) runners[k++] = LeftArray[i++];
    while(j < n2) runners[k++] = RightArray[j++];
}

void mergeSort(Runner runners[], int low, int high){
    if(low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(runners, low, mid);
    mergeSort(runners, mid + 1, high);
    merge(runners, low, mid, high);
}

int main(void) {
    Runner runners[10];
    for(int i = 0; i < 10; i++){
        cout << "Enter name and finish time for runner " << i + 1 << ": ";
        cin >> runners[i].name >> runners[i].finishTime;
    }

    cout << endl;

    mergeSort(runners, 0, 9);
    cout << "Top 5 fastest runners: " << endl;
    for(int i = 0; i < 5; i++){
        cout << i + 1 << ": ";
        runners[i].display();
    }
}