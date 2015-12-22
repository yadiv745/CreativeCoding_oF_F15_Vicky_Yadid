//
//  Leaf.h
//  alphaMaskingShaderExample
//
//  Created by Vicky Yadid on 12/11/15.
//
//

#ifndef __alphaMaskingShaderExample__Leaf__
#define __alphaMaskingShaderExample__Leaf__

#include <ofMain.h>

#endif /* defined(__alphaMaskingShaderExample__Leaf__) */

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

};