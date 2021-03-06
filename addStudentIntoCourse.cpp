Node_student* findStudent(Node_year* ph_y, string id){
    Node_year* yCur = ph_y;
    while(yCur){
        Node_class* classCur = yCur->ph_classes;
        while(classCur){
            Node_student* stuCur = classCur->ph_student;
            while(stuCur){
		if(stuCur->data.ID == id)
                	return stuCur;
                stuCur = stuCur->student_next;
            }
            classCur = classCur->class_next;
        }
        yCur = yCur->year_next;
    }

    return 0;
}

void addStudentIntoCourse(Node_year*& currentYear, Node_year* pHallyear){
    Node_semester* sCur = currentYear->ph_semester;
    while(sCur){
        Node_course* cCur = sCur->ph_course;
        while(cCur){
            fstream f;
            f.open("CoursesData\\" + sCur->semester_no + "\\" + cCur->data.course_name + ".csv");
            while(!f.eof()){
                Node_student* stuCur;
				if(!cCur->ph_student_enrolled){
					string tmp;
                    getline(f,tmp,',');
                    getline(f,tmp,',');
                    cCur->ph_student_enrolled = new Node_student;
					*cCur->ph_student_enrolled = *findStudent(pHallyear,tmp);
					stuCur = cCur->ph_student_enrolled;
					for(int i = 0; i < 5; ++i)
						getline(f,tmp,',');
					getline(f,tmp);
				}
				else{
					string tmp;
					getline(f,tmp,',');
                    getline(f,tmp,',');
					stuCur->student_next = new Node_student;
					*stuCur->student_next = *findStudent(pHallyear,tmp);
					stuCur->student_next->student_next = 0;
					stuCur = stuCur->student_next;
					for(int i = 0; i < 5; ++i)
						getline(f,tmp,',');
					getline(f,tmp);
				}
			}
			f.close();
			cCur = cCur->course_next;
		}
		sCur = sCur->semester_next;
    }
}
