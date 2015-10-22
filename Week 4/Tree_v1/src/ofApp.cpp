#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    bool hasDrawn = false;
    ofRectMode(RECT_MODE_CENTER);
     ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofBackground (125, 125, 125);
myBranch1.setup(ofGetWidth()/3, 2*(ofGetHeight()/2), 20, 120, 0.35, PI/4, 2, 5, 0, -PI/2, 0, ofColor(73, 36, 13));
    

//myBranch2.setup(ofGetWidth()/2,      //float _xPos
//               2*(ofGetHeight()/2),     //float _yPos
//               //                   ofGetHeight()/2,     //float _yPos
//               20,                  //float _width
//               80,                  //float _length
//               0.35,                //float _splitPercentage
//               PI/4,                //float _maxSplitAngle
//               2,                   //int _maxSubdivisions
//               5,                   //int _maxSegments
//               0,                   //int _segmentsSinceStart
//               -PI/2,                //float _angle
//               0,                   //float _curvature
//               ofColor(73, 36, 13)); //ofColor _color
    


}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
