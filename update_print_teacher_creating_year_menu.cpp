void print_teacher_creating_year_menu(Node_year*& ph_year, Node_year*& current_year)
{
	string year_name;
	int choose = 1;	char move;

	do {
		system("CLS");
		print_year_section(choose);
		do {
			ingiaodien_creating_year(current_year, ph_year, choose);
			move = _getch();
			if (move == 'w' || move == 72)
				if (choose > 1)
					choose--;
			if (move == 's' || move == 80)
				if (choose < 9)
					choose++;
		} while (move != 13);
		//Create year
		if (choose == 1)
		{
			if (ph_year == NULL || check_year_end(current_year))
			{
				print_double_square(30, 10, 33, 3, 15, "Type year name(Ex: 2021-2022)");
				print_double_square(63, 10, 13, 3, 15, "\0");
				gotoXY(65, 11);
				cin >> year_name;
				if (check_year_name_appropriate(year_name) && check_year_duplicate(ph_year, year_name))
				{
					print_double_square(30, 15, 13, 3, 15, "Accepted!");
					string text = "Have been created: " + year_name;
					print_double_square(43, 15, 33, 3, 15, text);
					add_year(ph_year, year_name, current_year);
					reset_student(ph_year);
				}
				else print_double_square(30, 15, 15, 3, 15, "Not Accepted!");
			}
			_getch();
		}
		//Continue
		if (choose == 2 && ph_year != NULL)
		{
			print_teacher_after_creating_year_menu(current_year);
			continue;
		}
		//View class
		if (choose == 3 && ph_year != NULL)
		{
			if (ph_year->ph_classes != NULL)
				viewAllClass(ph_year);
			else print_double_square(30, 10, 31, 3, 15, "There is no any class to view");
			_getch();
		}
		//View student
		if (choose == 4 && ph_year != NULL)
		{
			int choose;
			print_double_square(30, 10, 28, 3, 15, "1.View students in a class");
			print_double_square(30, 15, 29, 3, 15, "2.View students in a course");
			print_type_in_box(30, 20, "Your option", 5);
			char choose_char;
			cin >> choose_char;
			if (choose_char < 48 || choose_char > 57)
				return;
			choose = choose_char - 48;
			if (choose == 1)
			{
				if (ph_year->ph_classes != NULL)
				{
					int class_no;
					int year_no;
					viewAllClass(ph_year);
					print_type_in_box(30, 25, "Choose a school year", 5);
					char year_no_char;
					cin >> year_no_char;
					if (year_no_char < 48 || year_no_char > 57)
						return;
					year_no = year_no_char - 48;
					Node_year* year_choose = find_year(ph_year, year_no);
					print_type_in_box(30, 30, "Choose a class", 5);
					char class_no_char;
					cin >> class_no_char;
					if (class_no_char < 48 || class_no_char > 57)
						return;
					class_no = class_no_char - 48;
					Node_class* class_choose = find_class(year_choose->ph_classes, class_no);
					if (class_choose == NULL)
						print_double_square(30, 35, 32, 3, 15, "Class not exists or not found!");
					if (class_choose != NULL)
						if (class_choose->ph_student != NULL)
							viewAllStudentInAClass(class_choose->ph_student);
						else print_double_square(30, 35, 40, 3, 15, "This class has not been added students");
				}
				else print_double_square(30, 25, 31, 3, 15, "There is no any class to view");
			}
			else // choose == 2
			{
				if (current_year->ph_semester != NULL)
				{
					check_time_for_semester(current_year);

					Node_semester* semester_choose = nullptr;
					int no;
					if (current_year->semestercount == 1)
					{
						semester_choose = find_semester(current_year->ph_semester, "1");
						print_course(semester_choose->ph_course);

					}
					if (current_year->semestercount == 2)
					{
						semester_choose = find_semester(current_year->ph_semester, "2");
						print_course(semester_choose->ph_course);

					}
					if (current_year->semestercount == 3)
					{
						semester_choose = find_semester(current_year->ph_semester, "3");
						print_course(semester_choose->ph_course);
					}
					print_type_in_box(30, 25, "Choose a course", 5);
					char no_char;
					cin >> no_char;
					if (no_char < 48 || no_char > 57)
						return;
					no = no_char - 48;
					Node_course* course_choose = find_course(semester_choose->ph_course, no);
					if (course_choose->ph_student_enrolled != NULL)
						viewListofstudentsincourse(course_choose->ph_student_enrolled);
					else
					{
						print_double_square(30, 30, 45, 3, 15, "Course has not been enrolled by any student");
					}
				}
				else print_double_square(30, 30, 33, 3, 15, "Semesters have not been created");

			}
			_getch();
		}
		//View course
		if (choose == 5 && ph_year != NULL)
		{
			if (current_year->ph_semester != NULL)
			{
				check_time_for_semester(current_year);
				Node_semester* semester_choose;
				if (current_year->semestercount == 1)
				{
					semester_choose = find_semester(current_year->ph_semester, "1");
				}
				else if (current_year->semestercount == 2)
				{
					semester_choose = find_semester(current_year->ph_semester, "2");

				}
				else {
					semester_choose = find_semester(current_year->ph_semester, "3");

				}
				viewListofcourse(semester_choose->ph_course);

			}
			else print_double_square(30, 10, 32, 3, 15, "There is no any course to view");
			_getch();
		}
		//Export
		if (choose == 6)
		{
			if (check_not_end_semester(current_year))
			{
				Node_semester* semester_choose = nullptr;
				if (current_year->semestercount == 1)
					semester_choose = find_semester(current_year->ph_semester, "1");
				if (current_year->semestercount == 2)
					semester_choose = find_semester(current_year->ph_semester, "2");
				if (current_year->semestercount == 3)
					semester_choose = find_semester(current_year->ph_semester, "3");
				export_studentIncourse_to_csv(semester_choose->ph_course, current_year);
				print_double_square(30, 10, 19, 3, 15, "Export succeeded!");
			}
			_getch();
		}
		//Update scoreboard
		if (choose == 7)
		{
			if (check_not_end_semester(current_year))
			{
				updateScoreBoardOfACourse(current_year);
				update = 1;
			}
			_getch();
		}
		if (choose == 8)
		{
			if (check_not_end_semester(current_year))
			{
				if (update)
				{
					print_double_square(30, 10, 31, 3, 15, "1.View scoreboard of a course");
					print_double_square(61, 10, 30, 3, 15, "2.View scoreboard of a class");
					print_type_in_box(30, 15, "Your option", 5);
					int choose;
					char choose_char;
					cin >> choose_char;
					if (choose_char < 48 || choose_char > 57)
						return;
					choose = choose_char - 48;
					if (choose == 1)
						viewScoreBoardOfACourse(current_year);
					else
					{
						if (ph_year->ph_classes != NULL)
						{
							int class_no;
							int year_no;
							viewAllClass(ph_year);
							print_type_in_box(30, 20, "Choose a school year", 5);
							char year_no_char;
							cin >> year_no_char;
							if (year_no_char < 48 || year_no_char > 57)
								return;
							year_no = year_no_char - 48;
							Node_year* year_choose = find_year(ph_year, year_no);
							print_type_in_box(30, 25, "Choose a class", 5);
							char class_no_char;
							cin >> class_no_char;
							if (class_no_char < 48 || class_no_char > 57)
								return;
							class_no = class_no_char - 48;						cin >> class_no;
							Node_class* class_choose = find_class(year_choose->ph_classes, class_no);
							if (class_choose == NULL)
								print_double_square(30, 30, 32, 3, 15, "Class not exists or not found!");
							if (class_choose != NULL)
								viewScoreBoardOfAClass(class_choose, current_year);
						}
						else print_double_square(30, 20, 31, 3, 15, "There is no any class to view");
					}
				}
				else
					print_double_square(30, 10, 36, 3, 15, "Scoreboards have not been updated!");
			}
			_getch();
		}

	} while (choose != 9);
}