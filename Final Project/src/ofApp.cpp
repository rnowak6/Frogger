#include "ofApp.h"

/*
sets up game
*/
void ofApp::setup(){
	ofSetWindowTitle("Frogger");

	srand(static_cast<unsigned>(time(0))); // Seed random with current time
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
	if (key == OF_KEY_F12) {
		ofToggleFullscreen();
		return;
	}

	int upper_key = toupper(key); // Standardize on upper case

	if (upper_key == 'P' && current_state_ != FINISHED) {
		// Pause or unpause
		current_state_ = (current_state_ == IN_PROGRESS) ? PAUSED : IN_PROGRESS;
	}
	else if (current_state_ == IN_PROGRESS)
	{
		//get frog direction

		// If current direction has changed to a valid new one, force an immediate update and skip the next frame update
		if (upper_key == 'W' && current_direction != DOWN && current_direction != UP) {
			game_frog_.setDirection(UP);
			update();
			should_update_ = false;
		}
		else if (upper_key == 'A' && current_direction != RIGHT && current_direction != LEFT) {
			game_frog_.setDirection(LEFT);
			update();
			should_update_ = false;
		}
		else if ((upper_key == 'S') && current_direction != UP && current_direction != DOWN) {
			game_frog_.setDirection(DOWN);
			update();
			should_update_ = false;
		}
		else if (upper_key == 'D' && current_direction != LEFT && current_direction != RIGHT) {
			game_frog_.setDirection(RIGHT);
			update();
			should_update_ = false;
		}
	}
	else if (upper_key == 'R' && current_state_ == FINISHED) {
		reset();
	}
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
