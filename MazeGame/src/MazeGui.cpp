#include "MazeGui.h"

const int MazeGui::DELAY = 500;

window->setKeyListener([this](GEvent event) {
    GKeyEvent keyEvent(event);
    if(event.typeToString(event.getType()) == "KEY_RELEASED") {
        this->keyCheck(event);
    }
});

void MazeGui::keyCheck(const GKeyEvent& event) {
    string key = event.keyCodeToString(event.getKeyCode());
    if(key == "Up") {
        model->moveUp();
    } else if (key == "Down") {
        model->moveDown();
    } else if (key == "Right") {
        model->moveRight();
    } else if (key == "Left") {
        model->moveLeft();
    } else if (key == " ") {
        model->useStair();
    }
    update();
}



//MazeGui::MazeGui(MazeGame* model) : model(model) , window(nullptr) {
//    window = new GWindow(model->length, model->width);
//}
void MazeGui:: update() {

}

