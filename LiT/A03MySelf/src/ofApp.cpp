#include "ofApp.h"
#define CIRCLE_NUM 3
double counter = 0;
int magnified = 300;
double accel = 0;
double gravity = 0;
int Rcolor_controler = 1;
int Gcolor_controler = 1;
int Bcolor_controler = 1;
int r = 0;
int g = 100;
int b = 200;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    for (int i = 0; i < CIRCLE_NUM; i++) {
        circle_x[i] = cos(2 * PI / CIRCLE_NUM * i)* magnified + (ofGetWidth() / 2);
        circle_y[i] = sin(2 * PI / CIRCLE_NUM * i) * magnified + (ofGetHeight() / 2);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    counter += accel;
    for (int i = 0; i < CIRCLE_NUM; i++) {
        circle_x[i] = cos(2 * PI / CIRCLE_NUM * i + counter) * magnified + (ofGetWidth() / 2);
        circle_y[i] = sin(2 * PI / CIRCLE_NUM * i + counter) * magnified + (ofGetHeight() / 2) + gravity;
    }
    if (r < 0)
        Rcolor_controler *= -1;
    else if (r > 255)
        Rcolor_controler *= -1;
    r += Rcolor_controler;
    if (g < 0)
        Gcolor_controler *= -1;
    else if (g > 255)
        Gcolor_controler *= -1;
    g += Gcolor_controler;
    if (b < 0)
        Bcolor_controler *= -1;
    else if (b > 255)
        Bcolor_controler *= -1;
    b += Bcolor_controler;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 50);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for (int i = 0; i < CIRCLE_NUM; i++) {
        switch (i) {
            case 0:
                ofSetColor(r, 0, 0, 200);
                break;
            case 1:
                ofSetColor(0, g, 0, 200);
                break;
            case 2:
                ofSetColor(0, 0, b, 200);
                break;
            default:
                break;
        }
        ofDrawCircle(circle_x[i], circle_y[i], circle_diameter);
        ofDrawTriangle(circle_x[i], circle_y[i], ofGetWidth() / 2 - 10, ofGetHeight() / 2 - 10, ofGetWidth() / 2 + 10, ofGetHeight() / 2 + 10);
        if (i < 2) {
            ofDrawLine(circle_x[i], circle_y[i], circle_x[i + 1], circle_y[i + 1]);
        } else if (i == 2) {
            ofDrawLine(circle_x[i], circle_y[i], circle_x[0], circle_y[0]);
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
    x = x - ofGetWidth() / 2;
    accel = double(x) / ofGetWidth() * 0.4;
    y = y - ofGetHeight() / 2;
    gravity = double(y) / ofGetHeight() * 300;
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
