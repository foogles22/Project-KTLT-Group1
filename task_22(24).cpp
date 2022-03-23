//void printExistedCourses(fstream &fs){
//	fs.open("CoursesData\\Semester 1\\Courses.txt");
//	while (!fs.eof()){
//		string s;
//		fs>>s;
//		cout<<s<<endl;
//	}
//	fs.close();
//}
void updateStudentResult(Node_student *&a, Node_year *b,string s, double x, double y, double z, double t,){
	//use while loop to get each  student ID then use the find_student by id to make changes
	if (b->s_cur == 1){
		Node_course *cur = a->ph_course_enrolled1;
		while (cur->data->course_name != s){
			cur = cur->course_next->next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}
	if (b->s_cur == 2){
		Node_course *cur = a->ph_course_enrolled2;
		while (cur->data->course_name != s){
			cur = cur->course_next->next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}
	if (b->s_cur == 3){
		Node_course *cur = a->ph_course_enrolled3;
		while (cur->data->course_name != s){
			cur = cur->course_next->next;
		}
		cur->total = x;
		cur->final = y;
		cur->midterm = z;
		cur->other = t;
	}		
}
