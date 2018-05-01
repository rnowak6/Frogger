#include "ofMain.h"
#include "ofApp.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>


#define BACKGROUND_FILE "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\background.jpg"
#define FROG_FILE    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\frog.png"
#define RIGHT_CAR    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carright.png"
#define LEFT_CAR "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carleft.png"
bool done = false;

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


void gameOverDisplay(bool game_over) {
	al_init();
	al_init_font_addon();
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "You lost!");
	al_flip_display();
	al_rest(5.0);
}

void wonGame() {
	al_init();
	al_init_font_addon();
	ALLEGRO_DISPLAY* display = al_create_display(200, 200);
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_CENTER, "You win!");
	al_flip_display();
	al_rest(5.0);
	done = true;
}


bool checkIfTouching(Car car, Frog frog) {
	int carx = car.getX();
	int cary = car.getY();
	int frogx = frog.getX();
	int frogy = frog.getY();

	if (frogx == carx && frogy == cary) {
		gameOverDisplay(true);
	}
	else if (frogx + 10 == carx && frogy + 10 == cary) {
		gameOverDisplay(true);
	}
	else {
		gameOverDisplay(false);
	}
	return false;
}

/**
void playGameOverSound() {
	ofSoundPlayer   mySound;
	mySound.load("gameover");
	mySound.play();
}

void playGameWonSound() {
	ofSoundPlayer   mySound;
	mySound.load("gamewon");
	mySound.play();
}
**/


int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *background = NULL;
	ALLEGRO_BITMAP  *frog = NULL;
	ALLEGRO_BITMAP  *right_car = NULL;
	ALLEGRO_BITMAP *left_car = NULL;
	//will be used later to initialize screen
	bool draw = true;
	bool active = false;

	ofSoundPlayer  hop;
	ofSoundPlayer win;
	win.load("gamewon.wav");
	hop.load("hop.wav");
	ofSoundSetVolume(1.0);

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	al_init_image_addon();

	display = al_create_display(640, 480);

	background = al_load_bitmap(BACKGROUND_FILE);
	frog = al_load_bitmap(FROG_FILE);
	right_car = al_load_bitmap(RIGHT_CAR);
	left_car = al_load_bitmap(LEFT_CAR);


	//initializes sprite placement
	Frog moving_frog;
	Car right_car_1 = Car(-300, 100, true);
	Car right_car_2 = Car(-700, 100, true);
	Car right_car_3 = Car(-1100, 100, true);
	Car left_car_1 = Car(600, 0, false);
	Car left_car_2 = Car(200, 0, false);

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
		int ax = right_car_1.getX();
		int ax2 = right_car_2.getX();
		int ax3 = right_car_3.getX();
		int bx = left_car_1.getX();
		int bx2 = left_car_2.getX();

		if (ax > 800) {
			right_car_1.setX(-300);
			//checkIfTouching(right_car_1, moving_frog);
		}
		else {
			ax++;
			right_car_1.setX(ax);
			//checkIfTouching(right_car_1, moving_frog);
		}

		if (ax2 > 800) {
			right_car_2.setX(-300);
			//checkIfTouching(right_car_2, moving_frog);
		}
		else {
			ax2++;
			right_car_2.setX(ax2);
		}
		if (ax3 > 800) {
			right_car_3.setX(-300);
			//checkIfTouching(right_car_2, moving_frog);
		}
		else {
			ax3++;
			right_car_3.setX(ax3);
		}

		if (bx < -300) {
			left_car_1.setX(600);
			//checkIfTouching(left_car_1, moving_frog);
		}
		else {
			bx--;
			left_car_1.setX(bx);
			//checkIfTouching(left_car_1, moving_frog);
		}

		if (bx2 < -300) {
			left_car_2.setX(600);
			//checkIfTouching(left_car_1, moving_frog);
		}
		else {
			bx2--;
			left_car_2.setX(bx2);
			//checkIfTouching(left_car_1, moving_frog);
		}
		
		//************************************FROG****************************//

		ALLEGRO_EVENT events;
		al_get_next_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		//controls the movements of the sprite
			int frog_x = moving_frog.getX();
			int frog_y = moving_frog.getY();
			int frog_speed = moving_frog.getSpeed();

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


		//creates the background and the sprite
		al_draw_bitmap(background, 0, 0, 0);
		al_draw_bitmap(frog, moving_frog.getX(), moving_frog.getY(), NULL);
		al_draw_bitmap(right_car, right_car_1.getX(), right_car_1.getY(), NULL);
		al_draw_bitmap(right_car, right_car_2.getX(), right_car_2.getY(), NULL);
		al_draw_bitmap(right_car, right_car_3.getX(), right_car_3.getY(), NULL);
		al_draw_bitmap(left_car, left_car_1.getX(), left_car_1.getY(), NULL);
		al_draw_bitmap(left_car, left_car_2.getX(), left_car_2.getY(), NULL);
		al_flip_display();
	}

	//closes program
	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_destroy_bitmap(frog);
	//al_uninstall_system();
	return 0;
}