//
//  StemBranch.h
//  flowerTimer
//
//  Created by Vicky Yadid on 11/19/15.
//
//

#ifndef __flowerTimer__StemBranch__
#define __flowerTimer__StemBranch__

#include <ofMain.h>

#endif /* defined(__flowerTimer__StemBranch__) */


class StemBranch {
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