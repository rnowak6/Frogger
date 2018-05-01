#include "ofApp.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP  *background = NULL;
ALLEGRO_BITMAP  *frog = NULL;
ALLEGRO_BITMAP  *right_car = NULL;
ALLEGRO_BITMAP *left_car = NULL;

//float x = 60;
//float y = 100;
float direction = 7;
float carax = -300;
float caray = 100;
float carbx = 600;
float carby = 0;

/*
sets up game
*/
void ofApp::setup(){
#define BACKGROUND_FILE "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\background.jpg"
#define FROG_FILE    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\frog.png"
#define RIGHT_CAR    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carright.png"
#define LEFT_CAR "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carleft.png"


	al_init_image_addon();

	display = al_create_display(640, 480);

	background = al_load_bitmap(BACKGROUND_FILE);
	frog = al_load_bitmap(FROG_FILE);
	right_car = al_load_bitmap(RIGHT_CAR);
	left_car = al_load_bitmap(LEFT_CAR);
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
	al_draw_bitmap(background, 0, 0, 0);
	//al_draw_bitmap(frog, x, y, NULL);
	al_draw_bitmap(right_car, carax, caray, NULL);
	al_draw_bitmap(left_car, carbx, carby, NULL);
	al_flip_display();
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
	/**if (key == OF_KEY_DOWN) {
		if (y > 260) {
			y = 260;
		}
		else {
			y += direction;
		}

	}
	else if (key == OF_KEY_UP) {
		if (y < -170) {
			y = -170;
		}
		else {
			y -= direction;
		}
	}
	else if (key == OF_KEY_RIGHT) {
		if (x > 430) {
			x = 430;
		}
		else {
			x += direction;
		}
	}
	else if (key == OF_KEY_LEFT) {
		if (x < -150) {
			x = -150;
		}
		else {
			x -= direction;
		}
	}
	else {
	}
	**/
}

void ofApp::reset() {
	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_destroy_bitmap(frog);
	al_uninstall_system();
	//resets game
	//repositions snake and resets timer
}

void ofApp::displayCars() {
	ALLEGRO_BITMAP  *right_car = NULL;
	ALLEGRO_BITMAP *left_car = NULL;
	right_car = al_load_bitmap(RIGHT_CAR);
	left_car = al_load_bitmap(LEFT_CAR);


	if (carax > 600) {
		carax = -300;
	}
	else {
		carax++;
	}

	if (carbx < -300) {
		carbx = 600;
	}
	else {
		carbx--;
	}

	al_draw_bitmap(right_car, carax, caray, NULL);
	al_draw_bitmap(left_car, carbx, carby, NULL);

	//displays cars
	//keeps them moving continuously
}

void ofApp::setFrog() {
	float x = 60;
	float y = 100;
	float direction = 7;
	//sets frog at starting position
	//if user changes keys, move frog in given direction
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	

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
