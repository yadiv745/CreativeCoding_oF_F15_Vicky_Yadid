//
//  Leaf.cpp
//  alphaMaskingShaderExample
//
//  Created by Vicky Yadid on 12/11/15.
//
//

#include "Leaf.h"



//--------------------------------------------------------------
void Leaf::setup(){
    //position: float xPos , yPos
    //lenght and width: float leafLength, leafWidth
    //stem: float stemLeaf
    //rotation: float rotation
    //leaf color: float leafColor
    //stem color: float stemColor
    //scale: float scaleFactor
    
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    leafLength = ofRandom (150, 350);
    leafWidth = ofRandom (50,150);
    leafColor = ofColor(251, 135, 250, 70);
    
    stemLength = ofRandom (2,5);
    stemWidth = ofRandom (2,10);
    stemColor = ofColor (138,90,69, 70);
    
    leafNewLength = ofRandom(100, 300);
    leafNewWidth = ofRandom(50,100);
    leafNewColor = ofColor(ofRandom(0,30), ofRandom(100,255), ofRandom(50,100), 70);
    
    leafNewNewLength = ofRandom(150, 300);
    leafNewNewWidth = ofRandom(100,150);
    leafNewNewColor = ofColor(ofRandom(100,255), ofRandom(15,50), ofRandom(20,50), 90);
    
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
    ofSetColor (leafColor);
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
    ofSetColor (stemColor);
    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafLength/4));
    
    
    //2
    //leaf new
    
    //left leaf
    ofSetColor (leafNewColor);
    ofBeginShape();
    x0 = 0;
    x1 = x0 - leafNewWidth/2;
    x2 = x0 - leafNewWidth/4;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafNewLength/3;
    y2 = y1 - leafNewLength/3;
    y3 = y0 - leafNewLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafNewWidth/2;
    x2 = x0 + leafWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafNewLength/3;
    y2 = y1 - leafNewLength/3;
    y3 = y0 - leafNewLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    //draw stem
    ofSetColor (stemColor);
    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafNewLength/4));
    
    
    
    ofEndShape();
    
    
    //3
    //leaf new new
    
    //left leaf
    ofSetColor (leafNewNewColor);
    ofBeginShape();
    x0 = 0;
    x1 = x0 - leafNewNewWidth/2;
    x2 = x0 - leafNewNewWidth/4;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafNewNewLength/3;
    y2 = y1 - leafNewNewLength/3;
    y3 = y0 - leafNewNewLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafNewNewWidth/2;
    x2 = x0 + leafNewWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafNewNewLength/3;
    y2 = y1 - leafNewNewLength/3;
    y3 = y0 - leafNewNewLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    //draw stem
    ofSetColor (stemColor);
    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafNewNewLength/4));
    
    
    ofEndShape();
    
    
    
    //4
    //leaf falling one
    //     ofSetColor (leafFallingColor);
    //
    //    ofBeginShape();
    //
    //    x0 = xPos;
    //    x1 = x0 - leafFallingWidth;
    //    x2 = x0 - leafFallingWidth/4;  //leafCurvature;
    //    x3 = x0;
    //
    //   y0 = yPos - stemFallingLength;
    //   y1 = y0 - leafFallingLength/3;
    //   y2 = y1 - leafFallingLength/3;
    //   y3 = y0 - leafFallingLength;
    //
    //    ofVertex(x0,y0);
    //    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    //
    //
    //    ofEndShape();
    //
    //    //draw right half of leaf
    //
    //    ofBeginShape();
    //
    //    x0 = xPos;
    //    x1 = x0 + leafFallingWidth;
    //    x2 = x0 + leafFallingWidth/4; //leafCurvature;
    //    x3 = x0;
    //
    //    y0 = yPos - stemFallingLength;
    //    y1 = y0 - leafFallingLength/3;
    //    y2 = y1 - leafFallingLength/3;
    //    y3 = y0 - leafFallingLength;
    //
    //    ofVertex(x0,y0);
    //    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    //
    //    ofEndShape();
    
    //draw stem falling
    //    ofSetColor (stemColorFalling);
    //    ofRect (xPos, yPos - (stemFallingLength/2), stemFallingWidth, stemFallingLength);
    //    ofTriangle (xPos - stemFallingWidth/2, yPos - stemFallingLength, xPos + stemFallingWidth/2, yPos - stemFallingLength, xPos, yPos- stemFallingLength - 3*(leafFallingLength/4));
    
    ofPopMatrix();
    
}

//--------------------------------------------------------------
