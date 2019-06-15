#include "ofApp.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    ofBackground(11, 11, 11);

    ofSetFrameRate(60);
    
    ofSetLineWidth(1);

    // Allocate and clear the FBO
    allocateFBO();
    
    gui.setup();
    gui.add(r.setup("r", 196, 0, 255));
    gui.add(g.setup("g", 74, 0, 255));
    gui.add(b.setup("b", 147, 0, 255));
}

void ofApp::allocateFBO() {
    rgbaFboFloat.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA32F_ARB);
    rgbaFboFloat.begin();
    ofClear(255,255,255, 0);
    rgbaFboFloat.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofEnableAlphaBlending();
    
    rgbaFboFloat.begin();
    
    // Clear the FBO
    ofFill();
    ofSetColor(255, 200, 200, fadeAmount);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    // Start drawing the scene
    ofNoFill();
    drawScene();

    rgbaFboFloat.end();
}

void ofApp::draw() {
    rgbaFboFloat.draw(0,0);
    
    if (ofGetKeyPressed('d')) {
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("t: " + ofToString(ofGetElapsedTimef() / rot90T) + "\nfade: " + ofToString(fadeAmount), ofPoint(ofGetWindowWidth() - 100, 20));
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::drawScene(){
    int numCubes = 8;
    
    // I want sin == 0 to coincide with 0, 90, 180, etc rotations
    fadeAmount = sin((int(ofGetElapsedTimef()) % int(rot90T)) / rot90T) * 45;
    
    for (int i = -(numCubes / 2); i < numCubes / 2; i++) {
        ofPushMatrix();
        
        ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0);
        
        float t = (ofGetElapsedTimef() * (i + 1) / rot90T) * 90;
        ofRotateXDeg(45);
        ofRotateYDeg(t);
        ofRotateZDeg(45);
        
        ofNoFill();
        
        ofSetColor(i * (r / numCubes), g, b);
        
        ofDrawBox(400);
        
        ofPopMatrix();
    }
}

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    allocateFBO();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
