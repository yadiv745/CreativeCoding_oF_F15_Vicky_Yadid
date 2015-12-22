//
//  Leaf.cpp
//  mySketch_addons_leaf
//
//  Created by Vicky Yadid on 12/9/15.
//
//

#include "Leaf.h"

//--------------------------------------------------------------
void Leaf::setup(){
    
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    leafLength = ofRandom (150, 350);
    leafWidth = ofRandom (50,150);
//    leafColor = ofColor(251, 135, 250, 70);
    
    stemLength = ofRandom (2,5);
    stemWidth = ofRandom (2,10);
//    stemColor = ofColor (138,90,69, 70);
    
    rotation = ofRandom(0,360);
    scaleFactor = ofRandom(.5, 1.0);
//    ofSetRectMode (OF_RECTMODE_CENTER);
    leafCurvature = ofRandom(1,5);
    
    
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw(){
    //    ofRect(xPos, yPos, 20,20); //test if code is working - white rect
    cout << stemWidth << endl;  //this is println - displays values
    
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofScale(scaleFactor, scaleFactor);
    ofRotateZ(rotation);
    
    //1
    //left leaf
//    ofSetColor (myColor);
    ofBeginShape();
    float x0 = 0;
    float x1 = x0 - leafWidth/2;
    float x2 = x0 - leafWidth/4; // or leafCurvature
    float x3 = x0;
    
    float y0 = 0 -  stemLength;
    float y1 = y0 - leafLength/3;
    float y2 = y1 - leafLength/3;
    float y3 = y0 - leafLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafWidth/2;
    x2 = x0 + leafWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafLength/3;
    y2 = y1 - leafLength/3;
    y3 = y0 - leafLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    //draw stem
//    ofSetColor (stemColor);
//    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
//    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafLength/4));
    
    
    ofPopMatrix();
    
}