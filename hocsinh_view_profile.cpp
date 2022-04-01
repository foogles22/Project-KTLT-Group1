{
	int i = 1;
	gotoXY(78, 20);
	cout << "No       ID             First Name       Last Name       Gender       Date of birth       Social ID";
		gotoXY(78, 20 + i++);
		cout << student_login->data.No << "        ";
		cout << student_login->data.ID << "       ";
		cout << student_login->data.first_name;
		for (int i = 0; i < 19 - student_login->data.first_name.length(); i++)
			cout << " ";
		cout << student_login->data.lastname;
		for (int i = 0; i < 16 - student_login->data.lastname.length(); i++)
			cout << " ";
		cout << student_login->data.gender << "  ";
		for (int i = 0; i < 10 - student_login->data.gender.length(); i++)
			cout << " ";
		cout << student_login->data.date << "       ";
		cout << student_login->data.social_ID << "   ";

	print_double_square(76, 20, 104, i , 15, "\0");
	return;
}
