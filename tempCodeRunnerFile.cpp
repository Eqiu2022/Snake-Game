#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void clearScreen() {
    cout << "\x1b[2J\x1b[H";
}


int main(){
    int width  = 60;
    int height = 20;

    int snakeX = width/2;
    int snakeY = height/2;
    
    while(true){
        clearScreen();      
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
                if (i == snakeY && j == snakeX){
                    cout << 'O';   // snake head
                }
                else {
                    cout << ' ';
                }
            }
            cout << '|' << endl;
        }
        //bottom
        cout << '+';
        for(int i = 0; i < width; i++){
            cout << '-';
        }
        cout << '+' << endl;
        snakeX++;
        if (snakeX >= width) snakeX = 0;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

}