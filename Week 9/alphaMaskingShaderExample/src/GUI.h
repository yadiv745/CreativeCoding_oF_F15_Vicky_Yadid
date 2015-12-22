//
//  GUI.h
//  alphaMaskingShaderExample
//
//  Created by Vicky Yadid on 12/10/15.
//
//

#ifndef __alphaMaskingShaderExample__GUI__
#define __alphaMaskingShaderExample__GUI__

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


#endif /* defined(__alphaMaskingShaderExample__GUI__) */
