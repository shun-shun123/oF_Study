#include "ofApp.h"
int num_line = 50;
int color_mode = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    for (int i = 0; i < num_line; i++) {
        x[i] = 30 * i;
    }
    ofSetLineWidth(10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < num_line; i++) {
        switch (color_mode) {
            case 0: ofSetColor(255, 0, 0); break;
            case 1: ofSetColor(ofColor::fromHsb(ofGetElapsedTimeMillis() % 255, 255, 255)); break;
            case 2: ofSetColor(x[i] % 255, 255 - x[i] % 255, 100);
        }
        ofDrawLine(x[i], 0, x[i], ofGetHeight());
    }
    cout << ofGetFrameRate() << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c')
        color_mode = (color_mode + 1) % 3;
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
