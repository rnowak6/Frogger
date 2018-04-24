#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define BACKGROUND_FILE     "background.jpg"
int main(void) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *background = NULL;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	al_init_image_addon();//should check for errors

	display = al_create_display(640, 480);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return -2;
	}

	background = al_load_bitmap(BACKGROUND_FILE);
	if (!background)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		return -3;
	}
	al_draw_bitmap(background, 0, 0, 0);

	al_flip_display();

	al_rest(2.0);

	while (1) {}

	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_uninstall_system();
	return 0;
}