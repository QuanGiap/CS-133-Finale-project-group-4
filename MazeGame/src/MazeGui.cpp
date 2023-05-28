#include "MazeGui.h"

const int MazeGui::DELAY = 500;

void MazeGui:: animate() {
    window->setTimerListener(DELAY, [this] {
        this->update();
    });
}

//MazeGui::MazeGui(MazeGame* model) : model(model) , window(nullptr) {
//    window = new GWindow(model->length, model->width);
//}
void MazeGui:: update() {

}
