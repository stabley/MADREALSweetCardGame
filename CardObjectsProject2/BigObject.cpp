//
//  BigObject.cpp
//  CardObjectsTester
//
//  Created by Matt on 9/4/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#include "BigObject.h"
#include "QuestionFinder.h"
#include "CardGameZipReader.h"



cg::BigObject::BigObject()
{
    
    std::string dirName = "/Users/Skabrams/Documents/Programming/Apps/MADREALSweetCardGame/CardObjectsProject2";
    
    std::shared_ptr<cg::QuestionFinder> qf(new cg::QuestionFinder());
    
    std::vector<cg::Question *> questionsFromDir = qf->getAllQuestionsFromDirectory(dirName);
    
    
    this->questions = questionsFromDir;
    
    
    for (int i = 0; i < this->questions.size(); i++) {
        cg::Question * currentQ = this->questions.at(i);
        currentQ->setID(std::to_string(i + 1));
    }
    
    
    //this->questions.push_back(firstQ);
}

cg::BigObject::~BigObject()
{
    for (int i = 0; i < this->questions.size(); i++) {
        delete this->questions.at(i);
    }
    
    std::cout << "We're done here!" << std::endl;
}

void cg::BigObject::run()
{
    cg::ScoreKeeper * miniscorekeeper = new cg::ScoreKeeper();
    while(true){//could be setting ourselves up to run FOREVER
        
        
        
        for (int i = 0; i < this->questions.size(); i++) {
            cg::Question * currentQ = this->questions.at(i);
            
            
            std::cout << currentQ->getQuestion() << std::endl;
            for (int i = 0; i < currentQ->getAnswers().size(); i++) {
                std::cout << currentQ->getAnswers().at(i) << std::endl;
            }
            
            std::string answerFromKeyboard;
            
            std::cout << "Input your answer : ";
            
            std::cin >> answerFromKeyboard;
            
            bool gotItRight = miniscorekeeper-> answerCheck(currentQ, answerFromKeyboard);
            
            //put some of the UI output code in function below
            
            this->handlePostAnswerOutput(currentQ, gotItRight);
        }
        
        
        std::cout << "You got " << miniscorekeeper->getQuestionsRightIDs().size() << " correct!" << std::endl;
        
        std::cout << "You got " << miniscorekeeper->getQuestionsWrongIDs().size() << " wrong!" << std::endl;
        
        bool dontWantToRetry = this->handleRetryQuestions(miniscorekeeper);
        
        
        if (dontWantToRetry) {
            break;
        }
        
        
        miniscorekeeper->resetQuestionLists();
        
    }
    
}


void cg::BigObject::handlePostAnswerOutput(cg::Question * question, bool wasCorrect)
{
    if (wasCorrect) {
        std::cout << "You're awesome and you don't need the explanation!" << std::endl;
        
        std::cout << "Want the explanation (y/n)? : ";
        std::string yesNo;
        std::cin >> yesNo;
        
        if ((yesNo.compare("y") == 0) | (yesNo.compare("Y") == 0)) {
            std::cout << question->getExplanation() << std::endl;
        }
        
    }
    else{
        std::cout << "Nice try! Here is the explanation : \n" << std::endl;
        std::cout << question->getExplanation() << std::endl;
        
        
    }
}


bool cg::BigObject::handleRetryQuestions(cg::ScoreKeeper *localScoreKeeper)
{
    bool Output = false;
    if (localScoreKeeper->getQuestionsWrongIDs().size() == 0) {
        Output = true;
    }
    else {
        std::string retry;
        std::cout << "Do you want to retry the questions you got wrong? (y/n) : ";
        
        std::cin >> retry;
        
        if ((retry.compare("y") == 0) | (retry.compare("Y") == 0)) {
            std::vector<cg::Question *> temp;
            std::vector<std::string> wrongIDs = localScoreKeeper->getQuestionsWrongIDs();
            
            for (int i = 0; i < this->questions.size(); i++) {
                
                for (int j = 0; j < wrongIDs.size(); j++) {
                    
                    int compResult = this->questions.at(i)->getID().compare(wrongIDs.at(j));
                    
                    if (compResult == 0) {
                        temp.push_back(this->questions.at(i));
                    }
                    
                    
                }
                
                
            }
            
            this->questions = temp;
            
            
        }
        
    }
    return Output;

    
}

