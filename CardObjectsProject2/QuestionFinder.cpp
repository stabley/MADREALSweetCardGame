//
//  QuestionFinder.cpp
//  CardObjectsTester
//
//  Created by Matt on 9/7/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#include "QuestionFinder.h"
#include "CardGameZipReader.h"
#include <dirent.h>

cg::QuestionFinder::QuestionFinder()
{
    
}

cg::QuestionFinder::~QuestionFinder()
{
    
}

std::vector<cg::Question *> cg::QuestionFinder::getAllQuestionsFromDirectory(std::string inputDirectory)
{
    std::vector<cg::Question *> output;
    
    DIR * dir;
    struct dirent * ent;
    if ((dir = opendir(inputDirectory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string curFileName = ent->d_name;
            
            if (curFileName.find(".zip") != std::string::npos) {
                
                std::shared_ptr<cg::CardGameZipReader> cgzr (new cg::CardGameZipReader());
                
                std::string archPath = inputDirectory + "/" + curFileName;
                
                cgzr->getDataFromArchive(archPath);
                
                cg::Question * newQ = new cg::Question(cgzr->question, cgzr->explanation, cgzr->answers, cgzr->answer);
                
                output.push_back(newQ);
                
            }
            
        }
        closedir(dir);
    }
    else{
        perror("Couldn't open directory");
    }
    
    return output;
}