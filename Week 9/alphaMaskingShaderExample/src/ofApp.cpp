#include "ofApp.h"
#include "ofxInkSim.h"
#include "ofxInkSim.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableAlphaBlending();
    
    numLeaves = (int)ofRandom(10,20);
    for (int i=0; i < numLeaves; i++) {
        Leaf tempLeaf;
        tempLeaf.setup();
        leaves.push_back(tempLeaf);
    }
    
    inkSim.setup();
    gui.setup(inkSim.getUniformInfo());
    moodmachine.setSpeed(1.0);
    
    srcImg2.loadImage("C-01.jpg");
//    dstImg2.loadImage("B.jpg");
   // brushImg2.loadImage("brush.png");
    
    int width = srcImg2.getWidth();
    int height = srcImg2.getHeight();
    
    maskFbo2.allocate(width,height);
    fbo2.allocate(width,height);
    
    // There are 3 of ways of loading a shader:
    //
    //  1 - Using just the name of the shader and ledding ofShader look for .frag and .vert: 
    //      Ex.: shader.load( "myShader");
    //
    //  2 - Giving the right file names for each one: 
    //      Ex.: shader.load( "myShader.vert","myShader.frag");
    //
    //  3 - And the third one it�s passing the shader programa on a single string;
    //


    #ifdef TARGET_OPENGLES
    shader2.load("shaders_gles/alphamask.vert","shaders_gles/alphamask.frag");
    #else
    if(ofGetGLProgrammableRenderer()){
    	string vertex = "#version 150\n\
    	\n\
		uniform mat4 projectionMatrix;\n\
		uniform mat4 modelViewMatrix;\n\
    	uniform mat4 modelViewProjectionMatrix;\n\
    	\n\
    	\n\
    	in vec4  position;\n\
    	in vec2  texcoord;\n\
    	\n\
    	out vec2 texCoordVarying;\n\
    	\n\
    	void main()\n\
    	{\n\
	        texCoordVarying = texcoord;\
    		gl_Position = modelViewProjectionMatrix * position;\n\
    	}";
		string fragment = "#version 150\n\
		\n\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
        in vec2 texCoordVarying;\n\
		\
        out vec4 fragColor;\n\
		void main (void){\
		vec2 pos = texCoordVarying;\
		\
		vec3 src = texture(tex0, pos).rgb;\
		float mask = texture(maskTex, pos).r;\
		\
		fragColor = vec4( src , mask);\
		}";
		shader2.setupShaderFromSource(GL_VERTEX_SHADER, vertex);
		shader2.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment);
		shader2.bindDefaults();
		shader2.linkProgram();
    }else{
		string shaderProgram = "#version 120\n \
		#extension GL_ARB_texture_rectangle : enable\n \
		\
		uniform sampler2DRect tex0;\
		uniform sampler2DRect maskTex;\
		\
		void main (void){\
		vec2 pos = gl_TexCoord[0].st;\
		\
		vec3 src = texture2DRect(tex0, pos).rgb;\
		float mask = texture2DRect(maskTex, pos).r;\
		\
		gl_FragColor = vec4( src , mask);\
		}";
		shader2.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
		shader2.linkProgram();
    }
    #endif

    // Let�s clear the FBO�s
    // otherwise it will bring some junk with it from the memory    
    maskFbo2.begin();
    ofClear(0,0,0,0);
    maskFbo2.end();
    
    fbo2.begin();
    ofClear(0,0,0,0);
    fbo2.end();
    
    bBrushDown = false;
    
    
    //leaf
//    xPos = ofGetWidth()/2;
//    yPos = ofGetHeight()/2;
//    leafLength = ofRandom (150, 350);
//    leafWidth = ofRandom (50,150);
//    leafColor = ofColor(255,0,0);
//    rotation = ofRandom(0,360);
//    scaleFactor = ofRandom(.5, 1.0);
////    ofSetRectMode (OF_RECTMODE_CENTER);
//    leafCurvature = ofRandom(1,5);
//    stemLength = ofRandom (2,5);
    




}

//--------------------------------------------------------------
void ofApp::update(){
       inkSim.update();
    for (int i = 0; i < numLeaves; i++){
        leaves[i].update();
    }
    
    // MASK (frame buffer object)
    maskFbo2.begin();

    if (bBrushDown){
//        brushImg2.draw(mouseX-25,mouseY-25,50,50);
          inkSim.draw();
        }
        //this will be your leaves ... not the brush
    
    drawLeaf();
    
    maskFbo2.end();
    
    // HERE the shader-masking happends
    fbo2.begin();
    
    // Cleaning everthing with alpha mask on 0 in order to make it transparent for default
    ofClear(0, 0, 0,0);
    
    shader2.begin();
    shader2.setUniformTexture("maskTex", maskFbo2.getTextureReference(), 1 );
    
    srcImg2.draw(0,0);     //put ink instead

    shader2.end();
    fbo2.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
    inkSim.draw();
  //  gui.draw();

    ofSetColor(255,255,255);
    
    dstImg2.draw(0,0);
    
    fbo2.draw(0,0);

//text on the screen
//    ofDrawBitmapString("Drag the Mouse to draw", 15,15);
//    ofDrawBitmapString("Press spacebar to clear", 15, 30);
}
    
//--------------------------------------------------------------

void ofApp::drawLeaf(){
    
    for (int i = 0; i < numLeaves; i++){
        leaves[i].draw();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    maskFbo2.begin();
    ofClear(0,0,0,255);
    maskFbo2.end();
    
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
    ofColor c = moodmachine;
    inkSim.stroke(&brush, x, y, getInkColor(c.getHueAngle(), 255, 10));

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    bBrushDown = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    bBrushDown = false;
//    leaves.clear();
//    setup();
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
