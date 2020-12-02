#include "ofApp.h"

#define RADIUS 300
#define FPS 60
#define COUNT 20

Particle ofApp::initParticle(double pop_x, double pop_y, double pop_z, double radius) {
	double x, z;

	if (pop_x != 0) {
		return Particle(pop_x, pop_y, pop_z, radius, /*type=*/ Particle::BubbleType::popped);
	}
	else {
		double a = ((double)rand() / (RAND_MAX)) * 2 * PI;
		double r = RADIUS * sqrt(((double)rand() / (RAND_MAX)));

		x = r * cos(a);
		z = r * sin(a);
	}
	

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

	ofSetSphereResolution(80);
	model.loadModel("cauldron.obj");
	model.setScale(1.7, 1.7, 1.7);
	light.setPosition(1000, -5000, 1000);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < particleSystem.size(); i++) {
		if (particleSystem[i].isDead()) {
			if (particleSystem[i].type != Particle::BubbleType::popped) {
				float pop_chance = rand() % 10;
				if (pop_chance >= 8) {
					double x = particleSystem[i].x;
					double y = particleSystem[i].y;
					double z = particleSystem[i].z;
					double radius = particleSystem[i].radius;

					// Create the bubbles that pop from it.
					particleSystem.push_back(initParticle(x, y, z, radius));
				}
				// Push all the particles to replace it.
				for (int j = i; j < particleSystem.size() - 1; j++) {
					particleSystem[j] = particleSystem[j + 1];
				}

				// Add a new particle.
				particleSystem[particleSystem.size() - 1] = initParticle();
			}
			else {
				// If the particle is a popped bubble, just remove it without replacing it.
				for (int j = i; j < particleSystem.size() - 1; j++) {
					particleSystem[j] = particleSystem[j + 1];
				}
				particleSystem.pop_back();
			}

		}
		// If the particle didn't die.
		else {
			if (moving) {
				particleSystem[i].Move(FPS);
				// The particle breathes only if it's not a bubble that resulted
				// from popping.
				if (particleSystem[i].type != Particle::BubbleType::popped) {
					particleSystem[i].Breathe();
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();
	ofTranslate(ofGetWidth() / 2.0, 2.0 * ofGetHeight() / 3.0);
	
	light.enable();
	cam.begin();
	cam.lookAt({ 0, 0, 0 }, {0,-1,0});

	ofPushMatrix();
	ofSetColor(0, 0, 0, 255);
	model.drawFaces();

	for (int i = 0; i < particleSystem.size(); i++) {
		ofSetColor(particleSystem[i].colour, 80);
		ofDrawSphere(particleSystem[i].x, particleSystem[i].y, particleSystem[i].z, particleSystem[i].radius);
	}
	
	cam.end();
	light.disable();
	ofDisableDepthTest();
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
