#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    lastTime = ofGetElapsedTimef();
    duration = 3;

    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    petalLength = 300;
    petalWidth = 150;
    rotation = 360;
    scaleFactor = ofRandom(.5, 1);
    petalCurvature = ofRandom(1,5);
    
    petal2Length= 300;
    petal2Width = 150;
    
    petal3Length= 300;
    petal3Width = 150;
    
    petal4Length= 300;
    petal4Width = 150;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float diffTimer = ofGetElapsedTimef() - lastTime;
    if(diffTimer > duration) {
        printf("Time %f\n", ofGetElapsedTimef());
        ofSetColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
        lastTime = ofGetElapsedTimef();
    
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofRotateZ(rotation);
    ofRotate(rotation, xPos, yPos, 0);
    
    ofTranslate(xPos, yPos);
    ofRotate(rotation);
    ofScale(scaleFactor, scaleFactor);
    
    
    //petal1
    ofBeginShape();
    float x0 = 0;
    float x1 = x0 - petalWidth/2;
    float x2 = x0 - petalWidth/4;
    float x3 = x0;
    
    float y0 = 0;
    float y1 = y0 + petalLength/3;
    float y2 = y1 + petalLength/3;
    float y3 = y0 + petalLength;
    
    ofRotate(0, x0, y0, 30);
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    ofBeginShape();
    x0 = 0;
    x1 = x0 + petalWidth/2;
    x2 = x0 + petalWidth/petalCurvature;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + petalLength/3;
    y2 = y1 + petalLength/3;
    y3 = y0 + petalLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    //stem rectangle
    ofBeginShape();
    ofRect(x0, y0 - (stemLength/2), stemWidth, stemLength);
    ofEndShape();
    
    
    
    //petal2
    ofBeginShape();
    ofRotate(70, x0, y0, 30);
    
    x0 = 0;
    x1 = x0 - petal2Width/2;
    x2 = x0 - petal2Width/4;
    x3 = 0;
    
    y0 = 0;
    y1 = y0 + petal2Length/3;
    y2 = y1 + petal2Length/3;
    y3 = y0 + petal2Length;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    ofBeginShape();
    x0 = 0;
    x1 = x0 + petal2Width/2;
    x2 = x0 + petal2Width/petalCurvature;
    x3 = 0;
    
    y0 = 0;
    y1 = y0 + petal2Length/3;
    y2 = y1 + petal2Length/3;
    y3 = y0 + petal2Length;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    //petal3
    ofBeginShape() ;
    ofRotate(70, x0, y0, 30);
    
    x0 = 0;
    x1 = x0 - petal3Width/2;
    x2 = x0 - petal3Width/4;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + petal3Length/3;
    y2 = y0 + petal3Length/3;
    y3 = y0 + petal3Length;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    ofEndShape();
    
    ofBeginShape();
    x0 = 0;
    x1 = x0 + petal3Width/2;
    x2 = x0 + petal3Width/petalCurvature;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + petal3Length/3;
    y2 = y0 + petal3Length/3;
    y3 = y0 + petal3Length;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    //petal4
    ofBeginShape() ;
    ofRotate(80, x0, y0, 30);
    
    x0 = 0;
    x1 = x0 - petalWidth/2;
    x2 = x0 - petalWidth/4;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + petalLength/3;
    y2 = y0 + petalLength/3;
    y3 = y0 + petalLength;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    ofEndShape();
    
    ofBeginShape();
    x0 = 0;
    x1 = x0 + petalWidth/2;
    x2 = x0 + petalWidth/petalCurvature;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + petalLength/3;
    y2 = y0 + petalLength/3;
    y3 = y0 + petalLength;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    //petal5
    ofBeginShape() ;
    ofRotate(70, x0, y0, 20);
    
    x0 = 0;
    x1 = x0 - petal4Width/2;
    x2 = x0 - petal4Width/4;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + petal4Length/3;
    y2 = y0 + petal4Length/3;
    y3 = y0 + petal4Length;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    ofEndShape();
    
    ofBeginShape();
    x0 = 0;
    x1 = x0 + petal4Width/2;
    x2 = x0 + petal4Width/petalCurvature;
    x3 = x0;
    
    y0 = 0;
    y1 = y0 + petal4Length/3;
    y2 = y0 + petal4Length/3;
    y3 = y0 + petal4Length;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    ofEndShape();
    
    
    ofPopMatrix();
    
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
