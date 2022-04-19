int countStudent (Node_student *a){
	int cnt = 0;
	while (a){
		cnt++;
		a = a->student_next;
	}
	return cnt;
}
