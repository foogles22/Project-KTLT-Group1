#include "all_structs.h"

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
	gotoXY(71, 20);
	cout << "Course ID  Course Name     Teacher Name     Number of Credits  The maximum number of students  Day of the week  The sessions";
	while (ph_course != NULL)
	{
		gotoXY(68, 20 + i);
		cout << i;
		gotoXY(71, 20 + i++);
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
	print_double_square(69, 20, 128, i, 15, "\0");
	print_double_square(67, 20, 3, i, 15, "\0");

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
				cout << count++ << "/" << "Khoa:" << year->name[2] << year->name[3];
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
	gotoXY(78, 40);
	cout << "No       ID             First Name       Last Name       Gender       Date of birth       Social ID";
	Node_student* pc_student = ph_student;
	while (pc_student) {
		gotoXY(78, 40 + i++);
		cout << pc_student->data.No << "        ";
		cout << pc_student->data.ID << "       ";
		cout << pc_student->data.first_name;
		for (int i = 0; i < 19 - pc_student->data.first_name.length(); i++)
			cout << " ";
		cout << pc_student->data.lastname;
		for (int i = 0; i < 16 - pc_student->data.lastname.length(); i++)
			cout << " ";
		cout << pc_student->data.gender << "  ";
		for (int i = 0; i < 10 - pc_student->data.gender.length(); i++)
			cout << " ";
		cout << pc_student->data.date << "       ";
		cout << pc_student->data.social_ID << "   ";

		pc_student = pc_student->student_next;
	}
	print_double_square(76, 40, 104, i, 15, "\0");
	return;
}
void viewListofstudentsincourse(Node_student* ph_student)
{
	int i = 1;
	gotoXY(78, 30);
	cout << "No       ID             First Name       Last Name       Gender       Date of birth       Social ID";
	Node_student* pc_student = ph_student;
	while (pc_student) {
		gotoXY(78, 30 + i++);
		cout << pc_student->data.No << "        ";
		cout << pc_student->data.ID << "       ";
		cout << pc_student->data.first_name;
		for (int i = 0; i < 19 - pc_student->data.first_name.length(); i++)
			cout << " ";
		cout << pc_student->data.lastname;
		for (int i = 0; i < 16 - pc_student->data.lastname.length(); i++)
			cout << " ";
		cout << pc_student->data.gender << "  ";
		for (int i = 0; i < 10 - pc_student->data.gender.length(); i++)
			cout << " ";
		cout << pc_student->data.date << "       ";
		cout << pc_student->data.social_ID << "   ";

		pc_student = pc_student->student_next;
	}
	print_double_square(76, 30, 104, i, 15, "\0");
	return;
}
//View profile
void view_profile_teacher(Node_teacher* teacher_login)
{
	int i = 1;//30 24 30
	gotoXY(86, 20);
	cout << "Gmail                         FullName                Date of birth     ID";
	//       21127512     Nguyen Le Hoang  Kha       08/02/2003      123456789123
	gotoXY(86, 20 + i++);
	cout << teacher_login->mail;
	for (int i = 0; i < 30 - teacher_login->mail.length(); i++) cout << " ";
	cout << teacher_login->fullname;
	for (int i = 0; i < 26 - teacher_login->fullname.length(); i++) cout << " ";
	cout << teacher_login->date << "      ";
	cout << teacher_login->cccd;
	print_double_square(84, 20, 88, i, 15, "\0");
}
void view_profile_student(Node_student* student_login)
{
	int i = 1;
	gotoXY(78, 20);
	cout << "No       ID             First Name       Last Name       Gender       Date of birth       Social ID";
	gotoXY(78, 20 + i++);
	cout << student_login->data.No << "        ";
	cout << student_login->data.ID << "       ";
	cout << student_login->data.first_name;
	for (int i = 0; i < 19 - student_login->data.first_name.length(); i++)
		cout << " ";
	cout << student_login->data.lastname;
	for (int i = 0; i < 16 - student_login->data.lastname.length(); i++)
		cout << " ";
	cout << student_login->data.gender << "  ";
	for (int i = 0; i < 10 - student_login->data.gender.length(); i++)
		cout << " ";
	cout << student_login->data.date << "       ";
	cout << student_login->data.social_ID << "   ";

	print_double_square(76, 20, 104, i, 15, "\0");
	return;
}
//Scoreboard
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
				pc_student = pc_student->student_next;
				if (pc_student) write1 << endl;
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
	print_type_in_box(30, 25, "Choose a course", 5);
	char no1; cin >> no1;
	if (no1 > '9' || no1 < '1')
	{
		print_double_square(30, 25, 13, 3, 15, "Wrong input");
		return;
	}
	int no = no1 - 48;
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
	print_double_square(72, 15 + i2, 112, i1, 15, "\0");
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
	char no1; cin >> no1;
	if (no1 > '9' || no1 < '1')
	{
		print_double_square(30, 15, 13, 3, 15, "Wrong input");
		return;
	}
	int no = no1 - 48;
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
	if (!check_class_score(a, b))
	{
		print_double_square(30, 35, 9, 3, 15, "No data");
	}
	Node_student* curStudent = a->ph_student;
	Node_course* curEnrolled = nullptr;
	double totalGPA = 0;
	int countStudent = 0;
	check_time_for_semester(b);
	int i = 1;
	gotoXY(80, 32);
	cout << "Student ID          Fullname          Course Name         Final Mark      GPA      Total GPA of class";

	while (curStudent) {
		if (b->semestercount == 1)
			curEnrolled = curStudent->ph_course_enrolled1;
		if (b->semestercount == 2)
			curEnrolled = curStudent->ph_course_enrolled2;
		if (b->semestercount == 3)
			curEnrolled = curStudent->ph_course_enrolled3;
		if (curEnrolled != nullptr)
			countStudent += 1;
		double gpacourse = 0;
		int cnt = 0;
		Node_course* tmp = curEnrolled;
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
		if (tmp != NULL)
		{
			cout << (double)gpacourse / cnt;
			totalGPA += (double)gpacourse / cnt;
		}

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
	char no_course1;
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

	if (semester_choose->ph_course != NULL && semester_choose)
	{
		if (check_time_regis(current_year))
			if (check_not_over_5_enrolled_course(*ph_course_enrolled))
			{
				print_double_square(120, 15, 12, 3, 15, "Semester " + to_string(current_year->semestercount));
				viewListofcourse(semester_choose->ph_course);
				print_type_in_box(30, 10, "Choose a course", 5);
				cin >> no_course1;
				if (no_course1 > '9' || no_course1 < '1')
				{
					print_double_square(30, 15, 13, 3, 15, "Wrong input");
					return;
				}
				int no_course = no_course1 - 48;
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
	else print_double_square(30, 10, 39, 3, 15, "Semester " + to_string(current_year->semestercount) + " has not been added courses");

}
bool check_year_name_appropriate(string year_name)
{
	int former = year_name[0] + year_name[1] + year_name[2] + year_name[3];
	int later = year_name[5] + year_name[6] + year_name[7] + year_name[8];
	if (year_name.length() == 9 && (later - former) == 1 && year_name[4] == '-')
		return 1;
	else return 0;
}
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