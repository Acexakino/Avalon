#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>
#include<cstdlib>

using namespace std;

struct card{							//describe Characters, sides and abilities
	string charName;
	char side;
	string ability;
};

class Roleset{
	public:
		vector<card> getrole;			//unrandomed role
		vector<string> name;			//bot names
		vector<card> randrole;			//randomed role
		void roleSet(int);
		void botSet(int);				//collect data of AI names then put it on vector<card> getrole
		void randRole(int);				//random 
		void showRole();
};

void Roleset::roleSet(int n){
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
			sscanf(text.c_str(),"%s, %c, [%^]:",&charName,&c.side,&c.ability);
			getrole.push_back(c);
		}
	}
}

void Roleset::botSet(int n){
	ifstream bot("Botnames.txt");
	string text;
	int state = 1;
	while(getline(bot,text)){
		if(state == 1){
			int i = atoi(text.c_str());
			if(i == n){						//check number of players that user has input.
				state == 2;
			}else{
				continue;
			}
		}else if(state == 2){				//get bot names until if-statement below.
			if(text == "---------------------------------------"){
				bot.close();
				break;
			}
			name.push_back(text.c_str());
		}
	}
}

void Roleset::randRole(int m){				//randoming unique number
	int *value = new int [30];
	bool check; 							//variable to check or number is already used
    int n; 									//variable to store the number in
    for(int i=0; i < m; i++){
		do{
    		n = rand()%m;					//check or number is already used:
    		check = true;
    		for (int j=0; j<i ;j++){
        		if (n == value[j]){ 		//if number is already used
            		check = false; 			//set check to false
            		break; 					//no need to check the other elements of value[]
        		}
			}
    	}while(!check); 					//loop until new, unique number is found
		value[i] = n;
	}
	for(int i=0; i < m; i++){
		int j = value[i];
		randrole[j] = getrole[i];			//get randomed role
	}
	delete [] value;
}

ostream & operator<<(ostream &os, card &c){
	return os << "You are " << c.charName << ".\n" << "Your ability is: " << c.ability << ".\n";
}

void Roleset::showRole(){
	cout << randrole[0];					//show your character and ability
}
