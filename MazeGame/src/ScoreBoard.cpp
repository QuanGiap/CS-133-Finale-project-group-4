
#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(){
    this->header = nullptr;
}

ScoreBoard::~ScoreBoard(){
    while(header!=nullptr){
        NodeScore* temp = header->next;
        delete header;
        header = temp;
    }
}

void ScoreBoard::add(NodeScore* node){
    if(this->header==nullptr){
        this->header = node;
    }
    else{
        NodeScore* cur = this->header;
        NodeScore* prev = nullptr;
        while(cur!=nullptr && node->score > cur->score){
            prev=cur;
            cur=cur->next;
        }
        if(prev==nullptr) {
            this->header = node;
        }else{
            prev->next = node;
        }
        node->next = cur;
    }
}

void ScoreBoard::add(string name,int score){
    NodeScore* node = new NodeScore(name,score);
    this->add(node);
}

string ScoreBoard::toString(){
    string result= "";
    int rank = 1;
    NodeScore* cur = this->header;
    while(cur!=nullptr){
        result+=to_string(rank)+". "+cur->name+" "+to_string(cur->score)+"\n";
        rank++;
        cur = cur->next;
    }
    return result;
}
