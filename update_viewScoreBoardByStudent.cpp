void viewScoreBoardByStudent(Node_student* a, Node_year* b) {
	// use find_node_student_for_login_account function to Node student a
	Node_course* view = nullptr;
	check_time_for_semester(b);
	if (b->semestercount == 1)
		view = a->ph_course_enrolled1;
	if (b->semestercount == 2)
		view = a->ph_course_enrolled2;
	if (b->semestercount == 3)
		view = a->ph_course_enrolled3;

	print_course(view);
	print_type_in_box(30, 10, "Choose a course", 5);
	char no_char;
	cin >> no_char;
	if (no_char < 48 || no_char > 57)
		return;
	int no = no_char - 48;
	view = find_course(view, no);

	gotoXY(80, 32);
	cout << "Student ID          Fullname          Total Mark       Final Mark       Midterm Mark       Other Mark";
	gotoXY(81, 33);
	cout << a->data.ID;
	for (int i = 0; i < 6; i++) cout << " ";
	cout << a->data.first_name << " ";
	cout << a->data.lastname;
	for (int i = 0; i < 27 - (a->data.first_name.length() + a->data.lastname.length()); i++) cout << " ";
	cout << view->total << "               ";
	cout << view->final << "                 ";
	cout << view->midterm << "                  ";
	cout << view->other;
	print_double_square(79, 32, 103, 2, 15, "\0");

}