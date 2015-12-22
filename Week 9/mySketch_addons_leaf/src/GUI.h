//
//  GUI.h
//  mySketch_addons_leaf
//
//  Created by Vicky Yadid on 12/9/15.
//
//

#ifndef __mySketch_addons_leaf__GUI__
#define __mySketch_addons_leaf__GUI__

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxInkSim.h"

class GUI
{
public:
    
    void setup(ofPtr<UniformInfos> uniforms);
    void draw();
    void toggleVisible();
    void resetToDefault();
    
private:
    
    bool bGUIHide;
    
    ofxPanel gui;
    ofXml settings;
    ofPtr<UniformInfos> uniforms;
};



#endif /* defined(__mySketch_addons_leaf__GUI__) */
