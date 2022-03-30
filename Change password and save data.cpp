void saveStudentData(Node_year *a){
	fstream fs;
	while (a){
		Node_class *b = a->ph_classes;
		while (b){
			fs.open((string)"StudentData\\" + (a->name)[2] + (a->name)[3] + "\\" +  b->name + ".csv");
			Node_student *c = b->ph_student;
			while (c){
				fs<<c->data.No<<","<<c->data.ID<<","<<c->data.first_name<<","<<c->data.lastname<<","<<c->data.gender<<","<<c->data.date<<","<<c->data.social_ID<<","<<c->data.password;
				c = c->student_next;
				if (c){
					fs<<endl;
				}
			}
			fs.close();
			b = b->class_next;
		}
		a = a->year_next;
	}
}
void changePassword(Node_student *&a, string b){
	a->data.password = b;
}
