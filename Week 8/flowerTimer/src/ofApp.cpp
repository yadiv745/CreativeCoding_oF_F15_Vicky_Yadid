#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    bgColor1.set(247,231,210);
//    bgColor2.set(207,193,168);
    
    width = 5;
    height =100;
    xPos = 500;
    yPos = 800;
    
    mainStemHeight = 250;
    mainStemWidth = 20;
    
    numLeaves = 8;
    for (int i=0; i < numLeaves; i++) {
        Leaf tempLeaf;
        tempLeaf.setup();
        leaves.push_back(tempLeaf);
    }
    
    numGrowLeaves = 16;
    for (int i=0; i < numGrowLeaves; i++) {
        LeafGrow tempLeaf;
        tempLeaf.setup();
        leavesGrow.push_back(tempLeaf);
    }
    
    numLeafBranch = 2;
    for (int i=0; i < numLeafBranch; i++) {
        LeafBranch tempLeaf;
        tempLeaf.setup();
        leafBranch.push_back(tempLeaf);
    }
    
//    numStemBranch = 2;
//    for (int i=0; i < numStemBranch; i++) {
//        StemBranch tempLeaf;
//        tempLeaf.setup();
//        stemBranch.push_back(tempLeaf);
//    }

    numFlowerBorn = 10;
    for (int i=0; i < numFlowerBorn; i++) {
        FlowerBorn tempLeaf;
        tempLeaf.setup();
        flowerBorn.push_back(tempLeaf);
    }

    
    numFlowerGrow = 16;
    for (int i=0; i < numFlowerGrow; i++) {
        FlowerGrow tempLeaf;
        tempLeaf.setup();
        flowerGrow.push_back(tempLeaf);
    }
    

    numGrassGrass =300;
    for (int i=0; i < numGrassGrass; i++) {
        Grass tempLeaf;
        tempLeaf.setup();
        grassGrass.push_back(tempLeaf);
    }


    
   
//    ofSetBackgroundAuto(false);
//    bool hasDrawn = false;


    ofToggleFullscreen();
    ofEnableAlphaBlending();
    ofEnableSmoothing();

//    ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
//
//     order = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    for (int i = 0; i < numLeaves; i++){
//        leaves[i].update();
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    for (int i = 0; i < numGrassGrass; i++){
        grassGrass[i].draw();
    }

    
    if(ofGetElapsedTimef() > 1) {
        ofSetColor(138,90,69);
        ofRect(xPos, yPos, width, height);
        ofRect(xPos - 200, yPos, width, height+2);
    }
    
    
    if(ofGetElapsedTimef() > 2) {
        ofSetColor(138,90,69);
        ofRect(xPos, yPos - 75, width+2, height + 25);
        ofRect(xPos-200, yPos - 75, width+3, height);
        
        for (int i = 0; i < numLeafBranch; i++){
            leafBranch[i].draw();
        }
    }
    
    
    if(ofGetElapsedTimef() > 3) {
        ofSetColor(138,90,69);
        ofRect(xPos, yPos - 185, width, height);
        ofRect(xPos-200, yPos - 185, width, height+30);
        
//        for (int i = 0; i < numStemBranch; i++){
//            stemBranch[i].draw();
//        }
//        
        
    }
    
    //branch tentativa
//    if(ofGetElapsedTimef() > 4) {
//        ofRect(xPos, yPos - 300, width, height + 50);
//        ofSetColor(0,0,255);
//        ofLine(xPos, yPos, height+100*cos(angle), height+100*sin(angle));
//      //  ofLine(xPos, yPos, xPos + height + 50* cos(angle), yPos + height +50 * sin(angle));
////        xPos +=  height + 50 * cos(angle);
////        yPos += height + 50 * sin(angle);
//    }
    
     if(ofGetElapsedTimef() > 4) {
         
         for (int i = 0; i < numLeaves; i++){
             leaves[i].draw();
         }
    
    for (int i = 0; i < numFlowerBorn; i++){
        flowerBorn[i].draw();
    }
}

    if(ofGetElapsedTimef() > 5) {
        
        for (int i = 0; i < numGrowLeaves; i++){
            leavesGrow[i].draw();
        }
        
        for (int i = 0; i < numFlowerGrow; i++){
            flowerGrow[i].draw();
        }

    }

//    
//    if(ofGetElapsedTimef() > 6) {
//        ofSetColor(99, 48, 20);
//        ofRect(ofGetWidth()/2-mainStemWidth/2, 520, mainStemWidth, mainStemHeight);
//        
//        myBranch.setup(ofGetWidth()/2,520, mainStemWidth, 70, 0.80, 2, 6, 0, 1.5*PI, 0, ofColor(99, 48, 20));
//        
//        myRoot.setup(ofGetWidth()/2, 520+mainStemHeight, mainStemWidth, 20, 0.80, 2, 5, 0, 2.5*PI, 0, ofColor(99, 48, 20));
//        }
 }
//
//    ofBackground(255);
//    height ++;
//    
//    if(ofGetElapsedTimef() > 1) {
//        ofSetColor (255,0,0);
//        ofRect(xPos, yPos, width, height);
//    }
//    
//    if(ofGetElapsedTimef() >2) {
//        ofSetColor(0, 255, 0);
//        ofRect(xPos, yPos, width, height); 
//    
//    }
//    

    
//    float diffTime = ofGetElapsedTimef() - beginTime;
//    
//    //if (diffTime > duration){
//        printf("hi ! at time %f \n", ofGetElapsedTimef());
//        
//        xPos = 500;
//        yPos = 700;
//        stemWidth1 = 5;
//        stemLength1 = 100;
//        ofSetColor(0,0,0);
//       
//    ofRect(xPos, yPos, stemWidth1, stemLength1);
//    stemLength1 = stemLength1 + 5;
//    cout<<stemLength1<<endl;
//    
    
    //if(yPos > 800) {
    
//    if (diffTime > duration+3){
//        printf("hi ! at time %f \n", ofGetElapsedTimef());
//        
//        xPos = 500;
//        yPos = 600;
//        stemWidth1 = 5;
//        stemLength1 = 200;
//        ofSetColor(255,0,0);
//    }

    
//    ofBackground (255, 255, 255);  //set white background
//    ofSetColor(0, 0, 0);  //set black color
//    
//    ofCircle(300,100, 40); //blossom
//    ofLine(300,100, 300, 400); //stem
//    ofTriangle(300, 270, 300, 300, 200, 220); //left leaf
 //   ofTriangle(300, 270, 300, 300, 400, 220); //right leaf



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
//    ofBackgroundGradient(bgColor1, bgColor2,OF_GRADIENT_CIRCULAR);
    //order = true;
   //        subBranch1.setup(xPos, yPos, width, length, splitPercentage, maxSubdivsions, maxSegments, segmentsSinceStart, angle1, curvature, color);


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
