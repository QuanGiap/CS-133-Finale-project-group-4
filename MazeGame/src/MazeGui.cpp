// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

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
            //Disable path and enable the cooldown
            showPath = false;
            onCool = true;
            hintSteps = HINT_COUNTDOWN;
            // Resize the window to fit the current maze
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
        window->removeKeyListener();
        window->close();
    }
    return moved;
}

// If the users hint is not on cooldown, enables the path to be displayed.
// The directions given by the hint are set at the time of pressing the hint button.
void MazeGui::toggleHint() {
    // the countdown is zero or less or the cooldown is disabled
    // Turn on the hint and turn off the cooldown
    if(!(onCool && hintSteps > 0)) {
        if(!showPath) {
            hintSteps = HINT_COUNTDOWN;
        }
        showPath = true;
        onCool = false;

        model->findShortPath(model->getCurX(), model->getCurY());
        coords = model->getMapDirection();
        drawMaze();
    }
}

// Moves the player if an arrow key or shift key was pressed. Redraws the 
// maze with the user at the appropriate position and manages the visibility
// of the hint. Decrements the amount of steps the user can take
// before their cooldown or hint wears off. 
void MazeGui::handleKey(const GKeyEvent& event) {
    bool moved = this->movePlayer(event);
    if(moved) {
        //Decrement counter if the path is being shown or the cooldown is activated
        if((showPath || onCool) && hintSteps > 0) {
            hintSteps--;
        } else if(onCool && hintSteps <= 0) {
            onCool = false;
        // if the countdown hits zero while showPath is true then turn off hint and turn on 
        // cooldown reset the counter
        } else if(showPath && hintSteps <= 0) {
            showPath = false;
            onCool = true;
            hintSteps = HINT_COUNTDOWN;
        }
        drawMaze();
    }
   
}

// Displays the shortest path to the end of the maze to the user 
// if the user is not on cooldown
void MazeGui::displayHint() {
    //draw out the shortest path. Goes through the coordinates for the shortest path
    if(showPath){
        window->setColor("red");
        for (int i = 0; i < coords.size(); i++) {
            int x = coords[i][0];
            int y = coords[i][1];
            pathType curPathType = model->getType(x,y);
            if(curPathType!=stair && curPathType != finishPoint)
                window->fillRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
        }
    }
}

// Aligns the south and east regions of the window for the hint button,
// message label, and the scoreboard label. Sets the colors and other
// settings for the interactors and window. 
void MazeGui::setGuiSettings() {
    window->setBackground("gray");

    // Align the window and place the interactors on the window
    window->setRegionAlignment(GWindow::REGION_SOUTH, ALIGN_LEFT);

    // Align the button and label to the bottom of the window
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

    message->setText("Loading please wait");
    message->setFont("Helvetica-12");
}

// Constructs a Gui object which displays the current maze level
// the user is located at. The users can use the arrow keys to move the
// player and use the shift key to switch between levels when
// ontop of stairs (yellow blocks currently).
MazeGui::MazeGui(MazeSystem* model, ScoreBoard* scores) : 
                                model(model), showPath(false), onCool(false), 
                                                    hintSteps(HINT_COUNTDOWN), scores(scores) {
    //Create window button and label objects. Add some space to the bottom of the window for
    // buttons and label
    message = new GLabel();
    hint = new GButton("Hint");
    scoreBoard = new GLabel();

    //Give space to the width and length of the window to display scoreboard and message/hint
    window = new GWindow(model->getLength() * SQUARE_SIZE + 2 *SQUARE_SIZE,
                                        model->getWidth() * SQUARE_SIZE + 2 * SQUARE_SIZE);
    
    // Initializes the window and interactor settings
    setGuiSettings();

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

    // ActionListener activates when the 'hint' button is presssed. Used to
    // show shortest path if the user is not on cooldown
    hint->setActionListener([this]() {
        this->toggleHint();
    });
}

// Draws the current users position onto the window
void MazeGui::drawUser() {
    string userColor = DEFAULT_USER_COLOR;
    if(onCool) {
        userColor = COOLDOWN_COLOR;
    } 
    window->setColor(userColor);
    window->fillRect(model->getCurX() * SQUARE_SIZE, model->getCurY() * SQUARE_SIZE, 
                                                                SQUARE_SIZE, SQUARE_SIZE);
}

// Displays the current steps, steps for countdown, and notifies when a change of the 
// maze structure occured
void MazeGui::displayStats() {
    // Message statement for label
    string toMessage = "Current Steps: " + to_string(model->getCurStep());
    toMessage += " | Hint countdown: " + to_string(hintSteps)+"\n";
    int remainStep = model->stepRemain();
    if(remainStep == 0) {
        toMessage += "Link between maze have been changed";
    }else{
        toMessage += "Maze will be changed in: " + to_string(remainStep);
    }
    message->setText(toMessage);
}

// Displays the scores for the shortest playthroughs of the game on the window
void MazeGui::displayScores() {
    scoreBoard->setColor("white");
    scoreBoard->setText(scores->toString());
    window->repaint();
}

// Draws the current level of the maze given by the MazeSystem
void MazeGui::drawMaze() {
    window->clear();

    //Goes through the current maze and draws each class of objects as a unique color.
    for(int x = 0; x < model->getLength(); x++) {
        for(int y = 0; y < model->getWidth(); y++) {
            Path* path = model->get(x,y);
            if(path != nullptr) {
                //prints the color given by the object on this coordinate in the maze.
                window->setColor(path->getColor());
                if(path->getType() == obstacle) {
                    window->setFont("Helvetica-10");
                    window->drawString(to_string(path->getCostStep()), x  * SQUARE_SIZE, 
                                                                        (y + 1) * SQUARE_SIZE);
                } else {
                    window->fillRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
                }

            }
        }
    }
    displayHint();
    displayStats();
    drawUser();
    displayScores();
}

MazeGui::~MazeGui() {
    delete window;
    delete message;
    delete hint;
}

