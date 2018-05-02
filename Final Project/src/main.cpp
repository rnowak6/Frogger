#include "ofMain.h"
#include "ofApp.h"
#include "..\Frog.h"
#include "..\gameState.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>


#define BACKGROUND_FILE "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\background.jpg"
#define FROG_FILE    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\frog.png"
#define RIGHT_CAR    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carright.png"
#define LEFT_CAR "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\carleft.png"

gameState game;


bool done = false;
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

void checkIfTouching(Car car, Frog frog) {
	al_init_primitives_addon();
	al_draw_rectangle(frog.getX() - 5, frog.getY() - 5, 5, 5, al_map_rgb(255, 255, 255), 2.0);

	ofRectangle frog_rect(frog.getX() - 5, frog.getY() -5, 5 , 5);
	ofRectangle car_rect(car.getX()-5, car.getY()-5, 5, 5);
	game.gameOverDisplay();
	//gameOverDisplay(frog_rect.intersects(car_rect));
}


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
	Frog moving_frog = Frog::Frog();
	Car right_car_1 = Car(-300, 100, true);
	Car right_car_2 = Car(-900, 100, true);
	Car right_car_3 = Car(-400, 250, true);
	Car right_car_4 = Car(-1000, 250, true);
	Car left_car_1 = Car(600, 0, false);
	Car left_car_2 = Car(200, 0, false);
	Car left_car_3 = Car(500, 300, false);
	Car left_car_4 = Car(200, 300, false);


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
		int ax4 = right_car_4.getX();
		int bx = left_car_1.getX();
		int bx2 = left_car_2.getX();
		int bx3 = left_car_3.getX();
		int bx4 = left_car_4.getX();

		/**
		checkIfTouching(right_car_1, moving_frog);
		checkIfTouching(right_car_2, moving_frog);
		checkIfTouching(right_car_3, moving_frog);
		checkIfTouching(right_car_4, moving_frog);
		checkIfTouching(left_car_1, moving_frog);
		checkIfTouching(left_car_2, moving_frog);
		checkIfTouching(left_car_3, moving_frog);
		checkIfTouching(left_car_4, moving_frog);
		**/
		al_init_primitives_addon();
		al_draw_rectangle(moving_frog.getX() - 5, moving_frog.getY() - 5, 5, 5, al_map_rgb(255, 255, 255), 2.0);



		if (ax > 800) {
			right_car_1.setX(-300);
		}
		else {
			ax++;
			right_car_1.setX(ax);
		}

		if (ax2 > 800) {
			right_car_2.setX(-300);
		}
		else {
			ax2++;
			right_car_2.setX(ax2);
		}
		if (ax3 > 800) {
			right_car_3.setX(-300);
		}
		else {
			ax3++;
			right_car_3.setX(ax3);
		}
		if (ax4 > 800) {
			right_car_4.setX(-300);
		}
		else {
			ax4++;
			right_car_4.setX(ax4);
		}

		if (bx < -300) {
			left_car_1.setX(600);
		}
		else {
			bx--;
			left_car_1.setX(bx);
		}

		if (bx2 < -300) {
			left_car_2.setX(600);
		}
		else {
			bx2--;
			left_car_2.setX(bx2);
		}
		if (bx3 < -300) {
			left_car_3.setX(600);
		}
		else {
			bx3--;
			left_car_3.setX(bx3);
		}
		if (bx4 < -300) {
			left_car_4.setX(600);
		}
		else {
			bx4--;
			left_car_4.setX(bx2);
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