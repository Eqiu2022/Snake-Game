#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int width  = 30;
    int height = 20;

    //top
    cout << '+';
    for(int i = 0; i < width; i++){
        cout << '-';
    }
    cout << '+' << endl;

    //middle
    for(int i = 0; i < height; i++){
        cout << '|';
        for(int j = 0; j < width; j++){
            cout << endl;
        }
    }
    //bottom
    cout << '+';
    for(int i = 0; i < width; i++){
        cout << '-';
    }
    cout << '+' << endl;

}