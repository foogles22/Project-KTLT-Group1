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
