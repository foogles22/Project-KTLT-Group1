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
