#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct COURSE_DATA
{
	//course id, course name, teacher name, number of credits, the maximum number of students in the course(default 50), day of the week, and the session that the course will be performed(MON / TUE / WED / THU / FRI / SAT, S1(07:30), S2(09:30), S3(13:30) and S4(15:30)).A course will be taught in 2 sessions in a week
	string id, course_name, teacher_name, number_of_credits, max_num_student, days_of_week;
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
	string No, ID, first_name, lastname, gender, social_ID;
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
	while (pc_class != NULL)
	{
		cout << pc_class->name << endl;
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
Node_year* find_year(Node_year* ph_year, string year_name)
{
	Node_year* pc_year = ph_year;
	while (pc_year->name != year_name)
		pc_year = pc_year->year_next;
	return pc_year;
}
//Hàm để tìm Node lớp học được chọn
Node_class* find_class(Node_class* ph_class, string class_name)
{
	Node_class* pc_class = ph_class;
	while (pc_class->name != class_name)
		pc_class = pc_class->class_next;
	return pc_class;
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
	//print classes
	print_class(ph_class);
}
//Hàm để add ngày sinh
DATE add_birthday(ifstream &read)
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
void add_1st_student(Node_student*& ph_student)
{
	ifstream read("csv.txt", ios::in);
	Node_student* pc_student = ph_student;
	int i = 2;
	while (i-- != 0)
	{
		Node_student* tmp = new Node_student;
		getline(read, tmp->data.No, ','); read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
		getline(read, tmp->data.ID, ','); read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
		getline(read, tmp->data.first_name, ','); read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
		getline(read, tmp->data.lastname, ','); read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
		getline(read, tmp->data.gender, ','); read.seekg(1, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
		tmp->data.date = add_birthday(read); read.seekg(2, 1); //dịch bit sang phải 1 byte để bỏ dấu ","
		getline(read, tmp->data.social_ID);
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
	//in ra thông tin sinh viên vừa mới add vào
	pc_student = ph_student;
	while (pc_student != NULL)
	{
		cout << pc_student->data.No << endl << pc_student->data.ID << endl << pc_student->data.first_name << endl << pc_student->data.lastname << endl << pc_student->data.gender <<  endl << pc_student->data.date.ngay << "/" << pc_student->data.date.thang << "/" << pc_student->data.date.nam <<endl <<pc_student->data.social_ID << endl;
		pc_student = pc_student->student_next;
	}
}
void add_semester(Node_semester* ph_semester, int no)
{
	string semester_no_tmp = "Semester " + to_string(no);
	Node_semester* tmp = new Node_semester;
	tmp->semester_no = semester_no_tmp;
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

int main()
{
	Node_year* ph_year = NULL;
	string year_name;
	int choice;
	do {
		cout << "1.Create year" << endl << "2.Show years" << endl << "3.Choose Year" << endl << "Your option: "; cin >> choice;
		if (choice == 1)
		{
			cout << "Type year name: "; cin >> year_name;
			cout << "Have been create: " << year_name << endl;
			add_year(ph_year, year_name);

		}
		if (choice == 2)
			print_year(ph_year);
		if (choice == 3)
		{
			print_year(ph_year);
			string year_name;
			int semester_num = 1;
			cout << "Choose year: "; cin >> year_name;
			Node_year* year_choose = find_year(ph_year, year_name);
			int choices;

			do
			{
				cout << "1.Create class" << endl << "2.Add Students" << "3.Add Semester" << endl;
				cin >> choices;
				if (choices == 1)
				{

					add_class(year_choose->ph_classes);
				}
				if (choices == 2)
				{
					print_class(year_choose->ph_classes);
					string class_name;
					cout << "Choose class: "; cin >> class_name;
					Node_class* class_choose = find_class(year_choose->ph_classes, class_name);
					add_1st_student(class_choose->ph_student);
				}
				if (choices == 3)
				{
					add_semester(year_choose->ph_semester, semester_num++);
				}
			} while (choice != 0);

		}

	} while (choice != 0);
}