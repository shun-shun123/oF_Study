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
        void init();
        void setupBG(float rect_size);
        void drawAim();
        void drawCircle();
        float hueCalc();
        void spaceAction();
        float rect_size, angle, out_radius;
        ofVec2f mouse, direction, center;
        const ofVec2f Xaxis = ofVec2f(1, 0);
        const ofVec2f adjust = ofVec2f(20, 20);
        ofColor color;
        bool isSpaceClicked;
};
