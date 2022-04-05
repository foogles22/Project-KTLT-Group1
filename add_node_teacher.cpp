void add_teacher(Node_teacher*& ph_teacher)
{
	ifstream read("GiaoVu.csv");
	Node_teacher* pc_teacher = ph_teacher;
	if (ph_teacher != NULL)
	{
		return;
	}
	while (!read.eof())
	{
		Node_teacher* tmp = new Node_teacher;
		getline(read, tmp->mail, ',');
		getline(read, tmp->fullname, ',');
		getline(read, tmp->date, ',');
		getline(read, tmp->cccd, ',');
		getline(read, tmp->pass);
		tmp->teacher_next = NULL;
		if (pc_teacher == NULL)
		{
			ph_teacher = tmp;
			pc_teacher = tmp;
		}
		else
		{
			pc_teacher->teacher_next = tmp;
			pc_teacher = pc_teacher->teacher_next;
		}

	}
	read.close();
}
