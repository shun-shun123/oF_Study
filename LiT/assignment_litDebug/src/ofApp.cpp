#include "ofApp.h"
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    
    Xaxis = ofVec2f(1, 0);
    rect_size = ofGetWidth() / 30.0;
    center_x = ofGetWidth() / 2.0;
    center_y = ofGetHeight() / 2.0;
    center = ofVec2f(center_x, center_y);
    mouse = ofVec2f(mouseX, mouseY);
    isSpaceClicked = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    setupBG(rect_size);
    drawAim();
    drawCircle();
    ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::setupBG(float rect_size) {
    ofPushStyle();
    ofSetColor(150);
    for (int i = 0; i < 30; i++) {
        ofDrawLine((i + 1) * rect_size, 0, (i + 1) * rect_size, ofGetHeight());
    }
    for (int i = 0; i < 22; i++) {
        ofDrawLine(0, (i + 1) * rect_size, ofGetWidth(), (i + 1) * rect_size);
    }
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::drawAim() {
    ofPushStyle();
    ofSetColor(0);
    ofDrawLine(0, mouse.y, ofGetWidth(), mouse.y);
    ofDrawLine(mouse.x, 0, mouse.x, ofGetHeight());
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::drawCircle() {
    out_radius = ofDist(center_x, center_y, mouse.x, mouse.y);
    if (isSpaceClicked) {
        out_radius += ofRandom(-6, 6);
        spaceAction();
    }
    color = ofColor::fromHsb(hueCalc(), 255, 255);
    ofPushStyle();
    ofSetColor(color);
    ofDrawLine(center, mouse);
    ofDrawCircle(center_x, center_y, out_radius * 0.24);
    ofNoFill();
    ofSetColor(color);
    ofDrawCircle(center_x, center_y, out_radius);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::spaceAction() {
    ofVec2f adjust = ofVec2f(10, 10);
    string info_radius = "radius : " + to_string(out_radius);
    string info_angle = "angle : " + to_string(angle);
    string info = info_radius + "\n" + info_angle;
    ofDrawBitmapString(info, mouse + adjust);
}

//--------------------------------------------------------------
float ofApp::hueCalc() {
    ofVec2f direction = mouse - center;
    angle = Xaxis.angle(direction);
    if (angle < 0) {
        angle = 360 + angle;
    }
    float hue = ofMap(angle, 0, 360, -255, 0);
    hue *= -1;
    return hue;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            isSpaceClicked = (isSpaceClicked + 1) % 2;
            cout << isSpaceClicked << endl;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouse = ofVec2f(x, y);
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
