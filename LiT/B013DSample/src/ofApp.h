#pragma once

#include "ofMain.h"

#define NUM 50

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
		
    ofBoxPrimitive box, mBox[NUM];
    float mBox_x[NUM];
    float mBox_y[NUM];
    float mBox_z[NUM];
    float alpha[NUM];
    
    int box_size;
    
    ofEasyCam cam;
};