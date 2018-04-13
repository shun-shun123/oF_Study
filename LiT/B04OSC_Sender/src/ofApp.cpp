#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
     setup()は指定したIPアドレスとポート番号でサーバーに接続するための命令
     senderはOSCメッセージの送信者ofxOscSenderのインスタンス
     */
    sender.setup(HOST, PORT);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    // 現在のマウスの場所に円を描画
    ofSetColor(255);
    ofDrawCircle(mouseX, mouseY, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofxOscMessage m; // OSCメッセージの準備
    m.setAddress("/mouse/button"); // OSCアドレスの指定
    m.addStringArg("down"); // OSC引数として、マウス状態"down"を送信
    sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    ofxOscMessage m;
    m.setAddress("/mouse/button");
    m.addStringArg("up");
    sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofxOscMessage m; // OSCメッセージの準備
    m.setAddress("/mouse/position"); // OSCアドレスの指定
    m.addIntArg(x); // OSC引数として、現在のマウスの座標(x)を追加
    m.addIntArg(y); // OSC引数として、現在のマウスの座標(y)を追加
    sender.sendMessage(m); // メッセージを送信
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
