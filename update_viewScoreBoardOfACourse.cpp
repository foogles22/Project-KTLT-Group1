void viewScoreBoardOfACourse(Node_year* a) {
	check_time_for_semester(a);
	fstream fs;
	fs.open("CoursesData\\Semester " + to_string(a->semestercount) + "\\Courses.txt");
	int i = 1;
	gotoXY(119, 11);
	cout << "LIST OF COURSES";
	while (!fs.eof()) {
		gotoXY(123, 12 + i);
		string s;
		fs >> s;
		cout << i++ << ":" << s << endl;
	}
	print_double_square(116, 10, 21, i + 3, 15, "\0");
	print_type_in_box(30, 20, "Choose a course", 5);
	char no_char;
	cin >> no_char;
	if (no_char < 48 || no_char > 57)
		return;
	int no = no_char - 48;
	fstream fs2;
	fs2.open("CoursesData\\Semester " + to_string(a->semestercount) + "\\Courses.txt");
	string s;
	while (no-- != 0)
		fs2 >> s;

	int i1 = 1;
	int i2 = i;
	fstream fs1;
	fs1.open("CoursesData\\Semester " + to_string(a->semestercount) + "\\" + s + ".csv");
	gotoXY(74, 15 + i);
	cout << "No     Student ID          FullName          Total Mark         Final Mark      Midterm Mark      Other Mark";
	while (!fs1.eof()) {
		string no, id, first_name, last_name, a, b, c, d;
		getline(fs1, no, ',');
		getline(fs1, id, ',');
		getline(fs1, first_name, ',');
		getline(fs1, last_name, ',');
		getline(fs1, a, ',');
		getline(fs1, b, ',');
		getline(fs1, c, ',');
		getline(fs1, d);
		gotoXY(74, 16 + i++);
		i1++;
		cout << no << "       ";
		cout << id << "       ";
		cout << first_name << " ";
		cout << last_name;
		for (int i = 0; i < 25 - (first_name.length() + last_name.length()); i++) cout << " ";
		cout << a; for (int i = 0; i < 19 - a.length(); i++) cout << " ";
		cout << b; for (int i = 0; i < 17 - b.length(); i++) cout << " ";
		cout << c; for (int i = 0; i < 17 - c.length(); i++) cout << " ";
		cout << d;
	}
	print_double_square(72, 15 + i2, 112, i1, 15, "\0");
	fs1.close();
	fs.close();
}