int main() {
	fstream fi;
	fi.open("StudentData.csv", ios::in);
	
	Node_student* pHead_Student = 0;
	Node_student* pCur_Student = 0;

	while (!fi.eof()) {
		if (!pHead_Student) {
			pHead_Student = new Node_student;
			getline(fi, pHead_Student->No, ',');
			getline(fi, pHead_Student->ID, ',');
			getline(fi, pHead_Student->first_name, ',');
			getline(fi, pHead_Student->lastname, ',');
			getline(fi, pHead_Student->gender, ',');
			getline(fi, pHead_Student->date_of_birth, ',');
			getline(fi, pHead_Student->social_ID);
			pCur_Student = pHead_Student;
		}
		else {
			pCur_Student->student_next = new Node_student;
			getline(fi, pCur_Student->student_next->No, ',');
			getline(fi, pCur_Student->student_next->ID, ',');
			getline(fi, pCur_Student->student_next->first_name, ',');
			getline(fi, pCur_Student->student_next->lastname, ',');
			getline(fi, pCur_Student->student_next->gender, ',');
			getline(fi, pCur_Student->student_next->date_of_birth, ',');
			getline(fi, pCur_Student->student_next->social_ID);
			pCur_Student = pCur_Student->student_next;
		}
	}
	pCur_Student ->student_next= 0;
	pCur_Student = pHead_Student;
	while (pCur_Student) {
		cout << pCur_Student->No;
		cout << pCur_Student->ID;
		cout << pCur_Student->first_name;
		cout << pCur_Student->lastname;
		cout << pCur_Student->gender;
		cout << pCur_Student->date_of_birth;
		cout << pCur_Student->social_ID;
		pCur_Student = pCur_Student->student_next;
		cout << endl;
	}
		
	return 0;
}
