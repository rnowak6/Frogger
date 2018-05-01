#pragma once
#include <ctime>
#include <cstdlib>
#include <utility>

#include "ofMain.h"

class ofApp : public ofBaseApp{
	// Enum to represent the current state of the game
	enum GameState {
		IN_PROGRESS = 0,
		PAUSED,
		FINISHED
	};

private:
	vector<int> high_scores;
	GameState current_state_ = IN_PROGRESS; // The current state of the game, used to determine possible actions

	bool should_update_ = true;     // A flag boolean used in the update() function. Due to the frame dependent animation we've
									// written, and the relatively low framerate, a bug exists where users can prefire direction 
									// changes faster than a frame update. Our solution is to force a call to update on direction
									// changes and then not update on the next frame to prevent the snake from skipping across the screen.


									// Private helper methods to render various aspects of the game on screen.
	void drawFrog();
	void drawGameOver();
	void drawGamePaused();

	// Resets the game objects to their original state.
	void reset();

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
		void ofApp::displayCars();
		void ofApp::setFrog();

		
		static void playFrogSound();

};
