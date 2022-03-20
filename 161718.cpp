void viewCourse_Student(Node_student* student){
    cout << "Your course in this semester:" << endl;
    if(student->ph_course_enrolled)
        cout << "ID\t Course name\t Teacher_name\t Session 1\t Session 2\t Nums of credit\t";
    else
        cout << "You haven't enrolled any class!!!"
    while(student->ph_course_enrolled){
        cout << student->ph_course_enrolled->data.id << ' ';
        cout << student->ph_course_enrolled->data.course_name << ' ';
        cout << student->ph_course_enrolled->data.teacher_name << ' ';
        cout << student->ph_course_enrolled->data.session1<< ' ';
        cout << student->ph_course_enrolled->data.session2 << ' ';
        cout << student->ph_course_enrolled->data.number_of_credits << ' ';

        student ->ph_course_enrolled = student ->ph_course_enrolled -> course_next;
    }

    return;
}

void viewAllClass(Node_year* year){
    if(!year)
        cout << "No years has been created";
    while(year){
        cout << year -> name<< endl;
        while(year -> ph_classes){
            cout << year->ph_classes->name << endl;
            year->ph_classes = year->ph_classes -> class_next;
        }
        year = year -> year_next;
    }

    return;
}

void viewAllStudentInAClass(Node_class* Curclass){
    cout << Curclass->name << endl;
    cout << "No \t ID \t First Name\t Last Name\tGender\tSocial ID";
    while(Curclass -> ph_student){
        cout << Curclass->ph_student->data.No<< ' ';
        cout << Curclass->ph_student->data.ID<< ' ';
        cout << Curclass->ph_student->data.first_name<< ' ';
        cout << Curclass->ph_student->data.lastname<< ' ';
        cout << Curclass->ph_student->data.gender<< ' ';
        cout << Curclass->ph_student->data.social_ID<< ' ';
    }

    return;
}