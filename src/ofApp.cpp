#include "ofApp.h"

#define RADIUS 100
#define FPS 60
#define COUNT 15

Particle ofApp::initParticle() {
	double a = ((double)rand() / (RAND_MAX)) * 2 * PI;
	double r = RADIUS * sqrt(((double)rand() / (RAND_MAX)));

	double x = r * cos(a);
	double z = r * sin(a);

	return Particle(x, 0, z);
}

void ofApp::initParticleSystem(int n) {
	particleSystem.clear();

	for (int i = 0; i < n; i++) {
		particleSystem.push_back(initParticle());
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

	ofTranslate(ofGetWidth() / 2, 2 * ofGetHeight() / 3);

	ofDrawCircle(0, 0, RADIUS);

	ofPushMatrix();

	ofNoFill();

	for (int i = 0; i < particleSystem.size(); i++) {
		if (particleSystem[i].isDead()) {
			std::cout << "size: " << particleSystem[i].radius << '\n';
			std::cout << "height: " << particleSystem[i].y << '\n';
			// Push all the particles to replace.
			for (int j = i; j < particleSystem.size() - 1; j++) {
				particleSystem[j] = particleSystem[j + 1];
			}
			// Add a new particle.
			particleSystem[particleSystem.size() - 1] = initParticle();
		}

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
