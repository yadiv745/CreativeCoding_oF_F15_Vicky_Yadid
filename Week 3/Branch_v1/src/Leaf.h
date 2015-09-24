//
//  Leaf.h
//  Branch_v1
//
//  Created by Vicky Yadid on 9/21/15.
//
//

#ifndef __Branch_v1__Leaf__
#define __Branch_v1__Leaf__

#include "ofMain.h"

#endif /* defined(__Branch_v1__Leaf__) */

class Leaf {
public:
    void setup();
    void update();
    void draw(float _xPos, float _yPos);
  
private:
    float xPos , yPos;
    float leafLength, leafWidth; //leaf1
    float leaf2Length, leaf2Width; //leaf2
    float leaf3Length, leaf3Width; //leaf3
    float stemLeaf;
    float stemLength, stemWidth;
    float rotation;
    ofColor leafColor; //leaf1 color
    ofColor leaf2Color; //leaf2 color
    ofColor leaf3Color; //leaf3 color
    ofColor stemColor;
    float scaleFactor;
    float leafCurvature;
 
    //leaf falling
    float leafFallingLength, leafFallingWidth;
    ofColor leafFallingColor;
    float stemFallingLength, stemFallingWidth;
    ofColor stemColorFalling;

};
    