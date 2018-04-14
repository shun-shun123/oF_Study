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
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    kinect.addUserGenerator();
    // start kinect
    kinect.start();
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    kinect.drawDepth(0, 0, 640, 480);
    
//    kinect.drawSkeletons(0, 0, 640, 480);
    
    if (kinect.getNumTrackedUsers() > 0) {
        ofxOpenNIUser user = kinect.getTrackedUser(0);
        
        ofSetColor(255, 255, 255, ofRandom(255));
        for (int i = 0; i < user.getNumJoints(); i++) {
            ofxOpenNIJoint joint = user.getJoint((enum Joint) i);
            if (joint.isFound()) {
                float x = joint.getProjectivePosition().x; // x position of joint
                float y = joint.getProjectivePosition().y; // y position of joint
                
                switch ((enum Joint) i) {
                    case JOINT_HEAD:
                    case JOINT_LEFT_HAND:
                    case JOINT_RIGHT_HAND:
                    case JOINT_LEFT_FOOT:
                    case JOINT_RIGHT_FOOT:
                        ofSetColor(255, 0, 0);
                        ofDrawCircle(x, y, 20);
                        break;
                    default:
                        ofSetColor(255);
                        ofDrawCircle(x, y, 10);
                        break;
                }
            }
        }// finish [for] about joint
        
        ofSetLineWidth(2);
        ofSetColor(100, 200, 255);
        for (int i = 0; i < user.getNumLimbs(); i++) {
            ofxOpenNILimb limb = user.getLimb((enum Limb) i);
            if (limb.isFound()) {
                float sX = limb.getStartJoint().getProjectivePosition().x;
                float sY = limb.getStartJoint().getProjectivePosition().y;
                float eX = limb.getEndJoint().getProjectivePosition().x;
                float eY = limb.getEndJoint().getProjectivePosition().y;
                ofDrawLine(sX, sY, eX, eY);
            }
        } // finish [for] about Limb
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
