#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
public:
    ofLight light; // creates a light and enables lighting
//    ofEasyCam cam; // add mouse controls for camera movement
    ofFbo rgbaFboFloat; // with alpha
    int fadeAmount;
    
    // Seconds for a 90 deg rotation
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
