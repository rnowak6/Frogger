#pragma once
#include "ofMain.h"
#include "ofApp.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include "main.h"
//loads file path of images
#define BACKGROUND_FILE "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\background.jpg"
#define FROG_FILE    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\frog.png"
#define RIGHT_CAR    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carright.png"
#define LEFT_CAR "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carleft.png"

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP  *background = NULL;
ALLEGRO_BITMAP  *frog = NULL;
ALLEGRO_BITMAP  *right_car = NULL;
ALLEGRO_BITMAP *left_car = NULL;

/**
Creates a frog object to simplify the code
**/
class Frog {
private:
	int x, y, speed;
public:
	Frog() {
		x = 150;
		y = 260;
		speed = 1;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getSpeed() {
		return speed;
	}
	void setX(int new_x) {
		x = new_x;
	}
	void setY(int new_y) {
		y = new_y;
	}
};


/**
Created a Car object to cut down on repeated methods. The Car object holds the coordinate of the car and 
if the car is facing right because if it isnt then it's facing right which mean we know the direction of the car
**/
class Car {
private:
	int x, y;
	bool facing_right;
public:
	Car(int new_x, int new_y, bool direction) {
		x = new_x;
		y = new_y;
		facing_right = direction;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	bool getDirection() {
		return facing_right;
	}
	void setX(int new_x) {
		x = new_x;
	}
	void setY(int new_y) {
		y = new_y;
	}
	void setDirection(bool is_facing_right) {
		facing_right = is_facing_right;
	}
};

//initializes sprite placement
Frog moving_frog = Frog();
Car right_car_1 = Car(-300, 100, true);
Car right_car_2 = Car(-900, 100, true);
Car right_car_3 = Car(-400, 250, true);
Car right_car_4 = Car(-1000, 250, true);
Car left_car_1 = Car(600, 0, false);
Car left_car_2 = Car(200, 0, false);
Car left_car_3 = Car(500, 300, false);
Car left_car_4 = Car(200, 300, false);
bool done = false;

void load() {
	//reloads to sprite placements
	moving_frog = Frog();
	right_car_1 = Car(-300, 100, true);
	right_car_2 = Car(-900, 100, true);
	right_car_3 = Car(-400, 250, true);
	right_car_4 = Car(-1000, 250, true);
	left_car_1 = Car(600, 0, false);
	left_car_2 = Car(200, 0, false);
	left_car_3 = Car(500, 300, false);
	left_car_4 = Car(200, 300, false);
	//will be used later to initialize screen
	bool draw = true;
	bool active = false;
	bool done = false;

	//makes sure allegro was initialized properly
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return;
	}

	al_init_image_addon();
	
	//creates images
	display = al_create_display(640, 480);

