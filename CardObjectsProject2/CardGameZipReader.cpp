//
//  CardGameZipReader.cpp
//  CardObjectsTester
//
//  Created by Matt on 8/31/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#include "CardGameZipReader.h"
#include <regex>

class cg::CardGameZipReader::ZipReaderHelper{
    
public:
    
    ZipReaderHelper(){};
    ~ZipReaderHelper(){/*std::cout << "Helper deleted" << std::endl;*/};
    
    
    std::vector<std::string> getFileNamesFromArchive(struct zip * arch){
        zip_int64_t nEntries = zip_get_num_entries(arch, ZIP_FL_UNCHANGED);
        std::vector<std::string> fnames;
        for (int i = 0; i < nEntries; i++) {
            std::string curName = zip_get_name(arch, i, ZIP_FL_UNCHANGED);
            fnames.push_back(curName);
        }
        return fnames;
    }
    
    std::string getDataForZFile(struct zip * arch, std::string fname){
        struct zip_stat zt;
        zip_stat_init(&zt);
        zip_stat(arch, fname.c_str(), 0, &zt);
        char * contents = new char[zt.size];
        
        zip_file * zFile = zip_fopen(arch, fname.c_str(), 0);
        zip_fread(zFile, contents, zt.size);
        zip_fclose(zFile);
        
        std::string output = contents;
        return output;
    }
    
    
    std::vector<std::string> getAnswersData(struct zip * arch)
    {
        std::vector<std::string> fnames = this->getFileNamesFromArchive(arch);
        std::vector<std::string> locanswers;
        std::string theFile = "answers.txt";
        for (int i = 0; i < fnames.size(); i++) {
            std::string curName = fnames.at(i);
            std::size_t found = curName.find(theFile);
            if ((found != std::string::npos) && (curName.find("MACOSX") == std::string::npos)) {
                //we got it
                
                std::string content = this->getDataForZFile(arch, curName);
                
                //break up the content
                std::size_t curpos = 0;
                std::size_t nextpos = 0;
                std::string delim = "\n";
                while ((nextpos = content.find_first_of(delim, curpos)) != std::string::npos){
                    
                    locanswers.push_back(content.substr(curpos, nextpos-curpos));
                    curpos = nextpos+1;
                    
                }
                
                break;
                
            }
        }
        
        
        return locanswers;
    }
    
    std::string getAnswerData(struct zip * arch)
    {
        std::vector<std::string> fnames = this->getFileNamesFromArchive(arch);
        std::string theFile = "answers.txt";
        std::string output;
        for (int i = 0; i < fnames.size(); i++) {
            std::string curName = fnames.at(i);
            std::size_t found = curName.find(theFile);
            if ((found != std::string::npos) && (curName.find("MACOSX") == std::string::npos)) {
                std::string content = this->getDataForZFile(arch, curName);
                
                
                
                std::regex ansReg("ANSWER : \\w");
                std::smatch ansMatch;
                
                std::regex_search(content, ansMatch, ansReg);
                output = ansMatch.str();
                output = output.substr(output.size()-1, output.size());
                break;
            }
            
        }
        
        return output;
    }
    
    std::string getQuestionData(struct zip * arch)
    {
        std::string output;
        std::vector<std::string> fnames = this->getFileNamesFromArchive(arch);
        std::string theFile = "question.txt";
        
        for (int i = 0; i < fnames.size(); i++) {
            std::string curName = fnames.at(i);
            std::size_t found = curName.find(theFile);
            if ((found != std::string::npos) && (curName.find("MACOSX") == std::string::npos)) {
                output = this->getDataForZFile(arch, curName);
            }
        }
        
        
        return output;
    }
    
    
    std::string getExplanationData(struct zip * arch)
    {
        std::string output;
        std::vector<std::string> fnames = this->getFileNamesFromArchive(arch);
        std::string theFile = "explanation.txt";
        
        for (int i = 0; i < fnames.size(); i++) {
            std::string curName = fnames.at(i);
            std::size_t found = curName.find(theFile);
            if ((found != std::string::npos) && (curName.find("MACOSX") == std::string::npos)) {
                output = this->getDataForZFile(arch, curName);
            }
        }
        
        
        return output;
    }
    
};



cg::CardGameZipReader::CardGameZipReader()
{
    this->question = "";
    this->explanation = "";
    this->answer = "";
    this->helper = std::shared_ptr<ZipReaderHelper>(new ZipReaderHelper());
}

cg::CardGameZipReader::~CardGameZipReader()
{
    
}



void cg::CardGameZipReader::getDataFromArchive(std::string path)
{
    int err = 0;
    struct zip * arch = zip_open(path.c_str(), 0, &err);
    this->getDataFromArchive(arch);
    zip_close(arch);
}

void cg::CardGameZipReader::getDataFromArchive(struct zip *arch)
{
    std::vector<std::string> fnames = this->helper->getFileNamesFromArchive(arch);
    
    this->answers = this->helper->getAnswersData(arch);
    
    this->answer = this->helper->getAnswerData(arch);
    
    this->explanation = this->helper->getExplanationData(arch);
    
    this->question = this->helper->getQuestionData(arch);
    
}


