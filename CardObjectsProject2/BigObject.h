//
//  BigObject.h
//  CardObjectsTester
//
//  Created by Matt on 9/4/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#ifndef __CardObjectsTester__BigObject__
#define __CardObjectsTester__BigObject__

#include <iostream>
#include "Question.h"
#include <vector>
#include "ScoreKeeper.h"



namespace cg {
    class BigObject{
    public:
        BigObject();
        ~BigObject();
        
        void run();
        
        
    
    private:
    protected:
        std::vector<cg::Question *> questions;
        
        
        void handlePostAnswerOutput(Question * question, bool wasCorrect);
        bool handleRetryQuestions(ScoreKeeper * localScoreKeeper);
        
        };
}


#endif /* defined(__CardObjectsTester__BigObject__) */