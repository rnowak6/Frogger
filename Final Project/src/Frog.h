#pragma once
//using namespace std;
class Frog {
		int x = 0;
		int y = 0;
		int speed = 0;
public:
	Frog::Frog();
	int getX();
	int getY();
	int getSpeed();
	void setX(int newX);
	void setY(int newY);
};
