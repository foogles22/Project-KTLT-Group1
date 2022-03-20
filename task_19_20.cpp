void viewListofcourse(Node_semester *&ph_semester)
{
	if (!ph_semester)
	{
		cout << "This semester hasn't been created!!!";
		return;
	}
	
	while(ph_semester)
	{
	    cout << "All courses in this semester: " << endl;
	    cout << "Course ID \t Course Name \t Teacher Name \t Number of Credits \t The maximum number of students in the course (default 50) \t Day of the week \t The session that the course will be performed " << endl;
    
        while(ph_semester -> ph_course)
        {
    	    cout << ph_semester -> ph_course -> DATA.id << " ";
    	    cout << ph_semester -> ph_course -> DATA.course_name << " ";
    	    cout << ph_semester -> ph_course -> DATA.teacher_name << " ";
    	    cout << ph_semester -> ph_course -> DATA.number_of_credits << " ";
    	    cout << ph_semester -> ph_course -> DATA.max_num_student << " ";
    	    cout << ph_semester -> ph_course -> DATA.days_of_week << " ";
    	    cout << ph_semester -> ph_course -> DATA.session1 << " ";
    	    cout << ph_semester -> ph_course -> DATA.session2 << " ";
	    }
	}
	
	return;
}

void viewListofstudentsincourse(Node_course *&ph_course)
{
	if(!ph_course)
	   return;
	   
	while (ph_course)
	{
	   cout << "All students in course: ";
	   cout << "No \t Student ID \t First name \t Last name \t Gender \t Date of Birth \t Social ID" << endl;
       while(ph_course -> ph_student)
       {
    	   cout << ph_course -> ph_student -> data.No << " ";
    	   cout << ph_course -> ph_student -> data.ID << " ";
    	   cout << ph_course -> ph_student -> data.first_name << " ";
    	   cout << ph_course -> ph_student -> data.lastname << " ";
    	   cout << ph_course -> ph_student -> data.gender << " ";
    	   cout << ph_course -> ph_student -> data.date << " ";
    	   cout << ph_course -> ph_student -> data.social_ID << " ";
	   }
    }
}
