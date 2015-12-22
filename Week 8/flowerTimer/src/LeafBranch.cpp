//
//  LeafBranch.cpp
//  flowerTimer
//
//  Created by Vicky Yadid on 11/19/15.
//
//

#include "LeafBranch.h"
//--------------------------------------------------------------
void LeafBranch::setup(){
    //position: float xPos , yPos
    //lenght and width: float leafLength, leafWidth
    //stem: float stemLeaf
    //rotation: float rotation
    //leaf color: float leafColor
    //stem color: float stemColor
    //scale: float scaleFactor
    
    xPos = 500;
    yPos = 715;
    
    //leaf is born
    leafBranchLength = ofRandom(40,70);
    leafBranchWidth = ofRandom(15,30);
    leafBranchColor = ofColor(170,208,56);
    
    stemLength = 2;
    stemWidth = 2;
    stemColor = ofColor (138,90,69, 70);
    
    rotation = ofRandom(0,360);
    scaleFactor = ofRandom(.5, 1.0);
    ofSetRectMode (OF_RECTMODE_CENTER);
    leafCurvature = ofRandom(1,5);
}

//--------------------------------------------------------------
void LeafBranch::update(){
    
}

//--------------------------------------------------------------
void LeafBranch::draw(){
    //    ofRect(xPos, yPos, 20,20); //test if code is working - white rect
    // cout << stemWidth << endl;  //this is println - displays values
    
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofScale(scaleFactor, scaleFactor);
    ofRotateZ(rotation);
    
    //born
    ofSetColor (leafBranchColor);
    ofBeginShape();
    float x0 = 0;
    float x1 = x0 - leafBranchWidth/2;
    float x2 = x0 - leafBranchWidth/4; // or leafCurvature
    float x3 = x0;
    
    float y0 = 0 -  stemLength;
    float y1 = y0 - leafBranchLength/3;
    float y2 = y1 - leafBranchLength/3;
    float y3 = y0 - leafBranchLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafBranchWidth/2;
    x2 = x0 + leafBranchWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafBranchLength/3;
    y2 = y1 - leafBranchLength/3;
    y3 = y0 - leafBranchLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    //draw stem
    ofSetColor (stemColor);
    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafBranchLength/4));
    
    ofPopMatrix();
    
}

//--------------------------------------------------------------

