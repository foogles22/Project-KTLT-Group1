struct teacher{
	string mail,cccd,pass,fullname,date;
	teacher *next;
};
void loadTeacherData(teacher *&head){
	fstream fs;
	fs.open("GiaoVu.csv");
	if (!fs.eof()) head = new teacher;
	teacher *cur = head;
	string a;
	while (!fs.eof()){
		getline(fs,cur->mail,',');
		getline(fs,cur->fullname,',');
		getline(fs,cur->date,',');
		getline(fs,cur->cccd,',');
		getline(fs,cur->pass);
		if (!fs.eof()){
			cur->next = new teacher;
			cur = cur->next;
		}
	}
	cur->next = nullptr;
	fs.close();
}
