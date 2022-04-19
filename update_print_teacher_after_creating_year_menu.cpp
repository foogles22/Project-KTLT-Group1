void print_teacher_after_creating_year_menu(Node_year*& year_choose)
{
	int choose = 1;	char move;
	do {
		system("CLS");
		print_after_year_section(choose, year_choose->name);
		do {
			ingiaodien_after_creating_year(year_choose, choose);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 7)
					choose++;
		} while (move != 13);

		if (choose == 1)
		{
			string class_name;
			print_type_in_box(30, 10, "Type class name", 11);
			cin >> class_name;
			if (check_class_duplicate(year_choose->ph_classes, class_name))
			{
				add_class(year_choose->ph_classes, class_name);
				print_double_square(30, 15, 25, 3, 15, "Create class succeeded");
			}
			else print_double_square(30, 15, 15, 3, 15, "Not accepted!");
			_getch();
		}
		//Delete class
		if (choose == 2)
		{
			if (year_choose->ph_classes != NULL)
			{
				print_class(year_choose->ph_classes);
				char class_no_char;
				int class_no;
				Node_class* class_choose;
				do
				{
					print_type_in_box(30, 10, "Type class number", 5);
					cin >> class_no_char;
					if (class_no_char < 48 || class_no_char > 57)
						return;
					class_no = class_no_char - 48;
				} while (class_no >= 1 && class_no <= count_class(year_choose->ph_classes));

				class_choose = find_class(year_choose->ph_classes, class_no);
				if (class_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Class not exists or not found!");
				if (class_choose != nullptr)
				{
					delete_specific_class(year_choose->ph_classes, class_choose);
					print_double_square(30, 15, 32, 3, 15, "Delete class succeeded!");
				}
			}
			else print_double_square(30, 10, 33, 3, 15, "There is no any class to delete");
			_getch();
		}
		//Add Students
		if (choose == 3)
		{
			if (year_choose->ph_classes != NULL)
			{
				print_class(year_choose->ph_classes);
				int class_no;
				Node_class* class_choose;

				print_type_in_box(30, 10, "Choose class to add students", 5);
				char class_no_char;
				cin >> class_no_char;
				if (class_no_char < 48 || class_no_char >57)
					return;
				class_no = class_no_char - 48;
				class_choose = find_class(year_choose->ph_classes, class_no);
				if (class_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Class not exists or not found!");
				if (class_choose != NULL)
					add_1st_student(class_choose->ph_student, class_choose->name, year_choose->name);

			}
			else print_double_square(30, 10, 31, 3, 15, "There is no any class to add");
			_getch();
		}
		//Add semester
		if (choose == 4)
		{
			if (year_choose->ph_semester == NULL)
			{
				print_double_square(30, 10, 28, 3, 15, "Create semesters succeeded");
				add_semester(year_choose->ph_semester);
			}
			else print_double_square(30, 10, 29, 3, 15, "Semesters have been created");
			_getch();
		}
		//Add course
		if (choose == 5)
		{
			if (year_choose->ph_semester != nullptr)
			{
				print_semester(year_choose->ph_semester);
				Node_semester* semester_choose;
				string no;

				print_type_in_box(30, 10, "Choose semester number", 5);
				char no_char;
				cin >> no_char;
				if (no_char < 48 || no_char > 57)
					return;
				no = no_char - 48;
				semester_choose = find_semester(year_choose->ph_semester, no);
				if (semester_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Semester not exists or not found!");
				if (semester_choose != NULL)
				{
					add_course(semester_choose->ph_course, semester_choose->semester_no, year_choose->name);
					print_double_square(30, 15, 26, 3, 15, "Create courses succeeded");
				}
			}
			else print_double_square(30, 10, 30, 3, 15, "No semester has been created");
			_getch();
		}
		//Delete course
		if (choose == 6)
		{
			if (year_choose->ph_semester != nullptr)
			{
				print_semester(year_choose->ph_semester);
				Node_semester* semester_choose;
				string semester_no;

				print_type_in_box(30, 10, "Choose semester number", 5);
				char semester_no_char;
				cin >> semester_no_char;
				if (semester_no_char, 48 || semester_no_char > 57)
					return;
				semester_no = semester_no_char - 48;
				semester_choose = find_semester(year_choose->ph_semester, semester_no);
				if (semester_choose == NULL)
					print_double_square(30, 15, 32, 3, 15, "Semester not exists or not found!");
				if (semester_choose != NULL)
					if (semester_choose->ph_course != NULL)
					{
						print_course(semester_choose->ph_course);
						int course_no;
						Node_course* course_choose;

						print_type_in_box(30, 15, "Choose course to delete", 5);
						char course_no_char;
						cin >> course_no_char;
						if (course_no_char < 48 || course_no_char > 57)
							return;
						course_no = course_no_char - 48;
						course_choose = find_course(semester_choose->ph_course, course_no);
						if (course_choose == NULL)
							print_double_square(30, 20, 33, 3, 15, "Course not exists or not found!");
						if (course_choose != NULL)
						{
							delete_specific_course(semester_choose->ph_course, course_choose);
							print_double_square(30, 20, 25, 3, 15, "Delete course succeeded");
						}
					}
					else print_double_square(30, 15, 35, 3, 15, "There is no any course to delete!");
			}
			else print_double_square(30, 10, 30, 3, 15, "No semester has been created");
			_getch();
		}

	} while (choose != 7);
}