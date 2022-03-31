void saveStudentData(Node_year *a){
	fstream fs;
	Node_year *d = a;
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
	fs.open("StudentData\\CreatedClass.txt", ios::out);
	while (d){
		Node_class *e = d->ph_classes;
		while (e){
			fs<<e->name;
			e = e->class_next;
			if (e) fs<<endl;
		}
		d = d->year_next;
		if (d) fs<<endl;
	}
	fs.close();
}
void changePassword(Node_student *&a, string b){
	a->data.password = b;
}
