#include "all_structs.h"

// Các hàm tổng hợp ingiaodien
void ingiaodien_creating_year(Node_year* current_year, Node_year* ph_year, int choose, Node_teacher* teacher_login)
{
	check_time_for_semester(current_year);
	print_duongthang(25, 1, 62);
	print_duongngang(2, 5, 23);
	print_duongngang(26, 5, 208);
	check_time_for_semester(current_year);
	print_current_time(208, 60);
	if (current_year != NULL && current_year->ph_semester != NULL)
	{
		print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(current_year->semestercount));
		print_semester_start_end_time(current_year);
	}
	if (ph_year != NULL)
		print_fill_square(196, 60, 13, 3, 15, current_year->name);
	text(105, 3, "BEING LOGGED IN BY " + teacher_login->mail, 0, 15);
	print_Viennen(235, 63);
	print_year_section(choose);
}
void ingiaodien_after_creating_year(Node_year* year_choose, int choose, Node_teacher* teacher_login)
{
	check_time_for_semester(year_choose);
	print_duongthang(25, 1, 62);
	print_duongngang(2, 5, 23);
	print_duongngang(26, 5, 208);
	print_current_time(208, 60);
	print_Viennen(235, 63);
	check_time_for_semester(year_choose);
	if (year_choose != NULL && year_choose->ph_semester != NULL)
	{
		print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(year_choose->semestercount));
		print_semester_start_end_time(year_choose);
	}
	print_fill_square(196, 60, 13, 3, 15, year_choose->name);
	text(105, 3, "BEING LOGGED IN BY " + teacher_login->mail, 0, 15);
	print_after_year_section(choose, year_choose->name);
}
void ingiaodien_student(Node_year* current_year, Node_year* ph_year, Node_student* student_login, int choose)
{
	check_time_for_semester(current_year);
	print_duongthang(25, 1, 62);
	print_duongngang(2, 5, 23);
	print_duongngang(26, 5, 208);
	print_current_time(208, 60);
	if (current_year != NULL && current_year->ph_semester != NULL)
	{
		print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(current_year->semestercount));
		print_semester_start_end_time(current_year);
	}
	if (ph_year != NULL)
		print_fill_square(196, 60, 13, 3, 15, current_year->name);
	text(112, 3, "BEING LOGGED IN BY " + student_login->data.ID, 0, 15);
	print_Viennen(235, 63);
	print_student_section(choose);
}
void ingiaodien_setting(Node_year* current_year, Node_year* ph_year, int choose, Node_teacher* teacher_login)
{
	check_time_for_semester(current_year);
	print_duongthang(25, 1, 62);
	print_duongngang(2, 5, 23);
	print_duongngang(26, 5, 208);
	print_current_time(208, 60);
	if (current_year != NULL && current_year->ph_semester != NULL)
	{
		print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(current_year->semestercount));
		print_semester_start_end_time(current_year);
	}
	if (ph_year != NULL)
		print_fill_square(196, 60, 13, 3, 15, current_year->name);
	text(105, 3, "BEING LOGGED IN BY " + teacher_login->mail, 0, 15);
	print_Viennen(235, 63);
	print_teacher_setting_section(choose);
}
void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}