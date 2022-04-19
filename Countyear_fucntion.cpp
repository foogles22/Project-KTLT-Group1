int countYear(Node_year *a){
	int cnt = 0;
	while (a){
		cnt++;
		a = a->year_next;
	}
	return cnt;
}
