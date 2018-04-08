#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);

    for (int i = 0; i < 100; ++i) {
        position[i] = ofVec3f(ofRandom(-1000, 1000), ofRandom(-1000, 1000), ofRandom(100, 1000));
        box[i].setPosition(position[i].x, position[i].y, position[i].z);
        box[i].set(ofRandom(50, 100), ofRandom(50, 100), ofRandom(50, 100));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 100; ++i) {
        position[i] += accel[i];
        box[i].setPosition(position[i].x, position[i].y, position[i].z);
        accel[i] *= friction;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for (int i = 0; i < 100; ++i) {
        ofSetColor(color[i]);
        box[i].draw();
    }
    cam.end();
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
    startMouse = ofVec3f(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    endMouse = ofVec3f(x, y);
    for (int i = 0; i < 100; ++i) {
        accel[i] = (startMouse - endMouse);
        accel[i] *= ofRandom(0.8, 1.2);
        color[i].setHsb(ofRandom(0, 255), 255, 255);
    }
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
