//
//  Question.h
//  CardObjectsTester
//
//  Created by Matt on 9/1/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#ifndef __CardObjectsTester__Question__
#define __CardObjectsTester__Question__

#include <iostream>
#include <string>
#include <vector>

namespace cg {
    class Question {
    public:
        Question(std::string _question, std::string _explanation, std::vector<std::string> _answers, std::string _correct);
        ~Question();
        
        
        void setID(std::string inputID);
        
        
        std::string getQuestion();
        std::string getExplanation();
        std::string getCorrectAnswer();
        std::vector<std::string> getAnswers();
        
        bool checkIsCorrect(std::string inputAnswer);
        
        std::string getID();
        
    private:
    protected:
        std::string ID;
        std::string question;
        std::string explanation;
        std::string correctAnswer;
        std::vector<std::string> answers;
    };
    
}

#endif /* defined(__CardObjectsTester__Question__) */
