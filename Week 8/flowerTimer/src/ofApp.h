#pragma once

#include "ofMain.h"
#include "LeafBorn.h"
#include "LeafGrow.h"
#include "LeafBranch.h"
//#include "Branch.h"

#include "StemBranch.h"
#include "FlowerBorn.h"
#include "FlowerGrow.h"
#include "Grass.h"


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
    
    //timeSinceLastImportantMomemt
  //  float timeOfLastImportantMomemt; //for our timer in ofApp.update();
//    float xPos, yPos;
//    float stemLength1, stemWidth1, stemLength2, stemWidth2;
//    float beginTime;
//    float duration;
    
    int radius, width, height;
    float xPos, yPos;
    int heightTemp;
     float angle;

private:
    vector < Leaf > leaves;
    int numLeaves;
    
    vector < FlowerBorn > flowerBorn;
    int numFlowerBorn;
    
    vector < LeafGrow > leavesGrow;
    int numGrowLeaves;
    
    vector < FlowerGrow > flowerGrow;
    int numFlowerGrow;
    
    vector < LeafBranch > leafBranch;
    int numLeafBranch;
    
//    vector < StemBranch > stemBranch;
//    int numStemBranch;

    vector < Grass > grassGrass;
    int numGrassGrass;

    float mainStemWidth;
    float mainStemHeight;
    
//    Branch myBranch;
    bool hasDrawn;

    
     bool order;

    ofColor bgColor1;
    ofColor bgColor2;

		
};
