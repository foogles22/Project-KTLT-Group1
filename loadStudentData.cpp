void loadFile(Node_year *& ph_y){
	fstream fi;
	ph_y = 0;
	Node_year* yCur = ph_y;
	fi.open("D:\\CODE\\Project-KTLT-Group1-main\\StudentData\\CreatedYear.txt", ios::in);
	while(!fi.eof()){
		if(!ph_y){
			ph_y = new Node_year;
			fi >> ph_y->name;
			yCur = ph_y;
		}
		else{
			yCur->year_next = new Node_year;
			fi >> yCur->year_next->name;
			yCur = yCur->year_next;
			yCur->year_next = 0;
		}
	}
	fi.close();

	yCur = ph_y;
	Node_class* cCur = 0;
	fstream fiClass;
	while(yCur){
		fiClass.open("D:\\CODE\\Project-KTLT-Group1-main\\StudentData\\" + yCur->name.substr(2,2) + "\\CreatedClass.txt", ios::in);
		while(!fiClass.eof()){
			if(!yCur->ph_classes){
				yCur->ph_classes = new Node_class;
				fiClass >> yCur->ph_classes->name;
				//cout << yCur->ph_classes->name;
				cCur = yCur->ph_classes;
				yCur->ph_classes->class_next = 0;
			}
			else{
				cCur->class_next = new Node_class;
				fiClass >> cCur->class_next->name;
				//cout << cCur->name;
				cCur = cCur ->class_next;
				cCur->class_next = 0;
			}
		}
		yCur = yCur->year_next;
		fiClass.close();
	}

	fstream fiStudent;
	yCur = ph_y;
	Node_student* sCur;
	while(yCur){
		cCur = yCur->ph_classes;
		while(cCur){
			fiStudent.open("D:\\CODE\\Project-KTLT-Group1-main\\StudentData\\" + yCur->name.substr(2,2) + "\\" + cCur->name + ".csv", ios::in);
			while(!fiStudent.eof()){
				if(!cCur->ph_student){
					cCur->ph_student = new Node_student;
					getline(fiStudent, cCur->ph_student->data.No, ',');
					getline(fiStudent, cCur->ph_student->data.ID, ',');
					getline(fiStudent, cCur->ph_student->data.first_name, ',');
					getline(fiStudent, cCur->ph_student->data.lastname, ',');
					getline(fiStudent, cCur->ph_student->data.gender, ',');
					getline(fiStudent, cCur->ph_student->data.date, ',');
					getline(fiStudent, cCur->ph_student->data.social_ID, ',');
					getline(fiStudent, cCur->ph_student->data.password);
					cCur->ph_student->student_next = NULL;
					cCur->ph_student->ph_course_enrolled1 = NULL;
					cCur->ph_student->ph_course_enrolled2 = NULL;
					cCur->ph_student->ph_course_enrolled3 = NULL;
					//cout << yCur->ph_classes->name;
					sCur = cCur->ph_student;
				}
				else{
					sCur->student_next = new Node_student;
					getline(fiStudent, sCur->student_next->data.No, ',');
					getline(fiStudent, sCur->student_next->data.ID, ',');
					getline(fiStudent, sCur->student_next->data.first_name, ',');
					getline(fiStudent, sCur->student_next->data.lastname, ',');
					getline(fiStudent, sCur->student_next->data.gender, ',');
					getline(fiStudent, sCur->student_next->data.date, ',');
					getline(fiStudent, sCur->student_next->data.social_ID, ',');
					getline(fiStudent, sCur->student_next->data.password);
					sCur->student_next->student_next = NULL;
					sCur->student_next->ph_course_enrolled1 = NULL;
					sCur->student_next->ph_course_enrolled2 = NULL;
					sCur->student_next->ph_course_enrolled3 = NULL;
					//cout << cCur->name;
					sCur = sCur ->student_next;
				}
			}
		cCur = cCur->class_next;
		fiStudent.close();
		}		
	yCur = yCur->year_next;
	fiStudent.close();
	}
}
