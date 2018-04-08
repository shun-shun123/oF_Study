#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(64);
    position.set(100, 100);
    velocity.set(30, 30);
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
//    if (position.x < 100 || position.x > ofGetWidth() - 100) velocity.x *= -1;
//    if (position.y < 100 || position.y > ofGetHeight() - 100) velocity.y *= -1;
//    position += velocity;

}
/*
 ofPushStyle();
 ofPopStyle();
 で、色とかブレンドモードとかを保存できる
 */

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 50, 0);
//    ofDrawCircle(300, 550, 100);
//    ofDrawRectangle(200, 450, 200, 200);
//    ofDrawTriangle(200, 450, 600, 250, 400, 650);
//    ofDrawEllipse(300, 550, 200, 100);
//    ofDrawLine(300, 550, ofGetWidth(), 0);
    // 多角形を描画する
//    ofBeginShape();
//    ofVertex(0, 0);
//    ofVertex(100, 100);
//    ofVertex(200, 500);
//    ofEndShape();
    int block_x = ofGetWidth() / 8;
    int block_y = ofGetHeight() / 6;
    ofSetLineWidth(3);
    for (int i = 0; i < 7; i++) {
        ofDrawLine(block_x * (i + 1), 0, block_x * (i + 1), ofGetHeight());
    }
    for (int i = 0; i < 5; i++) {
        ofDrawLine(0, block_y * (i + 1), ofGetWidth(), block_y * (i + 1));
    }
//    ofSetColor(255, 255, 0);
//    ofDrawEllipse(block_x, block_y * 3, block_x + 20, block_y * 5);
//    ofSetColor(color);
//    ofDrawCircle(position.x, position.y, 100);
//    ofSetColor(0, 255, 50);
//    ofDrawRectangle(block_x * 4, block_y * 2, block_x * 2, block_y * 2);
//    ofSetColor(255, 0, 255);
//    ofDrawTriangle(block_x * 2 + 20, block_y * 6 - 20, block_x * 2 + 20, block_y * 4 + 20, block_x * 4 - 20, block_y * 6 - 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    switch (key) {
//        case 'a':
//            velocity *= 2;
//            break;
//        case 's':
//            velocity /= 2;
//            break;
//        default:
//            break;
//    }
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
//    velocity *= -1;
//    switch (button) {
//        case 0:
//            ofBackground(255, 0, 0);
//            color.setHsb(150, 255, 255);
//            break;
//        case 2:
//            ofBackground(0, 255, 0);
//            color.setHsb(0, 255, 255);
//            break;
//        default:
//            break;
//    }
////    color.setHsb(ofGetElapsedTimeMillis() % 255, 255, 255);
//    ofBackground(ofColor::fromHsb(ofGetElapsedTimeMillis() % 255, 255, 255));
//
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
