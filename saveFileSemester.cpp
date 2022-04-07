void saveFileSemester (Node_year *cur){
	fstream fs;
	if (cur->ph_semester) fs.open((string)"StudentData" + cur->name[2] + cur->name[3] + "CreatedSemester.txt",ios::out);
}
void saveFileCourses (Node_year *cur){
	fstream fs;
	if (cur->ph_semester->ph_course) fs.open((string)"StudentData" + cur->name[2] + cur->name[3] + "CreatedSemester1.txt",ios::out);
	if (cur->ph_semester->semester_next->ph_course)	fs.open((string)"StudentData" + cur->name[2] + cur->name[3] + "CreatedSemester2.txt",ios::out);
	if (cur->ph_semester->semester_next->semester_next->ph_course)	fs.open((string)"StudentData" + cur->name[2] + cur->name[3] + "CreatedSemester3.txt",ios::out);	
}
