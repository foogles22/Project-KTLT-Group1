#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <unistd.h>
using namespace std;
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
	Node_course* course_next;
	Node_student* ph_student_enrolled;
};
struct Node_semester
{
	int start_date, end_date;
	string semester_no;
	Node_course* ph_course;
	Node_semester* semester_next;
};

struct SINHVIEN
{
	string No, ID, first_name, lastname, gender, social_ID, password, date;
};
//Node sinh viên
struct Node_student
{
	SINHVIEN data;
	Node_student* student_next;
	Node_course* ph_course_enrolled1, * ph_course_enrolled2, * ph_course_enrolled3;
};
//Node lớp học
struct Node_class
{
	string name;
	Node_class* class_next;
	Node_student* ph_student;
};
//Node năm học
struct Node_year
{
	int s_cur = 1;
	string name;
	Node_year* year_next;
	Node_class* ph_classes;
	Node_semester* ph_semester;
};
//Hàm để in ra các lớp học
Node_student* find_node_student_for_login_account(long mssv, Node_year* ph_year);
void print_class(Node_class* ph_class)
{
	Node_class* pc_class = ph_class;
	int i = 1;
	while (pc_class != NULL)
	{
		cout << i++ << ":" << pc_class->name << endl;
		pc_class = pc_class->class_next;
	}
}
//Hàm để in ra các năm học
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
//Hàm để tìm Node năm học được chọn
void print_semester(Node_semester* ph_semester)
{
	Node_semester* pc = ph_semester;
	int i = 1;
	while (pc != NULL)
	{
		cout << i++ << ":" << pc->semester_no << endl;
		pc = pc->semester_next;
	}
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
	while (pc != NULL)
	{
		cout << i++ << ":" << pc->data.course_name << endl;
		pc = pc->course_next;
	}
}
void print_enrolled_course(Node_student* student_login)
{
	int count = 1;
	if (student_login->ph_course_enrolled1 == NULL && student_login->ph_course_enrolled2 == NULL && student_login->ph_course_enrolled3 == NULL)
	{
		cout << "Haven't enrolled any course!\n";
		return;
	}

	Node_course* pc_enrolled_coure = student_login->ph_course_enrolled1;
	while (pc_enrolled_coure != NULL)
	{
		cout << "Semester 1\n";
		cout << count++<<": " << pc_enrolled_coure->data.course_name << endl;
		pc_enrolled_coure = pc_enrolled_coure->course_next;
	}
	pc_enrolled_coure = student_login->ph_course_enrolled2;
	count = 1;
	while (pc_enrolled_coure != NULL)
	{
		cout << "Semester 2\n";
		cout << count++ << ": " << pc_enrolled_coure->data.course_name << endl;
		pc_enrolled_coure = pc_enrolled_coure->course_next;
	}
	pc_enrolled_coure = student_login->ph_course_enrolled3;
	count = 1;
	while (pc_enrolled_coure != NULL)
	{
		cout << "Semester 3\n";
		cout << count++ << ": " << pc_enrolled_coure->data.course_name << endl;
		pc_enrolled_coure = pc_enrolled_coure->course_next;
	}

}
//void viewCourse_Student(Node_student* student) {
//	cout << "Your course in this semester:" << endl;
//	if (student->ph_course_enrolled)
//		cout << "ID\t Course name\t Teacher_name\t Session 1\t Session 2\t Nums of credit\t";
//	else
//		cout << "You haven't enrolled any class!!!\n";
//	while (student->ph_course_enrolled) {
//		cout << student->ph_course_enrolled->data.id << ' ';
//		cout << student->ph_course_enrolled->data.course_name << ' ';
//		cout << student->ph_course_enrolled->data.teacher_name << ' ';
//		cout << student->ph_course_enrolled->data.session1 << ' ';
//		cout << student->ph_course_enrolled->data.session2 << ' ';
//		cout << student->ph_course_enrolled->data.number_of_credits << ' ';
//		cout << student->ph_course_enrolled->data.days_of_week << ' ';
//
//		student->ph_course_enrolled = student->ph_course_enrolled->course_next;
//	}
//	return;
//}
void viewAllClass(Node_year* year) {
	if (!year)
		cout << "No years has been created";
	while (year) {
		cout << year->name << endl;
		while (year->ph_classes) {
			cout << year->ph_classes->name << endl;
			year->ph_classes = year->ph_classes->class_next;
		}
		year = year->year_next;
	}

	return;
}
void viewAllStudentInAClass(Node_class* Curclass) {
	cout << Curclass->name << endl;
	cout << "No \t ID \t First Name\t Last Name\tGender\tSocial ID";
	while (Curclass->ph_student) {
		cout << Curclass->ph_student->data.No << ' ';
		cout << Curclass->ph_student->data.ID << ' ';
		cout << Curclass->ph_student->data.first_name << ' ';
		cout << Curclass->ph_student->data.lastname << ' ';
		cout << Curclass->ph_student->data.gender << ' ';
		cout << Curclass->ph_student->data.social_ID << ' ';

		Curclass->ph_student = Curclass->ph_student->student_next;
	}

	return;
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
//Hàm để tìm Node lớp học được chọn
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
//Hàm để tìm Node lớp học được chọn
Node_class* find_class_by_name(Node_class* ph_class, string class_name)
{
	Node_class* pc_class = ph_class;
	while (pc_class != NULL && pc_class->name != class_name)
		pc_class = pc_class->class_next;
	return pc_class;
}
Node_student* find_student_by_id(Node_student* ph_student, string id)
{
	Node_student* pc_student = ph_student;
	while (pc_student != NULL && pc_student->data.ID != id)
		pc_student = pc_student->student_next;
	return pc_student;
}
//Hàm để thêm năm học vào
void add_year(Node_year*& ph_year, string year_name, Node_year*& current_year)
{
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
//Hàm để thêm lớp học vào 
void add_class(Node_class*& ph_class)
{
	string class_name;
	cout << "Type class name: "; cin >> class_name;

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
//Hàm để thêm hồ sơ các sinh viên năm nhất vào
void add_1st_student(Node_student*& ph_student, string class_name, string year_name)
{
	year_name = to_string(year_name[2] - 48) + to_string(year_name[3] - 48);
	ifstream read("StudentData\\" + year_name + "\\" + class_name + ".csv");
	Node_student* pc_student = ph_student;
	if (pc_student != NULL)
	{
		cout << "Student have been added to this class\n";
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
	print_student(ph_student);
}
void add_semester(Node_semester*& ph_semester)
{
	int no = 1;
	if (ph_semester != NULL)
	{
		cout << "Semesters have been created\n";
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		string semester_no_tmp = "Semester " + to_string(no++);
		Node_semester* tmp = new Node_semester;
		tmp->semester_no = semester_no_tmp;
		tmp->ph_course = NULL;
		tmp->semester_next = NULL;

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
	fstream fs;
	fs.open("CoursesData\\" + semester_no + "\\" + "Courses.txt");
	if (ph_course == nullptr)
	{
		year_name = to_string(year_name[2] - 48) + to_string(year_name[3] - 48);
		fstream read("StudentData\\" + year_name + "\\" + semester_no +".txt", ios::in);
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
			fs << DATA.course_name << endl;
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
	}
	else
	{
		COURSE_DATA DATA;
		cout << "Course ID: "; cin >> DATA.id; cin.ignore();
		cout << "Course Name: "; getline(cin, DATA.course_name);
		fs << DATA.course_name << endl;		
		cout << "Teacher Name: "; getline(cin, DATA.teacher_name);
		cout << "Number of Credits: "; cin >> DATA.number_of_credits;
		cout << "The maximum number of students in the course(default 50): "; cin >> DATA.max_num_student;
		cout << "Day of the week: "; cin >> DATA.days_of_week;
		cout << "          MON / TUE / WED / THU / FRI / SAT\n" << "S1(07:30)\n" << "S2(09:30)\n" << "S3(13:30)\n" << "S4(15:30)\n";
		cout << "The session that the course will be performed(Choose 2 session in a week)(Ex: MON_S2)\n" << "Session 1: ";
		cin >> DATA.session1;
		do
		{
			cout << "Session 2: "; cin >> DATA.session2;

		} while (DATA.session1 == DATA.session2);

		Node_course* tmp = new Node_course;
		tmp->data = DATA;
		tmp->course_next = NULL;
		tmp->ph_student_enrolled = NULL;
		Node_course* pc_course = ph_course;
		while (pc_course->course_next != NULL)
			pc_course = pc_course->course_next;
		pc_course->course_next = tmp;
	}
	fs.close();
}
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
void deleteEnrolledCourse(Node_student*& student) {
	if (student->ph_course_enrolled1 == NULL && student->ph_course_enrolled2 == NULL && student->ph_course_enrolled3 == NULL)
	{
		cout << "You have not enrolled in any course\n";
		return;
	}
	Node_course** ph_course_enrolled{};
	int no;
	do
	{
		print_enrolled_course(student);
		cin >> no;
		if (no == 1)
			ph_course_enrolled = &(student->ph_course_enrolled1);
		if (no == 2)
			ph_course_enrolled = &(student->ph_course_enrolled2);
		if (no == 3)
			ph_course_enrolled = &(student->ph_course_enrolled3);

		if (*ph_course_enrolled == NULL)
			cout << "You have not enrolled any course in this semester\n";

	} while (*ph_course_enrolled == NULL);
	cout << "Choose a course to delete: " << endl;
	int x;
	cin >> x;
	if ((*ph_course_enrolled)->course_next == nullptr) {
		delete *ph_course_enrolled;
		*ph_course_enrolled = nullptr;
		return;
	}
	int cnt = 1;
	Node_course* cur = *ph_course_enrolled;
	while (cnt != (x - 1)) {
		cur = cur->course_next;
	}
	if (x == 1) {
		Node_course* del = cur;
		cur = cur->course_next;
		delete del;
	}
	else if (cur->course_next->course_next) {
		Node_course* del = cur->course_next;
		cur->course_next = cur->course_next->course_next;
		delete del;
	}
	else {
		Node_course* del = cur->course_next;
		cur->course_next = nullptr;
		delete del;
	}
}
// hàm xóa Node_student
void deallocate_student(Node_student*& ph_student)
{
	while (ph_student != NULL)
	{
		Node_student* pc_student = ph_student->student_next;
		delete ph_student;
		ph_student = pc_student;
	}
}
// hàm xóa Node_class
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
// hàm xóa mọi Node
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
//void delete_specific_semester(Node_semester*& ph_semester, Node_semester* pdel_semester)
//{
//	deallocate_course(pdel_semester->ph_course);
//	if (ph_semester == pdel_semester)
//	{
//		ph_semester = ph_semester->semester_next;
//		delete pdel_semester;
//		return;
//	}
//	Node_semester* pc_semester = ph_semester;
//	while (pc_semester->semester_next != NULL && pc_semester->semester_next != pdel_semester)
//	{
//		pc_semester = pc_semester->semester_next;
//	}
//	pc_semester->semester_next = pc_semester->semester_next->semester_next;
//	delete pdel_semester;
//}
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
//void printExistedCourses(fstream &fs){
//	fs.open("CoursesData\\Semester 1\\Courses.txt");
//	while (!fs.eof()){
//		string s;
//		fs>>s;
//		cout<<s<<endl;
//	}
//	fs.close();
//}
void updateStudentResult(Node_student *&a, Node_year *b,string s, double x, double y, double z, double t){
	//use while loop to get each  student ID then use the find_student by id to make changes
	if (b->s_cur == 1){
		Node_course *cur = a->ph_course_enrolled1;
		while (cur->data.course_name != s){
			cur = cur->course_next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}
	if (b->s_cur == 2){
		Node_course *cur = a->ph_course_enrolled2;
		while (cur->data.course_name != s){
			cur = cur->course_next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}
	if (b->s_cur == 3){
		Node_course *cur = a->ph_course_enrolled3;
		while (cur->data.course_name != s){
			cur = cur->course_next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}		
}
void viewScoreBoardOfACourse(Node_year *a){
	fstream fs;
	fs.open("CoursesData\\Semester " + to_string(a->s_cur) +"\\Courses.txt");
	while (!fs.eof()){
		string s;
		fs>>s;
		cout<<s<<endl;
	}
	cout<<"Which course do you want to view? ";
	string b;
	cin>>b;
	fstream fs1;
	fs1.open("CoursesData\\Semester " + to_string(a->s_cur) +"\\" + b +".csv");
	while(!fs1.eof()){
		string c;
		getline(fs1,c);
		cout<<c<<endl;
	}
	fs1.close();
	fs.close();
} //view scoreboard
void viewScoreBoardByStudent (Node_student *a, Node_year *b){
	// use find_node_student_for_login_account function to Node student a
	if (b->s_cur == 1){
		Node_course *view = a->ph_course_enrolled1;
		Node_course *cur = a->ph_course_enrolled1;
		while (cur){
			cout<<cur->data.course_name<<endl;
			cur = cur->course_next;
		}
		cout<<"Which course to view?";
		string s;
		cin>>s;
		while (view->data.course_name!=s){
			view = view->course_next;
		}
		cout<<view->final<<endl;
		cout<<view->midterm<<endl;
		cout<<view->other<<endl;
		cout<<view->total;
	}
	if (b->s_cur == 2){
		Node_course *view = a->ph_course_enrolled2;
		Node_course *cur = a->ph_course_enrolled2;
		while (cur){
			cout<<cur->data.course_name<<endl;
			cur = cur->course_next;
		}
		cout<<"Which course to view?";
		string s;
		cin>>s;
		while (view->data.course_name!=s){
			view = view->course_next;
		}
		cout<<view->final<<endl;
		cout<<view->midterm<<endl;
		cout<<view->other<<endl;
		cout<<view->total;
	}
	if (b->s_cur == 3){
		Node_course *view = a->ph_course_enrolled3;
		Node_course *cur = a->ph_course_enrolled3;
		while (cur){
			cout<<cur->data.course_name<<endl;
			cur = cur->course_next;
		}
		cout<<"Which course to view?";
		string s;
		cin>>s;
		while (view->data.course_name!=s){
			view = view->course_next;
		}
		cout<<view->final<<endl;
		cout<<view->midterm<<endl;
		cout<<view->other<<endl;
		cout<<view->total;
	}		
}
void viewScoreBoardOfAClass (Node_class *a, Node_year *b){
	Node_student *curStudent = a->ph_student;
	double totalGPA = 0;
	int countStudent = 0;
	while (curStudent){
		countStudent+=1;
		cout<<curStudent->data.first_name<<" ";
		if (b->s_cur == 1){
			Node_course *curEnrolled = curStudent->ph_course_enrolled1;
			double gpaCourse = 0;
			int cnt = 0;
			while (curEnrolled){
				cnt+=1;
				gpaCourse += curEnrolled->final;
				cout<<curEnrolled->data.course_name<<":";
				cout<<curEnrolled->final<<" ";
				curEnrolled = curEnrolled->course_next;
			}
			cout<<"GPA:"<<(double)gpaCourse/cnt<<endl;
			totalGPA += gpaCourse;
		}
		if (b->s_cur == 2){
			Node_course *curEnrolled = curStudent->ph_course_enrolled2;
			double gpaCourse = 0;
			int cnt = 0;
			while (curEnrolled){
				cnt+=1;
				gpaCourse += curEnrolled->final;
				cout<<curEnrolled->data.course_name<<":";
				cout<<curEnrolled->final<<" ";
				curEnrolled = curEnrolled->course_next;
			}
			cout<<"GPA:"<<(double)gpaCourse/cnt<<endl;
			totalGPA += gpaCourse;			
		}
		if (b->s_cur == 3){
			Node_course *curEnrolled = curStudent->ph_course_enrolled3;
			double gpaCourse = 0;
			int cnt = 0;
			while (curEnrolled){
				cnt+=1;
				gpaCourse += curEnrolled->final;
				cout<<curEnrolled->data.course_name<<":";
				cout<<curEnrolled->final<<" ";
				curEnrolled = curEnrolled->course_next;
			}
			cout<<"GPA:"<<(double)gpaCourse/cnt<<endl;
			totalGPA += gpaCourse;			
		}				
		curStudent = curStudent->student_next;
	}
	cout<<"Total GPA of this class: "<<(double)totalGPA/countStudent;
}
void updateScoreBoardOfACourse(Node_year *b){
	fstream fs;
	fs.open("CoursesData\\Semester " + to_string(b->s_cur) +"\\Courses.txt");
	while (!fs.eof()){
		string s;
		fs>>s;
		fstream fs1;
		fs1.open("CoursesData\\Semester " + to_string(b->s_cur ) + "\\" + s + ".csv");
		if (fs1.is_open()){
			while (!fs1.eof()){
				long mssv;
				double x,y,z,t;
				string ign;
				fs1.ignore();
				fs1.ignore();
				fs1>>mssv;
				Node_student *curStudent = find_node_student_for_login_account(mssv,b);
				if (curStudent == nullptr) break;
				fs1.ignore();
				getline(fs1,ign,',');
				fs1>>x;
				fs1.ignore();
				fs1>>y;
				fs1.ignore();
				fs1>>z;
				fs1.ignore();
				fs1>>t;
				fs1.ignore();
				updateStudentResult(curStudent,b,s,x,y,z,t);
				cout<<mssv<<endl;
				cout<<x<<" "<<y<<" "<<z<<" "<<t<<endl;
				sleep(2);
			}		
		}
		fs1.close();
	}
	fs.close();
}
bool check_year_name_appropriate(string year_name)
{
	int former = year_name[0] + year_name[1] + year_name[2] + year_name[3];
	int later = year_name[5] + year_name[6] + year_name[7] + year_name[8];
	if (year_name.length() == 9 && (later - former) == 1 && year_name[4] == '-')
		return 1;
	else return 0;
}
Node_student* find_node_student_for_login_account(long mssv, Node_year* ph_year)
{
	Node_student* student_choose = NULL;
	string year_name = "20" + to_string(mssv / 1000000) + "-" + "20" + to_string((mssv / 1000000) + 1);
	string chatluong[8] = { "NULL","NULL","NULL","NULL","NULL","APCS","VP","CLC" };
	string class_name = to_string(mssv / 1000000) + chatluong[(mssv / 1000) % 10];
	Node_year* year_choose = find_year_by_name(ph_year, year_name);
	if (year_choose == NULL)
	{
		cout << "School year has not been created!\n";
		return NULL;
	}
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
		cout << "Class has not been created!\n";

	return student_choose;
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
void enroll_course(Node_student* student_login, Node_year* current_year)
{
	print_semester(current_year->ph_semester);
	int no_semester;
	cout << "Choose a semester: "; cin >> no_semester;
	Node_semester* semester_choose = find_semester(current_year->ph_semester, to_string(no_semester));
	int no_course;
	//Choose ph_enrolled_course 1,2,3 
	Node_course** ph_course_enrolled{};
	if (semester_choose->semester_no == "Semester 1")
		ph_course_enrolled = &(student_login->ph_course_enrolled1);
	if (semester_choose->semester_no == "Semester 2")
		ph_course_enrolled = &(student_login->ph_course_enrolled2);
	if (semester_choose->semester_no == "Semester 3")
		ph_course_enrolled = &(student_login->ph_course_enrolled3);
	do
	{
		if (check_not_over_5_enrolled_course(*ph_course_enrolled))
		{
			print_course(semester_choose->ph_course);
			cout << "0.Quit\n";
			cout << "Choose a course: "; cin >> no_course;
			Node_course* course_choose = find_course(semester_choose->ph_course, no_course);
			if (check_not_over_max_student_in_a_course(course_choose->ph_student_enrolled, course_choose->data.max_num_student))
				if (check_course_sessions(course_choose, *ph_course_enrolled))// check xem có bị trùng giờ học không?
				{
					cout << "Enrolling succeeded!\n";
					add_enrolled_course(*ph_course_enrolled, course_choose);
					add_enrolled_student(course_choose->ph_student_enrolled, student_login);
				}
				else cout << "Your chosen course has conflicting sessions with your enrolled courses!\n";
			else cout << "Course reaches limitation of students";
		}
		else
		{
			cout << "You can not enrolled more than 5 courses\n";
			break;
		}
	
	} while (no_course != 0);

}
void menu_for_teacher(Node_year*& ph_year, Node_year*& current_year)
{
	string year_name;
	int choice;
	//giao diện menu
	do {
		cout << "1.Create year\n" << "2.Show years\n" << "3.Choose Year\n" << "0.Quit\n" << "Your option: "; cin >> choice;
		if (choice == 1)
		{
			do
			{
				cout << "Type year name(Ex: 2021-2022): ";
				cin >> year_name;
				if (check_year_name_appropriate(year_name))
					cout << "Accepted!\n";
				else cout << "Not Accepted!\n";
			} while (check_year_name_appropriate(year_name) != 1);
			cout << "Have been create: " << year_name << endl;
			add_year(ph_year, year_name, current_year);

		}
		if (choice == 2)
			print_year(ph_year);
		if (choice == 3)
		{
			print_year(ph_year);
			int year_no;
			Node_year* year_choose;
			do
			{
				cout << "Choose year to add more information: "; cin >> year_no;
				year_choose = find_year(ph_year, year_no);
				if (year_choose == NULL)
					cout << "Year not exists or not found!\n";
			} while (year_choose == NULL);

			int choices;
			/////////////////////////////////////////////////////////
			do
			{
				cout << "1.Create class\n" << "2.Delete class\n" << "3.Add Students\n" << "4.Add Semester\n"<< "5.Add Course\n" << "6.Delete Course\n" <<"7.Add scoreboard\n"<<"8.View scoreboard of a course\n"<<"0.Quit\n";
				cin >> choices;
				//Create class
				if (choices == 1)
				{

					add_class(year_choose->ph_classes);
				}
				//Delete class
				if (choices == 2)
				{
					if (year_choose->ph_classes != NULL)
					{
						print_class(year_choose->ph_classes);
						int class_no;
						Node_class* class_choose;
						do
						{
							cout << "Choose class to delete: "; cin >> class_no;
							class_choose = find_class(year_choose->ph_classes, class_no);
							if (class_choose == NULL)
								cout << "Class not exists or not found!\n";
						} while (class_choose == NULL);
						delete_specific_class(year_choose->ph_classes, class_choose);
					}
					else cout << "There is no any class to delete\n";
				}
				//Add Students
				if (choices == 3)
				{
					print_class(year_choose->ph_classes);
					int class_no;
					Node_class* class_choose;
					do
					{
						cout << "Choose class to add students form file.csv: "; cin >> class_no;
						class_choose = find_class(year_choose->ph_classes, class_no);
						if (class_choose == NULL)
							cout << "Class not exists or not found!\n";
					} while (class_choose == NULL);

					add_1st_student(class_choose->ph_student, class_choose->name, year_choose->name);
				}
				//Add semester
				if (choices == 4)
				{
					if (year_choose->ph_semester == NULL)
						add_semester(year_choose->ph_semester);
					else cout << "Semesters have been created\n";
				}
				//Add course
				if (choices == 5)
				{
					if (year_choose->ph_semester != nullptr)
					{
						print_semester(year_choose->ph_semester);
						Node_semester* semester_choose;
						string no;
						do
						{
							cout << "Choose no: "; cin >> no;
							semester_choose = find_semester(year_choose->ph_semester, no);
							if (semester_choose == NULL)
								cout << "Semester not exists or not found!\n";
						} while (semester_choose == NULL);

						add_course(semester_choose->ph_course, semester_choose->semester_no, year_choose->name);
					}
					else cout << "No semester has been created\n";
					
				}
				//Delete course
				if (choices == 6)
				{
					if (year_choose->ph_semester != nullptr)
					{
						print_semester(year_choose->ph_semester);
						Node_semester* semester_choose;
						string semester_no;
						do
						{
							cout << "Choose no: "; cin >> semester_no;
							semester_choose = find_semester(year_choose->ph_semester, semester_no);
							if (semester_choose == NULL)
								cout << "Semester not exists or not found!\n";
						} while (semester_choose == NULL);

						if (semester_choose->ph_course != NULL)
						{
							print_course(semester_choose->ph_course);
							int course_no;
							Node_course* course_choose;
							do
							{
								cout << "Choose course to delete: "; cin >> course_no;
								course_choose = find_course(semester_choose->ph_course, course_no);
								if (course_choose == NULL)
									cout << "Course not exists or not found!\n";
							} while (course_choose == NULL);
							delete_specific_course(semester_choose->ph_course, course_choose);
						}
						else cout << "There is no any course to delete\n";
					}
					else cout << "No semester has been created";
				}
				if (choices == 7){
					updateScoreBoardOfACourse(current_year);
				}
				if (choices == 8){
					viewScoreBoardOfACourse(current_year);
				}					
			} while (choices != 0);

		}

	} while (choice != 0);
}
void menu_for_student(long a, Node_year* ph_year, Node_year* current_year)
{
	Node_student* student_login = find_node_student_for_login_account(a, ph_year);
	if (student_login == NULL)
	{
		cout << "Can not find your data!\nPlease contact for supporting\n";
		return;
	}
	else
		cout << "Loading your profile completed!\n";
	int choice;
	do
	{
		cout << "1.Enroll course\n" << "2.View a list of enrolled courses\n" << "3.Delete an enrolled course\n"<<"4. View your scoreboard\n"<< "0.Quit\n" << "Your option:";
		cin >> choice;
		if (choice == 1)
		{
			enroll_course(student_login, current_year);
		}
		else if (choice == 2) {
			print_enrolled_course(student_login);
		}
		else if (choice == 3) {
			deleteEnrolledCourse(student_login);
		}
		else if (choice == 4){
			viewScoreBoardByStudent(student_login,current_year);
		}
	} while (choice != 0);

}
bool login(long a) {
	fstream fs; string s;
	cout << "Enter Password: "; cin >> s;
	string b = to_string(a);
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
	{
		cout << "Login succeeded as student!\n";
		return 1;
	}
	else
	{
		cout << "Failed login!\n";
		return 0;
	}
}
int main()
{
	Node_year* ph_year = NULL;
	Node_year* current_year = NULL;
	int choice;
	do
	{
		cout << "1.Login\n" << "2.Giao vu\n" << "0.Quit\n" << "Your option: ";
		cin >> choice;
		if (choice == 1)
		{
			long a;
			cout << "Nhap MSSV: ";
			cin >> a;
			if (login(a))
				menu_for_student(a, ph_year, current_year);
		}
		if (choice == 2)
			menu_for_teacher(ph_year, current_year);
	} while (choice != 0);

	deallocate_all_node(ph_year);
//	fstream fs;
//	printExistedCourses(fs);
	return 0;
}
