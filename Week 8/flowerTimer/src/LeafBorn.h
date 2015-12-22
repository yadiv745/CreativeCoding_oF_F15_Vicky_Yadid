//
//  Leaf.h
//  flowerTimer
//
//  Created by Vicky Yadid on 11/18/15.
//
//

#ifndef __flowerTimer__Leaf__
#define __flowerTimer__Leaf__

#include "ofMain.h"


#endif /* defined(__flowerTimer__Leaf__) */


class Leaf {
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
