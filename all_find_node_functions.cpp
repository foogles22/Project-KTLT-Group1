#include "all_structs.h"

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

	return pc_year;
}
Node_class* find_class(Node_class* ph_class, int class_no)
{
	if (ph_class == NULL)
		return NULL;
	Node_class* pc_class = ph_class;
	for (int i = 0; i < class_no - 1 && pc_class != NULL; i++, pc_class = pc_class->class_next);

	return pc_class;
}
Node_semester* find_semester(Node_semester* ph_semester, string semester_no_tmp)
{
	if (ph_semester == NULL)
		return NULL;
	semester_no_tmp = "Semester " + semester_no_tmp;
	Node_semester* pc_semester = ph_semester;
	while (pc_semester != NULL && pc_semester->semester_no != semester_no_tmp)
		pc_semester = pc_semester->semester_next;

	return pc_semester;
}
Node_course* find_course(Node_course* ph_course, int course_no)
{
	if (ph_course == NULL)
		return NULL;
	Node_course* pc_course = ph_course;
	for (int i = 0; i < course_no - 1 && pc_course != NULL; i++, pc_course = pc_course->course_next);

	return pc_course;
}
Node_course* find_course_byname(Node_course* ph_course, string course_name)
{
	if (ph_course == NULL)
		return NULL;
	Node_course* pc_course = ph_course;
	while (pc_course != NULL && pc_course->data.course_name != course_name)
		pc_course = pc_course->course_next;
	return pc_course;
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
Node_teacher* find_teacher_login(string mail, Node_teacher* ph_teacher)
{
	Node_teacher* pc_teacher = ph_teacher;
	while (pc_teacher != NULL && pc_teacher->mail != mail)
		pc_teacher = pc_teacher->teacher_next;
	return pc_teacher;
}