	//loads images
	background = al_load_bitmap(BACKGROUND_FILE);
	frog = al_load_bitmap(FROG_FILE);
	right_car = al_load_bitmap(RIGHT_CAR);
	left_car = al_load_bitmap(LEFT_CAR);
}


//displays game over and plays the game over sound
void gameOverDisplay() {
		ofSoundPlayer lost;
		lost.load("gameover.wav");
		ofSoundSetVolume(1.0);
		lost.play();
		al_init();
		al_init_font_addon();
		ALLEGRO_DISPLAY* display = al_create_display(200, 200);
		ALLEGRO_FONT* font = al_create_builtin_font();
		al_clear_to_color(al_map_rgb(105, 105, 105));
		al_draw_text(font, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_CENTER, "You lost!");
		al_flip_display();
		//leaves it up for 20 seconds
		al_rest(20.0);
}


//displays a win and plays a song for the winner
void wonGame() {
	al_init();
	al_init_font_addon();
	ALLEGRO_DISPLAY* display = al_create_display(200, 200);
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_clear_to_color(al_map_rgb(105, 105, 105));
	al_draw_text(font, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_CENTER, "You win!");
	al_flip_display();
	al_rest(10.0);
}


//helper function to check for collision by making rectangles for collision detection
bool checkCollision(int frogx, int frogy, int frogw, int frogh, int carx, int cary, int carw, int carh){
	//credit to Allegro tutorial for collision
	if ((frogx > carx + carw - 1) || (frogy > cary + carh - 1) || (carx > frogx + frogw - 1) ||
		(cary > frogy + frogh - 1))
	{
		return false;
	}
	return true;
}

//Checks if the frog is being hit by a car and if it is, it calls the game over function because the frog is dead
void checkIfTouching(Car car, Frog frog) {
	int frogx = frog.getX();
	int frogy = frog.getY();
	int frogw = 30;
	int frogh = 7;
	int carx = car.getX();
	int cary = car.getY();
	int carw = 30;
	int carh = 8;
	if (checkCollision(frogx, frogy, frogw, frogh, carx, cary, carw, carh)) {
		gameOverDisplay();
	}
}


//Simpler function that moves cars instead of doing it individually. It moves it accordingly based on the direction of the car
int moveCar(Car car) {
	if (car.getDirection()) {
		if (car.getX() > 800) {
			car.setX(-300);
			return -300;
		}
		else {
			int new_x = car.getX() + 1;
			car.setX(new_x);
			checkIfTouching(car, moving_frog);
			return new_x;
		}
	}
	else {
		if (car.getX() < -300) {
			car.setX(600);
			return 600;
		}
		else {
			int new_x = car.getX() - 1;
			car.setX(new_x);
			checkIfTouching(car, moving_frog);
			return new_x;
		}
	}
}

int main() {
	//loads the game
	load();
	
	//loads the sound effects
	ofSoundPlayer  hop;
	ofSoundPlayer win;
	win.load("gamewon.wav");
	hop.load("hop.wav");
	ofSoundSetVolume(1.0);

	al_install_keyboard();
	al_init_image_addon();


	//allows user to use keyboard
	ALLEGRO_KEYBOARD_STATE keyState;
	//creates event listener
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		//moves cars
		right_car_1.setX(moveCar(right_car_1));
		right_car_2.setX(moveCar(right_car_2));
		right_car_3.setX(moveCar(right_car_3));
		right_car_4.setX(moveCar(right_car_4));
		left_car_1.setX(moveCar(left_car_1));
		left_car_2.setX(moveCar(left_car_2));
		left_car_3.setX(moveCar(left_car_3));
		left_car_4.setX(moveCar(left_car_4));

		//************************************FROG****************************//
		//credit to CodingMadeEasy
		ALLEGRO_EVENT events;
		al_get_next_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		//controls the movements of the sprite
		int frog_x = moving_frog.getX();
		int frog_y = moving_frog.getY();
		int frog_speed = moving_frog.getSpeed();

		//moves the frog accordingly
		if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
			hop.play();
			if (frog_y > 260) {
				moving_frog.setY(260);
			}
			else {
				moving_frog.setY(frog_y + frog_speed);
			}

		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
			hop.play();
			if (frog_y < -170) {
				win.play();
				wonGame();
				moving_frog.setY(-170);
			}
			else {
				moving_frog.setY(frog_y - frog_speed);
			}
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
			hop.play();
			if (frog_x > 430) {
				moving_frog.setX(430);
			}
			else {
				moving_frog.setX(frog_x + frog_speed);
			}
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
			hop.play();
			if (frog_x < -150) {
				moving_frog.setX(-150);
			}
			else {
				moving_frog.setX(frog_x - frog_speed);
			}
		}
		else {
			done = false;
		}


		//draws all the objects on the screen
		al_draw_bitmap(background, 0, 0, 0);
		al_draw_bitmap(frog, moving_frog.getX(), moving_frog.getY(), NULL);
		al_draw_bitmap(right_car, right_car_1.getX(), right_car_1.getY(), NULL);
		al_draw_bitmap(right_car, right_car_2.getX(), right_car_2.getY(), NULL);
		al_draw_bitmap(right_car, right_car_3.getX(), right_car_3.getY(), NULL);
		al_draw_bitmap(right_car, right_car_4.getX(), right_car_4.getY(), NULL);
		al_draw_bitmap(left_car, left_car_1.getX(), left_car_1.getY(), NULL);
		al_draw_bitmap(left_car, left_car_2.getX(), left_car_2.getY(), NULL);
		al_draw_bitmap(left_car, left_car_3.getX(), left_car_3.getY(), NULL);
		al_draw_bitmap(left_car, left_car_4.getX(), left_car_4.getY(), NULL);
		al_flip_display();
	}

	//closes program
	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_destroy_bitmap(frog);
	//al_uninstall_system();
	return 0;
}
