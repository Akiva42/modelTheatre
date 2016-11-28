#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//camera
	camera.speed = 1.0f;
	cameraMoving = true;

	//geometry
	model.loadModel("model.3ds", false);
	model.setPosition(0, 0, 0);
	model.setRotation(1, 180, 1, 0, 0);
	box.setScale(0.25f);

	//lighting
	ofSetSmoothLighting(true);
	pointLight.setDiffuseColor(ofColor(100, 150, 255));
	pointLight.setSpecularColor(ofFloatColor(1.f, 1.f, 1.f));
	pointLight.setPosition(20, 20, 20);

	//materials
	material.setShininess(120);
	material.setSpecularColor(ofColor(255, 255, 255, 255));

	//enabling things
	ofEnableLighting();
	pointLight.enable();
	ofSetVerticalSync(true);

	//gizmo
	gizmo.toggleVisible();
	gizmo.setDisplayScale(2.);
	nodes.push_back(box);
	nodes.push_back(pointLight);

	gizmoIndex = 0;
	if (nodes.size()) {
		gizmo.setNode(nodes[gizmoIndex]);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	//gizmo
	if (gizmoIndex > -1) {
		nodes[gizmoIndex].setTransformMatrix(gizmo.getMatrix());
	}
	box.setTransformMatrix(nodes[0].getGlobalTransformMatrix());
	pointLight.setTransformMatrix(nodes[1].getGlobalTransformMatrix());
	model.setPosition(box.getX(), box.getY(), box.getZ());
	//model.setScale(box.getX(), box.getY(), box.getZ());

	//camera
	camera.usemouse = cameraMoving;
	camera.applyTranslation = cameraMoving;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor(238, 238, 238), ofColor(255, 255, 255));
	//draw the model
	ofEnableDepthTest();
	camera.begin();
		material.begin();
			box.drawWireframe();
			ofFill();
			model.drawFaces();
			ofDrawGrid(50, 10);
			for (ofPolyline &stroke : paint)
				stroke.getSmoothed(4).draw();
		material.end();

		ofFill();
		ofSetColor(pointLight.getDiffuseColor());
		pointLight.draw();

		ofDisableDepthTest();
		gizmo.draw(camera);

	camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r') {
		gizmo.setType(ofxGizmo::OFX_GIZMO_ROTATE);
	}
	if (key == 'g') {
		gizmo.setType(ofxGizmo::OFX_GIZMO_MOVE);
	}
	if (key == 's') {
		gizmo.setType(ofxGizmo::OFX_GIZMO_SCALE);
	}
	if (key == ' ') {
		cameraMoving = !cameraMoving;
		gizmo.toggleVisible();
	}
	if (key == '=') {
		gizmoIndex++;
		if (gizmoIndex >= nodes.size()) {
			gizmoIndex = 0;
		}
		gizmo.setNode(nodes[gizmoIndex]);
	}
	if (key == '-') {
		gizmoIndex--;
		if (gizmoIndex < 0) {
			gizmoIndex = (int)nodes.size() - 1;
		}
		gizmo.setNode(nodes[gizmoIndex]);
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
