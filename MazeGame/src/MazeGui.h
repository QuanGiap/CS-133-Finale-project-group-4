#ifndef _Maze_Gui
#define _Maze_Gui

#include "gwindow.h"
#include "gevent.h"
#include "MazeSystem.h"

using namespace sgl;

class MazeGui {
    private:
        const int SQUARE_SIZE = 20;
        GWindow* window;

        //MazeGame* model;
        MazeSystem* model;

        void drawMaze();

        void animate();
        void handleKey(const GKeyEvent& event);




    public:
        //MazeGui(MazeGame* model);
        MazeGui(MazeSystem* model);

        void update();


        // Test purposes only: used to animate the algorithms path finding
        static const int DELAY;
};

#endif
