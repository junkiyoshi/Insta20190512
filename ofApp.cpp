#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
	ofSetLineWidth(5);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 90;
	int radius = span * 0.5;
	for (int x = radius; x < ofGetWidth(); x += span) {

		for (int y = radius; y < ofGetHeight(); y += span) {

			int r = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.001), 0, 1, 0, 4);
			int deg_start = r * 90;
			ofBeginShape();
			for (int deg = deg_start; deg <= deg_start + 270; deg++)  {

				ofVertex(x + radius * cos(deg * DEG_TO_RAD), y + radius * sin(deg * DEG_TO_RAD));
			}
			ofEndShape();
		}
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}