// Keeping track of the path taken by the mouse in the maze
// Using a multidimentional array
// Mikhail Nesterenko
// 11/21/2022
//
// Game loop by:
// David Tinley
// 12/05/2022

#include <iostream>

const int mazeLength = 6;
const int mazeWidth = 6;

char direction;

int main(){

    int mouseX = 0; // current mouse X index
    int mouseY = 0; // current mouse Y index

    bool maze[mazeLength][mazeWidth]; // declare mouse maze tracking array

    // initialize the maze array
    for (int i = 0; i < mazeLength; i++) {
        for (int j = 0; j < mazeWidth; j++) {
            maze[i][j] = false;
        }
    }
    maze[mouseX][mouseY] = true; // place mouse in the top-left corner

    do { // main game loop
        char columns;
        std::cout << "  ";

        for (int i = 0; i < mazeWidth; ++i) {
            columns = i + 97;
            std::cout << columns;
        }
        std::cout << std::endl;

        for (int i = 0; i < mazeLength; ++i) {
            std::cout << i + 1 << " ";
            for (int j = 0; j < mazeWidth; ++j) {
                if (maze[i][j]) { // placing mouse position in maze
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "Enter direction: 'l' for left, 'r' for right, 'u' for up, 'u' for down, or 'q' to quit: ";
        std::cin >> direction;

        switch (direction) { // switching on user direction input
            case 'u':
                mouseX = mouseX - 1;
                maze[mouseX][mouseY] = true;
                break;

            case 'd':
                mouseX = mouseX + 1;
                maze[mouseX][mouseY] = true;
                break;

            case 'r':
                mouseY = mouseY + 1;
                maze[mouseX][mouseY] = true;
                break;

            case 'l':
                mouseY = mouseY - 1;
                maze[mouseX][mouseY] = true;
                break;
        }
    } while (direction != 'q'); // quit if 'q' is entered

    return 0;
}
