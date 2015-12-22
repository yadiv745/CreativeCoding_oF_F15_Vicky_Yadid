//
//  FlowerBorn.h
//  flowerTimer
//
//  Created by Vicky Yadid on 11/19/15.
//
//

#ifndef __flowerTimer__FlowerBorn__
#define __flowerTimer__FlowerBorn__

#include "ofMain.h"

#endif /* defined(__flowerTimer__FlowerBorn__) */


class FlowerBorn {
public:
    void setup();
    void update();
    void draw();
    
    
    //variables of the leaf
    
    float xPos , yPos;
    
    
    float leafBornLength, leafBornWidth;
    ofColor leafBornColor;
    ofColor stemColor;
    
    float leafGrowingLength, leafGrowingWidth;
    ofColor leafGrowingColor;
    
    float leafGrowLength, leafGrowWidth;
    ofColor leafGrowColor;
    
    
    float stemLeaf;
    float stemLength, stemWidth;
    float rotation;
    float scaleFactor;
    float leafCurvature;
    
    
    
};