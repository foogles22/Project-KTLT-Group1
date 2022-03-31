void changePassword(Node_student*& a) {
	print_type_in_box(30, 10, "Type in your new password", 30);
	string b; cin >> b;
	a->data.password = b;
	print_double_square(30, 15, 24, 3, 15, "New password accepted!");
}
