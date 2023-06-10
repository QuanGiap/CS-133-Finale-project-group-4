// Justin Tun, Quan Giap, Giovanni Dominguez
// CS 133, Spring 2023
// Group-4 Finale Project: MazeGame

// This class manages a GUI for a system interconnected Mazes. Users can interact and play
// the game by using the arrow keys as keyboard inputs to move the player along the current level.
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
        const int HINT_COUNTDOWN = 7;
        vector<vector<int>> coords;
        const int SQUARE_SIZE = 20;
        int hintTime;

        // Stores the window that gets displayed to the user.
        GWindow* window;

        // Stores the system of interconnected mazes.
        MazeSystem* model;

        // Stores the highscores for the scoreboard.
        ScoreBoard* scores;

        // Draws the current level of the maze given by the MazeSystem
        void drawMaze();

        // Takes a reference to a key event which is triggered when a key is pressed.
        // Checks if the key pressed is an arrow key or a shift key to move the player
        // through the maze. Returns true if the player succesfully moved.
        bool movePlayer(const GKeyEvent& event);

        // Takes a reference to a key event which is triggered when a key
        // is pressed. Checks if the key pressed is an arrow key or a shift key to move the player
        // through the maze. Redraws the maze if the player moved. Micromanages the visibility
        // of the hint. Decrements the amount of steps the user can take
        // before their cooldown or hint wears off.
        void handleKey(const GKeyEvent& event);

        // Toggles the cooldown and ability to show the best path to the user
        void toggleHint();

        // Displays the shortest path to the end of the maze to the user 
        // if the user is not on cooldown
        void displayHint();

        // Draws the current users position onto the window
        void drawUser();

        
        // Displays the current steps, steps for countdown, and notifies when a change of the 
        // maze structure occured
        void displayStats();

        // Displays the scores for the shortest playthroughs of the game on the window
        void displayScores();

        // Aligns the south and east regions of the window for the hint button,
        // message label, and the scoreboard label. Sets the colors and other
        // settings for the interactors and window. 
        void setGuiSettings();
        
        const string DEFAULT_USER_COLOR = "pink";
        const string COOLDOWN_COLOR = "purple";
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
