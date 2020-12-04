#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "ofxAssimpModelLoader.h"
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

		void initParticleSystem(int n);
		Particle initParticle(double pop_x = 0, double pop_y = 0, 
							  double pop_z = 0, double radius = 0);
		float timeIncrease;

		bool moving = false;
		std::vector<Particle> particleSystem;
		ofMaterial bubbleMat;
		ofMaterial cauldronMat;

		ofEasyCam cam;
		ofxAssimpModelLoader model;
		ofLight light;
};