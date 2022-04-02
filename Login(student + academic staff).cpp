int login(string a) {
	if (a[0]=='1'||a[0]=='2'||a[0]=='3'||a[0]=='4'||a[0]=='5'||a[0]=='6'||a[0]=='7'||a[0]=='8'||a[0]=='9'||a[0]=='0'){
		long id = stol(a);
		fstream fs; string s;
		cout << "Enter Password: "; cin >> s;
		string b = a;
		int cnt = 1;
		bool acp = false;
		bool end = true;
		//	string *chatluong = { "NULL","NULL","NULL","NULL","NULL","APCS","VP","CLC" };
		string* chatLuong = new string[8];
		for (int i = 0; i <= 4; i++) {
			chatLuong[i] = "NULL";
		}
		chatLuong[5] = "APCS";
		chatLuong[6] = "VP";
		chatLuong[7] = "CLC";
		while (end) {
			fs.open("StudentData\\" + to_string(id / 1000000) + "\\" + to_string(id / 1000000) + chatLuong[(id / 1000) % 10] + to_string(cnt) + ".csv", ios::in);
			if (!fs.is_open()) end = false;
			else while (!fs.eof()) {
				fs.ignore();
				fs.ignore();
				string check;
				getline(fs, check, ',');
				if (check == b) {
					string pass;
					int dem = 5;
					while (dem--) {
						getline(fs, pass, ',');
					}
					getline(fs, pass);
					if (pass == s) {
						end = false;
						acp = true;
					}
				}
				else {
					getline(fs, check);
				}
				if (acp) break;
			}
			fs.close();
			cnt++;
		}
		delete[] chatLuong;
		if (acp)
		{
			cout << "Login succeeded as student!\n";
			return 1;
		}
		else
		{
			cout << "Failed login!\n";
			return 0;
		}
	}
	else{
		fstream fs;
		string b;
		cout<<"Enter Password: ";
		cin>>b;
		fs.open("GiaoVu.csv");
		while (!fs.eof()){
			string s;
			getline(fs,s,',');
			if (s==a){
				int dem = 3;
				string check;
				while (dem--){
					getline(fs,check,',');
				}
				getline(fs,check);
				if (b==check){
					cout<<"Login succeeded as a academic staff memeber!\n";
					return 2;
				}
			}
		}
		cout<<"Failed Login!\n";
		return 0;	
	}
}
