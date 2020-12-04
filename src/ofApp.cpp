#pragma once

#include "ofApp.h"

#define RADIUS 300
#define FPS 60
#define COUNT 60

extern float timeIncrease;

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
void ofApp::setup() {
	initParticleSystem(COUNT);
	ofSetFrameRate(FPS);
	ofSetBackgroundColor({ 224, 196, 81 });
	ofSetBackgroundColor({ 12, 10, 66 });

	ofSetSmoothLighting(true);

	ofColor lightColor = ofColor(255, 174, 168);
	lightColor.setBrightness(0.00001);

	ofSetSphereResolution(64);

	model.loadModel("cauldron.obj");
	model.setScale(2, 2, 2);
	model.setPosition(0, -30, 0);

	light.setup();
	light.enable();
	light.setAreaLight(120, 400);
	light.setAmbientColor({ 17, 17, 17 });
	light.setAttenuation(1, 0.0001, 0.0001);
	light.setDiffuseColor(lightColor);
	light.setSpecularColor(lightColor);
	light.setPosition(1000, -5000, 1000);

	cauldronMat.setEmissiveColor(ofFloatColor(17, 17, 17, 1.0));
	
	cam.setUpAxis({ 0, -1, 0 });
	cam.setPosition(-500, -200, 600);
	cam.lookAt({ 0, -200, 0 }, { 0, -1, 0 });

	timeIncrease = 0;
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
				particleSystem[i].Move(timeIncrease * ofGetLastFrameTime());
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

	cam.begin();

	ofPushMatrix();

	for (int i = 0; i < particleSystem.size(); i++) {
		bubbleMat.setEmissiveColor(ofFloatColor(particleSystem[i].colour, 0));
		bubbleMat.begin();
		ofDrawSphere(particleSystem[i].x, particleSystem[i].y, particleSystem[i].z, particleSystem[i].radius);
		bubbleMat.end();
	}

	cauldronMat.begin();
	model.drawFaces();
	cauldronMat.end();

	cam.end();
	ofDisableDepthTest();
	ofPopMatrix();	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case(32): 
		initParticleSystem(COUNT); 
		moving = false; 
		timeIncrease = 0;
		break;
	case('0'): moving = !moving; break;
	case('t'): 
		timeIncrease += 10;
		break;
	case('T'):
		if (timeIncrease > 10) {
			timeIncrease -= 10;
		}
		break;
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
