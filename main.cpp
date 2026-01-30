#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

using namespace std;

void clearScreen() {
    cout << "\x1b[2J\x1b[H";
}

void enableRawMode() {
    termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    t.c_cc[VMIN] = 0;
    t.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}


int readKey() {
    fd_set set;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;


    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);
    if (select(STDIN_FILENO + 1, &set, nullptr, nullptr, &tv) > 0) {
        char c;
        if (read(STDIN_FILENO, &c, 1) == 1) return (unsigned char)c;
    }
    return -1;
}


int main(){
    int width  = 60;
    int height = 20;

    int snakeX = width/2;
    int snakeY = height/2;
    bool gameOver = false;
    int dx = 1;
    int dy = 0;

    enableRawMode();
    while(!gameOver){
        clearScreen();   
        int c = readKey();
        if (c == 'w' && dy != 1)  { dx = 0; dy = -1; }
        if (c == 's' && dy != -1) { dx = 0; dy =  1; }
        if (c == 'a' && dx != 1)  { dx = -1; dy = 0; }
        if (c == 'd' && dx != -1) { dx =  1; dy = 0; }
        if (c == 'q') gameOver = true;
  
        //top
        cout << '+';
        for(int i = 0; i < width; i++){
            cout << '-';
        }
        cout << "+\n";

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
        cout << "+\n";

        snakeX +=dx;
        snakeY +=dy;

        if (snakeX < 0 || snakeX >= width || snakeY < 0 || snakeY >= height) gameOver = true;

        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "GAME OVER!!" << endl;

}