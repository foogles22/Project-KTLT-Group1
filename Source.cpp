void deleteEnrolledCourse(Node_student*& student, Node_year*& current_year) {
	if (student->ph_course_enrolled1 == NULL && student->ph_course_enrolled2 == NULL && student->ph_course_enrolled3 == NULL)
	{
		print_double_square(30, 10, 37, 3, 15, "You have not enrolled in any course");
		return;
	}
	Node_course** ph_course_enrolled{};

	if (current_year->semestercount == 1)
		ph_course_enrolled = &(student->ph_course_enrolled1);
	if (current_year->semestercount == 2)
		ph_course_enrolled = &(student->ph_course_enrolled2);
	if (current_year->semestercount == 3)
		ph_course_enrolled = &(student->ph_course_enrolled3);

	viewCourse_Student(student, current_year);
	print_type_in_box(30, 10, "Choose a course to delete", 5);
	int x;
	cin >> x;
	Node_course* course_choose = find_course(*ph_course_enrolled, x);
	string name_tmp = course_choose->data.course_name;
	if (course_choose != NULL)
	{
		delete_specific_course(*ph_course_enrolled, course_choose);
		print_double_square(30, 15, 34, 3, 15, "Delete enrolled course succeeded");
		Node_semester* semester_choose{};
		Node_course* course_choose_del{};
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
