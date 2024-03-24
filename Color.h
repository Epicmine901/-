#pragma once
#include <iostream>
#include <string>

using namespace std;
class Color {
public:
	string RGB(char F_or_B, int RED, int GREEN, int BLUE)
	{
		return rgb(F_or_B, RED, GREEN, BLUE);
	};
	string Reset= "\x1b[0m";
	string Hex(string H, char F_or_B) {
		//cout << hex(H[1], H[2]) << endl << hex(H[3], H[4]) << endl << hex(H[5], H[6]) << endl;
		int red = hex(H[1], H[2]), green = hex(H[3],H[4]), blue = hex(H[5],H[6]);
		return rgb(F_or_B, red, green, blue);
	}
private:
	string rgb(char F_or_B, int Red, int Green, int Blue)
	{
		string Color, FB;
		if (F_or_B == 'F')FB = "38";
		if (F_or_B == 'B')FB = "48";
		Color = "\x1b[" + FB + ";2;" + to_string(Red) + ";" + to_string(Green) + ";" + to_string(Blue) + "m";
		return Color;
	};
	int hex(char A,char B) {
		int a=0, b=0;
		switch (A)
		{
		case 'A':a = 160; break;
		case 'B':a = 176; break;
		case 'C':a = 192; break;
		case 'D':a = 208; break;
		case 'E':a = 224; break;
		case 'F':a = 240; break;
		default: a = (A-'0') * 16; break;
		}
		switch (B)
		{
		case 'A':b = 10; break;
		case 'B':b = 11; break;
		case 'C':b = 12; break;
		case 'D':b = 13; break;
		case 'E':b = 14; break;
		case 'F':b = 15; break;
		default: b = (B - '0'); break;
		}
		return a + b;
	}
};
