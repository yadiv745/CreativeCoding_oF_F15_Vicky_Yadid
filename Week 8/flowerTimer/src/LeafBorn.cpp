//
//  Leaf.cpp
//  flowerTimer
//
//  Created by Vicky Yadid on 11/18/15.
//
//

#include "LeafBorn.h"


//--------------------------------------------------------------
void Leaf::setup(){
    //position: float xPos , yPos
    //lenght and width: float leafLength, leafWidth
    //stem: float stemLeaf
    //rotation: float rotation
    //leaf color: float leafColor
    //stem color: float stemColor
    //scale: float scaleFactor
        
    xPos = 500;
    yPos = 560;
    
    //leaf is born
    leafBornLength = 50;
    leafBornWidth = 25;
    leafBornColor =ofColor(244,226,59, 90);


    //leaf is growing
    leafGrowingLength = 40;
    leafGrowingWidth = 15;
    leafGrowingColor = ofColor(244,226,59, 90);
    
    //leaf grew
    leafGrowLength = 55;
    leafGrowWidth = 20;
    leafGrowColor = ofColor(249,226,6, 65);
    
    stemLength = 3;
    stemWidth = 3;
    stemColor = ofColor(247,239,170);

    rotation = ofRandom(0,360);
    scaleFactor = ofRandom(.5, 1.0);
    ofSetRectMode (OF_RECTMODE_CENTER);
    leafCurvature = ofRandom(1,5);
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw(){
    //    ofRect(xPos, yPos, 20,20); //test if code is working - white rect
   // cout << stemWidth << endl;  //this is println - displays values
    
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofScale(scaleFactor, scaleFactor);
    ofRotateZ(rotation);
    
    //born
    ofSetColor (leafBornColor);
    ofBeginShape();
    float x0 = 0;
    float x1 = x0 - leafBornWidth/2;
    float x2 = x0 - leafBornWidth/4; // or leafCurvature
    float x3 = x0;
    
    float y0 = 0 -  stemLength;
    float y1 = y0 - leafBornLength/3;
    float y2 = y1 - leafBornLength/3;
    float y3 = y0 - leafBornLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafBornWidth/2;
    x2 = x0 + leafBornWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafBornLength/3;
    y2 = y1 - leafBornLength/3;
    y3 = y0 - leafBornLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    //draw stem
    ofSetColor (stemColor);
    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafBornLength/4));
    
    
    //2
    //leaf new
    
    //left leaf
    ofSetColor (leafGrowingColor);
    ofBeginShape();
    x0 = 0;
    x1 = x0 - leafGrowingWidth/2;
    x2 = x0 - leafGrowingWidth/4;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafGrowingLength/3;
    y2 = y1 - leafGrowingLength/3;
    y3 = y0 - leafGrowingLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafGrowingWidth/2;
    x2 = x0 + leafBornWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafGrowingLength/3;
    y2 = y1 - leafGrowingLength/3;
    y3 = y0 - leafGrowingLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    //draw stem
    ofSetColor (stemColor);
    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafGrowingLength/4));
    
    
    
    ofEndShape();
    
    
    //3
    //leaf new new
    
    //left leaf
    ofSetColor (leafGrowColor);
    ofBeginShape();
    x0 = 0;
    x1 = x0 - leafGrowWidth/2;
    x2 = x0 - leafGrowWidth/4;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafGrowLength/3;
    y2 = y1 - leafGrowLength/3;
    y3 = y0 - leafGrowLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //right leaf
    ofBeginShape();
    x0 = 0;
    x1 = x0 + leafGrowWidth/2;
    x2 = x0 + leafBornWidth/leafCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafGrowLength/3;
    y2 = y1 - leafGrowLength/3;
    y3 = y0 - leafGrowLength;
    
    ofVertex (x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    //draw stem
    ofSetColor (stemColor);
    ofRect (0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle (0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafGrowLength/4));
    ofEndShape();
    
    ofPopMatrix();
    
}

//--------------------------------------------------------------

