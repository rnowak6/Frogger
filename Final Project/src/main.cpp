#include "ofMain.h"
#include "ofApp.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#define BACKGROUND_FILE "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\background.jpg"
#define FROG_FILE    "C:\\Users\\Rose\\source\\repos\\final-project-rnowak6\\Final Project\\resources\\frog.jpg"

int main() {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *background = NULL;
	ALLEGRO_BITMAP  *frog = NULL;
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

	if (!background)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		return -3;
	}

	//initializes sprite placement
	float x = 60;
	float y = 100;
	float direction = 5;

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
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		//controls the movements of the sprite
		else {
			active = true;
			if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
				y += direction;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
				y -= direction;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
				x += direction;
			}
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
				x -= direction;
			}
			else {
				active = false;
			}

			draw = true;
		}

		//creates the background and the sprite
		if (draw) {
			al_draw_bitmap(background, 0, 0, 0);
			//al_draw_bitmap(frog, x, y, NULL);
			al_flip_display();
		}
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