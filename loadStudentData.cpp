#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;
time_t now;
bool update = 0;

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
	Node_course* course_next = 0;
	Node_student* ph_student_enrolled = 0;
};
struct Node_semester
{

	/*int start_date, end_date;
	int regis_start, regis_end;*/
	string semester_no;
	Node_course* ph_course = 0;
	Node_semester* semester_next = 0;
};
struct SINHVIEN
{
	string No, ID, first_name, lastname, gender, social_ID, password, date;
};
struct Node_student
{
	SINHVIEN data;
	Node_student* student_next = 0;
	Node_course* ph_course_enrolled1 = 0, * ph_course_enrolled2 = 0, * ph_course_enrolled3 = 0;
};
struct Node_class
{
	string name;
	Node_class* class_next = 0;
	Node_student* ph_student = 0;
};
struct Node_year
{
	int semestercount;
	bool end = 0;
	string name;
	Node_year* year_next;
	Node_class* ph_classes = 0;
	Node_semester* ph_semester = 0;
};

void loadFileStudent(Node_year *& ph_y){
	fstream fi;
	ph_y = 0;
	Node_year* yCur = ph_y;
	fi.open("D:\\CODE\\Project-KTLT-Group1-main\\StudentData\\CreatedYear.txt", ios::in);
	while(!fi.eof()){
		if(!ph_y){
			ph_y = new Node_year;
			fi >> ph_y->name;
			yCur = ph_y;
		}
		else{
			yCur->year_next = new Node_year;
			fi >> yCur->year_next->name;
			yCur = yCur->year_next;
			yCur->year_next = 0;
		}
	}
	fi.close();

	yCur = ph_y;
	Node_class* cCur = 0;
	fstream fiClass;
	while(yCur){
		fiClass.open("StudentData\\" + yCur->name.substr(2,2) + "\\CreatedClass.txt", ios::in);
		while(!fiClass.eof()){
			if(!yCur->ph_classes){
				yCur->ph_classes = new Node_class;
				fiClass >> yCur->ph_classes->name;
				//cout << yCur->ph_classes->name;
				cCur = yCur->ph_classes;
				yCur->ph_classes->class_next = 0;
			}
			else{
				cCur->class_next = new Node_class;
				fiClass >> cCur->class_next->name;
				//cout << cCur->name;
				cCur = cCur ->class_next;
				cCur->class_next = 0;
			}
		}
		yCur = yCur->year_next;
		fiClass.close();
	}

	fstream fiStudent;
	yCur = ph_y;
	Node_student* sCur;
	while(yCur){
		cCur = yCur->ph_classes;
		while(cCur){
			fiStudent.open("StudentData\\" + yCur->name.substr(2,2) + "\\" + cCur->name + ".csv", ios::in);
			while(!fiStudent.eof()){
				if(!cCur->ph_student){
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
				else{
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
					sCur = sCur ->student_next;
				}
			}
		cCur = cCur->class_next;
		fiStudent.close();
		}		
	yCur = yCur->year_next;
	fiStudent.close();
	}
}

void loadFileCourse(Node_year*& ph_y){
	fstream fStu;
	Node_year* yCur = ph_y;
	Node_semester* sCur;
	while(yCur){
		for(int i = 1; i < 4; ++i){
			fStu.open("StudentData\\" + yCur->name.substr(2,2) + "\\Semester " + to_string(i) + ".txt", ios::in);
			if(!fStu.is_open());
			else{
				if(!yCur->ph_semester){
					yCur->ph_semester = new Node_semester;
					yCur->ph_semester->semester_no = "Semester " + to_string(i);
					yCur->ph_semester->semester_next = 0;
					sCur = yCur->ph_semester;
				}
				else{
					sCur->semester_next = new Node_semester;
					sCur->semester_next->semester_no = "Semester " + to_string(i);
					sCur->semester_next->semester_next = 0;
					sCur = sCur->semester_next;
				}
			}
			fStu.close();
		}
		yCur = yCur->year_next;
	}
	fStu.close();

	fstream fCourse;
	yCur = ph_y;
	Node_course* cCur;
	while(yCur){
		sCur = yCur->ph_semester;
		while(sCur){
			fCourse.open("StudentData\\" + yCur->name.substr(2,2) + "\\" + sCur->semester_no + ".txt", ios::in);
			while(!fCourse.eof()){
				if(!sCur->ph_course){
					sCur->ph_course = new Node_course;
					fCourse >> sCur->ph_course->data.id;
					fCourse >> sCur->ph_course->data.course_name;
					fCourse >> sCur->ph_course->data.teacher_name;
					fCourse >> sCur->ph_course->data.number_of_credits;
					fCourse >> sCur->ph_course->data.max_num_student;
					fCourse >> sCur->ph_course->data.days_of_week;
					fCourse >> sCur->ph_course->data.session1;
					fCourse >> sCur->ph_course->data.session2;
					cCur = sCur->ph_course;
				}
				else{
					cCur->course_next = new Node_course;
					fCourse >> cCur->course_next->data.id;
					fCourse >> cCur->course_next->data.course_name;
					fCourse >> cCur->course_next->data.teacher_name;
					fCourse >> cCur->course_next->data.number_of_credits;
					fCourse >> cCur->course_next->data.max_num_student;
					fCourse >> cCur->course_next->data.days_of_week;
					fCourse >> cCur->course_next->data.session1;
					fCourse >> cCur->course_next->data.session2;
					cCur->course_next->course_next = 0;
					cCur = cCur->course_next;
				}
			}
			fCourse.close();
		sCur = sCur->semester_next;
		}
		yCur = yCur->year_next;
	}

}

int main(){
	Node_year* y = 0;
	loadFileStudent(y);
	loadFileCourse(y);
	while(y){
		while(y->ph_semester){
			cout << y->ph_semester->semester_no;
			y->ph_semester = y->ph_semester->semester_next;
		}
		y = y->year_next;
	}

	return 0;
}
