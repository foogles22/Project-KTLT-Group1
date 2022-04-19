int countClass(Node_class *a){
	int cnt = 0;
	while (a){
		cnt++;
		a = a->class_next;
	}
	return cnt;
}
