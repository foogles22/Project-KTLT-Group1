void saveFileSemester (Node_year *cur){
	fstream fs;
	if (cur->ph_semester) fs.open((string)"StudentData" + cur->name[2] + cur->name[3] + "CreatedSemester.txt",ios::out);
}
