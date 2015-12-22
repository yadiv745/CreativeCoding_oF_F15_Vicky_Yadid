//
//  GUI.h
//  flowerSimple
//
//  Created by Vicky Yadid on 12/9/15.
//
//

#ifndef __flowerSimple__GUI__
#define __flowerSimple__GUI__

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxInkSim.h"

#endif /* defined(__flowerSimple__GUI__) */

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
