#include "ofApp.h"

#include <string>
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    kinect.setRegistration(true); // RGBイメージに合わせる深度画像を調整します
    kinect.init(); // kinectを初期化
    kinect.open(); // kinectの接続を開き、データ取得開始
    if (!kinect.isConnected()) {
        ofSystemAlertDialog("Serial Error: Kinect is not connected. Check a USB port then pus space bar.");
    }
    // GUIの設定
    ofxGuiSetDefaultWidth(300); // Guiの横幅を設定
    ofxGuiSetDefaultHeight(10); // Guiの高さを設定
    gui.setup("Depth Masking Control"); // 表示するパネル名を指定してメインとなるパネル部分を初期化し生成
    gui.setPosition(10, 10);
//    gui.add(radius.set("Radius", 0, 0, 255));
    gui.add(near.set("near", 0, 0, 255));
    gui.add(far.set("far", 0, 0, 255));
    gui.add(color.set("color", ofColor(255, 255, 255, 255), ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
    /*
     gui.add(スライダー名.setup(名前, 初期値, 最小値, 最大値));
     */
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update(); // kinectからのデータを更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
//    kinect.draw(0, 0, ofGetWidth(), ofGetHeight()); // カラーカメラで取得した画像を送信
    if (kinect.isFrameNew()) { // 現在のframeが新しく追加されたものであるか？
        cameraImage.setFromPixels(kinect.getPixels().getData(), kinect.width, kinect.height, OF_IMAGE_COLOR); // 用意したcameraImageに画像をセット
        /*
         setFromPixels(unsigned char * pixel(配列による画像データ)、配列による画像の幅、配列による画像の高さ、イメージタイプ)
         openCVで解析する画像領域に取得した映像をフレームとして格納する変数
         */
        depthImage.setFromPixels(kinect.getDepthPixels().getData(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
        unsigned char * cameraPixels = cameraImage.getPixels().getData(); // RGB画像の配列データ
        unsigned char * depthPixels = depthImage.getPixels().getData(); // 深度画像の配列データ
        maskedImage.allocate(kinect.width, kinect.height, OF_IMAGE_COLOR); // maskedImageにメモリを割り当てる
        /*
         ofImage.allocate(画像の幅, 画像の高さ, イメージタイプ)
         */
        unsigned char * maskedPixels = maskedImage.getPixels().getData(); // マスク画像の配列データ
        for (int i = 0; i < kinect.width * kinect.height; i++) {
            if ((255 - far.get() < depthPixels[i]) && (depthPixels[i] < 255 - near.get())) { // 指定範囲内の距離のpixelの時
                maskedPixels[i * 3] = cameraPixels[i * 3]; // RGBカメラのpixelをコピー(red)
                maskedPixels[i * 3 + 1] = cameraPixels[i * 3 + 1]; // copy RGB camera's pixel(green)
                maskedPixels[i * 3 + 2] = cameraPixels[i * 3 + 2]; // copy RGB camera'x pixel(blue)
            } else { // allocate 000(RGB) which is black
                maskedPixels[i * 3] = 0; // R [0, 255]
                maskedPixels[i * 3 + 1] = 0; // G [0, 255]
                maskedPixels[i * 3 + 2] = 0; // B [0, 255]
            }
        }
        maskedImage.setFromPixels(maskedPixels, kinect.width, kinect.height, OF_IMAGE_COLOR); // set prepared array data into maskedImage
    }
    cameraImage.draw(0, 0, kinect.width, kinect.height);
    depthImage.draw(0, kinect.height, kinect.width / 2, kinect.height / 2);
//    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, radius.get()); // ofParameterの変数.get()でパラメータの取得
    ofSetColor(color);
    maskedImage.draw(kinect.width / 2, kinect.height, kinect.width / 2, kinect.height / 2); // draw maskImage
    ofSetColor(255);
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            kinect.init(); // kinectを初期化
            kinect.open(); // kinectの接続を開き、データ取得開始
            if (!kinect.isConnected()) { // kinectが接続されていないときエラー出力
                ofSystemAlertDialog("Serial Error: kinect is not connected. Check please");
            }
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
