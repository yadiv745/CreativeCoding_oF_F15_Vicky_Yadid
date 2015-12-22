#include "ofApp.h"
#include "ofxInkSim.h"
#include "ofxInkSim.h"


//--------------------------------------------------------------
void ofApp::setup(){
    inkSim.setup();
    gui.setup(inkSim.getUniformInfo());
    moodmachine.setSpeed(1.0);
    
    
    myPos.x = ofGetWidth()/2;
    myPos.y = ofGetHeight()/2;
    
    //Set control points values
    stem0 = ofPoint( 300, 100 );
    stem1 = ofPoint( 300, 270 );
    stem2 = ofPoint( 300, 300 );
    stem3 = ofPoint( 300, 400 );
    
    leftLeaf = ofPoint( 200, 220 );
    rightLeaf = ofPoint( 400, 220 );
    
    //Move leftLeaf and rightLeaf by shifting their on some values
    
    //Compute shift values
    float time = ofGetElapsedTimef();
    float shiftX = sin(time * M_TWO_PI * 0.33 + 33.1 ) * 30.0;
    //0.33 - speed, 33.1 - arbitrary phase shift, 30.0 - amplitude of shift in x
    
    float shiftY = sin(time * M_TWO_PI * 0.25 + 54.2) * 15.0;
    //0.25 - speed, 54.2 - arbitrary phase shift, 30.0 - amplitude of shift in y
    
    //Symmetrically shifting
    leftLeaf += ofPoint( shiftX, shiftY );
    rightLeaf += ofPoint( -shiftX, shiftY );

}

//--------------------------------------------------------------
void ofApp::update(){
    
    inkSim.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
   // ofBackground(255,0,0);
    inkSim.draw();
    gui.draw();
      drawFlower();
    
  //  ofColor c = moodmachine;
    
        inkSim.stroke(&brush, myPos.x , myPos.y, getInkColor(moodmachine.getHueAngle(), 255, 10));
    

    
  
    
   }

//--------------------------------------------------------------

void ofApp::drawFlower(){
   // ofBackground(255,0,0);
//        ofSetColor(0,0,255);
//    ofFill();
ofSetCircleResolution( 40 );			//Increase smoothing of the circle

ofCircle( stem0, 40 );					//Blossom
ofLine( stem0, stem3 );					//Stem
ofTriangle( stem1, stem2, leftLeaf );	//Left leaf
ofTriangle( stem1, stem2, rightLeaf );	//Right leaf
    
//        mouseReleased(x3, y3, 1);

//Drawing petals

ofPushMatrix();		//Store the coordinate system

//Translate the coordinate system center to stem0
ofTranslate( stem0 );

//Rotate the coordinate system depending on the time
float angle = ofGetElapsedTimef() * 30;
ofRotate( angle );

int petals = 15;	//Number of petals
for (int i=0; i<petals; i++) {
    //Rotate the coordinate system
    ofRotate( 360.0 / petals );
    
    //Draw petal as a triangle
    ofPoint p1( 0, 20 );
    ofPoint p2( 80, 0 );
    ofTriangle( p1, -p1, p2 );
}

//Restore the coordinate system
ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    
    ofColor c = moodmachine;
    inkSim.stroke(&brush, x, y, getInkColor(c.getHueAngle(), 255, 10));
}

void ofApp::mouseReleased(int x, int y, int button)
{
    inkSim.stopStroke(&brush);
}

void ofApp::keyPressed(int key)
{
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

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
