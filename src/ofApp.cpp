#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	aParticle = Particle(100, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	

	ofPushMatrix();

	if (moving) {
		aParticle.Move();
	}

	ofNoFill();
	ofDrawSphere(aParticle.getX(), aParticle.getY(), aParticle.getZ(), 64);

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
