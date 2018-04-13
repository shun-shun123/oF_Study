#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(255, 255, 255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    midiIn.listPorts();
    midiIn.openPort(0);
    
    midiIn.addListener(this);
    
    midiIn.setVerbose(true);
    midiIn.ignoreTypes(false, false, false);
    
    manager = ofxMidiOutputManager();
    ofSoundStreamSetup(2, 0, this, 44100, 1024, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor color;
    color.setHsb(midiMessage.pitch * 2, 255, 255);
    ofSetColor(color);
    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, midiMessage.pitch * 2);
}

//--------------------------------------------------------------
// Listener用の関数
void ofApp::newMidiMessage(ofxMidiMessage &msg) {
    midiMessage = msg;
    
    if (midiMessage.getStatusString(midiMessage.status) == "Note On") {
        manager.willConstBuffer(midiMessage.pitch);
    }
}

//--------------------------------------------------------------
// for output
void ofApp::audioRequested(float *buf, int bufSize, int nChan) {
    manager.constructBuffers(buf, bufSize);
}

//--------------------------------------------------------------
void ofApp::exit() {
    midiIn.closePort();
    midiIn.removeListener(this);
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
