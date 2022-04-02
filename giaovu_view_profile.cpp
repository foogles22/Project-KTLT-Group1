void view_profile_teacher(teacher teacher_login)
{
	int i = 1;//30 24 30
	gotoXY(86, 20);
	cout << "Gmail                         FullName                Date of birth     ID";
	//       21127512     Nguyen Le Hoang  Kha       08/02/2003      123456789123
	gotoXY(86, 20 + i++);
	cout << teacher_login.mail;
	for (int i = 0; i < 30 - teacher_login.mail.length(); i++) cout << " ";
	cout << teacher_login.fullname;
	for (int i = 0; i < 26 - teacher_login.fullname.length(); i++) cout << " ";
	cout << teacher_login.date << "      ";
	cout << teacher_login.cccd;
	print_double_square(84, 20, 88, i, 15, "\0");
}
