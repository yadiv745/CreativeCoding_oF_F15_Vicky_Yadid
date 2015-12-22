#include "ofApp.h"

ofImage image;
ofImage image2;

//--------------------------------------------------------------
void ofApp::setup(){
    ofToggleFullscreen();

    
    ofSetLogLevel( OF_LOG_VERBOSE );
    
    //shader parameters before loading shader
    shader.setGeometryInputType( GL_LINES );
    shader.setGeometryOutputType( GL_LINE_STRIP );
    shader.setGeometryOutputCount( 128 );	//Maximal possible number of output vertices

    //koad shader
   shader.load( "shaderVert.c", "shaderFrag.c", "shaderGeom.c" );
    
    
    fbo.allocate( ofGetWidth(), ofGetHeight() );
//   image.loadImage( "sunflower-transp.png" );
 //   image.loadImage( "Untitled-1-01.png" );
    image.loadImage( "Untitled-2-01.png" );
    image2.loadImage("title-01.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    float w = ofGetWidth();
    float h = ofGetHeight();
    
    // drawing image to fbo
fbo.begin();
    ofBackground( 0, 0, 0, 0 );
    ofSetColor( 255, 255, 255 );
//    float w1 = image.width * 2;
//    float h1 = image.height * 2;
   // image.draw( w/2-w1/2, h/2-h1/2, w1, h1 );
    image.draw(ofGetWidth()/5, ofGetHeight()/3);
    image2.draw(ofGetWidth()/5, ofGetHeight()/8);
    fbo.end();
    
    //Reading contents of rendered fbo.
    //line drawing
    ofPixels pixels;
    fbo.readToPixels(pixels);

    //drawing to screen
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    
    //enable shader
    shader.begin();
    
    //shader's parameters
    float time = ofGetElapsedTimef();
    shader.setUniform1f( "time", time );
    shader.setUniformTexture( "texture", fbo.getTextureReference(), 1 );
    
    //Draw lines (through vertex->geometry->fragment shaders)
    ofSetColor( 255, 255, 255 );
    int stepx = 10;
    int stepy = 10;
    float len = 20;
    //Scan fbo pixels colors and search for not-transparent pixels
    for (int y=0; y<h; y+=stepy) {
        for (int x=0; x<w; x+=stepx) {
            if ( pixels.getColor( x, y ).a > 0 ) {
                //Draw line
                ofLine( x, y, x, y - len );
            }
        }
    }
    
    shader.end();
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key=='f'){
        ofToggleFullscreen();
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
