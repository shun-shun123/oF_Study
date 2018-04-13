#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    cam.setOrientation(ofPoint(-20, 0, 0));
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    leap.open(); // begin leap Motion
}

//--------------------------------------------------------------
void ofApp::update(){
    simpleHands = leap.getSimpleHands();
    if ( leap.isFrameNew() && simpleHands.size()) {
        fingerPos.clear();
        handPos.clear();
        
        leap.setMappingX(-230, 230, -ofGetWidth() / 2, ofGetHeight() / 2);
        leap.setMappingY(90, 450, -ofGetWidth() / 2, ofGetHeight() / 2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for (int i = 0; i < simpleHands.size(); i++) {
            handPos.push_back(simpleHands[i].handPos);
            for (int f = 0; f < 5; f++) {
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;
                fingerPos.push_back(mcp);
                
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;
                fingerPos.push_back(pip);
                
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;
                fingerPos.push_back(dip);
                
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;
                fingerPos.push_back(tip);
            }
        }
    }
    leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    cam.begin();
    for (int i = 0; i < simpleHands.size(); i++) {
        ofSetColor(0, 255, 0);
        ofDrawSphere(handPos.at(i), 20);
        for (int f = 0; f < 5; f++) {
            ofSetColor(255);
            ofDrawSphere(fingerPos.at(20 * i + 4 * f + 0), 10);
            
            ofSetColor(200);
            ofDrawSphere(fingerPos.at(20 * i + 4 * f + 1), 10);
            
            ofSetColor(155);
            ofDrawSphere(fingerPos.at(20 * i + 4 * f + 2), 10);
            
            ofSetColor(100);
            ofDrawSphere(fingerPos.at(20 * i + 4 * f + 3), 10);
            
            ofDrawLine(fingerPos.at(20 * i + 4 * f + 0), fingerPos.at(20 * i + 4 * f + 1));
            ofDrawLine(fingerPos.at(20 * i + 4 * f + 1), fingerPos.at(20 * i + 4 * f + 2));
            ofDrawLine(fingerPos.at(20 * i + 4 * f + 2), fingerPos.at(20 * i + 4 * f + 3));
        }
    }
    if (simpleHands.size() == 2) {
        float distance = sqrt(pow(handPos.at(0).x - handPos.at(1).x, 2)
                              + pow(handPos.at(0).y - handPos.at(1).y, 2)
                              + pow(handPos.at(0).z - handPos.at(1).z, 2));
        
        ofSetColor(277, 100);
        ofDrawSphere((handPos.at(0).x + handPos.at(1).x) / 2,
                     (handPos.at(0).y + handPos.at(1).y) / 2,
                     (handPos.at(0).z + handPos.at(1).z) / 2);
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::exit() {
    
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
