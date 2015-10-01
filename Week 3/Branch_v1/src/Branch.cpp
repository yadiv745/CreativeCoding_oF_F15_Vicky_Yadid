//
//  Branch.cpp
//  Branch_v1
//
//  Created by Vicky Yadid on 9/21/15.
//
//

#include "Branch.h"

//--------------------------------------------------------------
void Branch::setup(
                   float _xPos,
                  float _yPos,
                  float _width,
                  float _length,
                  float _splitPercentage,
                  int _maxSubdivisions,
                  int _maxSegments,
                  int _segmentsSinceStart,
                  float _angle,
                  float _curvature,
                   ofColor _color){
    
    // set incoming values based on what was passed in from previous instance of branch:
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    length = _length;
    splitPercentage = _splitPercentage;
    maxSubdivsions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
    
    myLeaf.setup();
    
    //print line - counsol print:
    cout << "New Branch" << endl;
    cout << "Segment Count = ";
    cout << "segmentSinceStart" << endl;
    
    //draw current branch:
    ofSetColor(color);
    ofSetLineWidth((int)width);

    //o que é isso mesmo? posição e angulo dos branches? ofLine é a função para criar lines?
    ofLine(xPos, yPos, xPos + length * cos(angle), yPos + length * sin(angle));
    
    //definições:
    //pq q isso não está no draw?
    xPos += length * cos(angle); //aqui o angle é angle pq pode ser qualquer um? se eu quisesse que fosse um angle especifico eu colocaria numero?
    yPos += length * sin(angle);
    width = width * (ofRandom(0.5, 0.8)); // variação do tamanho dos branches
    segmentsSinceStart += 1; // esse é para acrescentar mais um branch?
    angle += curvature;
    curvature += ofRandom (0, (float)(2* PI)/360);
    
    myLeaf.draw(xPos, yPos);

    //recursion:
    if ( segmentsSinceStart <= maxSegments) {
        if (ofRandom (0,1) > splitPercentage) {
            Branch subBranch;
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSubdivsions, maxSegments, segmentsSinceStart, angle, curvature, color);
        } else {
            cout << "split" << endl;
            Branch subBranch1;
            float angle1 = angle + ofRandom(0, PI/2);
            Branch subBranch2;
            float angle2 = angle - ofRandom(0, PI/2);
            subBranch1.setup(xPos, yPos, width,length,splitPercentage, maxSubdivsions, maxSegments, segmentsSinceStart, angle1,curvature,color);
            subBranch2.setup(xPos, yPos, width,length,splitPercentage, maxSubdivsions, maxSegments,segmentsSinceStart, angle2,curvature,color);
        }
    }
}

//--------------------------------------------------------------
void Branch::update(){

    
}

//--------------------------------------------------------------
void Branch::draw(){
   
}

//--------------------------------------------------------------
//void Branch::mouseReleased(int x, int y, int button){
//  }
//--------------------------------------------------------------

