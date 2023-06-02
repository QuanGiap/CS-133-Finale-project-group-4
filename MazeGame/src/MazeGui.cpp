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
void MazeGui::handleKey(const GKeyEvent& event) {
    //cout << "Key Detected" << endl;
    string key = event.keyCodeToString(event.getKeyCode());
    if(model->getUser()->getType() == stair && key == "Shift") {
        model->useStair();
    } else if(key == "Up") {
        model->moveUp();
        //cout << "HIT Up" << endl;
    } else if(key == "Down") {
        model->moveDown();
       // cout << "HIT Down" << endl;
    } else if(key == "Left") {
        model->moveLeft();
       // cout << "HIT Left" << endl;
    } else if(key == "Right") {
        model->moveRight();
       // cout << "HIT Right" << endl;
    } else if(key == "f") {
        model->findShortPath(model->getCurY(), model->getCurX());
    }

    if(model->getUser()->getType() == finishPoint) {
        cout << "Finished Maze" << endl;
        window->removeKeyListener();
        window->close();
    }
    drawMaze();
}


MazeGui::MazeGui(MazeSystem* model) : model(model), window(nullptr) {
    window = new GWindow(model->getLength() * SQUARE_SIZE, model->getWidth() * SQUARE_SIZE);
    window->setExitOnClose(true);
    window->setBackground("brown");
   // window->set
    drawMaze();
    window->setKeyListener([this](GEvent event) {
       GKeyEvent keyEvent(event);
       if(event.typeToString(event.getType()) == "KEY_RELEASED") {
            this->handleKey(event);
       }
    });

    //animate();
}

void MazeGui::drawMaze() {
    window->clear();
    for(int x = 0; x < model->getLength(); x++) {
        for(int y = 0; y < model->getWidth(); y++) {
            Path* path = model->get(x,y);
            if(path != nullptr) {
                //cout << path->toString();
                if(model->getCurY() == y && model->getCurX() == x) {
                    window->setColor("green");
                } else {
                    window->setColor(path->getColor());
                }
                window->fillRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
            }
        }
        //cout << endl;
    }
}


void MazeGui:: update() {

    drawMaze();
}
