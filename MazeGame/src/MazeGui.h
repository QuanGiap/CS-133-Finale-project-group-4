#ifndef _Maze_Gui
#define _Maze_Gui

#include "gwindow.h"
#include "gbutton.h"
#include "MazeGame.h"

using namespace sgl;

class MazeGui {
    private:
        GWindow* window;

        MazeGame* model;

        void drawModel();

        void animate();

    public:
        MazeGui(MazeGame* model);

        void update();

        // Test purposes only: used to animate the algorithms path finding
        static const int DELAY;
};

#endif 
