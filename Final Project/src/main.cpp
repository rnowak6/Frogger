#include "ofMain.h"
#include "ofApp.h"

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#define BACKGROUND_FILE "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\background.jpg"
#define FROG_FILE    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\frog.png"
#define RIGHT_CAR    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carright.png"
#define LEFT_CAR "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carleft.png"

using namespace std;
class Frog {
private:
	int x, y, speed;
public:
	Frog::Frog() {
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
	void setX(int newX) {
		x = newX;
	}
	void setY(int newY) {
		y = newY;
	}
};

class Car {
private:
	int x, y;
	bool facing_right;
public:
	Car::Car(int newX, int newY, bool direction) {
		x = newX;
		y = newY;
		facing_right = direction;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	bool getDirection(){
		return facing_right;
	}
	void setX(int newX) {
		x = newX;
	}
	void setY(int newY) {
		y = newY;
	}
	void setDirection(bool is_facing_right) {
		facing_right = is_facing_right;
	}
};


void checkIfTouching(int carx, int cary, int frogx, int frogy) {
	
}


int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *background = NULL;
	ALLEGRO_BITMAP  *frog = NULL;
	ALLEGRO_BITMAP  *right_car = NULL;
	ALLEGRO_BITMAP *left_car = NULL;
	//will be used later to initialize screen
	bool done = false;
	bool draw = true;
	bool active = false;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	al_init_image_addon();

	display = al_create_display(640, 480);

	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -2;
	}

	background = al_load_bitmap(BACKGROUND_FILE);
	frog = al_load_bitmap(FROG_FILE);
	right_car = al_load_bitmap(RIGHT_CAR);
	left_car = al_load_bitmap(LEFT_CAR);

	if (!background)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		return -3;
	}

	//initializes sprite placement
	Frog moving_frog;
	float carax = -300;
	float caray = 100;
	float carbx = 600;
	float carby = 0;

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
		
		ALLEGRO_EVENT events;
		al_get_next_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		//controls the movements of the sprite
			int frog_x = moving_frog.getX();
			int frog_y = moving_frog.getY();
			int frog_speed = moving_frog.getSpeed();

			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
				if (frog_y > 260) {
					moving_frog.setY(260);
				}
				else {
					moving_frog.setY(frog_y + frog_speed);
				}
				 
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
				if (frog_y < -170) {
					moving_frog.setY(-170);
				}
				else {
					moving_frog.setY(frog_y - frog_speed);
				}
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
				if (frog_x > 430) {
					moving_frog.setX(430);
				}
				else {
					moving_frog.setX(frog_x + frog_speed);
				}
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
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


		//creates the background and the sprite
		al_draw_bitmap(background, 0, 0, 0);
		al_draw_bitmap(frog, moving_frog.getX(), moving_frog.getY(), NULL);
		al_draw_bitmap(right_car, carax, caray, NULL);
		al_draw_bitmap(left_car, carbx, carby, NULL);
		al_flip_display();
	}

	//throws it into a while loop so it doesn't immediately close
	while (1) {}

	//closes program
	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_destroy_bitmap(frog);
	al_uninstall_system();
	return 0;
}