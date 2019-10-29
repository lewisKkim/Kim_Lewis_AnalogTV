#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	camWidth = 320;
	camHeight = 240;
	skew = 1;

	vidGrabber.setVerbose(true);
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(30);
	vidGrabber.initGrabber(camWidth, camHeight);

	vidPixels.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	vidHorzSlope.allocate(vidPixels);
	vidHorzMult.allocate(vidPixels);
	vidHorzInter.allocate(vidPixels);
	vidVertSlope.allocate(vidPixels);
	vidVertMult.allocate(vidPixels);
	vidVertInter.allocate(vidPixels);
}

//--------------------------------------------------------------
void ofApp::update() {
	vidGrabber.update();

	ofPixelsRef pixelRef = vidGrabber.getPixels();

	for (int c = 0; c < camWidth; c++) {
		for (int i = 0; i < camHeight; i++) {
			vidPixels.setColor(c,
				i,
				pixelRef.getColor(c, (i + (int)((float)(c - camWidth / 2) * (float)(skew) * 0.008) + camHeight * 10) % camHeight));
		}
	}

	vidHorzSlope.loadData(vidPixels);

	for (int c = 0; c < camWidth; c++) {
		for (int i = 0; i < camHeight; i++) {
			vidPixels.setColor(c,
				i,
				pixelRef.getColor(c, (i + (c - camWidth / 2 + camHeight) * skew) % camHeight));
		}
	}

	vidHorzMult.loadData(vidPixels);

	for (int c = 0; c < camWidth; c++) {
		for (int i = 0; i < camHeight; i++) {
			if (c % 2 == 0) {
				vidPixels.setColor(c,
					i,
					pixelRef.getColor(c, (i - skew + camHeight) % camHeight));
			}
			else {
				vidPixels.setColor(c,
					i,
					pixelRef.getColor(c, (i + skew + camHeight) % camHeight));
			}
		}
	}

	vidHorzInter.loadData(vidPixels);

	for (int c = 0; c < camWidth; c++) {
		for (int i = 0; i < camHeight; i++) {
			vidPixels.setColor(c,
				i,
				pixelRef.getColor((c + (int)((float)(i - camHeight / 2) * (float)(skew) * 0.008) + camWidth * 10) % camWidth, i));
		}
	}

	vidVertSlope.loadData(vidPixels);

	for (int c = 0; c < camWidth; c++) {
		for (int i = 0; i < camHeight; i++) {
			vidPixels.setColor(c,
				i,
				pixelRef.getColor((c + (i - camHeight / 2 + camWidth) * skew ) % camWidth, i));
		}
	}

	vidVertMult.loadData(vidPixels);

	for (int c = 0; c < camWidth; c++) {
		for (int i = 0; i < camHeight; i++) {
			if (i % 2 == 0) {
				vidPixels.setColor(c,
					i,
					pixelRef.getColor((c - skew + camWidth) % camWidth, i));
			}
			else {
				vidPixels.setColor(c,
					i,
					pixelRef.getColor((c + skew + camWidth) % camWidth, i));
			}
		}
	}

	vidVertInter.loadData(vidPixels);

	for (int c = 0; c < camWidth; c++) {
		for (int i = 0; i < camHeight; i++) {
			if (ofRandom(1) < 0.666) {
				vidPixels.setColor(c,
					i,
					ofColor::black);
			}
			else {
				vidPixels.setColor(c,
					i,
					ofColor::white);
			}
		}
	}

	vidStatic.loadData(vidPixels);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(ofColor::white);
	vidGrabber.draw(20, 40, 320, 240);
	//(x, y, w, h)
	vidHorzSlope.draw(350, 40, 320, 240);
	vidHorzMult.draw(680, 40, 320, 240);
	vidVertSlope.draw(20, 290, 320, 240);
	vidVertMult.draw(350, 290, 320, 240);
	vidHorzInter.draw(680, 290, 320, 240);
	vidVertInter.draw(20, 540, 320, 240);
	vidStatic.draw(350, 540, 320, 240);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0) {
		skew++;

	}
	else if (button == 2){
		skew--;

	}
	else {
		skew = 1;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}