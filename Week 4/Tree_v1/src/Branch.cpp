//
//  Branch.cpp
//  Tree_v1
//
//  Created by Vicky Yadid on 9/29/15.
//
//

#include "Branch.h"

//--------------------------------------------------------------
void Branch::setup (float _xPos,
                   float _yPos,
                   float _width,
                   float _length,
                   float _splitPercentage,
                   float _maxSplitAngle,
                   int _maxSubdivisions,
                   int _maxSegments,
                   int _segmentsSinceStart,
                   float _angle,
                   float _curvature,
                   ofColor _color){
    
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    length = _length;
    splitPercentage = _splitPercentage;
    maxSplitAngle = _maxSplitAngle;
    maxSubdivsions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
    
     ofSetFrameRate(60);
    
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofLine(xPos, yPos, xPos + length*cos(angle), yPos + length*sin(angle)); //draw the branch segnment
    

    //branch split
    if(ofRandom(0, 1) > splitPercentage && segmentsSinceStart != maxSegments){ //if random number between 0-1 is greater than split %, then split ... and never split on last branch
        split = true;
    } else{
        split = false;
    }
    
    
    // create leaves
    
    numLeaves = (int)ofRandom(0,4);
    if(segmentsSinceStart == maxSegments){ // make sure there are leaves at the end of the final branch
        numLeaves = (int)ofRandom(3,5);
    }
    if(segmentsSinceStart == 0){ // no leaves at the end of the first branch (aka the Trunk!)
        numLeaves = 0;
    }
    
        for(int i = 0; i < numLeaves; i++){
            Leaf tempLeaf;
            tempLeaf.setup(angle);
            leaves.push_back(tempLeaf);
        }

    
    //draw leaves on current branch
        for(int i = 0; i < numLeaves; i++){
            leaves[i].draw(xPos + length*cos(angle), yPos + length*sin(angle));
            //drawing leaves at the end of this branch...based on length and angle
        }
    

    //update variables to pass to next (sub) branch
    
    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*(ofRandom(0.5,0.8));
    length = length*(ofRandom(0.7, 0.9));
    angle += curvature;
    curvature += ofRandom(0, (float)(2*PI)/360.0);
    
    segmentsSinceStart += 1; // DO THIS OR THE RECURSION WILL NEVER STOP!!!
    
    
    //Recursion
    
    if (segmentsSinceStart <= maxSegments) {
        if(!split){ //if the branch does not split... just create one more branch to keep going (in roughly the same direction)
            Branch subBranch;
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivsions, maxSegments, segmentsSinceStart, angle, curvature, color);
        } else { //if the branch does split!! create two sub-branches
            cout << "split" << endl; //some feedback
            Branch subBranch1;
            float angle1 = angle + ofRandom(0, maxSplitAngle);
            Branch subBranch2;
            float angle2 = angle - ofRandom(0, maxSplitAngle);
            
            subBranch1.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivsions, maxSegments, segmentsSinceStart, angle1, curvature, color);
            
            subBranch2.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivsions, maxSegments, segmentsSinceStart, angle2, curvature, color);
        }
    }
}

//--------------------------------------------------------------
void Branch::update(){
    
}

//--------------------------------------------------------------
void Branch::draw(){
    
}