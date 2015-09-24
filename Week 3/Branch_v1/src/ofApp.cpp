#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    bool hasDrawn = false;
    
    /*myBranch.setup(;, <#float _yPos#>, <#float _width#>, <#float _length#>, <#float _splitPercentage#>, <#int _maxSubdivisions#>, <#int _maxSegments#>, <#int _segmentsSinceStart#>, <#float _angle#>, <#float _curvature#>, <#ofColor _color#>);*/
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
   //o que Ž isso?
    if(ofGetElapsedTimeMillis() > 500 && ofGetElapsedTimeMillis() < 1000 && hasDrawn == false){}
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
    myBranch.setup(ofGetWidth()/2, ofGetHeight()/2, 25, 35, 0.35, 3, 6, 0, PI/2, 0, ofColor(138,90,69));
    
    
    //xPos, yPos, width, length, splitPercentage, maxSubdivisions,maxSegments, segmentsSinceStart, angle, curvature, color
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
