#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetWindowShape(640, 480);
    ofSetFrameRate(30);
    
    kinect.setup();
    kinect.setRegister(true); // adjust depth info
    kinect.setMirror(true); // reverse right side and left side
    kinect.addDepthGenerator(); // add distance info to kinect
    kinect.addImageGenerator(); // add color info to kinect
    
    kinect.addHandsGenerator();
    kinect.addAllHandFocusGestures();
    kinect.setMaxNumHands(2);
    // start kinect
    kinect.start();
    mode = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    kinect.drawDepth(0, 0);
    if (mode == 0) {
        ofSetColor(255);
    } else {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }
    
    ofSetColor(255);
    if (kinect.getNumTrackedHands() > 0) {
        for (int i = 0; i < kinect.getNumTrackedHands(); i++) {
        ofxOpenNIHand hand = kinect.getTrackedHand(i);
            p[i] = hand.getPosition();
            ofDrawCircle(p[i].x, p[i].y, 20);
            int newacc = ofDist(p[i].x, p[i].y, preP[i].x, preP[i].y);
            if (acc[i] < 20 && newacc > 20) {
                mode = (mode + 1) % 2;
            }
            acc[i] = newacc;
        }
        for (int j = 0; j < 2; j++) {
            preP[j] = p[j];
        }
        ofPoint p = hand.getPosition();
        ofDrawCircle(p.x, p.y, 20);
        }
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
    unsigned short *depthData = kinect.getDepthRawPixels().getData();
    unsigned short depthMM = depthData[y * 640 + x];
    sprintf(distanceBuffer, "%d mm", depthMM);
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
