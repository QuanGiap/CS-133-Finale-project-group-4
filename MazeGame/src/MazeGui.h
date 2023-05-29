#ifndef _Maze_Gui
#define _Maze_Gui

#include "gwindow.h"
#include "gbutton.h"
#include <Windows.h>
#include "MazeGame.h"
#include "MazeSystem.h"

using namespace sgl;

class MazeGui {
    private:
        GWindow* window;

        MazeGame* model;

        void drawModel();

        void animate();

        int pos_x;
        int pos_y;

    public:
        MazeGui(MazeGame* model);

        void update();

        // Test purposes only: used to animate the algorithms path finding
        static const int DELAY;

        //Function to check the key states
        void keyCheck();
        
        //User
        //void player(int x, int y);
};

#endif 
