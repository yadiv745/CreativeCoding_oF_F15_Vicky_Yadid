//
//  LeafBranch.h
//  flowerTimer
//
//  Created by Vicky Yadid on 11/19/15.
//
//

#ifndef __flowerTimer__LeafBranch__
#define __flowerTimer__LeafBranch__

#include <ofMain.h>
#endif /* defined(__flowerTimer__LeafBranch__) */


class LeafBranch {
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