#include "ofMain.h"
#include ".\Frog.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include "gameState.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

void gameOverDisplay(bool game_over) {
	if (game_over) {
		ofSoundPlayer lost;
		lost.load("gameover.wav");
		ofSoundSetVolume(1.0);
		al_init();
		al_init_font_addon();
		ALLEGRO_DISPLAY* display = al_create_display(200, 200);
		ALLEGRO_FONT* font = al_create_builtin_font();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(font, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_CENTER, "You lost!");
		al_flip_display();
		al_rest(5.0);
	}
}

bool wonGame() {
	al_init();
	al_init_font_addon();
	ALLEGRO_DISPLAY* display = al_create_display(200, 200);
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 100, 100, ALLEGRO_ALIGN_CENTER, "You win!");
	al_flip_display();
	al_rest(5.0);
	return true;
}