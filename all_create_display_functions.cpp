#include "all_structs.h"
using namespace std; 

void gotoXY(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX - 1;
	Position.Y = posY - 1;

	SetConsoleCursorPosition(hStdout, Position);
}
void textColor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
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
void print_duongthang(int x1, int y1, int length)
{
	for (int y = 2; y < length + y1; y++)
	{
		gotoXY(x1, y);
		cout << char(219);
	}
}
void print_duongngang(int x1, int y1, int lenght)
{
	for (int x = x1; x < lenght + x1; x++)
	{
		gotoXY(x, y1);
		cout << char(220);
	}
}
void print_fill_square(int x1, int y1, int length, int width, int color, string text)
{
	gotoXY(x1 + ((length - 2) - text.length()) / 2 + 1, width / 2 + y1);
	cout << text;
	textColor(color);
	//Tren cung
	for (int x = x1; x < x1 + length; x++)
	{
		gotoXY(x, y1 - 1);
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
void print_double_square(int x1, int y1, int length, int width, int color, string text)
{
	gotoXY(x1 + ((length - 2) - text.length()) / 2 + 1, width / 2 + y1);
	cout << text;
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
void print_type_in_box(int x1, int y1, string text, int size)
{
	print_double_square(x1, y1, text.length() + 2, 3, 15, text);
	print_double_square(x1 + text.length() + 2, y1, size, 3, 15, "\0");
	gotoXY(x1 + 2 + text.length() + 2, y1 + 1);
}
void text(int x, int y, string text, bool led, int color)
{
	if (led) textColor(color);
	gotoXY(x, y);
	cout << text;
	if (led) textColor(15);
}
