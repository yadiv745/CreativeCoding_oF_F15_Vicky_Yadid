#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
   lastTime = ofGetElapsedTimef();
    duration = 3;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float diffTime = ofGetElapsedTimef() - lastTime;
    if(diffTime > duration) {
        printf("Time %f \n", ofGetElapsedTimef());
        ofSetColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
        lastTime = ofGetElapsedTimef();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofCircle (ofGetWidth()/2, ofGetHeight()/2, 100);
    
    
    


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
