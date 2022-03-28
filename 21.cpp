void exportCourseStudentIntoCSV(Node_course c) {
	fstream fo;
	fo.open(c.data.course_name + ".csv", ios::out);
	Node_course tmp = c;
	while (tmp.ph_student_enrolled) {
		fo << tmp.ph_student_enrolled->data.ID << ',';
		fo << tmp.ph_student_enrolled->data.first_name << ',';
		fo << tmp.ph_student_enrolled->data.lastname << endl;
		tmp.ph_student_enrolled = tmp.ph_student_enrolled->student_next;
	}
	fo.close();

	return;
}
