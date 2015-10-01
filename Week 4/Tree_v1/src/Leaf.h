//
//  Leaf.h
//  Tree_v1
//
//  Created by Vicky Yadid on 9/29/15.
//
//

#ifndef __Branches__Leaf__
#define __Branches__Leaf__

#include "ofMain.h"

class Leaf {
    
public:
    
    void setup(float _branchAngle);
    void update();
    void draw(float _xPos, float _yPos);
    
private:
    
    ofColor stemColor;
    ofColor leafColor;
    float xPos, yPos;
    float scaleFactor;
    float rotation;
    float _branchAngle; 
    
    float stemLength, stemWidth;
    float leafLength, leafWidth;
    float leafCurvature;
    
    //leaf 2
    ofColor leaf2Color;
    float leaf2Length, leaf2Width;
    
    //leaf 3
//    ofColor leaf3Color;
//    float leaf3Length, leaf3Width; 
    
    
    
    
    
    
//    float randomNumber;

    
};

#endif /* defined(__Branches__Leaf__) */
