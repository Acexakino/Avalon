#include"Avalon.h"

int main(){
	srandtime(0);
	cout << "-------------------------------------------------------\n";
	cout << "                       AVALON                          \n";
	cout << "-------------------------------------------------------\n";
	
	while(true){
		int mode;
		cout << "Select mode (5-10 player?): ";
		cin >> mode;
		if(mode < 5 && mode > 10){
			cout << "Invalid Input\n";
			cout << "Select mode (5-10 player?): ";
			cin >> mode;
		}else{
			break;
		}
	}
	
	botSet(mode);
	roleSet(mode);
	randRole();
	showAbility();
	
	return 0;
}
