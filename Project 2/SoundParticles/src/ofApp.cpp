#include "ofApp.h"

const int N = 256;		//number in spectrum
float spectrum[ N ];	//smoothed spectrum values
float Rad = 500;		//circle radius parameter
float Vel = 0.1;		//circle velocity parameter
int bandRad = 2;		//Band index in spectrum, affecting Radius value
int bandVel = 100;		//Band index in spectrum, affecting Velocity value

const int n = 400;		//number of circles

//Offsets for Perlin noise calculation for points
float tx[n], ty[n];
ofPoint p[n];			//circles points positions

float time0 = 0;		//Time value, used for dt computing

//--------------------------------------------------------------
void ofApp::setup(){
    //sound sample loading + set perlin noise points
    
    //Set up sound sample
    sound.loadSound( "Firestone (feat. Conrad).mp3" );
    sound.play();
    soundSpeed = 1.0;
    
    //Set spectrum values to 0
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }
    
    //Initialize points offsets by random numbers
    for ( int j=0; j<n; j++ ) {
        tx[j] = ofRandom( 0, 1000 );
        ty[j] = ofRandom( 0, 1000 );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //gets played sound + set values to the array + recalculates Rad and Vel params
    
    //Update sound engine
    ofSoundUpdate();
    
    //Get current spectrum with N bands
    float *val = ofSoundGetSpectrum( N );
    
    //udpdate spectrum,
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.97;	//Slow decreasing
        spectrum[i] = max( spectrum[i], val[i] );
    }

    
    //Update particles using spectrum valuees
    
    //Computing dt as a time between the last and the current calling of update()
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp( dt, 0.0, 0.1 );
    time0 = time; //Store the current time
    
    //Update Rad and Vel from spectrum
    Rad = ofMap( spectrum[ bandRad ], 1, 3, 400, 800, true );
    Vel = ofMap( spectrum[ bandVel ], 0, 0.1, 0.05, 0.5 );
    
    //Update particles positions
    for (int j=0; j<n; j++) {
        tx[j] += Vel * dt;	//move offset
        ty[j] += Vel * dt;	//move offset
        //Calculate Perlin's noise in [-1, 1] and multiply on Rad
        p[j].x = ofSignedNoise( tx[j] ) * Rad;
        p[j].y = ofSignedNoise( ty[j] ) * Rad;
    }
    
    //update color
//    ofFloatColor color ( ofNoise (time*0.05), ofNoise(time*0.1), ofNoise(time*0.15));
//    color.setSaturation(1.0); //make the color maximally colorful
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);	//background white
    
    //particles
    //Move center of coordinate system to the screen center
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //Draw points
    ofSetColor (ofRandom(100,200), ofRandom(100,200), ofRandom(100,200));
    ofFill();
    for (int i=0; i<n; i++) {
        ofCircle( p[i], ofRandom(2, 6));
    }
    
    ofPopMatrix();
    
    //Subtitles on top
    ofSetColor( 255, 255);
    ofSetColor(0,0,0);
    ofDrawBitmapString(" P: Play    S: Stop    Left arrow: Speed Down    Right arrow: Speed Up" , ofPoint(ofGetWidth()/5, 20));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // 1 is normal speed ; less than 0 is backwards
    
    if (key == 'p') {
       sound.play();
    }
    
    if(key == 's'){
       sound.stop();
    }
    
    if (key == OF_KEY_LEFT) {
        soundSpeed = soundSpeed - 0.1;
       sound.setSpeed(soundSpeed);
    }
    
    
    if (key == OF_KEY_RIGHT){
        soundSpeed = soundSpeed + 0.1;
        sound.setSpeed(soundSpeed);
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
