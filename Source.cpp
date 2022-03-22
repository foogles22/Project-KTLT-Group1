#include <iostream>
#include <windows.h>
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
void print_Login_logo(int x1, int y1)
{
	textColor(11);
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
					cout << "| |    | |   _   | || |  | |    | |  | || || |     ____  | || |      | |     | || |  | |\\ \\| |   | |";
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
void print_Viennen(int length, int width)
{
	//Tren cung
	for (int x = 2; x < length; x++)
	{
		gotoXY(x, 1);
		cout << char(220);
	}
	//Ben phai
	for (int y = 2; y <= width; y++)
	{
		gotoXY(length - 1, y);
		cout << char(219);
	}
	//Ben trai
	for (int y = 2; y <= width; y++)
	{
		gotoXY(2, y);
		cout << char(219);
	}
	//Duoi cung
	for (int x = 2; x < length; x++)
	{
		gotoXY(x, width);
		cout << char(223);
	}
}
void print__fill_square(int x1, int y1, int length, int width, bool led, int color)
{
	textColor(color);
	//Tren cung
	for (int x = x1; x < x1 + length; x++)
	{
		gotoXY(x, y1-1);
		cout << char(220);
	}
	//Ben phai
	for (int y = y1; y <= y1 + width; y++)
	{
		gotoXY(x1 + length - 1, y);
		cout << char(219);
	}
	//Ben trai
	for (int y = y1; y <= y1 + width; y++)
	{
		gotoXY(x1, y);
		cout << char(219);
	}
	//Duoi cung
	for (int x = x1; x < x1 + length; x++)
	{
		gotoXY(x, y1 + width);
		cout << char(223);
	}
	textColor(15);
}
void print__double_square(int x1, int y1, int length, int width, bool led, int color)
{
	textColor(color);
	//Tren cung
	for (int x = x1; x < x1 + length; x++)
	{
		gotoXY(x, y1 - 1);
		if (x == x1)
			cout << char(201);
		if (x == x1 + length - 1)
			cout << char(187);
		else
			cout << char(205);
	}
	//Ben phai
	for (int y = y1; y <= y1 + width; y++)
	{
		gotoXY(x1 + length - 1, y);
		cout << char(186);
	}
	//Ben trai
	for (int y = y1; y <= y1 + width; y++)
	{
		gotoXY(x1, y);
		cout << char(186);
	}
	//Duoi cung
	for (int x = x1; x < x1 + length; x++)
	{
		gotoXY(x, y1 + width);
		if (x == x1)
			cout << char(200);
		if (x == x1 + length - 1)
			cout << char(188);
		else
			cout << char(205);
	}
	textColor(15);
}
void text(int x, int y, string text, bool led, int color)
{
	if(led) textColor(color);
	gotoXY(x, y);
	cout << text;
	if(led) textColor(15);
}
void print_username_password(int choose)
{
	//x,y,length,width,led,color (square)
	//x,y,text,led,color (text)
	if (choose == 1)
		print__double_square(66, 26, 40, 3, 0, 12);	
	else
		print__double_square(66, 26, 40, 3, 0, 15);
		text(67, 27, "USERNAME: ", 1, 15);
	
	if (choose == 2)
		print__double_square(66, 31, 40, 3, 0, 12);
	else 
		print__double_square(66, 31, 40, 3, 0, 15);
		text(67, 32, "PASSWORD: ", 1, 15);

	if (choose == 3)
		print__double_square(78, 36, 17, 1, 0, 12);
	else
		print__double_square(78, 36, 17, 1, 0, 15);
		text(84, 36, "Login", 1, 15);

	if (choose == 4)
		print__double_square(78, 39, 17, 1, 0, 12);
	else
		print__double_square(78, 39, 17, 1, 0, 15);
	text(84, 39, "Exit!", 1, 15);
}
void print_login_status(int x1, int y1, bool succeed)
{
	if (succeed)
	{
			gotoXY(x1, ++y1);
			cout << "	 _                 _                                         _          _ ";
			gotoXY(x1, ++y1);
			cout << "	| |               (_)                                       | |        | |";
			gotoXY(x1, ++y1);
			cout << "	| |     ___   __ _ _ _ __    ___ _   _  ___ ___ ___  ___  __| | ___  __| |";
			gotoXY(x1, ++y1);
			cout << "	| |    / _ \\ / _` | | '_ \\  / __| | | |/ __/ __/ _ \\/ _ \\/ _` |/ _ \\/ _` |";
			gotoXY(x1, ++y1);
			cout << "	| |___| (_) | (_| | | | | | \\__ \\ |_| | (_| (_|  __/  __/ (_| |  __/ (_| |";
			gotoXY(x1, ++y1);
			cout << "	\\_____/\\___/ \\__, |_|_| |_| |___/\\__,_|\\___\\___\\___|\\___|\\__,_|\\___|\\__,_|";
			gotoXY(x1, ++y1);
			cout << "                     __/ |                                                ";
			gotoXY(x1, ++y1);
			cout << "                    |___/                                                 ";
	}
	else
	{
		x1 += 13;
			gotoXY(x1, ++y1);
			cout << "  _                 _          __      _ _          _ ";
			gotoXY(x1, ++y1);
			cout << " | |               (_)        / _|    (_) |        | |";
			gotoXY(x1, ++y1);
			cout << " | |     ___   __ _ _ _ __   | |_ __ _ _| | ___  __| |";
			gotoXY(x1, ++y1);
			cout << " | |    / _ \\ / _` | | '_ \\  |  _/ _` | | |/ _ \\/ _` |";
			gotoXY(x1, ++y1);
			cout << " | |___| (_) | (_| | | | | | | || (_| | | |  __/ (_| |";
			gotoXY(x1, ++y1);
			cout << " |______\\___/ \\__, |_|_| |_| |_| \\__,_|_|_|\\___|\\__,_|";
			gotoXY(x1, ++y1);
			cout << "               __/ |                                  ";
			gotoXY(x1, ++y1);
			cout << "              |___/                                   ";
	}
}
void print_login_section()
{
	int choose = 1;	char move; string mssv, password;
	bool one = true, two = true;
	do {	
		print_username_password(0);
		do {
			// 235, 63
			print_Viennen(167, 51);
			// 68, 4
			print_Login_logo(35,2);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 4)
					choose++;
			print_username_password(choose);
		} while (move != 13);
		if (choose == 1 && one)
		{
			gotoXY(77, 27);
			cin >> mssv;
			one = false;
		}
		if (choose == 2 && two)
		{
			gotoXY(77, 32);
			cin >> password;
			two = false;
		}
		if (choose == 3)
		{
			print_login_status(46, 15,0);
			one = true; two = true;
		}
	} while (choose != 4);
}
int main()
{
	print_login_section();
}