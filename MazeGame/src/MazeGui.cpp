// This file implements the functions and constructor for the MazeGui class.

#include "MazeGui.h"

// Takes a reference to a key event which is triggered when a key is pressed.
// Checks if the key pressed is an arrow key or a shift key to move the player
// through the maze.Returns true if the player successfuly moved positions
bool MazeGui::movePlayer(const GKeyEvent& event) {
    // Checks for arrow key or shift key inputs to move the player.
    string key = event.keyCodeToString(event.getKeyCode());
    bool moved = false;
    if(model->getUser()->getType() == stair && key == "Shift") {
        moved =  model->useStair();
    } else if(key == "Up") {
        moved = model->moveUp();
    } else if(key == "Down") {
        moved = model->moveDown();
    } else if(key == "Left") {
        moved = model->moveLeft();
    } else if(key == "Right") {
        moved = model->moveRight();
    }

    // If the user is on the finish point the game is over.
    if(model->getUser()->getType() == finishPoint) {
        cout << "Finished Maze" << endl;
        window->removeKeyListener();
        window->close();
    }
    return moved;
}

// If the users hint is not on cooldown, enables the path to be displayed.
void MazeGui::displayHint() {
    // the countdown is zero or less or the cooldown is disabled
    // Turn on the hint and turn off the cooldown
    if(!(onCool && hintSteps > 0)) {
        if(!showPath) {
            hintSteps = 5;
        }
        showPath = true;
        onCool = false;

        // Test statement
        message->setColor("Green");
        drawMaze();
    }
}

void MazeGui::handleKey(const GKeyEvent& event) {
    bool moved = this->movePlayer(event);
    //Decrement counter if the path is being shown or the cooldown is activated
    if(moved && (showPath || onCool) && hintSteps > 0) {
        hintSteps--;

    } else if(moved && onCool && hintSteps <= 0) {
        onCool = false;
        drawMaze();
    // if the countdown hits zero while showPath is true then turn off hint and turn on cooldown
    // reset the counter
    }else if(moved && showPath && hintSteps <= 0) {
        showPath = false;
        onCool = true;
        hintSteps = 5;

        // Test statement
        message->setColor("red");
    }

    // redraw the maze only if the player moved
    if(moved) {
        drawMaze();
    }
}

// Constructs a Gui object which displays the current maze level
// the user is located at. The users can use the arrow keys to move the
// player and use the shift key to switch between levels when
// ontop of stairs (yellow blocks currently).
MazeGui::MazeGui(MazeSystem* model) : model(model), showPath(false), onCool(false), hintSteps(5) {
    //Create window button and label objects. Add some space to the bottom of the window for
    // buttons and label
    message = new GLabel();
    hint = new GButton("Hint");
    window = new GWindow(model->getLength() * SQUARE_SIZE,
                                        model->getWidth() * SQUARE_SIZE + message->getHeight());
    window->setExitOnClose(true);
    window->setBackground("brown");
    window->setRegionAlignment(GWindow::REGION_SOUTH, ALIGN_LEFT);

    // Allign the button and label to the bottom of the window
    window->addToRegion(hint, GWindow::Region::REGION_SOUTH);
    window->addToRegion(message, GWindow::Region::REGION_SOUTH);

    message->setForeground("gray");
    message->setColor("Red");
    message->setBackground("black");
    message->setText("Hello World");
    message->setFont("Helvetica-12");

    // Draw the initial maze
    drawMaze();

    // KeyListener activates whenever a key is pressed and calls the handleKey function
    // only if the key was released. Prevents "bouncing" in the key press, that is
    // it ensures the player is moved once when the key is pressed.
    window->setKeyListener([this](GEvent event) {
       GKeyEvent keyEvent(event);
       if(event.typeToString(event.getType()) == "KEY_RELEASED") {
            handleKey(keyEvent);
       }
    });

    hint->setActionListener([this]() {
        this->displayHint();
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
                    string userColor = "pink";
                    if(onCool) {
                        userColor = "blue";
                    } else if(showPath) {
                        userColor = "green";
                    }
                    window->setColor(userColor);
                } else {
                    window->setColor(path->getColor());
                }
                window->fillRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
            }
        }
    }
    // test statement for label
    message->setText(to_string(hintSteps));
}

