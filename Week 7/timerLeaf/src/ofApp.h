#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //timer
    float lastTime;
    float duration;
    
    //flower 
    float xPos, yPos;
    float stemLength, stemWidth;
    ofColor stemColor;
    float rotation;
    float scaleFactor;
    float petalCurvature;
    
    //petal
    float petalLength, petalWidth;
    
    //petal2
    float petal2Length, petal2Width;
    
    //petal3
    float petal3Length, petal3Width;
    
    //petal4
    float petal4Length, petal4Width;
    
    
		
};
