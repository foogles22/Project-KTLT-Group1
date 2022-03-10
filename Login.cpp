#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void login (long a, fstream &fs, string s){
	string b = to_string(a);
	int cnt = 1;
	bool acp = false;
	bool end = true;
	string chatluong[8] = {"NULL","NULL","NULL","NULL","NULL","APCS","VP","CLC"};
	while (end){
		fs.open("StudentData/" + to_string(a/1000000) + "/" + to_string(a/1000000) + chatluong[(a/1000)%10] + to_string(cnt) + ".csv", ios::in);
		if (!fs.is_open()) end = false;
		else while (!fs.eof()){
			fs.ignore();
			fs.ignore();
			string check;
			getline (fs,check,',');
			if (check == b){
				string pass;
				int dem = 5;
				while (dem--){
					getline (fs,pass,',');
				}
				getline (fs,pass);
				if (pass == s){
					end = false;
					acp = true;
				}
			}
			else{
				getline (fs,check);
			}
			if (acp) break;	
		}
		fs.close();
		cnt++;	
	}
	if (acp) cout<<"Ban da dang nhap thanh cong!";
	else cout<<"Dang nhap that bai!";	
}
int main(){
	fstream fs;
//	int dem=5;
	string s = "ccgiz";
	login (17127123,fs,s);
//	long a = 17127038;
//	string b = to_string(a);
//	cout<<s[2];
//	fs.open ("StudentData/17/17CLC1.csv");
//	string s;
//	fs.ignore();
//	fs.ignore();
//	getline(fs,s,',');
////	if (s==b) cout<<"ok";
//	while (dem--){
//		getline (fs,s,',');
//	}
//	getline (fs,s);
//	cout<<s<<endl;
//	fs.ignore();
//	fs.ignore();
//	getline (fs,s,',');
//	cout<<s;
//	fs.close();
	return 0;
}
