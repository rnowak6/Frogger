#include "Frog.h"


//using namespace std;
Frog::Frog() {
	x = 150;
	y = 260;
	speed = 1;
}
int Frog::getX() {
	return x;
}
int Frog::getY() {
	return y;
}
int Frog::getSpeed() {
	return speed;
}
void Frog::setX(int newX) {
	x = newX;
}
void Frog::setY(int newY) {
	y = newY;
}


