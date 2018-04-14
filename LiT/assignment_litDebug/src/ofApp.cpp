#include "ofApp.h"
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    // 変数の初期化
    init();
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
void ofApp::init() {
    rect_size = ofGetWidth() / 30.0;
    center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    mouse = ofVec2f(mouseX, mouseY);
    isSpaceClicked = false;
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
    out_radius = center.distance(mouse);
    color = ofColor::fromHsb(hueCalc(), 255, 255);
    ofPushStyle();
    ofSetColor(color);
    ofDrawLine(center, mouse);
    ofDrawCircle(center, out_radius * 0.24);
    ofNoFill();
    ofSetColor(color);
    ofDrawCircle(center, out_radius);
    ofPopStyle();
    if (isSpaceClicked) {
        spaceAction();
    }
}

//--------------------------------------------------------------
void ofApp::spaceAction() {
    out_radius += ofRandom(-6, 6);
    char info_radius[30];
    char info_angle[30];
    sprintf(info_radius, "radius : %.3f\n", out_radius);
    sprintf(info_angle, "angle : %.3f", angle);
    string info = strcat(info_radius, info_angle);
    ofDrawBitmapString(info, mouse + adjust);
    
    ofPath curve;
    curve.setColor(ofColor::fromHex(0x000000, 100));
    curve.setCircleResolution(271);
    curve.arc(center, out_radius, out_radius, 0, angle + 1, false);
    curve.draw();
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
