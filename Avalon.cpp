#include"Avalon.h"

int main(){
	srand(time(0));
	cout << "-------------------------------------------------------\n";
	cout << "                       AVALON                          \n";
	cout << "-------------------------------------------------------\n";
	
	while(true){
		string nimi;
		int mode;
		cout << "Player Name : ";
		getline(cin,nimi);
		name.push_back(nimi);
		
		cout << "Select mode (5-8 player?): ";
		cin >> mode;
		if(mode < 5 && mode > 8){
			cout << "Invalid Input\n";
			cout << "Select mode (5-8 player?): ";
			cin >> mode;
		}else{
			break;
		}
	}
	
	botSet(mode);
	roleSet(mode);
	randRole(mode);
	showRole();
	
	return 0;
}
