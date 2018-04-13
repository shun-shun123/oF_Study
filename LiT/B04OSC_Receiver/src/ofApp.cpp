#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(PORT);
    // 指定したポートで接続
    // receiverはOSCメッセージを受信するインスタンス ofxOscReceiver
    // OSCを受信するポート番号を設定 #define PORT 8020
    remoteMouse.x = 0; // マウスの座標の値(x)を初期化
    remoteMouse.y = 0; // マウスの座標の値(y)を初期化
    mouseButtonState = "";
}

//--------------------------------------------------------------
void ofApp::update(){
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m; // 次のメッセージを取得
        receiver.getNextMessage(m); // mのアドレスが引数
        
        if (m.getAddress() == "/mouse/position") { // メッセージが/mouse/position ならマウスの位置を取得
            remoteMouse.x = m.getArgAsInt32(0); // 受信したマウス座標ofPoint(引数の0番目の32bitのintを取得)
            remoteMouse.y = m.getArgAsInt32(1); // 受信したマウス座標のofPoint(引数の1番目の32bitのintを取得)
        } else if (m.getAddress() == "/mouse/button") {
            mouseButtonState = m.getArgAsString(0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
//    ofSetColor(0);
//    ofDrawCircle(remoteMouse.x, remoteMouse.y, 30);
    if (mouseButtonState == "down") {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    } else {
        ofSetColor(0);
    }
    ofDrawCircle(remoteMouse.x, remoteMouse.y, 30);
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
