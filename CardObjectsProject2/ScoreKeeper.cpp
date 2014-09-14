//
//  ScoreKeeper.cpp
//  CardObjectsTester
//
//  Created by Matt on 9/7/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#include "ScoreKeeper.h"



cg::ScoreKeeper::ScoreKeeper()
{
    
}

cg::ScoreKeeper::~ScoreKeeper()
{
    
}

bool cg::ScoreKeeper::answerCheck(cg::Question *inputQ, std::string inputAns)
{
    bool gotItRight = false;
    if (inputQ->checkIsCorrect(inputAns)) {
        this->questionsRightIDs.push_back(inputQ->getID());
        gotItRight = true;
    }
    else {
        this->questionsWrongIDs.push_back(inputQ->getID());
    
    }
    return gotItRight;

}

std::vector<std::string> cg::ScoreKeeper::getQuestionsRightIDs()
{
    return this->questionsRightIDs;
}

std::vector<std::string> cg::ScoreKeeper::getQuestionsWrongIDs()
{
    return this->questionsWrongIDs;
}


void cg::ScoreKeeper::resetQuestionLists()
{
    this->questionsRightIDs.clear();
    this->questionsWrongIDs.clear();
}
