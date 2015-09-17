//
//  Leaf.h
//  Leaf_v1
//
//  Created by Vicky Yadid on 9/10/15.
//
//

#ifndef __Leaf_v1__Leaf__
#define __Leaf_v1__Leaf__

#include <ofMain.h>

class Leaf {
public:
void setup();
void update();
void draw();


//variables of the leaf

//position
float xPos , yPos;

//leaf length and width
float leafLength, leafWidth;

//stem
float stemLeaf;

//stem length and width
float stemLength, stemWidth;

//rotation
float rotation;

//leaf color
ofColor leafColor;

//stem color
ofColor stemColor;

//scale
float scaleFactor;
    
//curvature
float leafCurvature;

    
//leaf new

//leaf new length and width
    float leafNewLength, leafNewWidth;
    
//leaf new color
    ofColor leafNewColor;
    

//leaf new new
    float leafNewNewLength, leafNewNewWidth;

//leaf new new color
    ofColor leafNewNewColor;

    
//leaf falling 
    float leafFallingLength, leafFallingWidth;
    
//leaf falling color
    ofColor leafFallingColor;

//leaf falling stem
    float stemFallingLength, stemFallingWidth;
    
//leaf falling stem color
    ofColor stemColorFalling;
    
};

#endif /* defined(__Leaf_v1__Leaf__) */
