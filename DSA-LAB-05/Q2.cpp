#include <iostream>
#include <cstdlib>
#include <ctime>   
using namespace std;

void recursiveGame(int randNum, int turn = 0){
    int guess;
    cout << "Player " << (turn % 2) + 1 << " Enter your number: ";
    cin >> guess;

    if(guess == randNum){
        cout << "Player " << (turn % 2) + 1 << " wins!" << endl;
        return;
    }

    if(guess > randNum){
        cout << "Too high!" << endl;
    }else{
        cout << "Too low!" << endl;
    }
    recursiveGame(randNum, turn + 1);
}

int main(void){
    srand(time(0));

    int randNum = (rand() % 100) + 1;

    recursiveGame(randNum);
}