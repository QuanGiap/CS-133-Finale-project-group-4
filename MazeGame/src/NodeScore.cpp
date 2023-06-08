
#include "NodeScore.h"

NodeScore::NodeScore(string name,int score)
{
    this->name = name;
    this->score = score;
    this->next = nullptr;
}

NodeScore::NodeScore(string name,int score,NodeScore* next)
{
    this->name = name;
    this->score = score;
    this->next = next;
}
