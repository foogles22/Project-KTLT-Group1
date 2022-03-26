#include <iostream>
#include <fstream>
using namespace std;

int main(){
	fstream fs;
	fs.open("VTP1.csv");
	while (!fs.eof()){
	long mssv;
	double x,y,z,t;
	string ign;
	fs.ignore();
	fs.ignore();
	fs>>mssv;
	fs.ignore();
	getline(fs,ign,',');
	fs>>x;
	fs.ignore();
	fs>>y;
	fs.ignore();
	fs>>z;
	fs.ignore();
	fs>>t;
	fs.ignore();
	cout<<mssv<<endl;
	cout<<x<<" "<<y<<" "<<z<<" "<<t<<endl;
	}
	fs.close();
	return 0;
}
