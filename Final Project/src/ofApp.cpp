#include "ofApp.h"

/*
sets up game
*/
void ofApp::setup(){
}

/*
Update function called before every draw
If the function should update when it is called it will:
1. Check to see if the game is in progress, if it is paused or over it should not update.
2. Check to see if frog was hit by a car
3. Update the frog in the current direction it is moving
4. Check to see if the frog's new position has resulted in its death and the end of the game
*/
void ofApp::update(){
	//do as stated in javadoc
}

//--------------------------------------------------------------
void ofApp::draw(){

	//if game is paused display paused screen

	//if the game has ended display the game over screen

}

/*
Function that handles actions based on user key presses
1. if key == F12, toggle fullscreen
2. if key == p and game is not over, toggle pause
3. if game is in progress handle arrow action
4. if key == r and game is over reset it
*/
void ofApp::keyPressed(int key){
	
}

void ofApp::reset() {
	//resets game
	//repositions snake and resets timer
}

void ofApp::displayCars() {
	//displays cars
	//keeps them moving continuously
}

void ofApp::setFrog() {
	//sets frog at starting position
	//if user changes keys, move frog in given direction
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
