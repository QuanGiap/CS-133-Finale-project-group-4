// This class manages a GUI for a system interconnected Mazes. Users can interact and play the game by
// using the arrow keys as keyboard inputs to move the player along the current level.
// To switch between levels, players must be on top of stairs (currently yellow blocks) and
// hit the shift key.

#ifndef _Maze_Gui
#define _Maze_Gui

#include "gwindow.h"
#include "gevent.h"
#include "glabel.h"
#include "gbutton.h"
#include "MazeSystem.h"
#include "ScoreBoard.h"

using namespace sgl;

class MazeGui {
    private:
        vector<vector<int>> coords;
        const int SQUARE_SIZE = 20;

        // Stores the window that gets displayed to the user.
        GWindow* window;

        // Stores the system of interconnected mazes.
        MazeSystem* model;

        ScoreBoard* scores;

        // Draws the current level of the maze given by the MazeSystem
        void drawMaze();

        // Takes a reference to a key event which is triggered when a key is pressed.
        // Checks if the key pressed is an arrow key or a shift key to move the player
        // through the maze. Returns true if the player succesfully moved.
        bool movePlayer(const GKeyEvent& event);

        // Takes a reference to a key event which is triggered when a key
        // is pressed. Checks if the key pressed is an arrow key or a shift key to move the player
        // through the maze. Redraws the maze if the player moved.
        void handleKey(const GKeyEvent& event);

        void displayHint();

        bool showPath;
        bool onCool;
        int hintSteps;

        GLabel* message;
        GButton* hint;
        GLabel* scoreBoard;



    public:
        // Constructs a Gui object which displays the current maze level
        // the user is located at. The users can use the arrow keys to move the
        // player and use the shift key to switch between levels when
        // ontop of stairs (yellow blocks currently).
        MazeGui(MazeSystem* model, ScoreBoard* scores);
        ~MazeGui();
};

#endif
