#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numLeaves = (int)ofRandom(10,20);
    for (int i=0; i < numLeaves; i++) {
        Leaf tempLeaf;
        tempLeaf.setup();
        leaves.push_back(tempLeaf);
    }
    
    numLeavesFalling = (int)ofRandom(10,20);
    for (int j=0; j < numLeaves; j++) {
        Leaf tempLeaf;
        tempLeaf.setup();
        leaves.push_back(tempLeaf);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < numLeaves; i++){
        leaves[i].update();
    }
    
    for (int j = 0; j < numLeavesFalling; j++){
        leaves[j].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < numLeaves; i++){
        leaves[i].draw();
    }
    
    for (int j = 0; j < numLeavesFalling; j++){
        leaves[j].draw();
    }
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
    leaves.clear();
    setup();
    
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
