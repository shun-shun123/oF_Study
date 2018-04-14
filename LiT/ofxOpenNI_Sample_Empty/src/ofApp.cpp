#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetWindowShape(640, 480);
    ofSetFrameRate(30);
    
    kinect.setup();
    kinect.setRegister(true); // adjust depth info
    kinect.setMirror(true); // reverse right side and left side
    kinect.addDepthGenerator(); // add distance info to kinect
    kinect.addImageGenerator(); // add color info to kinect
    
    // adapt depth image with RGB image's view, adjust difference
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    // start kinect
    kinect.start();
    
    maskedImage.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);
    scenery.load("photo.jpg"); // load pic
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
    unsigned char *maskedImageData = maskedImage.getPixels().getData();
    unsigned char *imageData = kinect.getImagePixels().getData();
    unsigned short *depthData = kinect.getDepthRawPixels().getData();
    
    for (int k = 0; k < 640 * 480; k++) {
        maskedImageData[k * 4 + 0] = imageData[k * 3 + 0];
        maskedImageData[k * 4 + 1] = imageData[k * 3 + 1];
        maskedImageData[k * 4 + 2] = imageData[k * 3 + 2];
        // leave objected pixels alpha others
        if (880 <= depthData[k] && depthData[k] < 1200) {
            maskedImageData[k * 4 + 3] = 255; // visible
        } else {
            maskedImageData[k * 4 + 3] = 0; // invisible
        }
    }
    maskedImage.setFromPixels(maskedImageData, 640, 480, OF_IMAGE_COLOR_ALPHA);
}

//--------------------------------------------------------------
void ofApp::draw(){
    kinect.drawDepth(0, 0, 640, 480);
    scenery.draw(640, 0, 640, 480);
    maskedImage.draw(640, 0, 640, 480);
//    ofBackground(0);
//    ofSetColor(155, 155, 155);
//    kinect.drawDepth(0, 0, 640, 480); // draw depth image
//    kinect.drawImage(640, 0, 640, 480); // draw RGB image
//
//    ofSetColor(0, 0, 0);
//    ofDrawBitmapString(distanceBuffer, 20, 40);
//    ofSetCircleResolution(8);
//    ofSetColor(0, 0, 255, ofRandom(255));
//    ofDrawCircle(mouseX, mouseY, 10);
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
    unsigned short *depthData = kinect.getDepthRawPixels().getData();
    unsigned short depthMM = depthData[y * 640 + x];
    sprintf(distanceBuffer, "%d mm", depthMM);
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
