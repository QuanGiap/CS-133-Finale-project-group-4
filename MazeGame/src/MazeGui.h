#ifndef _Maze_Gui
#define _Maze_Gui

#include "gwindow.h"
#include "gbutton.h"
#include "MazeSystem.h"

using namespace sgl;

class MazeGui {
    private:
        GWindow* window;

        MazeSystem* model;

        void drawModel();

    public:
        MazeGui(MazeSystem* model);

        void update();

        // Test purposes only: used to animate the algorithms path finding
        static const int DELAY;

        //Function to check the key states
        void keyCheck(const GKeyEvent& event);
        
        //User
        //void player(int x, int y);
};

#endif 
