#include <iostream>
#include <vector>
using namespace std;

vector<int> findOccurences(string text, string keyword){
    vector<int> arr;
    if(keyword.size() == 0 || keyword.size() > text.size()) return arr;

    for(int i = 0; i < text.size() - keyword.size(); i++){
        bool found = true;
        for(int j = 0; j < keyword.size() && found; j++){
            if(text[i + j] != keyword[j]){
                found = false;
            }
        }

        if(found) arr.push_back(i);
    }

    return arr;
}

int main(){
    vector<int> indices = findOccurences("the quick brown fox jumps over the lazy dog", "the");
    for(int i = 0; i < indices.size(); i++){
        cout << indices[i] << " ";
    }
    cout << endl;
}