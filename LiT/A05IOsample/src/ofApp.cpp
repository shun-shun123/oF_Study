#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
//    ofSetBackgroundAuto(false);
    ofSetCircleResolution(64);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
//    ofSetColor(0, 100);
    /* input */
//    soundStream.setup(this, 0, 1, 44100, 256, 4);
    /* output */
//    soundPlayer.load("Alone.mp3");
//    soundPlayer.setLoop(true);
//    soundPlayer.setVolume(1.0);
//    soundPlayer.play();
    /* video */
    video.initGrabber(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    /* out put */
//    volume = ofSoundGetSpectrum(1);
//    circle_radius = volume[0] * 1300;
    /* input */
//    curVol = curVol * 2000;
    /* video */
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* out put */
//    ofSetColor(255, 100);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//    ofSetColor(0, 200);
//    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, circle_radius);
    /* input */
//    ofSetColor(255, 200);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//    ofSetColor(0, 200);
//    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, curVol);
    /* video */
    video.draw(0, 0);
    
}

void ofApp::audioIn(float *input, int bufferSize, int nChannels) {
//    curVol = 0.0;
//    for (int i = 0; i < bufferSize; i++) {
//        curVol += input[i] * input[i];
//    }
//    curVol /= bufferSize;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    switch (key) {
//        case 'a':
//            circle_radius += 20;
//            break;
//        case 's':
//            circle_radius -= 20;
//            break;
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
//    switch (key) {
//        case 'q':
//            circle_radius += 20;
//            break;
//        case 'm':
//            circle_radius -= 20;
//            break;
//    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    circle_x = x;
//    circle_y = y;
//    ofSetColor(ofColor::fromHsb(ofRandom(255), 255, 255));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//    switch (button) {
    // 左クリック
//        case 0:
//            ofSetColor(255, 0, 0);
//            break;
//        case 1:
//            ofSetColor(0, 255, 0);
//            break;
    // 右クリック
//        case 2:
//            ofSetColor(0, 0, 255);
//            break;
//    }
//    circle_x = x;
//    circle_y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    circle_x = x;
//    circle_y = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    circle_x = ofGetWidth() / 2;
//    circle_y = ofGetHeight() / 2;
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
