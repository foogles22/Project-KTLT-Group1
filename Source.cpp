#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <mmsystem.h>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;
time_t now;
bool update = 0;
// Các hàm làm giao diện
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

// Các struct node
struct Node_student;
struct COURSE_DATA
{
	//course id, course name, teacher name, number of credits, the maximum number of students in the course(default 50), day of the week, and the session that the course will be performed(MON / TUE / WED / THU / FRI / SAT, S1(07:30), S2(09:30), S3(13:30) and S4(15:30)).A course will be taught in 2 sessions in a week
	string id, course_name, teacher_name, session1, session2;
	int number_of_credits, max_num_student, days_of_week;
};
struct Node_course
{
	double final = 0;
	double midterm = 0;
	double total = 0;
	double other = 0;
	COURSE_DATA data;
	Node_course* course_next = nullptr;
	Node_student* ph_student_enrolled = nullptr;
};
struct Node_semester
{

	/*int start_date, end_date;
	int regis_start, regis_end;*/
	string semester_no;
	Node_course* ph_course = nullptr;
	Node_semester* semester_next = nullptr;
};
struct SINHVIEN
{
	string No, ID, first_name, lastname, gender, social_ID, password, date;
};
struct Node_student
{
	SINHVIEN data;
	Node_student* student_next = nullptr;
	Node_course* ph_course_enrolled1 = nullptr, * ph_course_enrolled2 = nullptr, * ph_course_enrolled3 = nullptr;
};
struct Node_class
{
	string name;
	Node_class* class_next = nullptr;
	Node_student* ph_student = nullptr;
};
struct Node_year
{
	int semestercount;
	bool end = 0;
	string name;
	Node_year* year_next;
	Node_class* ph_classes = nullptr;
	Node_semester* ph_semester = nullptr;
};
void updateScoreBoardOfACourse(Node_year* b);
void viewScoreBoardOfAClass(Node_class* a, Node_year* b);
void viewScoreBoardByStudent(Node_student* a, Node_year* b);
void viewScoreBoardOfACourse(Node_year* a);
void viewCourse_Student(Node_student* student_login, Node_year* current_year);
void export_studentIncourse_to_csv(Node_course* ph_course, Node_year* current_year);
// Các hàm thời gian
void print_current_time(int x, int y)
{
	time_t cur_time = time(0);
	char* dt = std::ctime(&cur_time);
	string time = dt;
	//meunu o trong 208, 60, o ngoai login la 140, 48
	print_fill_square(x, y, 27, 3, 15, time);
}
void check_time_for_semester(Node_year*& current_year)
{
	time_t cur_time = time(0);
	if (cur_time <= now + 600)
		current_year->semestercount = 1;
	else
		if (cur_time <= now + 1200)
			current_year->semestercount = 2;
		else
			if (cur_time <= now + 1800)
				current_year->semestercount = 3;
}
bool check_time_regis(Node_year*& current_year)
{
	time_t cur_time = time(0);
	if (current_year->semestercount == 1)
		if (cur_time <= now + 300)
		{
			time_t time = now + 300;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_double_square(160, 7, 74, 3, 15, "Registration session of semester 1 will end at " + time_end);
			return 1;
		}
		else { print_double_square(30, 10, 56, 3, 15, "Registration session of semester 1 has ran out of time"); return 0; }
	if (current_year->semestercount == 2)
		if (cur_time <= now + 900)
		{
			time_t time = now + 900;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_double_square(160, 7, 74, 3, 15, "Registration session of semester 2 will end at " + time_end);
			return 1;
		}
		else { print_double_square(30, 10, 56, 3, 15, "Registration session of semester 2 has ran out of time"); return 0; }
	if (current_year->semestercount == 3)
		if (cur_time <= now + 1500)
		{
			time_t time = now + 1500;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_double_square(160, 7, 74, 3, 15, "Registration session of semester 3 will end at " + time_end);
			return 1;
		}
		else { print_double_square(30, 10, 56, 3, 15, "Registration session of semester 3 has ran out of time"); return 0; }
}
bool check_year_end(Node_year*& current_year)
{
	time_t cur_time = time(0);
	if (cur_time <= now + 1800)
	{
		print_double_square(30, 10, 46, 3, 15, "The school year " + current_year->name + " has not ended yet!");
		_getch();
		return 0;
	}
	else return 1;
}
bool check_not_end_semester(Node_year*& current_year)
{
	check_time_for_semester(current_year);
	time_t cur_time = time(0);
	if (current_year->semestercount == 1)
		if (cur_time <= now + 300)
		{
			print_double_square(30, 10, 26, 3, 15, "Semester 1 has not ended");
			return 0;
		}
	if (current_year->semestercount == 2)
		if (cur_time <= now + 300)
		{
			print_double_square(30, 10, 26, 3, 15, "Semester 2 has not ended");
			return 0;
		}
	if (current_year->semestercount == 3)
		if (cur_time <= now + 300)
		{
			print_double_square(30, 10, 26, 3, 15, "Semester 3 has not ended");
			return 0;
		}
	return 1;
}
// Các hàm tìm node
Node_class* find_class_by_name(Node_class* ph_class, string class_name)
{
	Node_class* pc_class = ph_class;
	while (pc_class != NULL && pc_class->name != class_name)
		pc_class = pc_class->class_next;
	return pc_class;
}
Node_year* find_year(Node_year* ph_year, int year_no)
{
	if (ph_year == NULL)
		return NULL;
	Node_year* pc_year = ph_year;
	for (int i = 0; i < year_no - 1 && pc_year != NULL; i++, pc_year = pc_year->year_next);
	if (pc_year != NULL)
		return pc_year;
	else return NULL;
}
Node_class* find_class(Node_class* ph_class, int class_no)
{
	if (ph_class == NULL)
		return NULL;
	Node_class* pc_class = ph_class;
	for (int i = 0; i < class_no - 1 && pc_class != NULL; i++, pc_class = pc_class->class_next);
	if (pc_class != NULL)
		return pc_class;
	else return NULL;
}
Node_semester* find_semester(Node_semester* ph_semester, string semester_no_tmp)
{
	if (ph_semester == NULL)
		return NULL;
	semester_no_tmp = "Semester " + semester_no_tmp;
	Node_semester* pc_semester = ph_semester;
	while (pc_semester->semester_no != semester_no_tmp)
		pc_semester = pc_semester->semester_next;
	if (pc_semester != NULL)
		return pc_semester;
	else return NULL;
}
Node_course* find_course(Node_course* ph_course, int course_no)
{
	if (ph_course == NULL)
		return NULL;
	Node_course* pc_course = ph_course;
	for (int i = 0; i < course_no - 1 && pc_course != NULL; i++, pc_course = pc_course->course_next);
	if (pc_course != NULL)
		return pc_course;
	else return NULL;
}
Node_year* find_year_by_name(Node_year* ph_year, string year_name)
{
	if (ph_year == NULL)
		return NULL;
	Node_year* pc_year = ph_year;
	while (pc_year != NULL && pc_year->name != year_name)
		pc_year = pc_year->year_next;
	return pc_year;
}
Node_student* find_student_by_id(Node_student* ph_student, string id)
{
	Node_student* pc_student = ph_student;
	while (pc_student != NULL && pc_student->data.ID != id)
		pc_student = pc_student->student_next;
	return pc_student;
}
Node_student* find_node_student_for_login_account(long mssv, Node_year* ph_year)
{
	Node_student* student_choose = NULL;
	string year_name = "20" + to_string(mssv / 1000000) + "-" + "20" + to_string((mssv / 1000000) + 1);
	string chatluong[8] = { "NULL","NULL","NULL","NULL","NULL","APCS","VP","CLC" };
	string class_name = to_string(mssv / 1000000) + chatluong[(mssv / 1000) % 10];
	Node_year* year_choose = find_year_by_name(ph_year, year_name);
	if (year_choose == NULL)
		return NULL;
	else
	{
		Node_class* class_choose;
		int stt = 1;
		do
		{
			class_name = class_name + to_string(stt);
			class_choose = find_class_by_name(year_choose->ph_classes, class_name);
			if (class_choose != NULL)
				student_choose = find_student_by_id(class_choose->ph_student, to_string(mssv));
			else
				stt++;
			if (student_choose != NULL)
				break;
		} while (stt < 12);
		if (stt == 12)
			return NULL;
	}

	return student_choose;
}
// Các hàm xóa các node
void deallocate_student(Node_student*& ph_student)
{
	while (ph_student != NULL)
	{
		Node_student* pc_student = ph_student->student_next;
		delete ph_student;
		ph_student = pc_student;
	}
}
void deallocate_class(Node_class*& ph_class)
{
	while (ph_class != NULL)
	{
		deallocate_student(ph_class->ph_student);
		Node_class* pc_class = ph_class->class_next;
		delete ph_class;
		ph_class = pc_class;
	}
}
void deallocate_all_node(Node_year* ph_year)
{
	while (ph_year != NULL)
	{
		deallocate_class(ph_year->ph_classes);
		Node_year* pc_year = ph_year->year_next;
		delete ph_year;
		ph_year = pc_year;
	}
}
void delete_specific_class(Node_class*& ph_class, Node_class* pdel_class)
{
	deallocate_student(pdel_class->ph_student);
	if (ph_class == pdel_class)
	{
		ph_class = ph_class->class_next;
		delete pdel_class;
		return;
	}
	Node_class* pc_class = ph_class;
	while (pc_class->class_next != NULL && pc_class->class_next != pdel_class)
	{
		pc_class = pc_class->class_next;
	}
	pc_class->class_next = pc_class->class_next->class_next;
	delete pdel_class;
}
void delete_specific_student(Node_student*& ph_student, Node_student* pdel_student)
{
	if (ph_student == pdel_student)
	{
		ph_student = ph_student->student_next;
		delete pdel_student;
		return;
	}
	Node_student* pc_student = ph_student;
	while (pc_student->student_next != NULL && pc_student->student_next != pdel_student)
	{
		pc_student = pc_student->student_next;
	}
	pc_student->student_next = pc_student->student_next->student_next;
	delete pdel_student;
}
void delete_specific_course(Node_course*& ph_course, Node_course* pdel_course)
{
	if (ph_course == pdel_course)
	{
		ph_course = ph_course->course_next;
		delete pdel_course;
		return;
	}
	Node_course* pc_course = ph_course;
	while (pc_course->course_next != NULL && pc_course->course_next != pdel_course)
	{
		pc_course = pc_course->course_next;
	}
	pc_course->course_next = pc_course->course_next->course_next;
	delete pdel_course;
}
void deallocate_course(Node_course*& ph_course)
{
	while (ph_course != NULL)
	{
		Node_course* pc_course = ph_course->course_next;
		delete ph_course;
		ph_course = pc_course;
	}
}
void delete_specific_course(Node_course*& ph_course, Node_course* pdel_course);
void delete_specific_student(Node_student*& ph_student, Node_student* pdel_student);
void deleteEnrolledCourse(Node_student*& student, Node_year*& current_year) {
	if (student->ph_course_enrolled1 == NULL && student->ph_course_enrolled2 == NULL && student->ph_course_enrolled3 == NULL)
	{
		print_double_square(30, 10, 37, 3, 15, "You have not enrolled in any course");
		return;
	}
	Node_course** ph_course_enrolled = nullptr;
	check_time_for_semester(current_year);
	if (current_year->semestercount == 1)
		ph_course_enrolled = &(student->ph_course_enrolled1);
	if (current_year->semestercount == 2)
		ph_course_enrolled = &(student->ph_course_enrolled2);
	if (current_year->semestercount == 3)
		ph_course_enrolled = &(student->ph_course_enrolled3);

	viewCourse_Student(student, current_year);
	print_type_in_box(30, 10, "Choose a course to delete", 5);
	int x;
	cin >> x;
	Node_course* course_choose = find_course(*ph_course_enrolled, x);
	string name_tmp = course_choose->data.course_name;
	if (course_choose != NULL)
	{
		delete_specific_course(*ph_course_enrolled, course_choose);
		print_double_square(30, 15, 34, 3, 15, "Delete enrolled course succeeded");
		Node_semester* semester_choose = nullptr;
		Node_course* course_choose_del = nullptr;
		if (current_year->semestercount == 1)
			semester_choose = find_semester(current_year->ph_semester, "1");
		if (current_year->semestercount == 2)
			semester_choose = find_semester(current_year->ph_semester, "2");
		if (current_year->semestercount == 3)
			semester_choose = find_semester(current_year->ph_semester, "3");
		course_choose_del = semester_choose->ph_course;

		while (course_choose_del != NULL && course_choose_del->data.course_name != name_tmp)
			course_choose_del = course_choose_del->course_next;

		Node_student* pc_student_enrolled = course_choose_del->ph_student_enrolled;
		while (pc_student_enrolled->data.ID != student->data.ID)
			pc_student_enrolled = pc_student_enrolled->student_next;

		delete_specific_student(course_choose_del->ph_student_enrolled, pc_student_enrolled);

	}
}
// Các hàm in thông tin các node
void print_class(Node_class* ph_class)
{
	Node_class* pc_class = ph_class;
	int i = 1;
	gotoXY(118, 11);
	cout << "LIST OF CLASSES";
	while (pc_class != NULL)
	{
		gotoXY(121, 12 + i);
		cout << i++ << ":" << pc_class->name << endl;
		pc_class = pc_class->class_next;
	}
	print_double_square(116, 10, 19, i + 3, 15, "\0");
}
void print_year(Node_year* ph_year)
{
	Node_year* pc = ph_year;
	int i = 1;
	while (pc != NULL)
	{
		cout << i++ << ":" << pc->name << endl;
		pc = pc->year_next;
	}
}
void print_semester(Node_semester* ph_semester)
{
	Node_semester* pc = ph_semester;
	int i = 1;
	gotoXY(118, 11);
	cout << "LIST OF SEMESTERS";
	while (pc != NULL)
	{
		gotoXY(121, 12 + i);
		cout << i++ << ":" << pc->semester_no << endl;
		pc = pc->semester_next;
	}
	print_double_square(116, 10, 21, i + 3, 15, "\0");
}
void print_student(Node_student* ph_student)
{
	//in ra thông tin sinh viên vừa mới add vào
	Node_student* pc_student = ph_student;
	while (pc_student->student_next != NULL)
	{
		cout << pc_student->data.No << " " << pc_student->data.ID << " " << pc_student->data.first_name << " " << pc_student->data.lastname << " " << pc_student->data.gender << " " << pc_student->data.date << " " << pc_student->data.social_ID << " " << endl;
		pc_student = pc_student->student_next;
	}
}
void print_course(Node_course* ph_course)
{

	Node_course* pc = ph_course;
	int i = 1;
	gotoXY(119, 20);
	cout << "LIST OF COURSES";
	while (pc != NULL)
	{
		gotoXY(123, 21 + i);
		cout << i++ << ":" << pc->data.course_name << endl;
		pc = pc->course_next;
	}
	print_double_square(116, 19, 21, i + 3, 15, "\0");
}
void viewListofcourse(Node_course* ph_course)
{
	int i = 1;
	gotoXY(71, 19);
	cout << "Course ID  Course Name     Teacher Name     Number of Credits  The maximum number of students  Day of the week  The sessions";
	while (ph_course != NULL)
	{
		gotoXY(68, 19 + i);
		cout << i;
		gotoXY(71, 19 + i++);
		cout << ph_course->data.id;
		for (int i = 0; i < 14 - ph_course->data.id.length(); i++) cout << " ";
		cout << ph_course->data.course_name;
		for (int i = 0; i < 13 - ph_course->data.course_name.length(); i++) cout << " ";
		cout << ph_course->data.teacher_name;
		for (int i = 0; i < 25 - ph_course->data.teacher_name.length(); i++) cout << " ";
		cout << ph_course->data.number_of_credits;
		for (int i = 0; i < 23; i++) cout << " ";
		cout << ph_course->data.max_num_student;
		for (int i = 0; i < 23; i++) cout << " ";
		cout << ph_course->data.days_of_week;
		for (int i = 0; i < 9; i++) cout << " ";
		cout << ph_course->data.session1 << " ";
		cout << ph_course->data.session2;

		ph_course = ph_course->course_next;
	}
	print_double_square(69, 19, 128, i, 15, "\0");
	print_double_square(67, 19, 3, i, 15, "\0");

	return;
}
void viewCourse_Student(Node_student* student_login, Node_year* current_year)
{
	if (student_login->ph_course_enrolled1 == NULL && student_login->ph_course_enrolled2 == NULL && student_login->ph_course_enrolled3 == NULL)
	{
		print_double_square(30, 10, 30, 3, 15, "Haven't enrolled any course!");
		return;
	}
	check_time_for_semester(current_year);
	Node_course* ph_enrolled_course = nullptr;
	if (current_year->semestercount == 1)
		ph_enrolled_course = student_login->ph_course_enrolled1;
	if (current_year->semestercount == 2)
		ph_enrolled_course = student_login->ph_course_enrolled2;
	if (current_year->semestercount == 3)
		ph_enrolled_course = student_login->ph_course_enrolled3;

	viewListofcourse(ph_enrolled_course);

}
void viewAllClass(Node_year* year) {
	int i = 1;
	gotoXY(119, 10);
	cout << "LIST OF CLASSES";
	int count = 1;
	while (year) {
		Node_class* pc_class = year->ph_classes;
		int dem = 1;
		while (pc_class) {
			if (pc_class == year->ph_classes)
			{
				gotoXY(122, 11 + i++);
				cout << count++ << "/" << year->name;
			}
			gotoXY(122, 11 + i++);
			cout << dem++ << "." << pc_class->name << endl;
			pc_class = pc_class->class_next;
		}
		year = year->year_next;
	}
	print_double_square(117, 10, 19, i + 1, 15, "\0");
	return;
}
void viewAllStudentInAClass(Node_student* ph_student) {
	int i = 1;
	gotoXY(140, 10);
	cout << "No       ID             First Name       Last Name       Gender       Social ID";
	Node_student* pc_student = ph_student;
	while (pc_student) {
		gotoXY(140, 10 + i++);
		cout << pc_student->data.No << "        ";
		cout << pc_student->data.ID << "       ";
		cout << pc_student->data.first_name;
		for (int i = 0; i < 19 - pc_student->data.first_name.length(); i++)
			cout << " ";
		cout << pc_student->data.lastname;
		for (int i = 0; i < 15 - pc_student->data.lastname.length(); i++)
			cout << " ";
		cout << pc_student->data.gender << "  ";
		for (int i = 0; i < 9 - pc_student->data.gender.length(); i++)
			cout << " ";
		cout << pc_student->data.social_ID << "   ";

		pc_student = pc_student->student_next;
	}
	print_double_square(138, 10, 84, i - 1, 15, "\0");
	return;
}
void viewListofstudentsincourse(Node_student* ph_student)
{
	int i = 1;
	gotoXY(140, 10);
	cout << "No       ID             First Name       Last Name       Gender       Social ID";
	Node_student* pc_student = ph_student;
	while (pc_student) {
		gotoXY(140, 10 + i++);
		cout << pc_student->data.No << "        ";
		cout << pc_student->data.ID << "       ";
		cout << pc_student->data.first_name;
		for (int i = 0; i < 19 - pc_student->data.first_name.length(); i++)
			cout << " ";
		cout << pc_student->data.lastname;
		for (int i = 0; i < 15 - pc_student->data.lastname.length(); i++)
			cout << " ";
		cout << pc_student->data.gender << "  ";
		for (int i = 0; i < 9 - pc_student->data.gender.length(); i++)
			cout << " ";
		cout << pc_student->data.social_ID << "   ";

		pc_student = pc_student->student_next;
	}
	print_double_square(138, 10, 84, i + 1, 15, "\0");
	return;
}
//Enroll course
void add_enrolled_course(Node_course*& ph_course_enrolled, Node_course* enrolled_course)
{
	Node_course* tmp = new Node_course;
	tmp->data = enrolled_course->data;
	tmp->course_next = NULL;
	tmp->ph_student_enrolled = NULL;
	if (ph_course_enrolled == NULL)
	{
		ph_course_enrolled = tmp;
	}
	else
	{
		Node_course* pc_enrolled_course = ph_course_enrolled;
		while (pc_enrolled_course->course_next != NULL)
			pc_enrolled_course = pc_enrolled_course->course_next;
		pc_enrolled_course->course_next = tmp;
	}
}
void add_enrolled_student(Node_student*& ph_student_enrolled, Node_student* enrolled_student)
{
	Node_student* tmp = new Node_student;
	tmp->data = enrolled_student->data;
	tmp->student_next = NULL;
	tmp->ph_course_enrolled1 = NULL;
	tmp->ph_course_enrolled2 = NULL;
	tmp->ph_course_enrolled3 = NULL;
	if (ph_student_enrolled == NULL)
	{
		ph_student_enrolled = tmp;
	}
	else
	{
		Node_student* pc_enrolled_student = ph_student_enrolled;
		while (pc_enrolled_student->student_next != NULL)
			pc_enrolled_student = pc_enrolled_student->student_next;
		pc_enrolled_student->student_next = tmp;
	}
	Node_student* pc_enrolled_student = ph_student_enrolled;

}
bool check_course_sessions(Node_course* course_enrolled, Node_course* ph_course_enrolled)
{
	if (ph_course_enrolled == NULL)
		return true;
	Node_course* pc_course_enrolled = ph_course_enrolled;
	while (pc_course_enrolled != NULL)
	{
		if (pc_course_enrolled->data.session1 == course_enrolled->data.session1 || pc_course_enrolled->data.session1 == course_enrolled->data.session2 || pc_course_enrolled->data.session2 == course_enrolled->data.session1 || pc_course_enrolled->data.session2 == course_enrolled->data.session2)
			return false;
		pc_course_enrolled = pc_course_enrolled->course_next;
	}
	return true;
}
bool check_not_over_5_enrolled_course(Node_course* ph_enrolled_course)
{
	int dem = 0;
	while (ph_enrolled_course != NULL)
	{
		ph_enrolled_course = ph_enrolled_course->course_next;
		dem++;
	}
	if (dem < 5)
		return true;
	else return false;
}
bool check_not_over_max_student_in_a_course(Node_student* ph_student_enrolled, int max)
{
	int dem = 0;
	while (ph_student_enrolled != NULL)
	{
		++dem;
		ph_student_enrolled = ph_student_enrolled->student_next;
	}
	if (dem < max)
		return true;
	else return false;
}
void enroll_course(Node_student* student_login, Node_year*& current_year)
{
	int no_course;
	Node_semester* semester_choose = nullptr;
	Node_course** ph_course_enrolled = nullptr;
	check_time_for_semester(current_year);
	cout << current_year->semestercount;
	if (current_year->semestercount == 1)
	{
		ph_course_enrolled = &student_login->ph_course_enrolled1;
		semester_choose = find_semester(current_year->ph_semester, to_string(1));
	}
	if (current_year->semestercount == 2)
	{
		ph_course_enrolled = &student_login->ph_course_enrolled2;
		semester_choose = find_semester(current_year->ph_semester, to_string(2));
	}
	if (current_year->semestercount == 3)
	{
		ph_course_enrolled = &student_login->ph_course_enrolled3;
		semester_choose = find_semester(current_year->ph_semester, to_string(3));
	}
	if (check_time_regis(current_year))
		if (check_not_over_5_enrolled_course(*ph_course_enrolled))
		{
			print_double_square(120, 15, 12, 3, 15, "Semester " + to_string(current_year->semestercount));
			viewListofcourse(semester_choose->ph_course);
			print_type_in_box(30, 10, "Choose a course", 5);
			cin >> no_course;
			Node_course* course_choose = find_course(semester_choose->ph_course, no_course);
			if (check_not_over_max_student_in_a_course(course_choose->ph_student_enrolled, course_choose->data.max_num_student))
				if (check_course_sessions(course_choose, *ph_course_enrolled))// check xem có bị trùng giờ học không?
				{
					print_double_square(30, 15, 22, 3, 15, "Enrolling succeeded!");
					add_enrolled_course(*ph_course_enrolled, course_choose);
					add_enrolled_student(course_choose->ph_student_enrolled, student_login);
				}
				else print_double_square(30, 15, 79, 3, 15, "Your chosen course has conflicting sessions with your other enrolled courses!");
			else print_double_square(30, 15, 39, 3, 15, "Course reaches limitation of students");
		}
		else
		{
			print_double_square(30, 10, 42, 3, 15, "You can not enrolled more than 5 courses");
		}
}
//Add các Node cơ bản
bool check_year_duplicate(Node_year* ph_year, string year_name)
{
	if (ph_year == NULL) return 1;
	while (ph_year != NULL)
	{
		if (ph_year->name == year_name)
			return 0;
		ph_year = ph_year->year_next;
	}
	return 1;
}
bool check_class_duplicate(Node_class* ph_class, string class_name)
{
	if (ph_class == NULL) return 1;
	while (ph_class != NULL)
	{
		if (ph_class->name == class_name)
			return 0;
		ph_class = ph_class->class_next;
	}
	return 1;
}
bool check_course_duplicate(Node_course* ph_course, string course_name)
{
	if (ph_course == NULL) return 1;
	while (ph_course != NULL)
	{
		if (ph_course->data.course_name == course_name)
			return 0;
		ph_course = ph_course->course_next;
	}
	return 1;
}
void add_1st_student(Node_student*& ph_student, string class_name, string year_name)
{
	year_name = to_string(year_name[2] - 48) + to_string(year_name[3] - 48);
	ifstream read("StudentData\\" + year_name + "\\" + class_name + ".csv");
	Node_student* pc_student = ph_student;
	if (pc_student != NULL)
	{
		print_double_square(30, 15, 39, 3, 15, "Student have been added to this class");
		return;
	}
	while (!read.eof())
	{
		Node_student* tmp = new Node_student;
		getline(read, tmp->data.No, ',');
		getline(read, tmp->data.ID, ',');
		getline(read, tmp->data.first_name, ',');
		getline(read, tmp->data.lastname, ',');
		getline(read, tmp->data.gender, ',');
		getline(read, tmp->data.date, ',');
		getline(read, tmp->data.social_ID, ',');
		getline(read, tmp->data.password);
		tmp->student_next = NULL;
		tmp->ph_course_enrolled1 = NULL;
		tmp->ph_course_enrolled2 = NULL;
		tmp->ph_course_enrolled3 = NULL;
		if (pc_student == NULL)
		{
			ph_student = tmp;
			pc_student = tmp;
		}
		else
		{
			pc_student->student_next = tmp;
			pc_student = pc_student->student_next;
		}

	}
	read.close();
	viewAllStudentInAClass(ph_student);
}
void add_semester(Node_semester*& ph_semester)
{
	int no = 1;
	for (int i = 0; i < 3; i++)
	{
		string semester_no_tmp = "Semester " + to_string(no++);
		Node_semester* tmp = new Node_semester;
		tmp->semester_no = semester_no_tmp;
		tmp->ph_course = NULL;
		tmp->semester_next = NULL;
		/*tmp->start_date = now;
		tmp->regis_start = now;
		tmp->regis_end = now + 60;
		tmp->end_date = now + 120;
		now += 120;*/
		if (ph_semester == NULL)
		{
			ph_semester = tmp;
		}
		else
		{
			Node_semester* pc_semester = ph_semester;
			while (pc_semester->semester_next != NULL)
				pc_semester = pc_semester->semester_next;
			pc_semester->semester_next = tmp;
		}
	}

}
void add_course(Node_course*& ph_course, string semester_no, string year_name)
{
	if (ph_course == nullptr)
	{
		year_name = to_string(year_name[2] - 48) + to_string(year_name[3] - 48);
		fstream read("StudentData\\" + year_name + "\\" + semester_no + ".txt", ios::in);

		while (!read.eof())
		{
			COURSE_DATA DATA;
			read >> DATA.id; read.ignore();
			getline(read, DATA.course_name);
			getline(read, DATA.teacher_name);
			read >> DATA.number_of_credits;
			read >> DATA.max_num_student;
			read >> DATA.days_of_week;
			read >> DATA.session1;
			read >> DATA.session2;
			Node_course* tmp = new Node_course;
			tmp->data = DATA;
			tmp->course_next = NULL;
			tmp->ph_student_enrolled = NULL;
			Node_course* pc_course = ph_course;
			if (pc_course == NULL)
			{
				ph_course = tmp;
			}
			else
			{
				while (pc_course->course_next != NULL)
					pc_course = pc_course->course_next;
				pc_course->course_next = tmp;
			}
		}
		read.close();
		viewListofcourse(ph_course);
	}
	else
	{
		COURSE_DATA DATA;
		print_double_square(139, 10, 87, 14, 15, "\0");
		int y = 10;
		gotoXY(140, y++);
		cout << "Course ID: "; cin >> DATA.id; cin.ignore();
		gotoXY(140, y++);
		cout << "Course Name: "; getline(cin, DATA.course_name);
		gotoXY(140, y++);
		cout << "Teacher Name: "; getline(cin, DATA.teacher_name);
		gotoXY(140, y++);
		cout << "Number of Credits: "; cin >> DATA.number_of_credits;
		gotoXY(140, y++);
		cout << "The maximum number of students in the course(default 50): "; cin >> DATA.max_num_student;
		gotoXY(140, y++);
		cout << "Day of the week: "; cin >> DATA.days_of_week;
		gotoXY(140, y++);
		cout << "          MON / TUE / WED / THU / FRI / SAT\n";
		gotoXY(140, y++);
		cout << "S1(07:30)";
		gotoXY(140, y++);
		cout << "S2(09:30)";
		gotoXY(140, y++);
		cout << "S3(13:30)";
		gotoXY(140, y++);
		cout << "S4(15:30)";
		gotoXY(140, y++);
		cout << "The session that the course will be performed(Choose 2 session in a week)(Ex: MON_S2)";
		gotoXY(140, y++);
		cout << "Session 1: ";
		cin >> DATA.session1;

		do
		{
			gotoXY(140, y);
			cout << "Session 2: "; cin >> DATA.session2;
		} while (DATA.session1 == DATA.session2);
		if (check_course_duplicate(ph_course, DATA.course_name))
		{
			Node_course* tmp = new Node_course;
			tmp->data = DATA;
			tmp->course_next = NULL;
			tmp->ph_student_enrolled = NULL;
			Node_course* pc_course = ph_course;
			while (pc_course->course_next != NULL)
				pc_course = pc_course->course_next;
			pc_course->course_next = tmp;
		}
		else print_double_square(30, 15, 15, 3, 15, "Not accepted!");
	}
}
void add_class(Node_class*& ph_class, string class_name)
{
	Node_class* tmp = new Node_class;
	tmp->name = class_name;
	tmp->class_next = NULL;
	tmp->ph_student = NULL;
	if (ph_class == NULL)
	{
		ph_class = tmp;
	}
	else
	{
		Node_class* pc_class = ph_class;
		while (pc_class->class_next != NULL)
			pc_class = pc_class->class_next;
		pc_class->class_next = tmp;
	}
}
bool check_year_name_appropriate(string year_name)
{
	int former = year_name[0] + year_name[1] + year_name[2] + year_name[3];
	int later = year_name[5] + year_name[6] + year_name[7] + year_name[8];
	if (year_name.length() == 9 && (later - former) == 1 && year_name[4] == '-')
		return 1;
	else return 0;
}
void add_year(Node_year*& ph_year, string year_name, Node_year*& current_year)
{
	now = time(0);
	Node_year* tmp = new Node_year;
	tmp->name = year_name;
	tmp->ph_classes = NULL;
	tmp->ph_semester = NULL;
	tmp->year_next = NULL;
	current_year = tmp;
	if (ph_year == NULL)
	{
		ph_year = tmp;
	}
	else
	{
		Node_year* pc = ph_year;
		while (pc->year_next != NULL)
			pc = pc->year_next;
		pc->year_next = tmp;
	}
}
//Menu
void print_student_section(int choose)
{
	text(4, 3, " ENROLLING SECTION ", 1, 11);
	//x,y,length,width,led,color (square)
	//x,y,text,led,color (text)
	int x = 3, y = 10;
	if (choose == 1)
		print_double_square(x, y, 22, 3, 12, "ENROLL COURSE");
	else
		print_double_square(x, y, 22, 3, 15, "ENROLL COURSE");
	y += 5;
	if (choose == 2)
		print_double_square(x, y, 22, 3, 12, "VIEW ENROLLED COURSE");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW ENROLLED COURSE");
	y += 5;
	if (choose == 3)
		print_double_square(x, y, 22, 3, 12, "DELETE ENROLL COURSE");
	else
		print_double_square(x, y, 22, 3, 15, "DELETE ENROLL COURSE");
	y += 5;
	if (choose == 4)
		print_double_square(x, y, 22, 3, 12, "VIEW SCOREBOARD");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW SCOREBOARD");
	y += 5;
	if (choose == 5)
		print_double_square(x, y, 22, 3, 12, "Exit!");
	else
		print_double_square(x, y, 22, 3, 15, "Exit!");

}
void print_year_section(int choose)
{
	text(4, 3, "SCHOOL YEAR SECTION", 1, 11);
	//x,y,length,width,led,color (square)
	//x,y,text,led,color (text)
	int x = 3, y = 10;
	if (choose == 1)
		print_double_square(x, y, 22, 3, 12, "CREATE SCHOOL YEAR");
	else
		print_double_square(x, y, 22, 3, 15, "CREATE SCHOOL YEAR");
	y += 5;
	if (choose == 2)
		print_double_square(x, y, 22, 3, 12, "CONTINUE");
	else
		print_double_square(x, y, 22, 3, 15, "CONTINUE");
	y += 5;
	if (choose == 3)
		print_double_square(x, y, 22, 3, 12, "VIEW CLASSES");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW CLASSES");
	y += 5;
	if (choose == 4)
		print_double_square(x, y, 22, 3, 12, "VIEW STUDENTS");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW STUDENTS");
	y += 5;
	if (choose == 5)
		print_double_square(x, y, 22, 3, 12, "VIEW COURSES");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW COURSES");
	y += 5;
	if (choose == 6)
		print_double_square(x, y, 22, 3, 12, "EXPORT COURSES INFO");
	else
		print_double_square(x, y, 22, 3, 15, "EXPORT COURSES INFO");
	y += 5;
	if (choose == 7)
		print_double_square(x, y, 22, 3, 12, "UPDATE SCOREBOARD");
	else
		print_double_square(x, y, 22, 3, 15, "UPDATE SCOREBOARD");
	y += 5;
	if (choose == 8)
		print_double_square(x, y, 22, 3, 12, "VIEW SCOREBOARD");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW SCOREBOARD");
	y += 5;
	if (choose == 9)
		print_double_square(x, y, 22, 3, 12, "Exit!");
	else
		print_double_square(x, y, 22, 3, 15, "Exit!");

}
void print_after_year_section(int choose, string year_name)
{
	text(9, 3, year_name, 1, 11);
	//x,y,length,width,led,color (square)
	//x,y,text,led,color (text)
	int x = 3, y = 10;
	if (choose == 1)
		print_double_square(x, y, 22, 3, 12, "CREATE CLASS");
	else
		print_double_square(x, y, 22, 3, 15, "CREATE CLASS");
	y += 5;
	if (choose == 2)
		print_double_square(x, y, 22, 3, 12, "DELETE CLASS");
	else
		print_double_square(x, y, 22, 3, 15, "DELETE CLASS");
	y += 5;
	if (choose == 3)
		print_double_square(x, y, 22, 3, 12, "ADD STUDENT");
	else
		print_double_square(x, y, 22, 3, 15, "ADD STUDENT");
	y += 5;
	if (choose == 4)
		print_double_square(x, y, 22, 3, 12, "ADD SEMESTERS");
	else
		print_double_square(x, y, 22, 3, 15, "ADD SEMESTERS");
	y += 5;
	if (choose == 5)
		print_double_square(x, y, 22, 3, 12, "ADD COURSE");
	else
		print_double_square(x, y, 22, 3, 15, "ADD COURSE");
	y += 5;
	if (choose == 6)
		print_double_square(x, y, 22, 3, 12, "DELETE COURSE");
	else
		print_double_square(x, y, 22, 3, 15, "DELETE COURSE");
	y += 5;
	if (choose == 7)
		print_double_square(x, y, 22, 3, 12, "Exit!");
	else
		print_double_square(x, y, 22, 3, 15, "Exit!");
}
void print_teacher_after_creating_year_menu(Node_year*& year_choose)
{
	int choose = 1;	char move;
	do {
		system("CLS");
		print_after_year_section(choose, "2020-2021");
		do {
			check_time_for_semester(year_choose);
			print_duongthang(25, 1, 62);
			print_duongngang(2, 5, 23);
			print_duongngang(26, 5, 208);
			print_current_time(208, 60);
			print_Viennen(235, 63);
			if (year_choose != NULL && year_choose->ph_semester != NULL)
				print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(year_choose->semestercount));
			print_fill_square(196, 60, 13, 3, 15, year_choose->name);;
			text(112, 3, "BEING LOGGED IN BY TEACHER", 0, 15);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 7)
					choose++;
			print_after_year_section(choose, "2020-2021");
		} while (move != 13);

		if (choose == 1)
		{
			string class_name;
			print_type_in_box(30, 10, "Type class name", 11);
			cin >> class_name;
			if (check_class_duplicate(year_choose->ph_classes, class_name))
			{
				add_class(year_choose->ph_classes, class_name);
				print_double_square(30, 15, 25, 3, 15, "Create class succeeded");
			}
			else print_double_square(30, 15, 15, 3, 15, "Not accepted!");
			_getch();
		}
		//Delete class
		if (choose == 2)
		{
			if (year_choose->ph_classes != NULL)
			{
				print_class(year_choose->ph_classes);
				int class_no;
				Node_class* class_choose;
				print_type_in_box(30, 10, "Type class number", 5);
				cin >> class_no;
				class_choose = find_class(year_choose->ph_classes, class_no);
				if (class_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Class not exists or not found!");
				if (class_choose != nullptr)
				{
					delete_specific_class(year_choose->ph_classes, class_choose);
					print_double_square(30, 15, 32, 3, 15, "Delete class succeeded!");
				}
			}
			else print_double_square(30, 10, 33, 3, 15, "There is no any class to delete");
			_getch();
		}
		//Add Students
		if (choose == 3)
		{
			if (year_choose->ph_classes != NULL)
			{
				print_class(year_choose->ph_classes);
				int class_no;
				Node_class* class_choose;

				print_type_in_box(30, 10, "Choose class to add students", 5);
				cin >> class_no;
				class_choose = find_class(year_choose->ph_classes, class_no);
				if (class_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Class not exists or not found!");
				if (class_choose != NULL)
					add_1st_student(class_choose->ph_student, class_choose->name, year_choose->name);

			}
			else print_double_square(30, 10, 31, 3, 15, "There is no any class to add");
			_getch();
		}
		//Add semester
		if (choose == 4)
		{
			if (year_choose->ph_semester == NULL)
			{
				print_double_square(30, 10, 28, 3, 15, "Create semesters succeeded");
				add_semester(year_choose->ph_semester);
			}
			else print_double_square(30, 10, 29, 3, 15, "Semesters have been created");
			_getch();
		}
		//Add course
		if (choose == 5)
		{
			if (year_choose->ph_semester != nullptr)
			{
				print_semester(year_choose->ph_semester);
				Node_semester* semester_choose;
				string no;

				print_type_in_box(30, 10, "Choose semester number", 5);
				cin >> no;
				semester_choose = find_semester(year_choose->ph_semester, no);
				if (semester_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Semester not exists or not found!");
				if (semester_choose != NULL)
				{
					add_course(semester_choose->ph_course, semester_choose->semester_no, year_choose->name);
					print_double_square(30, 15, 26, 3, 15, "Create courses succeeded");
				}
			}
			else print_double_square(30, 10, 30, 3, 15, "No semester has been created");
			_getch();
		}
		//Delete course
		if (choose == 6)
		{
			if (year_choose->ph_semester != nullptr)
			{
				print_semester(year_choose->ph_semester);
				Node_semester* semester_choose;
				string semester_no;

				print_type_in_box(30, 10, "Choose semester number", 5);
				cin >> semester_no;
				semester_choose = find_semester(year_choose->ph_semester, semester_no);
				if (semester_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Semester not exists or not found!");
				if (semester_choose != NULL)
					if (semester_choose->ph_course != NULL)
					{
						print_course(semester_choose->ph_course);
						int course_no;
						Node_course* course_choose;

						print_type_in_box(30, 15, "Choose course to delete", 5);
						cin >> course_no;
						course_choose = find_course(semester_choose->ph_course, course_no);
						if (course_choose == NULL)
							print_double_square(30, 20, 33, 3, 15, "Course not exists or not found!");
						if (course_choose != NULL)
						{
							delete_specific_course(semester_choose->ph_course, course_choose);
							print_double_square(30, 20, 25, 3, 15, "Delete course succeeded");
						}
					}
					else print_double_square(30, 15, 35, 3, 15, "There is no any course to delete!");
			}
			else print_double_square(30, 10, 30, 3, 15, "No semester has been created");
			_getch();
		}

	} while (choose != 7);
}
void print_teacher_creating_year_menu(Node_year*& ph_year, Node_year*& current_year)
{
	string year_name;
	int choose = 1;	char move;
	
	do {
		system("CLS");
		print_year_section(choose);
		do {
			print_duongthang(25, 1, 62);
			print_duongngang(2, 5, 23);
			print_duongngang(26, 5, 208);
			print_current_time(208, 60);
			if (current_year != NULL && current_year->ph_semester != NULL)
				print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(current_year->semestercount));
			if (ph_year != NULL)
				print_fill_square(196, 60, 13, 3, 15, current_year->name);
			text(112, 3, "BEING LOGGED IN BY TEACHER", 0, 15);
			print_Viennen(235, 63);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 9)
					choose++;
			print_year_section(choose);
		} while (move != 13);
		//Create year
		if (choose == 1)
		{
			if (ph_year == NULL || check_year_end(current_year))
			{
				print_double_square(30, 10, 33, 3, 15, "Type year name(Ex: 2021-2022)");
				print_double_square(63, 10, 13, 3, 15, "\0");
				gotoXY(65, 11);
				cin >> year_name;
				if (check_year_name_appropriate(year_name) && check_year_duplicate(ph_year, year_name))
				{
					print_double_square(30, 15, 13, 3, 15, "Accepted!");
					string text = "Have been created: " + year_name;
					print_double_square(43, 15, 33, 3, 15, text);
					add_year(ph_year, year_name, current_year);
				}
				else print_double_square(30, 15, 15, 3, 15, "Not Accepted!");
			}
			_getch();
		}
		//Continue
		if (choose == 2 && ph_year != NULL)
		{
			print_teacher_after_creating_year_menu(current_year);
			continue;
		}
		//View class
		if (choose == 3 && ph_year != NULL)
		{
			if (ph_year->ph_classes != NULL)
				viewAllClass(ph_year);
			else print_double_square(30, 10, 31, 3, 15, "There is no any class to view");
			_getch();
		}
		//View student
		if (choose == 4 && ph_year != NULL)
		{
			int choose;
			print_double_square(30, 10, 28, 3, 15, "1.View students in a class");
			print_double_square(30, 15, 29, 3, 15, "2.View students in a course");
			print_type_in_box(30, 20, "Your option", 5);
			cin >> choose;
			if (choose == 1)
			{
				if (ph_year->ph_classes != NULL)
				{
					int class_no;
					int year_no;
					viewAllClass(ph_year);
					print_type_in_box(30, 25, "Choose a school year", 5);
					cin >> year_no;
					Node_year* year_choose = find_year(ph_year, year_no);
					print_type_in_box(30, 30, "Choose a class", 5);
					cin >> class_no;
					Node_class* class_choose = find_class(year_choose->ph_classes, class_no);
					if (class_choose == NULL)
						print_double_square(30, 35, 32, 3, 15, "Class not exists or not found!");
					if (class_choose != NULL)
						viewAllStudentInAClass(class_choose->ph_student);
				}
				else print_double_square(30, 25, 31, 3, 15, "There is no any class to view");
			}
			else // choose == 2
			{
				if (current_year->ph_semester != NULL)
				{
					check_time_for_semester(current_year);

					Node_semester* semester_choose = nullptr;
					int no;
					if (current_year->semestercount == 1)
					{
						semester_choose = find_semester(current_year->ph_semester, "1");
						print_course(semester_choose->ph_course);

					}
					if (current_year->semestercount == 2)
					{
						semester_choose = find_semester(current_year->ph_semester, "2");
						print_course(semester_choose->ph_course);

					}
					if (current_year->semestercount == 3)
					{
						semester_choose = find_semester(current_year->ph_semester, "3");
						print_course(semester_choose->ph_course);
					}
					print_type_in_box(30, 25, "Choose a course", 5);
					cin >> no;
					Node_course* course_choose = find_course(semester_choose->ph_course, no);
					if (course_choose->ph_student_enrolled != NULL)
						viewListofstudentsincourse(course_choose->ph_student_enrolled);
					else
					{
						print_double_square(30, 30, 45, 3, 15, "Course has not been enrolled by any student");
					}
				}
				else print_double_square(30, 30, 33, 3, 15, "Semesters have not been created");

			}
			_getch();
		}
		//View course
		if (choose == 5 && ph_year != NULL)
		{
			if (current_year->ph_semester != NULL)
			{
				check_time_for_semester(current_year);
				Node_semester* semester_choose;
				if (current_year->semestercount == 1)
				{
					semester_choose = find_semester(current_year->ph_semester, "1");
				}
				else if (current_year->semestercount == 2)
				{
					semester_choose = find_semester(current_year->ph_semester, "2");

				}
				else {
					semester_choose = find_semester(current_year->ph_semester, "3");

				}
				viewListofcourse(semester_choose->ph_course);

			}
			else print_double_square(120, 10, 31, 3, 15, "There is no any course to view");
			_getch();
		}
		//Export
		if (choose == 6)
		{
			if (check_not_end_semester(current_year))
			{
				Node_semester* semester_choose = nullptr;
				if (current_year->semestercount == 1)
					semester_choose = find_semester(current_year->ph_semester, "1");
				if (current_year->semestercount == 2)
					semester_choose = find_semester(current_year->ph_semester, "2");
				if (current_year->semestercount == 3)
					semester_choose = find_semester(current_year->ph_semester, "3");
				export_studentIncourse_to_csv(semester_choose->ph_course, current_year);
				print_double_square(30, 10, 19, 3, 15, "Export succeeded!");
			}
			_getch();
		}
		//Update scoreboard
		if (choose == 7)
		{
			if (check_not_end_semester(current_year))
			{
				updateScoreBoardOfACourse(current_year);
				update = 1;
			}
			_getch();
		}
		if (choose == 8)
		{
			if (check_not_end_semester(current_year))
			{
				if (update)
				{
					print_double_square(30, 10, 31, 3, 15, "1.View scoreboard of a course");
					print_double_square(61, 10, 30, 3, 15, "2.View scoreboard of a class");
					print_type_in_box(30, 15, "Your option", 5);
					int choose;  cin >> choose;
					if (choose == 1)
						viewScoreBoardOfACourse(current_year);
					else
					{
						if (ph_year->ph_classes != NULL)
						{
							int class_no;
							int year_no;
							viewAllClass(ph_year);
							print_type_in_box(30, 20, "Choose a school year", 5);
							cin >> year_no;
							Node_year* year_choose = find_year(ph_year, year_no);
							print_type_in_box(30, 25, "Choose a class", 5);
							cin >> class_no;
							Node_class* class_choose = find_class(year_choose->ph_classes, class_no);
							if (class_choose == NULL)
								print_double_square(30, 30, 32, 3, 15, "Class not exists or not found!");
							if (class_choose != NULL)
								viewScoreBoardOfAClass(class_choose, current_year);
						}
						else print_double_square(30, 20, 31, 3, 15, "There is no any class to view");
					}
				}
				else
					print_double_square(30, 10, 36, 3, 15, "Scoreboards have not been updated!");
			}
			_getch();
		}

	} while (choose != 9);
}
void print_menu_for_student(long a, Node_year*& ph_year, Node_year*& current_year)
{
	system("CLS");
	Node_student* student_login = find_node_student_for_login_account(a, ph_year);
	if (student_login == NULL)
	{
		print_student_section(0);
		print_duongthang(25, 1, 62);
		print_duongngang(2, 5, 23);
		print_duongngang(26, 5, 208);
		if (current_year != NULL && current_year->ph_semester != NULL)
			print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(current_year->semestercount));
		if (ph_year != NULL)
			print_fill_square(196, 60, 13, 3, 15, current_year->name);
		print_Viennen(235, 63);
		print_double_square(30, 10, 25, 3, 15, "Can not find your data!");
		print_double_square(30, 15, 31, 3, 15, "Please contact for supporting");
		_getch();
		return;
	}
	else
	{
		print_double_square(30, 10, 33, 3, 15, "Loading your profile completed!");
		print_student_section(0);
		print_duongthang(25, 1, 62);
		print_duongngang(2, 5, 23);
		print_duongngang(26, 5, 208);
		print_current_time(208, 60);
		if (current_year != NULL && current_year->ph_semester != NULL)
			print_fill_square(183, 60, 14, 3, 15, "Semester " + to_string(current_year->semestercount));
		if (ph_year != NULL)
			print_fill_square(196, 60, 13, 3, 15, current_year->name);
		text(112, 3, "BEING LOGGED IN BY " + student_login->data.ID, 0, 15);
		print_Viennen(235, 63);
		_getch();
		int choose = 1;	char move;
		do {
			system("CLS");
			print_student_section(choose);
			do {
				print_duongthang(25, 1, 62);
				print_duongngang(2, 5, 23);
				print_duongngang(26, 5, 208);
				print_current_time(208, 60);
				if (ph_year != NULL)
				{
					string textx = "RECENTLY CREATED " + current_year->name;
					text(203, 3, textx, 1, 12);
				}
				text(112, 3, "BEING LOGGED IN BY " + student_login->data.ID, 0, 15);
				print_Viennen(235, 63);
				move = _getch();
				if (move == 'w' || move == 72)
					if (choose > 1)
						choose--;
				if (move == 's' || move == 80)
					if (choose < 5)
						choose++;
				print_student_section(choose);
			} while (move != 13);

			if (choose == 1)
			{
				enroll_course(student_login, current_year);
				_getch();
			}
			if (choose == 2) {
				viewCourse_Student(student_login, current_year);
				_getch();
			}
			if (choose == 3)
			{
				deleteEnrolledCourse(student_login, current_year);
				_getch();
			}
			if (choose == 4)
			{
				viewScoreBoardByStudent(student_login, current_year);
				_getch();
			}
		} while (choose != 5);
	}
}
//Login
void print_username_password(int choose)
{
	//x,y,length,width,led,color (square)
	//x,y,text,led,color (text)
	if (choose == 1)
		print_double_square(66, 26, 40, 3, 12, "\0");
	else
		print_double_square(66, 26, 40, 3, 15, "\0");
	text(67, 27, "USERNAME: ", 1, 15);

	if (choose == 2)
		print_double_square(66, 31, 40, 3, 12, "\0");
	else
		print_double_square(66, 31, 40, 3, 15, "\0");
	text(67, 32, "PASSWORD: ", 1, 15);
	if (choose == 3)
		print_double_square(78, 36, 17, 1, 12, "Login");
	else
		print_double_square(78, 36, 17, 1, 15, "Login");

	if (choose == 4)
		print_double_square(78, 39, 17, 1, 12, "Exit!");
	else
		print_double_square(78, 39, 17, 1, 15, "Exit!");
}
bool login(long a, string s) {
	fstream fs;
	string b = to_string(a);
	int cnt = 1;
	bool acp = false;
	bool end = true;
	string* chatLuong = new string[8];
	for (int i = 0; i <= 4; i++) {
		chatLuong[i] = "NULL";
	}
	chatLuong[5] = "APCS";
	chatLuong[6] = "VP";
	chatLuong[7] = "CLC";
	while (end) {
		fs.open("StudentData\\" + to_string(a / 1000000) + "\\" + to_string(a / 1000000) + chatLuong[(a / 1000) % 10] + to_string(cnt) + ".csv", ios::in);
		if (!fs.is_open()) end = false;
		else while (!fs.eof()) {
			fs.ignore();
			fs.ignore();
			string check;
			getline(fs, check, ',');
			if (check == b) {
				string pass;
				int dem = 5;
				while (dem--) {
					getline(fs, pass, ',');
				}
				getline(fs, pass);
				if (pass == s) {
					end = false;
					acp = true;
				}
			}
			else {
				getline(fs, check);
			}
			if (acp) break;
		}
		fs.close();
		cnt++;
	}
	delete[] chatLuong;
	if (acp)
		return 1;
	else
		return 0;
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
		cout << "                __/ |                                                ";
		gotoXY(x1, ++y1);
		cout << "               |___/                                                 ";
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
void print_login_section(Node_year*& ph_year, Node_year*& current_year)
{
	long mssv = -1; string password = "\0";
	int choose = 1;	char move;
	bool one = true, two = true;
	do {
		print_username_password(choose);
		print_current_time(140, 48);

		do {
			// 235, 63
			print_Viennen(167, 51);
			// 68, 4
			print_Login_logo(35, 2);
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

			if (mssv != -1 && password != "\0" && login(mssv, password))
			{
				print_login_status(47, 15, 1);
				_getch();
				print_menu_for_student(mssv, ph_year, current_year);
				system("CLS"); choose = 1;
			}
			else
				if (mssv == 1111)
				{
					print_teacher_creating_year_menu(ph_year, current_year);
					system("CLS"); choose = 1;
				}
				else
				{
					print_login_status(46, 15, 0);
					_getch();
					system("CLS");
				}
			one = true; two = true;
		}
	} while (choose != 4);
}
//
void export_studentIncourse_to_csv(Node_course* ph_course, Node_year* current_year)
{
	if (ph_course == NULL) return;
	int count = 1;
	Node_course* pc_course = ph_course;
	fstream write("CoursesData\\Semester " + to_string(current_year->semestercount) + "\\Courses.txt", ios::out);
	while (pc_course != NULL)
	{
		string course_name = pc_course->data.course_name;
		if (pc_course->ph_student_enrolled != NULL)
		{
			write << course_name;
			//check xem có cần xuống dòng không
			Node_course* temp = pc_course->course_next;
			while (temp != NULL)
			{
				if (temp->ph_student_enrolled != NULL)
				{
					write << endl; break;
				}
				temp = temp->course_next;
			}
			ofstream write1("CoursesData\\Semester " + to_string(current_year->semestercount) + "\\" + course_name + ".csv", ios::out);
			Node_student* pc_student = pc_course->ph_student_enrolled;
			while (pc_student != NULL)
			{
				write1 << count++ << "," << pc_student->data.ID << "," << pc_student->data.first_name << "," << pc_student->data.lastname;
				if (pc_student->student_next != NULL)
					write1 << endl;
				pc_student = pc_student->student_next;
			}
			write1.close();
		}
		pc_course = pc_course->course_next;
	}

	write.close();
}
void updateStudentResult(Node_student*& a, Node_year* b, string s, double x, double y, double z, double t) {
	//use while loop to get each  student ID then use the find_student by id to make changes
	check_time_for_semester(b);
	if (b->semestercount == 1) {
		Node_course* cur = a->ph_course_enrolled1;
		while (cur->data.course_name != s) {
			cur = cur->course_next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}
	if (b->semestercount == 2) {
		Node_course* cur = a->ph_course_enrolled2;
		while (cur->data.course_name != s) {
			cur = cur->course_next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}
	if (b->semestercount == 3) {
		Node_course* cur = a->ph_course_enrolled3;
		while (cur->data.course_name != s) {
			cur = cur->course_next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}
}
void viewScoreBoardOfACourse(Node_year* a) {
	check_time_for_semester(a);
	fstream fs;
	fs.open("CoursesData\\Semester " + to_string(a->semestercount) + "\\Courses.txt");
	int i = 1;
	gotoXY(119, 11);
	cout << "LIST OF COURSES";
	while (!fs.eof()) {
		gotoXY(123, 12 + i);
		string s;
		fs >> s;
		cout << i++ << ":" << s << endl;
	}
	print_double_square(116, 10, 21, i + 3, 15, "\0");
	print_type_in_box(30, 20, "Choose a course", 5);
	int no; cin >> no;
	fstream fs2;
	fs2.open("CoursesData\\Semester " + to_string(a->semestercount) + "\\Courses.txt");
	string s;
	while (no-- != 0)
		fs2 >> s;

	int i1 = 1;
	int i2 = i;
	fstream fs1;
	fs1.open("CoursesData\\Semester " + to_string(a->semestercount) + "\\" + s + ".csv");
	gotoXY(74, 15 + i);
	cout << "No     Student ID          FullName          Total Mark         Final Mark      Midterm Mark      Other Mark";
	while (!fs1.eof()) {
		string no, id, first_name, last_name, a, b, c, d;
		getline(fs1, no, ',');
		getline(fs1, id, ',');
		getline(fs1, first_name, ',');
		getline(fs1, last_name, ',');
		getline(fs1, a, ',');
		getline(fs1, b, ',');
		getline(fs1, c, ',');
		getline(fs1, d);
		gotoXY(74, 16 + i++);
		i1++;
		cout << no << "       ";
		cout << id << "       ";
		cout << first_name << " ";
		cout << last_name;
		for (int i = 0; i < 25 - (first_name.length() + last_name.length()); i++) cout << " ";
		cout << a; for (int i = 0; i < 19 - a.length(); i++) cout << " ";
		cout << b; for (int i = 0; i < 17 - b.length(); i++) cout << " ";
		cout << c; for (int i = 0; i < 17 - c.length(); i++) cout << " ";
		cout << d;
	}
	print_double_square(72, 15 + i2, 112, i1-1, 15, "\0");
	fs1.close();
	fs.close();
} //view scoreboard
void viewScoreBoardByStudent(Node_student* a, Node_year* b) {
	// use find_node_student_for_login_account function to Node student a
	Node_course* view = nullptr;
	check_time_for_semester(b);
	if (b->semestercount == 1)
		view = a->ph_course_enrolled1;
	if (b->semestercount == 2)
		view = a->ph_course_enrolled2;
	if (b->semestercount == 3)
		view = a->ph_course_enrolled3;

	print_course(view);
	print_type_in_box(30, 10, "Choose a course", 5);
	int no; cin >> no;
	view = find_course(view, no);

	gotoXY(80, 32);
	cout << "Student ID          Fullname          Total Mark       Final Mark       Midterm Mark       Other Mark";
	gotoXY(81, 33);
	cout << a->data.ID;
	for (int i = 0; i < 6; i++) cout << " ";
	cout << a->data.first_name << " ";
	cout << a->data.lastname;
	for (int i = 0; i < 27 - (a->data.first_name.length() + a->data.lastname.length()); i++) cout << " ";
	cout << view->total << "               ";
	cout << view->final << "                 ";
	cout << view->midterm << "                  ";
	cout << view->other;
	print_double_square(79, 32, 103, 2, 15, "\0");

}
void viewScoreBoardOfAClass(Node_class* a, Node_year* b) {
	Node_student* curStudent = a->ph_student;
	Node_course* curEnrolled = nullptr;
	double totalGPA = 0;
	int countStudent = 0;
	check_time_for_semester(b);
	int i = 1;
	gotoXY(80, 32);
	cout << "Student ID          Fullname          Course Name         Final Mark      GPA      Total GPA of class";

	while (curStudent) {
		countStudent += 1;
		if (b->semestercount == 1)
			curEnrolled = curStudent->ph_course_enrolled1;
		if (b->semestercount == 2)
			curEnrolled = curStudent->ph_course_enrolled2;
		if (b->semestercount == 3)
			curEnrolled = curStudent->ph_course_enrolled3;

		double gpacourse = 0;
		int cnt = 0;
		while (curEnrolled) {
			gotoXY(81, 32 + i++);
			cout << curStudent->data.ID;
			for (int i = 0; i < 6; i++) cout << " ";
			cout << curStudent->data.first_name << " ";
			cout << curStudent->data.lastname;
			cnt += 1;
			gpacourse += curEnrolled->final;
			for (int i = 0; i < 26 - (curStudent->data.first_name.length() + curStudent->data.lastname.length()); i++) cout << " ";
			cout << curEnrolled->data.course_name << "                 ";
			cout << curEnrolled->final << "           ";
			curEnrolled = curEnrolled->course_next;
		}

		cout << (double)gpacourse / cnt;
		totalGPA += (double)gpacourse / cnt;

		curStudent = curStudent->student_next;
	}
	gotoXY(172, 32 + i);
	cout << (double)totalGPA / countStudent;
	print_double_square(79, 32, 103, i + 1, 15, "\0");

}
void updateScoreBoardOfACourse(Node_year* b) {
	check_time_for_semester(b);
	fstream fs;
	fs.open("CoursesData\\Semester " + to_string(b->semestercount) + "\\Courses.txt");
	while (!fs.eof()) {
		string s;
		fs >> s;
		fstream fs1;
		fs1.open("CoursesData\\Semester " + to_string(b->semestercount) + "\\" + s + ".csv");
		if (fs1.is_open()) {
			while (!fs1.eof()) {
				long mssv;
				double x, y, z, t;
				string ign1, ign2;
				fs1.ignore();
				fs1.ignore();
				fs1 >> mssv;
				Node_student* curStudent = find_node_student_for_login_account(mssv, b);
				if (curStudent == nullptr) break;
				fs1.ignore();
				getline(fs1, ign1, ',');
				getline(fs1, ign2, ',');
				fs1 >> x;
				fs1.ignore();
				fs1 >> y;
				fs1.ignore();
				fs1 >> z;
				fs1.ignore();
				fs1 >> t;
				fs1.ignore();
				updateStudentResult(curStudent, b, s, x, y, z, t);
			}
		}
		fs1.close();
	}
	fs.close();
	print_double_square(30, 10, 30, 3, 15, "Update scoreboard completed!");
}
int main()
{
	Node_year* ph_year = NULL;
	Node_year* current_year = NULL;
	print_login_section(ph_year, current_year);
	deallocate_all_node(ph_year);
	return 0;
}
