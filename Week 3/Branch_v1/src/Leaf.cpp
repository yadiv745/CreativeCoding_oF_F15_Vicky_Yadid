//
//  Leaf.cpp
//  Branch_v1
//
//  Created by Vicky Yadid on 9/21/15.
//
//

#include "Leaf.h"

//--------------------------------------------------------------
void Leaf::setup(){
    
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    
    //leaf1
    leafLength = ofRandom (50,150);
    leafWidth = ofRandom (16, 50);
    leafColor = ofColor(251, 135, 250, 70);
    
    //leaf2
    leaf2Length = ofRandom(33, 100);
    leaf2Width = ofRandom(16, 50);
    leaf2Color = ofColor(ofRandom(0,30), ofRandom(100,255), ofRandom(50,100), 70);
    
    //leaf3
    leaf3Length = ofRandom(50, 100);
    leaf3Width = ofRandom(33, 50);
    leaf3Color = ofColor(ofRandom(100,255), ofRandom(15,50), ofRandom(20,50), 90);

    stemLength = ofRandom (2,5);
    stemWidth = ofRandom (2,10);
    stemColor = ofColor (138,90,69, 70);

    rotation = ofRandom(0,360);
    scaleFactor = ofRandom(.5, 1.0);
    ofSetRectMode (OF_RECTMODE_CENTER);
    leafCurvature = ofRandom(1,5);
    
    //leaf falling
    leafFallingLength = ofRandom(20,50);
    leafFallingWidth = ofRandom(10,20);
    leafFallingColor =  ofColor(ofRandom(100,255), ofRandom(15,50), ofRandom(20,50), 90);
    stemFallingLength = ofRandom(1,3);
    stemFallingWidth = ofRandom (1,3);
    stemColorFalling = ofColor (138,90,69);
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw (float _xPos, float _yPos){
    ofPushMatrix();
    ofSetLineWidth(1);
    ofTranslate(_xPos, _yPos);
    ofScale(scaleFactor, scaleFactor);
    ofRotateZ(rotation);

    
    //1
    //draw leaf
    ofSetColor(leafColor);
    //draw left half of leaf
    
    ofBeginShape();
    float x0 = 0;
    float x1 = x0 - leafWidth;
    float x2 = x0 - leafWidth/leafCurvature;
    float x3 = x0;
    
    float y0 = 0 - stemLength;
    float y1 = y0 - leafLength/3;
    float y2 = y1 - leafLength/3;
    float y3 = y0 - leafLength;
    
    
    ofVertex(x0, y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //draw right half of leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafWidth;
    x2 = x0 + leafWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafLength/3;
    y2 = y1 - leafLength/3;
    y3 = y0 - leafLength;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //2
    //draw leaf2
    ofSetColor(leaf2Color);
    //draw left half of leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 - leaf2Width;
    x2 = x0 - leaf2Width/leafCurvature;
    x3 = x0;
    
     y0 = 0 - stemLength;
     y1 = y0 - leaf2Length/3;
     y2 = y1 - leaf2Length/3;
     y3 = y0 - leaf2Length;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //draw right half of leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leaf2Width;
    x2 = x0 + leaf2Width/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leaf2Length/3;
    y2 = y1 - leaf2Length/3;
    y3 = y0 - leaf2Length;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();

    //3
    //draw leaf3
    ofSetColor(leaf3Color);
    //draw left half of leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 - leaf3Width;
    x2 = x0 - leaf3Width/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leaf3Length/3;
    y2 = y1 - leaf3Length/3;
    y3 = y0 - leaf3Length;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //draw right half of leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leaf3Width;
    x2 = x0 + leaf3Width/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leaf3Length/3;
    y2 = y1 - leaf3Length/3;
    y3 = y0 - leaf3Length;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
//
//    //leaf falling
//    ofSetColor(leafFallingColor);
//    //draw left half of leaf
//    ofBeginShape();
//    x0 = xPos;
//    x1 = x0 - leafFallingWidth;
//    x2 = x0 - leafFallingWidth/leafCurvature;
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
//    
//    //draw right half of leaf
//    ofBeginShape();
//    x0 = xPos;
//    x1 = x0 + leafFallingWidth;
//    x2 = x0 + leafFallingWidth/leafCurvature;
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
//    
//    //draw stem falling
//    ofSetColor (stemColorFalling);
//    ofRect (0,0 - (stemFallingLength/2), stemFallingWidth, stemFallingLength);
//    float x33 = 0 - stemFallingWidth/2;
//    float x44 = 0 + stemFallingWidth/2;
//    
//    ofTriangle (x33, 0 - stemFallingLength, x44, 0 - stemFallingLength, 0, 0 - stemFallingLength - 3* (leafFallingLength/4));
//
//
//    //draw stem leaf
//    ofSetColor(stemColor);
//    ofRect(0,0 - (stemLength/2), stemWidth, stemLength); //MATH!
//    
//    //o que é isso?
//    float x11 = 0 - stemWidth/2;
//    float x22 = 0 + stemWidth/2;
//    
//    ofTriangle(x11, 0 - stemLength, x22, 0 - stemLength, 0, 0 - stemLength - 3*(leafLength/4));
    
//    cout << "x1 = ";
//    cout << x1 << endl;
//    cout << "x2 = ";
//    cout << x2 << endl;
    
    ofPopMatrix();

}

//--------------------------------------------------------------
