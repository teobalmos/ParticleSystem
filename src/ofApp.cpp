#include "ofApp.h"

#define RADIUS 100
#define FPS 30
#define COUNT 5

void ofApp::initParticleSystem(int n) {
	particleSystem.clear();

	for (int i = 0; i < n; i++) {
		double a = ((double)rand() / (RAND_MAX)) * 2 * PI;
		double r = RADIUS * sqrt(((double)rand() / (RAND_MAX)));

		double x = r * cos(a);
		double z = r * sin(a);

		particleSystem.push_back(Particle(x, 0, z));
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	initParticleSystem(COUNT);
	ofSetFrameRate(FPS);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	ofDrawCircle(0, 0, RADIUS);

	ofPushMatrix();

	

	ofNoFill();

	for (int i = 0; i < particleSystem.size(); i++) {

		if (moving) {
			particleSystem[i].Move(FPS);
		}

		ofDrawSphere(particleSystem[i].x, particleSystem[i].y, particleSystem[i].z, particleSystem[i].radius);
	}

	

	ofPopMatrix();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case(32): setup(); moving = false; break;
	case('0'): moving = !moving; break;
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
