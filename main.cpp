#include "all_structs.h"


int main()
{
	Node_year* ph_year = NULL;
	Node_year* current_year = NULL;
	loadFile(ph_year, current_year);
	SetWindowSize(235, 62);
	SetScreenBufferSize(235, 9001);
	print_login_section(ph_year, current_year);
	saveStudentData(ph_year, current_year);
	deallocate_all_node(ph_year);
	return 0;
}