#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0x000000);
    ofSetFrameRate(60);
    
    // kinect初期設定
    // adjust differential bt depth and RGB
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    // adjust angle -> 0
    kinectAngle = 0;
    kinect.setCameraTiltAngle(kinectAngle);
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update(); // update info from kinect
}

//--------------------------------------------------------------
void ofApp::draw(){
    easyCam.begin();
    drawPointCloud();
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::drawPointCloud() {
    // screen width and height
    int w = 640;
    int h = 480;
    // create mesh
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(0.1);
    int step = 2; // setting interval
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (kinect.getDistanceAt(x, y) > 0) {
                mesh.addColor(kinect.getColorAt(x, y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    // draw point mesh
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, -1000);
    glEnable(GL_DEPTH_TEST);
    mesh.drawVertices();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit() {
    kinect.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            kinectAngle++;
            if (kinectAngle > 27) kinectAngle = 27;
            kinect.setCameraTiltAngle(kinectAngle);
            break;
        case OF_KEY_DOWN:
            kinectAngle--;
            if (kinectAngle < -27) kinectAngle = -70;
            kinect.setCameraTiltAngle(kinectAngle);
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
