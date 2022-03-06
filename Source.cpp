#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


struct Node_student
{
	//No, Student ID, First name, Last name, Gender, Date of Birth, Social ID.
	string No, ID, first_name, lastname, gender, date_of_birth, social_ID;
	Node_student* student_next;
};
struct Node_class
{
	string name;
	Node_class* class_next;
	Node_student* ph_student;
};
struct Node_year
{
	string name;
	Node_year* year_next;
	Node_class* ph_classes;
};
void print_class(Node_class* ph_class)
{
	Node_class* pc_class = ph_class;
	while (pc_class != NULL)
	{
		cout << pc_class->name << endl;
		pc_class = pc_class->class_next;
	}
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
Node_year* find_year(Node_year* ph_year, string year_name)
{
	Node_year* pc_year = ph_year;
	while (pc_year->name != year_name)
		pc_year = pc_year->year_next;
	return pc_year;
}

Node_class* find_class(Node_class* ph_class, string class_name)
{
	Node_class* pc_class = ph_class;
	while (pc_class->name != class_name)
		pc_class = pc_class->class_next;
	return pc_class;
}
void add_year(Node_year*& ph_year, string year_name)
{
	Node_year* tmp = new Node_year;
	tmp->name = year_name;
	tmp->ph_classes = NULL;
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
void add_1st_student(Node_student*& ph_student)
{
	ifstream read("csv.txt", ios::in);
	int n; read >> n;
	Node_student* pc_student = ph_student;
	for (int i = 0; i < n; i++)
	{
		Node_student* tmp = new Node_student;
		read >> tmp->No >> tmp->ID >> tmp->first_name >> tmp->lastname >> tmp->gender >> tmp->date_of_birth >> tmp->social_ID;
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
	pc_student = ph_student;
	while (pc_student != NULL)
	{
		cout << pc_student->No << endl << pc_student->ID << endl << pc_student->first_name << endl << pc_student->lastname << endl << pc_student->gender << endl << pc_student->date_of_birth << endl << pc_student->social_ID << endl;
		pc_student = pc_student->student_next;
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
			cout << "Choose year: "; cin >> year_name;
			Node_year* year_choose = find_year(ph_year, year_name);
			int choices;

			do
			{
				cout << "1.Create class" << endl << "2.Add Students" << endl;
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
			} while (choice != 0);

		}

	} while (choice != 0);
}