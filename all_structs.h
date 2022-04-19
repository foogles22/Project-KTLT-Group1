#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;

struct COURSE_DATA;
struct Node_course;
struct Node_semester;
struct SINHVIEN;
struct Node_student;
struct Node_class;
struct Node_year;
struct teacher;

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
	string name;
	Node_year* year_next;
	Node_class* ph_classes = nullptr;
	Node_semester* ph_semester = nullptr;
};
struct Node_teacher
{
	string mail, fullname, date, cccd, pass;
	Node_teacher* teacher_next;
};
void updateScoreBoardOfACourse(Node_year* b);
void viewScoreBoardOfAClass(Node_class* a, Node_year* b);
void viewScoreBoardByStudent(Node_student* a, Node_year* b);
void viewScoreBoardOfACourse(Node_year* a);
void viewCourse_Student(Node_student* student_login, Node_year* current_year);
void export_studentIncourse_to_csv(Node_course* ph_course, Node_year* current_year);
void deallocate_student(Node_student*& ph_student);
void deallocate_class(Node_class*& ph_class);
void deallocate_semester(Node_semester*& ph_semester);
void deallocate_course(Node_course*& ph_course);
void deallocate_all_node(Node_year*& ph_year);
void delete_specific_class(Node_class*& ph_class, Node_class* pdel_class);
void delete_specific_course(Node_course*& ph_course, Node_course* pdel_course);
void delete_specific_student(Node_student*& ph_student, Node_student* pdel_student);
void deleteEnrolledCourse(Node_student*& student, Node_year*& current_year);
void reset_student(Node_year* ph_year);
void add_1st_student(Node_student*& ph_student, string class_name, string year_name);
void add_semester(Node_semester*& ph_semester);
void add_course(Node_course*& ph_course, string semester_no, string year_name, bool view);
void add_class(Node_class*& ph_class, string class_name);
void add_year(Node_year*& ph_year, string year_name, Node_year*& current_year);
void add_teacher(Node_teacher*& ph_teacher);
void gotoXY(SHORT posX, SHORT posY);
void textColor(int color);
void print_Login_logo(int x1, int y1);
void print_Viennen(int length, int width);
void print_duongthang(int x1, int y1, int length);
void print_duongngang(int x1, int y1, int lenght);
void print_double_square(int x1, int y1, int length, int width, int color, string text);
void print_fill_square(int x1, int y1, int length, int width, int color, string text);
void print_type_in_box(int x1, int y1, string text, int size);
void text(int x, int y, string text, bool led, int color);
void print_current_time(int x, int y);
void check_time_for_semester(Node_year*& current_year);
void print_semester_start_end_time(Node_year* current_year);
bool check_time_regis(Node_year*& current_year);
bool check_year_end(Node_year*& current_year);
bool check_not_end_semester(Node_year*& current_year, bool view);
void changePassword(Node_student*& a);
void teacher_change_password(Node_teacher* teacher_login);
void print_student_section(int choose);
void print_year_section(int choose);
void print_teacher_setting_section(int choose);
void print_after_year_section(int choose, string year_name);
void print_teacher_after_creating_year_menu(Node_year*& year_choose, Node_teacher* teacher_login);
void print_teacher_creating_year_menu(Node_year*& ph_year, Node_year*& current_year, Node_teacher* teacher_login);
void print_menu_for_student(long a, Node_year*& ph_year, Node_year*& current_year);
void print_teacher_setting(Node_year*& ph_year, Node_year*& current_year, Node_teacher* teacher_login, Node_teacher* ph_teacher);
void print_username_password(int choose);
int login(string a, string s1);
void print_login_status(int x1, int y1, bool succeed);
void print_login_section(Node_year*& ph_year, Node_year*& current_year);
void print_class(Node_class* ph_class);
void print_year(Node_year* ph_year);
void print_semester(Node_semester* ph_semester);
void print_course(Node_course* ph_course);
void viewListofcourse(Node_course* ph_course);
void viewCourse_Student(Node_student* student_login, Node_year* current_year);
void viewAllClass(Node_year* year);
void viewAllStudentInAClass(Node_student* ph_student);
void viewListofstudentsincourse(Node_student* ph_student);
void view_profile_teacher(Node_teacher* teacher_login);
void view_profile_student(Node_student* student_login);
void export_studentIncourse_to_csv(Node_course* ph_course, Node_year* current_year);
void updateStudentResult(Node_student*& a, Node_year* b, string s, double x, double y, double z, double t);
void viewScoreBoardOfACourse(Node_year* a);
void viewScoreBoardByStudent(Node_student* a, Node_year* b);
void viewScoreBoardOfAClass(Node_class* a, Node_year* b);
void updateScoreBoardOfACourse(Node_year* b);
void add_enrolled_course(Node_course*& ph_course_enrolled, Node_course* enrolled_course);
void add_enrolled_student(Node_student*& ph_student_enrolled, Node_student* enrolled_student);
bool check_course_sessions(Node_course* course_enrolled, Node_course* ph_course_enrolled);
bool check_not_over_5_enrolled_course(Node_course* ph_enrolled_course);
bool check_not_over_max_student_in_a_course(Node_student* ph_student_enrolled, int max);
void enroll_course(Node_student* student_login, Node_year*& current_year);
bool check_year_name_appropriate(string year_name);
bool check_year_duplicate(Node_year* ph_year, string year_name);
bool check_class_duplicate(Node_class* ph_class, string class_name);
bool check_course_duplicate(Node_course* ph_course, string course_name);
void savePassword(Node_year* a);
void saveStudentData(Node_year* ph_year, Node_year* current_year);
void loadFile(Node_year*& ph_y, Node_year*& current_year);
void saveTeacherData(Node_teacher*& head);
void ingiaodien_creating_year(Node_year* current_year, Node_year* ph_year, int choose, Node_teacher* teacher_login);
void ingiaodien_after_creating_year(Node_year* year_choose, int choose, Node_teacher* teacher_login);
void ingiaodien_student(Node_year* current_year, Node_year* ph_year, Node_student* student_login, int choose);
void ingiaodien_setting(Node_year* current_year, Node_year* ph_year, int choose, Node_teacher* teacher_login);
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
Node_class* find_class_by_name(Node_class* ph_class, string class_name);
Node_year* find_year(Node_year* ph_year, int year_no);
Node_class* find_class(Node_class* ph_class, int class_no);
Node_semester* find_semester(Node_semester* ph_semester, string semester_no_tmp);
Node_course* find_course(Node_course* ph_course, int course_no);
Node_course* find_course_byname(Node_course* ph_course, string course_name);
Node_year* find_year_by_name(Node_year* ph_year, string year_name);
Node_student* find_student_by_id(Node_student* ph_student, string id);
Node_student* find_node_student_for_login_account(long mssv, Node_year* ph_year);
Node_teacher* find_teacher_login(string mail, Node_teacher* ph_teacher);



