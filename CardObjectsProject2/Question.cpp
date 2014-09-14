//
//  Question.cpp
//  CardObjectsTester
//
//  Created by Matt on 9/1/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#include "Question.h"

cg::Question::Question(std::string _question, std::string _explanation, std::vector<std::string> _answers, std::string _correct)
{
    this->question = _question;
    this->explanation = _explanation;
    this->correctAnswer = _correct;
    this->answers = _answers;
}

cg::Question::~Question() {}

bool cg::Question::checkIsCorrect(std::string inputAnswer)
{
    bool areSame = false;
    
    int result = this->correctAnswer.compare(inputAnswer);
    
    if (result == 0 ) {
        areSame = true;
    }
    
    return areSame;
}

std::string cg::Question::getQuestion()
{
    return this->question;
}

std::string cg::Question::getExplanation()
{
    return this->explanation;
}

std::string cg::Question::getCorrectAnswer()
{
    return this->correctAnswer;
}

std::vector<std::string> cg::Question::getAnswers()
{
    return this->answers;
}

std::string cg::Question::getID()
{
    return this->ID;
}

void cg::Question::setID(std::string inputID)
{
    this->ID = inputID;
}