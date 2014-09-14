//
//  ScoreKeeper.h
//  CardObjectsTester
//
//  Created by Matt on 9/7/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#ifndef __CardObjectsTester__ScoreKeeper__
#define __CardObjectsTester__ScoreKeeper__

#include <iostream>
#include "Question.h"
#include <string>
#include <vector>

namespace cg {
    class ScoreKeeper{
        
    public:
        ScoreKeeper();
        ~ScoreKeeper();
        
        bool answerCheck(Question * inputQ, std::string inputAns);
        
        void resetQuestionLists();
        
        std::vector<std::string> getQuestionsRightIDs();
        std::vector<std::string> getQuestionsWrongIDs();
        
        
    private:
    
        
    protected:
        
        std::vector<std::string> questionsRightIDs;
        std::vector<std::string> questionsWrongIDs;
    };
}
#endif /* defined(__CardObjectsTester__ScoreKeeper__) */
