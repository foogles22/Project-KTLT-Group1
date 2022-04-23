#include "all_structs.h"

// Các hàm xóa các node
void deallocate_student(Node_student*& ph_student);
void deallocate_class(Node_class*& ph_class);
void deallocate_semester(Node_semester*& ph_semester);
void deallocate_course(Node_course*& ph_course);
void deallocate_student(Node_student*& ph_student)
{
	while (ph_student != NULL)
	{
		deallocate_course(ph_student->ph_course_enrolled1);
		deallocate_course(ph_student->ph_course_enrolled2);
		deallocate_course(ph_student->ph_course_enrolled3);
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
void deallocate_semester(Node_semester*& ph_semester)
{
	while (ph_semester != NULL)
	{
		deallocate_course(ph_semester->ph_course);
		Node_semester* pc_semester = ph_semester->semester_next;
		delete ph_semester;
		ph_semester = pc_semester;
	}
}
void deallocate_course(Node_course*& ph_course)
{
	while (ph_course != NULL)
	{
		deallocate_student(ph_course->ph_student_enrolled);
		Node_course* pc_course = ph_course->course_next;
		delete ph_course;
		ph_course = pc_course;
	}
}
void deallocate_all_node(Node_year*& ph_year)
{
	while (ph_year != NULL)
	{
		deallocate_class(ph_year->ph_classes);
		deallocate_semester(ph_year->ph_semester);
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
	char x1;
	cin >> x1;
	if (x1 > '9' || x1 < '1')
	{
		print_double_square(30, 15, 13, 3, 15, "Wrong input");
		return;
	}
	int x = x1 - 48;
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
void reset_student(Node_year* ph_year)
{
	Node_year* pc_year = ph_year;
	while (pc_year != NULL)
	{
		Node_class* pc_class = pc_year->ph_classes;
		while (pc_class != NULL)
		{
			Node_student* pc_student = pc_class->ph_student;
			while (pc_student != NULL)
			{
				pc_student->ph_course_enrolled1 = NULL; pc_student->ph_course_enrolled2 = NULL; pc_student->ph_course_enrolled3 = NULL;
				pc_student = pc_student->student_next;
			}
			pc_class = pc_class->class_next;
		}
		pc_year = pc_year->year_next;
	}
}