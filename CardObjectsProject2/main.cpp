//
//  main.cpp
//  CardObjectsProject2
//
//  Created by Matt on 9/7/14.
//  Copyright (c) 2014 Matt Antalek. All rights reserved.
//

#include "BigObject.h"
#include <iostream>

int main(int argc, const char * argv[])
{
    
    std::shared_ptr<cg::BigObject> bo(new cg::BigObject());
    
    bo->run();
    
    
    return 0;

}

