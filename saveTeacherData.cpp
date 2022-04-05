void saveTeacherData (teacher *head){
	fstream fs;
	fs.open("GiaoVu.csv",ios::out|ios::trunc);
	while (head){
		fs<<head->mail<<","<<head->fullname<<","<<head->date<<","<<head->cccd<<","<<head->pass;
		head = head->next;
		if (head) fs<<endl;
	}
	fs.close();
}
