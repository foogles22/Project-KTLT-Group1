void enroll_course(Node_student* student_login, Node_year*& current_year)
{
	char no_course_char;
	int no_course;
	Node_semester* semester_choose = nullptr;
	Node_course** ph_course_enrolled = nullptr;
	check_time_for_semester(current_year);
	cout << current_year->semestercount;
	if (current_year->semestercount == 1)
	{
		ph_course_enrolled = &student_login->ph_course_enrolled1;
		semester_choose = find_semester(current_year->ph_semester, to_string(1));
	}
	if (current_year->semestercount == 2)
	{
		ph_course_enrolled = &student_login->ph_course_enrolled2;
		semester_choose = find_semester(current_year->ph_semester, to_string(2));
	}
	if (current_year->semestercount == 3)
	{
		ph_course_enrolled = &student_login->ph_course_enrolled3;
		semester_choose = find_semester(current_year->ph_semester, to_string(3));
	}
	if (check_time_regis(current_year))
		if (check_not_over_5_enrolled_course(*ph_course_enrolled))
		{
			print_double_square(120, 15, 12, 3, 15, "Semester " + to_string(current_year->semestercount));
			viewListofcourse(semester_choose->ph_course);
			print_type_in_box(30, 10, "Choose a course", 5);
			cin >> no_course_char;
			if (no_course_char < 49 || no_course_char >57)
				return;
			no_course = no_course_char - 48;
			Node_course* course_choose = find_course(semester_choose->ph_course, no_course);
			if (check_not_over_max_student_in_a_course(course_choose->ph_student_enrolled, course_choose->data.max_num_student))
				if (check_course_sessions(course_choose, *ph_course_enrolled))// check xem có bị trùng giờ học không?
				{
					print_double_square(30, 15, 22, 3, 15, "Enrolling succeeded!");
					add_enrolled_course(*ph_course_enrolled, course_choose);
					add_enrolled_student(course_choose->ph_student_enrolled, student_login);
				}
				else print_double_square(30, 15, 79, 3, 15, "Your chosen course has conflicting sessions with your other enrolled courses!");
			else print_double_square(30, 15, 39, 3, 15, "Course reaches limitation of students");
		}
		else
		{
			print_double_square(30, 10, 42, 3, 15, "You can not enrolled more than 5 courses");
		}
}