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
