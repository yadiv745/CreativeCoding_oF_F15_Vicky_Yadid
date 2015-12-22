//
//  Leaf.h
//  mySketch_addons_leaf
//
//  Created by Vicky Yadid on 12/9/15.
//
//

#ifndef __mySketch_addons_leaf__Leaf__
#define __mySketch_addons_leaf__Leaf__

#include <ofMain.h>

#endif /* defined(__mySketch_addons_leaf__Leaf__) */


class Leaf {
public:
    void setup();
    void update();
    void draw();
    
    
    //variables of the leaf
    float xPos , yPos;
    float leafLength, leafWidth;
    float stemLeaf;
    float stemLength, stemWidth;
    float rotation;
    ofColor leafColor;
    ofColor stemColor;
    float scaleFactor;
    float leafCurvature;
};