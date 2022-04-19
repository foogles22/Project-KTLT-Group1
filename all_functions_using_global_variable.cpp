#include "all_structs.h"

time_t now;
bool update = 0;

//Add các Node cơ bản
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
	if (!read.is_open()) {
		print_double_square(30, 15, 19, 3, 15, "File can not open");
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
void add_course(Node_course*& ph_course, string semester_no, string year_name, bool view)
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
		if (view) viewListofcourse(ph_course);
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
void add_teacher(Node_teacher*& ph_teacher)
{
	ifstream read("GiaoVu.csv");
	Node_teacher* pc_teacher = ph_teacher;
	if (ph_teacher != NULL)
	{
		return;
	}
	while (!read.eof())
	{
		Node_teacher* tmp = new Node_teacher;
		getline(read, tmp->mail, ',');
		getline(read, tmp->fullname, ',');
		getline(read, tmp->date, ',');
		getline(read, tmp->cccd, ',');
		getline(read, tmp->pass);
		tmp->teacher_next = NULL;
		if (pc_teacher == NULL)
		{
			ph_teacher = tmp;
			pc_teacher = tmp;
		}
		else
		{
			pc_teacher->teacher_next = tmp;
			pc_teacher = pc_teacher->teacher_next;
		}

	}
	read.close();
}

//Menu
void changePassword(Node_student*& a)
{
	print_type_in_box(30, 10, "Type in your new password", 30);
	string b; cin >> b;
	a->data.password = b;
	print_double_square(30, 15, 24, 3, 15, "New password accepted!");
}
void teacher_change_password(Node_teacher* teacher_login)
{
	print_type_in_box(30, 10, "Type in your new password", 30);
	cin >> teacher_login->pass;
	print_double_square(30, 15, 24, 3, 15, "New password accepted!");
}
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
		print_double_square(x, y, 22, 3, 12, "CHANGE PASSWORD");
	else
		print_double_square(x, y, 22, 3, 15, "CHANGE PASSWORD");
	y += 5;
	if (choose == 6)
		print_double_square(x, y, 22, 3, 12, "VIEW PROFILE");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW PROFILE");
	y += 5;
	if (choose == 7)
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
void print_teacher_setting_section(int choose)
{
	int x = 3, y = 10;
	if (choose == 1)
		print_double_square(x, y, 22, 3, 12, "START EDITING");
	else
		print_double_square(x, y, 22, 3, 15, "START EDITING");
	y += 5;
	if (choose == 2)
		print_double_square(x, y, 22, 3, 12, "CHANGE PASSWORD");
	else
		print_double_square(x, y, 22, 3, 15, "CHANGE PASSWORD");
	y += 5;
	if (choose == 3)
		print_double_square(x, y, 22, 3, 12, "VIEW PROFILE");
	else
		print_double_square(x, y, 22, 3, 15, "VIEW PROFILE");
	y += 5;
	if (choose == 4)
		print_double_square(x, y, 22, 3, 12, "EXIT!");
	else
		print_double_square(x, y, 22, 3, 15, "EXIT!");
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
void print_teacher_after_creating_year_menu(Node_year*& year_choose, Node_teacher* teacher_login)
{
	int choose = 1;	char move;
	do {
		system("CLS");
		print_after_year_section(choose, year_choose->name);
		do {
			ingiaodien_after_creating_year(year_choose, choose, teacher_login);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 7)
					choose++;
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
				char class_no1;
				Node_class* class_choose;
				print_type_in_box(30, 10, "Type class number", 5);
				cin >> class_no1;
				if (class_no1 > '9' || class_no1 < '1')
				{
					print_double_square(30, 15, 13, 3, 15, "Wrong input");
					_getch();
					continue;
				}
				int class_no = class_no1 - 48;
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
				char class_no1;
				Node_class* class_choose;

				print_type_in_box(30, 10, "Choose class to add students", 5);
				cin >> class_no1;
				if (class_no1 > '9' || class_no1 < '1')
				{
					print_double_square(30, 15, 13, 3, 15, "Wrong input");
					_getch();
					continue;
				}
				int class_no = class_no1 - 48;
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
					print_double_square(30, 15, 34, 3, 15, "Semester not exists or not found!");
				if (semester_choose != NULL)
				{
					add_course(semester_choose->ph_course, semester_choose->semester_no, year_choose->name, 1);
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
						char course_no1;
						Node_course* course_choose;

						print_type_in_box(30, 15, "Choose course to delete", 5);
						cin >> course_no1;
						if (course_no1 > '9' || course_no1 < '1')
						{
							print_double_square(30, 15, 13, 3, 15, "Wrong input");
							_getch();
							continue;
						}
						int course_no = course_no1 - 48;
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
void print_teacher_creating_year_menu(Node_year*& ph_year, Node_year*& current_year, Node_teacher* teacher_login)
{
	string year_name;
	int choose = 1;	char move;

	do {
		system("CLS");
		print_year_section(choose);
		do {
			ingiaodien_creating_year(current_year, ph_year, choose, teacher_login);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 9)
					choose++;
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
					reset_student(ph_year);
				}
				else print_double_square(30, 15, 15, 3, 15, "Not Accepted!");
			}
			_getch();
		}
		//Continue
		if (choose == 2 && ph_year != NULL)
		{
			print_teacher_after_creating_year_menu(current_year, teacher_login);
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
			char choose1;
			print_double_square(30, 10, 28, 3, 15, "1.View students in a class");
			print_double_square(30, 15, 29, 3, 15, "2.View students in a course");
			print_type_in_box(30, 20, "Your option", 5);
			cin >> choose1;
			if (choose1 > '2' || choose1 < '1')
			{
				print_double_square(30, 25, 13, 3, 15, "Wrong input");
				_getch();
				continue;
			}
			int choose = choose1 - 48;
			if (choose == 1)
			{
				if (ph_year->ph_classes != NULL)
				{
					char class_no1;
					char year_no1;
					viewAllClass(ph_year);
					print_type_in_box(30, 25, "Choose a school year", 5);
					cin >> year_no1;
					if (year_no1 > '9' || year_no1 < '1')
					{
						print_double_square(30, 30, 13, 3, 15, "Wrong input");
						_getch();
						continue;
					}
					int year_no = year_no1 - 48;
					Node_year* year_choose = find_year(ph_year, year_no);
					if (year_choose != nullptr)
					{
						print_type_in_box(30, 30, "Choose a class", 5);
						cin >> class_no1;
						if (class_no1 > '9' || class_no1 < '1')
						{
							print_double_square(30, 35, 13, 3, 15, "Wrong input");
							_getch();
							continue;
						}
						int class_no = class_no1 - 48;
						Node_class* class_choose = find_class(year_choose->ph_classes, class_no);
						if (class_choose == NULL)
							print_double_square(30, 35, 32, 3, 15, "Class not exists or not found!");
						if (class_choose != NULL)
							if (class_choose->ph_student != NULL)
								viewAllStudentInAClass(class_choose->ph_student);
							else print_double_square(30, 35, 40, 3, 15, "This class has not been added students");
					}
					else 	print_double_square(30, 30, 31, 3, 15, "Year not exists or not found!");

				}
				else print_double_square(30, 25, 31, 3, 15, "There is no any class to view");
			}
			else // choose == 2
			{
				if (current_year->ph_semester != NULL)
				{
					check_time_for_semester(current_year);

					Node_semester* semester_choose = nullptr;
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
					char no1;
					cin >> no1;
					if (no1 > '9' || no1 < '1')
					{
						print_double_square(30, 30, 13, 3, 15, "Wrong input");
						_getch();
						continue;
					}
					int no = no1 - 48;
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
			else print_double_square(30, 10, 32, 3, 15, "There is no any course to view");
			_getch();
		}
		//Export
		if (choose == 6)
		{
			if (check_not_end_semester(current_year, 1))
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
			if (check_not_end_semester(current_year, 1))
			{
				updateScoreBoardOfACourse(current_year);
				update = 1;
			}
			_getch();
		}
		if (choose == 8)
		{
			if (check_not_end_semester(current_year, 1))
			{
				if (update)
				{
					print_double_square(30, 10, 31, 3, 15, "1.View scoreboard of a course");
					print_double_square(30, 15, 30, 3, 15, "2.View scoreboard of a class");
					print_type_in_box(30, 20, "Your option", 5);
					char choose1;  cin >> choose1;
					if (choose1 > '2' || choose1 < '1')
					{
						print_double_square(30, 25, 13, 3, 15, "Wrong input");
						_getch();
						continue;
					}
					int choose = choose1 - 48;
					if (choose == 1)
						viewScoreBoardOfACourse(current_year);
					else
					{
						if (ph_year->ph_classes != NULL)
						{
							char class_no1;
							char year_no1;
							viewAllClass(ph_year);
							print_type_in_box(30, 25, "Choose a school year", 5);
							cin >> year_no1;
							if (year_no1 > '9' || year_no1 < '1')
							{
								print_double_square(30, 30, 13, 3, 15, "Wrong input");
								_getch();
								continue;
							}
							int year_no = year_no1 - 48;
							Node_year* year_choose = find_year(ph_year, year_no);
							print_type_in_box(30, 30, "Choose a class", 5);
							cin >> class_no1;
							if (class_no1 > '9' || class_no1 < '1')
							{
								print_double_square(30, 35, 13, 3, 15, "Wrong input");
								_getch();
								continue;
							}
							int class_no = class_no1 - 48;
							Node_class* class_choose = find_class(year_choose->ph_classes, class_no);
							if (class_choose == NULL)
								print_double_square(30, 35, 32, 3, 15, "Class not exists or not found!");
							if (class_choose != NULL)
								viewScoreBoardOfAClass(class_choose, current_year);
						}
						else print_double_square(30, 25, 31, 3, 15, "There is no any class to view");
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
	if (ph_year == nullptr || ph_year->ph_classes == NULL || current_year->ph_classes == NULL)
	{
		print_duongthang(25, 1, 62);
		print_duongngang(2, 5, 23);
		print_duongngang(26, 5, 208);
		print_current_time(208, 60);
		print_Viennen(235, 63);
		print_student_section(0);
		print_double_square(30, 10, 25, 3, 15, "Can not find your data!");
		print_double_square(30, 15, 31, 3, 15, "Please contact for supporting");
		_getch();
		return;
	}
	Node_student* student_login = find_node_student_for_login_account(a, ph_year);
	if (student_login == NULL)
	{
		print_duongthang(25, 1, 62);
		print_duongngang(2, 5, 23);
		print_duongngang(26, 5, 208);
		print_current_time(208, 60);
		print_Viennen(235, 63);
		print_student_section(0);
		print_double_square(30, 10, 25, 3, 15, "Can not find your data!");
		print_double_square(30, 15, 31, 3, 15, "Please contact for supporting");
		_getch();
		return;
	}
	else
	{
		ingiaodien_student(current_year, ph_year, student_login, 0);
		print_double_square(30, 10, 33, 3, 15, "Loading your profile completed!");
		_getch();
		int choose = 1;	char move;
		do {
			system("CLS");
			print_student_section(choose);
			do {
				ingiaodien_student(current_year, ph_year, student_login, choose);
				move = _getch();
				if (move == 'w' || move == 72)
					if (choose > 1)
						choose--;
				if (move == 's' || move == 80)
					if (choose < 7)
						choose++;
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
				if (!check_not_end_semester(current_year, 0))
					deleteEnrolledCourse(student_login, current_year);
				_getch();
			}
			if (choose == 4)
			{
				if (check_not_end_semester(current_year, 1))
					viewScoreBoardByStudent(student_login, current_year);
				_getch();
			}
			if (choose == 5)
			{
				changePassword(student_login);
				_getch();
			}
			if (choose == 6)
			{
				view_profile_student(student_login);
				_getch();
			}
		} while (choose != 7);
	}
	savePassword(ph_year);
}
void print_teacher_setting(Node_year*& ph_year, Node_year*& current_year, Node_teacher* teacher_login, Node_teacher* ph_teacher)
{
	system("CLS");
	print_double_square(30, 10, 33, 3, 15, "Loading your profile completed!");
	ingiaodien_setting(current_year, ph_year, 0, teacher_login);
	_getch();
	int choose = 1;	char move;
	do {
		system("CLS");
		print_teacher_setting_section(choose);
		do {

			ingiaodien_setting(current_year, ph_year, choose, teacher_login);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 4)
					choose++;
		} while (move != 13);

		if (choose == 1)
		{
			print_teacher_creating_year_menu(ph_year, current_year, teacher_login);
		}
		if (choose == 2) {
			teacher_change_password(teacher_login);
			saveTeacherData(ph_teacher);
			_getch();
		}
		if (choose == 3) {
			view_profile_teacher(teacher_login);
			_getch();
		}
	} while (choose != 4);
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
int login(string a, string s1) {
	if (a[0] == '1' || a[0] == '2' || a[0] == '3' || a[0] == '4' || a[0] == '5' || a[0] == '6' || a[0] == '7' || a[0] == '8' || a[0] == '9' || a[0] == '0') {
		long id = stol(a);
		fstream fs;
		string b = a;
		int cnt = 1;
		bool acp = false;
		bool end = true;
		//	string *chatluong = { "NULL","NULL","NULL","NULL","NULL","APCS","VP","CLC" };
		string* chatLuong = new string[8];
		for (int i = 0; i <= 4; i++) {
			chatLuong[i] = "NULL";
		}
		chatLuong[5] = "APCS";
		chatLuong[6] = "VP";
		chatLuong[7] = "CLC";
		while (end) {
			fs.open("StudentData\\" + to_string(id / 1000000) + "\\" + to_string(id / 1000000) + chatLuong[(id / 1000) % 10] + to_string(cnt) + ".csv", ios::in);
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
					if (pass == s1) {
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
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else {
		fstream fs;
		fs.open("GiaoVu.csv");
		while (!fs.eof()) {
			string s;
			getline(fs, s, ',');
			if (s == a) {
				int dem = 3;
				string check;
				while (dem--) {
					getline(fs, check, ',');
				}
				getline(fs, check);
				if (s1 == check) {
					return 2;
				}
			}
			else getline(fs, s);

		}
		return 0;
	}
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
	string mssv = "-1"; string password = "\0";
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
			if (mssv != "-1" && password != "\0" && login(mssv, password) == 1)
			{
				print_login_status(47, 15, 1);
				_getch();
				print_menu_for_student(stol(mssv), ph_year, current_year);
				system("CLS"); choose = 1;
			}
			else
				if (mssv != "-1" && password != "\0" && login(mssv, password) == 2)
				{
					Node_teacher* ph_teacher = NULL;
					add_teacher(ph_teacher);
					Node_teacher* teacher_login = find_teacher_login(mssv, ph_teacher);
					print_login_status(47, 15, 1);
					_getch();
					print_teacher_setting(ph_year, current_year, teacher_login, ph_teacher);
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
//Save load
void savePassword(Node_year* a) {
	fstream fs;
	Node_year* d = a;
	while (a) {
		Node_class* b = a->ph_classes;
		while (b) {
			fs.open((string)"StudentData\\" + (a->name)[2] + (a->name)[3] + "\\" + b->name + ".csv");
			Node_student* c = b->ph_student;
			while (c) {
				fs << c->data.No << "," << c->data.ID << "," << c->data.first_name << "," << c->data.lastname << "," << c->data.gender << "," << c->data.date << "," << c->data.social_ID << "," << c->data.password;
				c = c->student_next;
				if (c) {
					fs << endl;
				}
			}
			fs.close();
			b = b->class_next;
		}
		a = a->year_next;
	}

}
void saveStudentData(Node_year* ph_year, Node_year* current_year)
{
	if (ph_year != NULL)
	{
		//Save time
		ofstream time("StudentData\\Save\\time.txt");
		time << now;
		time.close();
		//Save bool update
		ofstream update1("StudentData\\Save\\update.txt");
		update1 << update;
		update1.close();
		fstream fyear("StudentData\\Save\\CreatedYear.txt", ios::out);
		while (ph_year != NULL)
		{
			fyear << ph_year->name;
			if (ph_year->ph_classes != NULL)
			{
				ofstream fclass("StudentData\\" + ph_year->name.substr(2, 2) + "\\Save\\CreatedClass.txt");
				Node_class* pc_class = ph_year->ph_classes;
				while (pc_class != NULL)
				{
					fclass << pc_class->name;
					if (pc_class->ph_student != nullptr)
						ofstream student("StudentData\\" + ph_year->name.substr(2, 2) + "\\Save\\" + pc_class->name + "_studentadded.txt");
					pc_class = pc_class->class_next;
					if (pc_class != NULL)
						fclass << endl;
				}
			}

			if (current_year->ph_semester != NULL)
			{
				ofstream semester_created("StudentData\\" + current_year->name.substr(2, 2) + "\\Save\\SemesterCreated.txt");
				semester_created.close();
				Node_semester* pc_semester = current_year->ph_semester;
				while (pc_semester != nullptr)
				{
					if (pc_semester->ph_course != NULL)
						ofstream fcourse("StudentData\\" + current_year->name.substr(2, 2) + "\\Save\\" + pc_semester->semester_no + "_courseadded.txt");
					pc_semester = pc_semester->semester_next;
				}
			}
			ph_year = ph_year->year_next;
			if (ph_year != NULL)
				fyear << endl;
		}
		fyear.close();
	}

}
void loadFile(Node_year*& ph_y, Node_year*& current_year) {
	fstream fi;
	Node_year* yCur = ph_y;
	fi.open("StudentData\\Save\\CreatedYear.txt", ios::in);
	if (!fi.is_open())
		return;
	//Load cac node
	while (!fi.eof()) {
		if (!ph_y) {
			ph_y = new Node_year;
			fi >> ph_y->name;
			yCur = ph_y;
			//fstream check_semester("StudentData\\" + yCur->name.substr(2, 2) + "\\Save\\CreatedSemester");
			yCur->year_next = nullptr;
			current_year = yCur;
		}
		else {
			yCur->year_next = new Node_year;
			fi >> yCur->year_next->name;
			yCur = yCur->year_next;
			current_year = yCur;
			yCur->year_next = 0;
		}
	}
	fi.close();

	yCur = ph_y;
	Node_class* cCur = 0;
	fstream fiClass;
	while (yCur) {
		fiClass.open("StudentData\\" + yCur->name.substr(2, 2) + "\\Save\\CreatedClass.txt", ios::in);
		while (!fiClass.eof()) {
			if (!yCur->ph_classes) {
				yCur->ph_classes = new Node_class;
				fiClass >> yCur->ph_classes->name;
				//cout << yCur->ph_classes->name;
				cCur = yCur->ph_classes;
				yCur->ph_classes->class_next = 0;
			}
			else {
				cCur->class_next = new Node_class;
				fiClass >> cCur->class_next->name;
				//cout << cCur->name;
				cCur = cCur->class_next;
				cCur->class_next = 0;
			}
		}
		yCur = yCur->year_next;
		fiClass.close();
	}
	fstream fiStudent;
	yCur = ph_y;
	//load hoc sinh
	Node_student* sCur = NULL;
	while (yCur) {
		cCur = yCur->ph_classes;
		while (cCur) {
			fstream check_added("StudentData\\" + yCur->name.substr(2, 2) + "\\Save\\" + cCur->name + "_studentadded.txt");
			if (check_added.is_open())
			{
				fiStudent.open("StudentData\\" + yCur->name.substr(2, 2) + "\\" + cCur->name + ".csv", ios::in);
				while (!fiStudent.eof()) {
					if (!cCur->ph_student) {
						cCur->ph_student = new Node_student;
						getline(fiStudent, cCur->ph_student->data.No, ',');
						getline(fiStudent, cCur->ph_student->data.ID, ',');
						getline(fiStudent, cCur->ph_student->data.first_name, ',');
						getline(fiStudent, cCur->ph_student->data.lastname, ',');
						getline(fiStudent, cCur->ph_student->data.gender, ',');
						getline(fiStudent, cCur->ph_student->data.date, ',');
						getline(fiStudent, cCur->ph_student->data.social_ID, ',');
						getline(fiStudent, cCur->ph_student->data.password);
						cCur->ph_student->student_next = NULL;
						cCur->ph_student->ph_course_enrolled1 = NULL;
						cCur->ph_student->ph_course_enrolled2 = NULL;
						cCur->ph_student->ph_course_enrolled3 = NULL;
						//cout << yCur->ph_classes->name;
						sCur = cCur->ph_student;
					}
					else {
						sCur->student_next = new Node_student;
						getline(fiStudent, sCur->student_next->data.No, ',');
						getline(fiStudent, sCur->student_next->data.ID, ',');
						getline(fiStudent, sCur->student_next->data.first_name, ',');
						getline(fiStudent, sCur->student_next->data.lastname, ',');
						getline(fiStudent, sCur->student_next->data.gender, ',');
						getline(fiStudent, sCur->student_next->data.date, ',');
						getline(fiStudent, sCur->student_next->data.social_ID, ',');
						getline(fiStudent, sCur->student_next->data.password);
						sCur->student_next->student_next = NULL;
						sCur->student_next->ph_course_enrolled1 = NULL;
						sCur->student_next->ph_course_enrolled2 = NULL;
						sCur->student_next->ph_course_enrolled3 = NULL;
						//cout << cCur->name;
						sCur = sCur->student_next;
					}
				}
				fiStudent.close();
			}

			cCur = cCur->class_next;
		}
		yCur = yCur->year_next;
		fiStudent.close();
	}

	//Load khÃ³a há»c
	fstream check_semester("StudentData\\" + current_year->name.substr(2, 2) + "\\Save\\SemesterCreated.txt");
	if (check_semester.is_open())
	{
		add_semester(current_year->ph_semester);
		int count = 1;
		while (count != 4)
		{
			//Load khoa hoc vao semester dong thoi add hoc sinh dang ki khoa hoc
			fstream check_course_added("StudentData\\" + current_year->name.substr(2, 2) + "\\Save\\" + "Semester " + to_string(count) + "_courseadded.txt");
			if (check_course_added.is_open())
			{
				Node_semester* pc_semester = find_semester(current_year->ph_semester, to_string(count));
				add_course(pc_semester->ph_course, "Semester " + to_string(count), current_year->name, 0);
				//Load hoc sinh dang ky
				fstream check_enrolled_student("CoursesData\\Semester " + to_string(count) + "\\Courses.txt", ios::in);
				if (check_enrolled_student.is_open())
				{
					while (!check_enrolled_student.eof())
					{
						string course_name;
						check_enrolled_student >> course_name;
						Node_course* course_being_added = find_course_byname(pc_semester->ph_course, course_name);
						ifstream infor("CoursesData\\Semester " + to_string(count) + "\\" + course_name + ".csv", ios::in);
						while (!infor.eof())
						{
							string trash;
							long mssv;
							getline(infor, trash, ',');
							infor >> mssv;
							Node_student* student = find_node_student_for_login_account(mssv, ph_y);
							check_time_for_semester(current_year);
							if (count == 1)
								add_enrolled_course(student->ph_course_enrolled1, course_being_added);
							if (count == 2)
								add_enrolled_course(student->ph_course_enrolled2, course_being_added);
							if (count == 3)
								add_enrolled_course(student->ph_course_enrolled3, course_being_added);
							add_enrolled_student(course_being_added->ph_student_enrolled, student);
							getline(infor, trash);
						}
					}


				}
			}
			check_course_added.close();
			count++;
		}
	}
	check_semester.close();

	//Load cac bien khac
	fstream time("StudentData\\Save\\time.txt");
	time >> now;
	time.close();
	fstream update1("StudentData\\Save\\time.txt");
	update1 >> update;
	update1.close();
}
void saveTeacherData(Node_teacher*& head) {
	fstream fs;
	fs.open("GiaoVu.csv", ios::out | ios::trunc);
	while (head) {
		fs << head->mail << "," << head->fullname << "," << head->date << "," << head->cccd << "," << head->pass;
		head = head->teacher_next;
		if (head) fs << endl;
	}
	fs.close();
}
// CÃ¡c hÃ m thá»i gian
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
	if (cur_time <= now + 10 * 60)
		current_year->semestercount = 1;
	else
		if (cur_time <= now + 20 * 60)
			current_year->semestercount = 2;
		else
			if (cur_time <= now + 30 * 60)
				current_year->semestercount = 3;

}
void print_semester_start_end_time(Node_year* current_year)
{

	time_t cur_time = time(0);
	if (cur_time <= now + 10 * 60)
	{

		if (cur_time <= now + 7 * 60)
		{
			time_t time = now + 7 * 60;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_fill_square(138, 60, 46, 3, 15, "Semester 1 ends at " + time_end);
		}
		else
		{
			time_t time = now + 10 * 60;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_fill_square(136, 60, 48, 3, 15, "Semester 2 starts at " + time_end);
		}


	}
	else
		if (cur_time <= now + 20 * 60)
		{
			if (cur_time <= now + 17 * 60)
			{
				time_t time = now + 17 * 60;
				char* dt = std::ctime(&time);
				string time_end = dt;
				print_fill_square(138, 60, 46, 3, 15, "Semester 2 ends at " + time_end);
			}
			else
			{
				time_t time = now + 20 * 60;
				char* dt = std::ctime(&time);
				string time_end = dt;
				print_fill_square(136, 60, 48, 3, 15, "Semester 3 starts at " + time_end);
			}
		}
		else
			if (cur_time <= now + 30 * 60)
			{
				if (cur_time <= now + 27 * 60)
				{
					time_t time = now + 27 * 60;
					char* dt = std::ctime(&time);
					string time_end = dt;
					print_fill_square(138, 60, 46, 3, 15, "Semester 3 ends at " + time_end);
				}
				else
				{
					time_t time = now + 30 * 60;
					char* dt = std::ctime(&time);
					string time_end = dt;
					print_fill_square(133, 60, 51, 3, 15, current_year->name + " will ends at " + time_end);
				}

			}
}
bool check_time_regis(Node_year*& current_year)
{
	check_time_for_semester(current_year);
	time_t cur_time = time(0);
	if (current_year->semestercount == 1)
		if (cur_time <= now + 7 * 60)
		{
			time_t time = now + 7 * 60;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_fill_square(160, 7, 74, 3, 15, "Registration session of semester 1 will end at " + time_end);
			return 1;
		}
		else { print_double_square(30, 10, 56, 3, 15, "Registration session of semester 1 has ran out of time"); return 0; }
	if (current_year->semestercount == 2)
		if (cur_time <= now + 17 * 60)
		{
			time_t time = now + 17 * 60;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_fill_square(160, 7, 74, 3, 15, "Registration session of semester 2 will end at " + time_end);
			return 1;
		}
		else { print_double_square(30, 10, 56, 3, 15, "Registration session of semester 2 has ran out of time"); return 0; }
	if (current_year->semestercount == 3)
		if (cur_time <= now + 27 * 60)
		{
			time_t time = now + 27 * 60;
			char* dt = std::ctime(&time);
			string time_end = dt;
			print_fill_square(160, 7, 74, 3, 15, "Registration session of semester 3 will end at " + time_end);
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
		return 0;
	}
	else return 1;
}
bool check_not_end_semester(Node_year*& current_year, bool view)
{
	check_time_for_semester(current_year);
	time_t cur_time = time(0);
	if (current_year->semestercount == 1)
		if (cur_time <= now + 7 * 60)
		{
			if (view) print_double_square(30, 10, 26, 3, 15, "Semester 1 has not ended");
			return 0;
		}
	if (current_year->semestercount == 2)
		if (cur_time <= now + 17 * 60)
		{
			if (view)print_double_square(30, 10, 26, 3, 15, "Semester 2 has not ended");
			return 0;
		}
	if (current_year->semestercount == 3)
		if (cur_time <= now + 27 * 60)
		{
			if (view) print_double_square(30, 10, 26, 3, 15, "Semester 3 has not ended");
			return 0;
		}
	return 1;
}