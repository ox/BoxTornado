#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
public:
    // creates a light and enables lighting
    ofLight light;
    
    // FBO to draw to
    ofFbo rgbaFboFloat;
    
    // Amount to fade between renders
    int fadeAmount;
    
    // Seconds to complete a 90 deg rotation
    float rot90T = 30;
    
    // GUI
    ofxFloatSlider r;
    ofxFloatSlider g;
    ofxFloatSlider b;
    ofxPanel gui;

    void setup();
    void update();
    void draw();
    
    void drawScene();
    void allocateFBO();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
};
