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

void addStudentIntoCourse(Node_year*& ph_y){
    Node_semester* sCur = ph_y->ph_semester;
    while(sCur){
        Node_course* cCur = sCur->ph_course;
        while(cCur){
            fstream f;
            f.open("CoursesData\\" + sCur->semester_no + "\\" + cCur->data.course_name + ".csv");
            while(!f.eof()){
                Node_student* stuCur;
				if(!cCur->ph_student_enrolled){
					string tmp;
                    f >> tmp;
                    f >> tmp;
                    cCur->ph_student_enrolled = findStudent(ph_y,tmp);
					stuCur = cCur->ph_student_enrolled;
				}
				else{
					string tmp;
					f >> tmp;
					f >> tmp;
					stuCur->student_next = findStudent(ph_y,tmp);
					stuCur->student_next->student_next = 0;
					stuCur = stuCur->student_next;
				}
			}
			f.close();
		}
    }
}
