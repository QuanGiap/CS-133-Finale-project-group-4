// This file implements the functions and constructor for the MazeGui class.

#include "MazeGui.h"

// Takes a reference to a key event which is triggered when a key is pressed.
// Checks if the key pressed is an arrow key or a shift key to move the player
// through the maze.
void MazeGui::handleKey(const GKeyEvent& event) {
    string key = event.keyCodeToString(event.getKeyCode());

    if(model->getUser()->getType() == stair && key == "Shift") {
        model->useStair();
    } else if(key == "Up") {
        model->moveUp();
    } else if(key == "Down") {
        model->moveDown();
    } else if(key == "Left") {
        model->moveLeft();
    } else if(key == "Right") {
        model->moveRight();
    } else if(key == "f") {
        model->findShortPath(model->getCurY(), model->getCurX());
    }

    // If the user is on the finish point the game is over.
    if(model->getUser()->getType() == finishPoint) {
        cout << "Finished Maze" << endl;
        window->removeKeyListener();
        window->close();
    }
    drawMaze();
}

// Constructs a Gui object which displays the current maze level
// the user is located at. The users can use the arrow keys to move the
// player and use the shift key to switch between levels when
// ontop of stairs (yellow blocks currently).
MazeGui::MazeGui(MazeSystem* model) : model(model), window(nullptr) {
    window = new GWindow(model->getLength() * SQUARE_SIZE, model->getWidth() * SQUARE_SIZE);
    window->setExitOnClose(true);
    window->setBackground("brown");

    drawMaze();

    // KeyListener activates whenever a key is pressed and calls the handleKey function
    // only if the key was released. Prevents "bouncing" in the key press, that is
    // it ensures the player is moved once when the key is pressed.
    window->setKeyListener([this](GEvent event) {
       GKeyEvent keyEvent(event);
       if(event.typeToString(event.getType()) == "KEY_RELEASED") {
            this->handleKey(event);
       }
    });
}

// Draws the current level of the maze given by the MazeSystem
void MazeGui::drawMaze() {
    window->clear();
    //Goes through the current maze and draws each class of objects as a unique color.
    for(int x = 0; x < model->getLength(); x++) {
        for(int y = 0; y < model->getWidth(); y++) {
            Path* path = model->get(x,y);
            if(path != nullptr) {
                // Prints a color to denote the user or prints the color given by the object on this coordinate in the maze.
                if(model->getCurY() == y && model->getCurX() == x) {
                    window->setColor("green");
                } else {
                    window->setColor(path->getColor());
                }
                window->fillRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
            }
        }
    }
}
