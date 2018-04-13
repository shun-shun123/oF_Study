#pragma once

#include "ofMain.h"

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
    
    private:
        void setupBG(float rect_size);
        void drawAim();
        void drawCircle();
        float hueCalc();
        void spaceAction();
        float rect_size;
        float center_x, center_y;
        float angle;
        float out_radius;
        ofVec2f mouse;
        ofVec2f Xaxis, direction, center;
        ofColor color;
        bool isSpaceClicked;
};
