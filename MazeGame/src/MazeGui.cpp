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
        if(moved) {
            window->setSize(model->getLength() * SQUARE_SIZE + 2 * SQUARE_SIZE,
                            model->getWidth() * SQUARE_SIZE + 2 * SQUARE_SIZE);
        }
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
        //cout << "Finished Maze" << endl;
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

        model->findShortPath(model->getCurX(), model->getCurY());
        coords = model->getMapDirection();
        drawMaze();
//        vector<vector<int>> coords = model->getMapDirection();
//        string test = "x: " + to_string(coords[0][0]) + ", y" + to_string(coords[0][1]);
//        message->setColor("blue");
//        message->setText(test);
//        // iterate through the vector of vectors
//        vector<vector<int>> coords = model->getMapDirection();
//        for (int i = 0; i < coords.size(); i++) {
//            message->setColor("blue");
//            cout << "x: " << coords[i][0] << ", y" << coords[i][1] << endl;
//            window->fillRect(coords[i][0] * SQUARE_SIZE, coords[i][1] * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
//        }
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
MazeGui::MazeGui(MazeSystem* model, ScoreBoard* scores) : model(model), showPath(false),
                                               onCool(false), hintSteps(5), scores(scores) {
    //Create window button and label objects. Add some space to the bottom of the window for
    // buttons and label
    message = new GLabel();
    hint = new GButton("Hint");
    scoreBoard = new GLabel();

    //Give space to the width and length of the window to display scoreboard and message/hint
    window = new GWindow(model->getLength() * SQUARE_SIZE + 2 *SQUARE_SIZE,
                                        model->getWidth() * SQUARE_SIZE + 2 * SQUARE_SIZE);
    window->setBackground("brown");

    // Allign the window and place the interactors on the window
    window->setRegionAlignment(GWindow::REGION_SOUTH, ALIGN_LEFT);
    // Allign the button and label to the bottom of the window
    window->addToRegion(hint, GWindow::Region::REGION_SOUTH);
    window->addToRegion(message, GWindow::Region::REGION_SOUTH);

    //Align object that go on the right side of the screen to be at the top
    window->setRegionAlignment(GWindow::REGION_EAST, ALIGN_TOP);
    //put the score label on the right of the screen
    window->addToRegion(scoreBoard, GWindow::Region::REGION_EAST);
    window->setAutoRepaint(false);

    // Change the formatting of the message label positioned at the bottom of the window
    message->setForeground("gray");
    message->setColor("Red");
    message->setBackground("black");
    message->setText("Loading please wait");
    message->setFont("Helvetica-12");

    // Draw the initial maze
    drawMaze();

    this->onCool = true;
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
                        userColor = "purple";
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
    if(showPath){
        for (int i = 0; i < coords.size(); i++) {
                window->setColor("red");
                window->fillRect(coords[i][0] * SQUARE_SIZE, coords[i][1] * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
                window->setColor("green");
                window->fillRect(model->getCurX() * SQUARE_SIZE, model->getCurY() * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);

        }
    }
    //print out the scores to the window
    scoreBoard->setText(scores->toString());
    window->repaint();
}

MazeGui::~MazeGui() {
    delete window;
    delete message;
    delete hint;
}

