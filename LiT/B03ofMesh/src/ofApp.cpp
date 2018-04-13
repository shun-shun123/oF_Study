#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    
    ofEnableDepthTest();
    
    light.enable();
    light.setPosition(-100, 100, 500);
    glPointSize(3);
    
//    myMesh = ofPlanePrimitive(1000, 1000, 50, 50).getMesh();
    myMesh = ofSpherePrimitive(200, 70).getMesh();
    // メッシュの色の設定
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(0.5, 1.0, 1.0, 0.5));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    for (int i = 0; i < myMesh.getVertices().size(); i++) {
//        ofVec3f point = myMesh.getVertices()[i] / 400.0; // 頂点の位置を取得
//        float z = ofNoise(point.x, point.y, ofGetElapsedTimef()) * 200.0; // パーリンノイズを精製
//        myMesh.setVertex(i, ofVec3f(myMesh.getVertices()[i].x, myMesh.getVertices()[i].y, z));
//    }
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        ofVec3f point = myMesh.getVertices()[i] / 300.0; // 頂点の位置を取得
        float size = 80 + 100 * ofNoise(point.x, point.y, ofGetElapsedTimef());
        ofVec3f newPoint = point.normalize() * size; // 新しい座標を作成
        myMesh.setVertex(i, newPoint); // 新しい座標をセット
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();

//    myMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
//    myMesh.draw();

    myMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    myMesh.draw();
    
    cam.end();
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
