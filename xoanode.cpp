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
		Node_semester* pc_semester= ph_semester->semester_next;
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