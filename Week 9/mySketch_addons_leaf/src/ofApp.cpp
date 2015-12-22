#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofToggleFullscreen();
    
    inkSim.setup();
    gui.setup(inkSim.getUniformInfo());
    
    moodmachine.setSpeed(1.0);
    
    myPos.x = ofGetWidth()/2;
    myPos.y = ofGetHeight()/2;
    
    myLeaf.setup();
   
}

//--------------------------------------------------------------
void ofApp::update(){
inkSim.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    inkSim.draw();
    gui.draw();
    
    
    //Defining the color:
    ofColor c = moodmachine;
    myTestColor = getInkColor(c.getHueAngle(), 255, 255);
    
    //original code that we used as example:
    //  inkSim.stroke(&brush, ofGetMouseX(), ofGetMouseY(), getInkColor(c.getHueAngle(), 255, 10));
    
    //here is a test of using mouse position:
    inkSim.stroke(&brush, ofGetMouseX(),ofGetMouseY(), myTestColor );
    
    //here is a test of just using a position
    //inkSim.stroke(&brush, myPos.x, myPos.y, myTestColor);
    
    //circle drawing
    //only a circle
    //ofCircle(myPos.x, myPos.y, 50);
    
   // ofCircle(ofGetMouseX(),ofGetMouseY(), 50);

    myLeaf.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='f'){
        ofToggleFullscreen();
    }
    
    if (key == '1')
    {
        inkSim.setDrawMode(ofxInkSim::INKFIX);
    }
    else if (key == '2')
    {
        inkSim.setDrawMode(ofxInkSim::INKSURF);
    }
    else if (key == '3')
    {
        inkSim.setDrawMode(ofxInkSim::INKFLOW);
    }
    else if (key == '4')
    {
        inkSim.setDrawMode(ofxInkSim::WATERFLOW);
    }
    else if (key == 'd')
    {
        inkSim.toggleDebug();
    }
    else if (key == ' ')
    {
        gui.toggleVisible();
    }
    else if (key == 'r')
    {
        gui.resetToDefault();
    }
    
    else if (key == 'c')
    {
        inkSim.clear();
    }


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
    inkSim.stopStroke(&brush);
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
