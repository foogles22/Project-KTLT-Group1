#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
struct COURSE_DATA
{
	//course id, course name, teacher name, number of credits, the maximum number of students in the course(default 50), day of the week, and the session that the course will be performed(MON / TUE / WED / THU / FRI / SAT, S1(07:30), S2(09:30), S3(13:30) and S4(15:30)).A course will be taught in 2 sessions in a week
	int start_date, end_date;
	string id, course_name, teacher_name, number_of_credits, max_num_student, days_of_week, session1, session2;
};
struct Node_course
{
	COURSE_DATA data;
	Node_course* course_next;
};
struct Node_semester
{
	string semester_no;
	Node_course* ph_course;
	Node_semester* semester_next;
};
struct DATE
{
	int ngay;
	int thang;
	int nam;
};
struct SINHVIEN
{
	string No, ID, first_name, lastname, gender, social_ID, password;
	DATE date;
};
//Node sinh viên
struct Node_student
{
	SINHVIEN data;
	Node_student* student_next;
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
	string name;
	Node_year* year_next;
	Node_class* ph_classes;
	Node_semester* ph_semester;
};
//Hàm để in ra các lớp học
void print_class(Node_class* ph_class)
{
	Node_class* pc_class = ph_class;
	int i = 1;
	while (pc_class != NULL)
	{
		cout << i++ <<":" << pc_class->name << endl;
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
	Node_student *pc_student = ph_student;
	while (pc_student != NULL)
	{
		cout << pc_student->data.No << endl << pc_student->data.ID << endl << pc_student->data.first_name << endl << pc_student->data.lastname << endl << pc_student->data.gender << endl << pc_student->data.date.ngay << "/" << pc_student->data.date.thang << "/" << pc_student->data.date.nam << endl << pc_student->data.social_ID << endl;
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
Node_year* find_year(Node_year* ph_year, int year_no)
{
	if (ph_year == NULL)
		return NULL;
	Node_year* pc_year = ph_year;
	for (int i = 0; i < year_no-1 && pc_year != NULL ; i++, pc_year = pc_year->year_next);
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
	for (int i = 0; i < class_no-1 && pc_class != NULL; i++, pc_class = pc_class->class_next);
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
//Hàm để thêm năm học vào
void add_year(Node_year*& ph_year, string year_name)
{
	Node_year* tmp = new Node_year;
	tmp->name = year_name;
	tmp->ph_classes = NULL;
	tmp->ph_semester = NULL;
	tmp->year_next = NULL;
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
//Hàm để add ngày sinh
DATE add_birthday(ifstream& read)
{
	DATE date;
	read >> date.ngay;
	read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
	read >> date.thang;
	read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
	read >> date.nam;
	return date;
}
//Hàm để thêm hồ sơ các sinh viên năm nhất vào
void add_1st_student(Node_student*& ph_student, string class_name, string year_name)
{
	ifstream read("StudentData\\" + year_name + "\\" + class_name + ".csv");
	Node_student* pc_student = ph_student;
	while (!read.eof())
	{
		Node_student* tmp = new Node_student;
		getline(read, tmp->data.No, ','); 
		getline(read, tmp->data.ID, ','); 
		getline(read, tmp->data.first_name, ','); 
		getline(read, tmp->data.lastname, ','); 
		getline(read, tmp->data.gender, ','); 
		tmp->data.date = add_birthday(read); read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
		getline(read, tmp->data.social_ID);
		getline(read, tmp->data.password);
		tmp->student_next = NULL;
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
void add_semester(Node_semester*& ph_semester, int no)
{
	string semester_no_tmp = "Semester " + to_string(no);
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
void add_course(Node_course*& ph_course)
{
	//course id, course name, teacher name, number of credits, the maximum number of students in the course(default 50), day of the week, and the session that the course will be performed(MON / TUE / WED / THU / FRI / SAT, S1(07:30), S2(09:30), S3(13:30) and S4(15:30)).A course will be taught in 2 sessions in a week
	COURSE_DATA DATA;
	cout << "Course ID: "; cin >> DATA.id;
	cout << "Course Name: "; cin >> DATA.course_name;
	cout << "Teacher Name: "; cin >> DATA.teacher_name;
	cout << "Number of Credits: "; cin >> DATA.number_of_credits;
	cout << "The maximum number of students in the course(default 50): "; cin >> DATA.max_num_student;
	cout << "Day of the week: "; cin >> DATA.days_of_week;
	cout << "         MON / TUE / WED / THU / FRI / SAT\n" << "S1(07:30)\n" << "S2(09:30)\n" << "S3(13:30)\n" << "S4(15:30)\n";
	cout << "The session that the course will be performed(2 session in a week)\n" << "Session 1: "; 
	cin >> DATA.session1;
	do
	{ 
		cout << "Session 2:"; cin >> DATA.session2;

	} while (DATA.session1 == DATA.session2);
	cout << "Start date: "; cin >> DATA.start_date;
	cout << "End date: "; cin >> DATA.end_date;
	Node_course* tmp = new Node_course;
	tmp->data = DATA;
	tmp->course_next = NULL;
	if (ph_course == NULL)
	{
		ph_course = tmp;
	}
	else
	{
		Node_course* pc_course = ph_course;
		while (pc_course->course_next != NULL)
			pc_course = pc_course->course_next;
		pc_course->course_next = tmp;
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
void delete_specific_class(Node_class* &ph_class, Node_class* pdel_class)
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
void delete_specific_semester(Node_semester*& ph_semester, Node_semester* pdel_semester)
{
	deallocate_course(pdel_semester->ph_course);
	if (ph_semester == pdel_semester)
	{
		ph_semester = ph_semester->semester_next;
		delete pdel_semester;
		return;
	}
	Node_semester* pc_semester = ph_semester;
	while (pc_semester->semester_next != NULL && pc_semester->semester_next != pdel_semester)
	{
		pc_semester = pc_semester->semester_next;
	}
	pc_semester->semester_next = pc_semester->semester_next->semester_next;
	delete pdel_semester;
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
bool check_year_name_appropriate(string year_name)
{
	int former = year_name[0] + year_name[1] + year_name[2] + year_name[3];
	int later = year_name[5] + year_name[6] + year_name[7] + year_name[8];
	if (year_name.length() == 9 && (later - former) == 1 && year_name[4] == '-')
		return 1;
	else return 0;
}
int main()
{
	Node_year* ph_year = NULL;
	string year_name;
	int choice;
	//giao diện menu
	do {
		cout << "1.Create year" << endl << "2.Show years" << endl << "3.Choose Year" << endl << "Your option: "; cin >> choice;
		if (choice == 1)
		{
			do
			{
				cout << "Type year name(Ex: 2021-2020): ";
				cin >> year_name;
				if (check_year_name_appropriate(year_name))
					cout << "Accepted!\n";
				else cout << "Not Accepted!\n";
			} while (check_year_name_appropriate(year_name) != 1);
			cout << "Have been create: " << year_name << endl;
			add_year(ph_year, year_name);

		}
		if (choice == 2)
			print_year(ph_year);
		if (choice == 3)
		{
			print_year(ph_year);
			int year_no;
			int semester_num = 1;
			Node_year* year_choose;
			do 
			{
				cout << "Choose year to add more information: "; cin >> year_no;
				year_choose = find_year(ph_year, year_no);
				if (year_choose == NULL)
					cout << "Year not exists or not found!\n";
			} while (year_choose == NULL);
			
			int choices;
			do
			{
				cout << "1.Create class" << endl << "2.Delete class" << endl << "3.Add Students" << endl << "4.Add Semester" <<endl << "5.Delete Semester" << endl << "6.Add Course" << endl << "7.Delete Course\n";
				cin >> choices;
				//Create class
				if (choices == 1 )
				{

					add_class(year_choose->ph_classes);
				}
				//Delete class
				if (choices == 2 )
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
						if(class_choose == NULL)
							cout << "Class not exists or not found!\n";
					} while (class_choose == NULL);
					
					add_1st_student(class_choose->ph_student, class_choose->name, year_choose->name);
				}
				//Add semester
				if (choices == 4)
				{
					add_semester(year_choose->ph_semester, semester_num++);
				}
				//Delete semester
				if (choices == 5)
				{

				}
				//Add course
				if (choices == 6)
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
					
					add_course(semester_choose->ph_course);
				}
				//Delete course
				if (choices == 7)
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
			} while (choice != 0);

		}

	} while (choice != 0);
	deallocate_all_node(ph_year);
	return 0;
}

