//
//  Grass.h
//  flowerTimer
//
//  Created by Vicky Yadid on 11/19/15.
//
//

#ifndef __flowerTimer__Grass__
#define __flowerTimer__Grass__

#include <ofMain.h>

#endif /* defined(__flowerTimer__Grass__) */

class Grass {
public:
    void setup();
    void update();
    void draw();
    
    //variables of the leaf
    
    float xPos , yPos;
    
    float leafBranchLength, leafBranchWidth;
    ofColor leafBranchColor;
    ofColor stemColor;
    
    float stemLeaf;
    float stemLength, stemWidth;
    float rotation;
    float scaleFactor;
    float leafCurvature;
    
};