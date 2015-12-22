#pragma once

#define WEBCAM

#include "ofMain.h"
#include "ofxInkSim.h"
#include "ofxMoodMachine.h"
#include "SampleBrush.h"
#include "GUI.h"
#include "Leaf.h"



class ofApp : public ofBaseApp{
public:
    
    void setup();
    void update();
    void draw();
    void drawLeaf();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	
    ofImage     srcImg2;
    ofImage     dstImg2;
    ofImage     brushImg2;
    
    ofFbo       maskFbo2;
    ofFbo       fbo2;
    
    ofShader    shader2;
    
    bool        bBrushDown;

    GUI gui;
    ofxMoodMachine moodmachine;
    
    ofxInkSim inkSim;
    SampleBrush brush;
    
private:
    vector < Leaf > leaves;
    int numLeaves;
    int numLeavesFalling;
    
    
    //leaf variables
//    float xPos , yPos;
//    float leafLength, leafWidth;
//    float rotation;
//    ofColor leafColor;
//    float scaleFactor;
//    float leafCurvature;
//    float stemLength;
//    
  
    

};
