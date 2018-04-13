#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    box_size = 15;
    for (int i = 0; i < NUM; i++) {
        mBox_x[i] = ofRandom(-500, 500);
        mBox_y[i] = ofRandom(-500, 500);
        mBox_z[i] = ofRandom(-500, 500);
        alpha[i] = 255 / NUM * i;
    }
    for (int i = 0; i < NUM; i++) {
        mBox[i].setPosition(mBox_x[i], mBox_y[i], mBox_z[i]);
        mBox[i].set(box_size);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < NUM; i++) {
        alpha[i] += 0.5;
        if (alpha[i] > 255)
            alpha[i] = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    // 周囲のサブボックスの描画
    ofSetColor(100, 200, 255);
    for (int i = 0; i < NUM; i++) {
        mBox[i].draw();
    }
    // メッシュワイヤーの描画
    for (int i = 0; i < NUM; i++) {
        for (int j = i + 1; j < NUM; j++) {
            ofSetColor(ofColor::fromHsb(int(ofGetElapsedTimeMillis() * 0.01) % 255, 255, 255, alpha[i]));
            ofDrawLine(mBox_x[i], mBox_y[i], mBox_z[i],
                       mBox_x[j], mBox_y[j], mBox_z[j]);
        }
    }
    // メインボックスの描画
    ofSetColor(255, 255, 255, (ofGetFrameNum() * 6) % 120);
    box.setPosition(0, 0, 0);
    box.set(150);
    box.draw();
    ofSetColor(255, 255, 255, 255);
    box.drawWireframe();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
    }
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
