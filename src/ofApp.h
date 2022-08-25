#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

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
		
    // Box2D objects
    ofxBox2d box2d; // box2d world !
    ofxBox2dEdge box2dEdge; // edge line
    std::vector<std::shared_ptr<ofxBox2dRect>> rects;
    
    ofxPanel gui;
    ofxVec2Slider gravitySlider;
    ofxFloatSlider densitySlider;
    ofxFloatSlider bounceSlider;
    ofxFloatSlider frictionSlider;
    ofxFloatField floatField;
};
