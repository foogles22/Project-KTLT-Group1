Node_teacher* find_teacher_login(string mail, Node_teacher* ph_teacher)
{
	Node_teacher* pc_teacher = ph_teacher;
	while (pc_teacher != NULL && pc_teacher->mail != mail)
		pc_teacher = pc_teacher->teacher_next;
	return pc_teacher;
}
