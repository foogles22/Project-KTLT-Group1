
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
	gotoXY(x1+2+text.length() + 2, y1 +1);
}
void text(int x, int y, string text, bool led, int color)
{
	if (led) textColor(color);
	gotoXY(x, y);
	cout << text;
	if (led) textColor(15);
}
