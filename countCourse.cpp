int countCourse (Node_course *a){
	int cnt = 0;
	while (a){
		cnt++;
		a = a->course_next;
	}
	return cnt;
}
