#ifndef HSV_COLOR_H
#define HSV_COLOR_H


//A helper class with HSV color manipulation
class HSVColor {
public:
	int hue;
	float sat;
	float val;
	HSVColor(int h, float s, float v);
};
#endif