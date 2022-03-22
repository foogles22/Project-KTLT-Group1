#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <mmsystem.h>
#include <cstring>
#include <math.h>
using namespace std;
void gotoXY(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX - 1;
	Position.Y = posY - 1;

	SetConsoleCursorPosition(hStdout, Position);
}
// func to changing text colour
void textColor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
// func to clear screen smoothly
void clrs()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 1;
	Position.Y = 1;
	SetConsoleCursorPosition(hOut, Position);
}
void print_Login()
{
	textColor(11);
	int x1 = 65, y1 = 4;

	gotoXY(x1, ++y1);
					cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.";
	gotoXY(x1, ++y1);
					cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
	gotoXY(x1, ++y1);
					cout << "| |   _____      | || |     ____     | || |    ______    | || |     _____    | || | ____  _____  | |";
	gotoXY(x1, ++y1);
					cout << "| |  |_   _|     | || |   .'    `.   | || |  .' ___  |   | || |    |_   _|   | || ||_   \\|_   _| | |";
	gotoXY(x1, ++y1);
					cout << "| |    | |       | || |  /  .--.  \\  | || | / .'   \\_|   | || |      | |     | || |  |   \\ | |   | |";
	gotoXY(x1, ++y1);
					cout << "| |    | |   _   | || |  | |    | |  | || | | |    ____  | || |      | |     | || |  | |\\ \\| |   | |";
	gotoXY(x1, ++y1);
					cout << "| |   _| |__/ |  | || |  \\  `--'  /  | || | \\ `.___]  _| | || |     _| |_    | || | _| |_\\   |_  | |";
	gotoXY(x1, ++y1);
					cout << "| |  |________|  | || |   `.____.'   | || |  `._____.'   | || |    |_____|   | || ||_____|\\____| | |";
	gotoXY(x1, ++y1);
					cout << "| |              | || |              | || |              | || |              | || |              | |";
	gotoXY(x1, ++y1);
					cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
	gotoXY(x1, ++y1);
					cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'";

	textColor(15);
}

void print_menu(int choose)
{
	int x = 110, y = 27;
	for (int i = 0; i < 6; i++) {
		if (choose == i) textColor(12);
		gotoXY(x, ++y);
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
		gotoXY(x, ++y);
		cout << char(186);
		if (choose == i)	textColor(15);
		if (i == 0)cout << "  START  ";
		if (i == 1)cout << "  LOGIN  ";
		if (i == 2)cout << "LOAD SAVE";
		if (i == 3)cout << "  GUIDE  ";
		if (i == 4) cout << "  SCORE  ";
		if (i == 5) cout << "  QUIT!  ";
		if (choose == i)	textColor(12);
		cout << char(186);
		gotoXY(x, ++y);
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);
		if (choose == i)	textColor(15);
	}
}
int main()
{
	/*int choose = 0;	char move;
	do {

		system("CLS");
		do {
			print_Login();
			print_menu(choose);
			move = _getch();

			if (move == 'w' || move == 72)
				if (choose > 0)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 5)
					choose++;

			print_menu(choose);

		} while (move != 13);

	} while (choose != 5);*/

	print_Login();
	_getch();
}