#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<cstdlib>

using namespace std;

struct card{
	string charName;
	char side;
};

class Avalon{
	private:
		vector<card> role;
		vector<string> botName;
	public:
		void roleSet(int);
		void botSet(int);
		void randRole(int);
		void showAbility();
};

Avalon Avalon::roleSet(int n){
	ifstream role("Roleset.txt");
	string text;
	int state = 1;
	while(getline(role,text)){
		if(state == 1){
			int i = atoi(text.c_str());
			if(i == n){
				state == 2;
			}else{
				continue;
			}
		}else if(state == 2){
			if(text == "----------------------------------------------------------------"){
				role.close();
				break;
			}
			card c;
			char charName[100];
			sscanf(text.c_str(),"%s,%c",&charName,&c.side);
			c.charName = role;
			role.push_back(c);
		}
	}
}

Avalon Avalon::botSet(int n){
	ifstream bot("Botnames.txt");
	string text;
	int state = 1;
	while(getline(bot,text)){
		if(state == 1){
			int i = atoi(text.c_str());
			if(i == n){
				state == 2;
			}else{
				continue;
			}
		}else if(state == 2){
			if(text == "---------------------------------------"){
				bot.close();
				break;
			}
			string s;
			char botname[100];
			sscanf(text.c_str(),"%s",&botname);
			botname = botName;
			botName.push_back(s);
		}
	}
}

Avalon Avalon::randRole(int n){
	int k = rand()%n;
	for(int i=0; i<n; i++){
		friend botName
	}
	
}

Avalon Avalon::showAbility(){
	
}
