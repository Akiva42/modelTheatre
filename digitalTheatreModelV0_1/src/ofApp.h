#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGameCamera.h"
#include "ofxGizmo.h"

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

		//camera
		ofxGameCamera camera;
		bool cameraMoving;

		//model loader
		ofxAssimpModelLoader model;

		//geometry
		vector< ofNode > nodes;
		ofBoxPrimitive box;

		//lighting
		ofLight pointLight;

		//material
		ofMaterial material;
		vector<ofPolyline> paint;

		//gizmo
		ofxGizmo gizmo;
		int gizmoIndex;
};
