//
//  Branch.h
//  flowerTimer
//
//  Created by Vicky Yadid on 11/19/15.
//
//

#ifndef __flowerTimer__Branch__
#define __flowerTimer__Branch__

#include <ofMain.h>

#endif /* defined(__flowerTimer__Branch__) */


class Branch : public ofBaseApp{
    
public:
    void setup(float _xPos, float _yPos, float _width,
               float _length,
               float _splitPercentage,
               int _maxSubdivisions,
               int _maxSegments,
               int _segmentsSinceStart,
               float _angle,
               float _curvature,
               ofColor _color);
    void update();
    void draw();
    
    
private:
    
    float xPos, yPos;
    float width, length;
    float splitPercentage;
    int maxSubdivsions;
    int maxSegments;
    int segmentsSinceStart;
    float angle;
    float curvature;
    bool hasLeaves;
    ofColor color;
//    
//    Maple myMaple;
//    
//    ofVec2f maplePos;
};


