#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8020 // OSCを受信するポート番号を設定

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxOscReceiver receiver; // OSCメッセージを受信するインスタンス
    ofPoint remoteMouse; // 受信したマウス座標を格納する(x, y, zまで格納できるが今回zは使わない)
    string mouseButtonState; // 受信したマウスボタンの状態（"up", "down")
};
