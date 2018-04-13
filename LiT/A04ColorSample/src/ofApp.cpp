#include "ofApp.h"
int blend_mode = 0;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    gui.setup();
    gui.add(hue.setup("hue", 1, 0, 255));
    gui.add(saturation.setup("saturation", 1,  0, 255));
    gui.add(brightness.setup("brightness", 1, 0, 255));
    gui.add(r.setup("R", 1, 0, 255));
    gui.add(g.setup("G", 1, 0, 255));
    gui.add(b.setup("B", 1, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetElapsedTimeMillis() > 10000)
        ofResetElapsedTimeCounter();
    /* 色相環の値から考えて、sin関数に当てはめる
     Hsbで色を設定すれば、sとbは255に値を固定することができるので、
     あとは、経過時間に合わせてHを変化させてやれば、虹のような色の移り変わりが可能になる */
    change_hue = 128 + 128 * sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2 * PI));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::fromHsb(hue, saturation, brightness));
    ofDrawRectangle(100, 300, 200, 200);
    ofSetColor(r, g, b);
    ofDrawRectangle(400, 300, 200, 200);
    ofSetColor(ofColor::fromHsb(change_hue, 255, 255));
    ofDrawRectangle(700, 300, 200, 200);
    switch (blend_mode) {
        case 0:
            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
            cout << "OF_BLENDMODE_ALPHA" << endl;
            break;
        case 1:
            ofEnableBlendMode(OF_BLENDMODE_ADD);
            cout << "ADD" << endl;
            break;
        case 2:
            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            cout << "MULTIPLY" << endl;
            break;
        case 3:
            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            cout << "SUBTRACT" << endl;
            break;
        case 4:
            ofEnableBlendMode(OF_BLENDMODE_SCREEN);
            cout << "SCREEN" << endl;
            break;
    }
    ofSetColor(ofColor::fromHsb(255, 200, 200, 200));
    ofDrawCircle(500, 600, 100);
    ofSetColor(ofColor::fromHsb(100, 200, 200, 200));
    ofDrawCircle(600, 600, 100);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c')
        blend_mode = (blend_mode + 1) % 5;
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
