//
//  QuestionFinder.h
//  CardObjectsTester
//
//  Created by Matt on 9/7/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#ifndef __CardObjectsTester__QuestionFinder__
#define __CardObjectsTester__QuestionFinder__

#include <iostream>
#include <vector>
#include <string>
#include "Question.h"

namespace cg {
    class QuestionFinder{
    public:
        QuestionFinder();
        ~QuestionFinder();
        
        std::vector<Question *> getAllQuestionsFromDirectory(std::string inputDirectory);
        
    protected:
    private:
    };
}

#endif /* defined(__CardObjectsTester__QuestionFinder__) */
