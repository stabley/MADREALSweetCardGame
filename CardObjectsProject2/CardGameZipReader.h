//
//  CardGameZipReader.h
//  CardObjectsTester
//
//  Created by Matt on 8/31/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#ifndef __CardObjectsTester__CardGameZipReader__
#define __CardObjectsTester__CardGameZipReader__

#include <iostream>
#include "zip.h"
#include <string>
#include <vector>

namespace cg {
    class CardGameZipReader{
    public:
        
        CardGameZipReader();
        ~CardGameZipReader();
        
        std::string question;
        std::string explanation;
        std::string answer;
        std::vector<std::string> answers;
        
        void getDataFromArchive(std::string path);
        void getDataFromArchive(struct zip * arch);
        
        
    protected:
    private:
        
        
        class ZipReaderHelper;
        std::shared_ptr<ZipReaderHelper> helper;
        
    };
}

#endif /* defined(__CardObjectsTester__CardGameZipReader__) */
