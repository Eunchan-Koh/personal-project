//============================================================================
// Name        : personal_project.cpp
// Author      : Eunchan Koh
// Version     :
// Copyright   : Your copyright notice
// Description : Runner_Maker game project made by Eunchan Koh.
//============================================================================

#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void status_setup();
struct character training(struct character current_character);
int train_success(int healthp);
void showSucceedRate(struct character current_character);
void result(struct character current_character);
void prepare(struct character current_character, struct character versus_character);
void versus(struct character current_character, struct character versus_character, int level);
void reset_values();



int speed_count = 0;
int stamina_count = 0;
int power_count = 0;
int will_count = 0;
int intellect_count = 0;

int speed_level = 1;
int stamina_level = 1;
int power_level = 1;
int will_level = 1;
int intellect_level = 1;

int turn = 0;
string cha_sel;


struct character{
private:
	char name[100];
	int character_id = -1;
	int speed;
	int stamina;
	int power;
	int will;
	int intellect;
	int current_hp;
	int max_hp = 120;
public:
	void set_name(char setting_name[], int name_length){
			strncpy(name, setting_name, name_length);
//			cout<<"size is" << setting_name.sizeof()<<endl;

//		name = setting_name;
	}
	char *get_name(){
		return name;
	}
	void set_character_id(int setting_character_id){
		character_id = setting_character_id;
	}
	int get_character_id(){
		return character_id;
	}
	void set_speed(int setting_speed){
		speed = setting_speed;
	}
	int get_speed(){
		return speed;
	}
	void set_stamina(int setting_stamina){
		stamina = setting_stamina;
	}
	int get_stamina(){
		return stamina;
	}
	void set_power(int setting_power){
		power = setting_power;
	}
	int get_power(){
		return power;
	}
	void set_will(int setting_will){
		will = setting_will;
	}
	int get_will(){
		return will;
	}
	void set_intellect(int setting_intellect){
		intellect = setting_intellect;
	}
	int get_intellect(){
		return intellect;
	}
	void set_current_hp(int setting_current_hp){
		current_hp = setting_current_hp;
		}
	int get_current_hp(){
		return current_hp;
	}
	void set_max_hp(int setting_max_hp){
		max_hp = setting_max_hp;
	}
	int get_max_hp(){
		return max_hp;
	}

//
//	void setName(char[] setting_name){
//		this.name = setting_name;
//	}

};

void entrance_page();
int MAX_NUMBER_OF_CHARACTER = 30;
void character_setup(struct character character_set[]);
//versus character
void versus_character_setup(struct character versus_character_set[]);
void show_status(struct character this_chara);
double additional_run(struct character chara, int floor_type, double current_stamina);

int main() {
//	cout << "Umamusume!" << endl;
//	cout << "TAP TO START" << endl;
//	string start;
//    int random = rand()%100;
//    srand(time(NULL));
//    cout<<"random" << random << endl;
//	cin >> start;
//	cin.clear();
//	bool selection_clear = 0;
	struct character* character_set = new struct character[MAX_NUMBER_OF_CHARACTER];
	struct character* versus_character_set = new struct character[MAX_NUMBER_OF_CHARACTER];
	struct character current_character;
	struct character versus_character;
	struct character* graduated_character = new struct character[MAX_NUMBER_OF_CHARACTER];
	int graduated_count = 0;
	character_setup(character_set);
	versus_character_setup(versus_character_set);
	versus_character = versus_character_set[0];
//	cout << "versus_character is " << versus_character_set[0].get_name() << endl;
	entrance_page();
	int playing = 1;
	int mode_select = 0;//0 for normal, 1 for vs
	while(playing){
		reset_values();
		bool selection_clear = 0;
		while (selection_clear == 0){
			cout << "Select a mode to play. Type help for explanation!" << endl;
			cout << "1. normal mode" << endl;
			cout << "2. graduated characters vs mode" << endl;
			cout << "EXIT" << endl;
			cin >> cha_sel;
			if(cha_sel == "1" || cha_sel == "normal mode"){
				cout << "Selected normal mode!" << endl;
				mode_select = 0;
				selection_clear = 1;
			}else if(cha_sel == "2" || cha_sel == "graduated characters vs mode"){
				cout << "Selected graduated characters vs mode!" << endl;
				mode_select = 1;
				selection_clear = 1;
			}else if(cha_sel == "EXIT"||cha_sel == "exit"){
				cout<<"do you really want to quit?Y/N";
				cin>> cha_sel;
				if(cha_sel == "Y"){
					cout << "goodbye, see you later!" << endl;
					selection_clear = 1;
					mode_select = -1;
					playing = 0;
				}else{
				}
			}else if(cha_sel == "help"){
				cout << "1. normal mode: Train your own character, and make your character have a race. "
						"There will be 20 turns for you to train your own character, and race will begin after that."<< endl;
				cout << "No matter if you lose or win the race, your character will graduated and will be added to "
						"graduated character list." << endl;
				cout << "2. graduated character vs mode: you can select two characters from your graduated character list. "
						"Selected two characters will have a race to find who is the better runner!" << endl;
			}else{
				cout << "Wrong command. please try again." << endl;
			}
		}
		selection_clear = 0;
		if(mode_select == 0){
			while (selection_clear == 0){

			cout << "Select a character to play." << endl;
			cout << "Type in number or name of character." << endl;
			for(int i = 0; character_set[i].get_character_id() != -1; i++){
				cout << i+1 << ". " << character_set[i].get_name() << endl;
			}
			Sleep(10);
			cin>>cha_sel;
			int a = (int)cha_sel[0]-48;
		//	cout<<a<<endl;
			for(int i = 0; character_set[i].get_character_id() != -1; i++){
				if(a == character_set[i].get_character_id() || cha_sel == character_set[i].get_name()){
					current_character = character_set[i];
					cout << "You've selected " << character_set[i].get_name() << "." << endl;
					Sleep(300);
					cout << "There will be a race after 20th turn! Be prepared!" << endl;
					Sleep(300);
					cout << "Training Start." << endl;
		//			system("cls");
					selection_clear = 1;
				}
				if(character_set[i+1].get_character_id() == -1 && selection_clear != 1){
					cout << "Character undefined. Please select again." << endl;
					Sleep(100);
				}
			}

			cin.clear();
			}

			for(int turns = 0; turns<20; turns++){
				current_character = training(current_character);
			}

			prepare(current_character, versus_character);
			versus(current_character, versus_character, 1);
			result(current_character);
			graduated_character[graduated_count] = current_character;
			graduated_count++;
			Sleep(1000);
			selection_clear = 0;//resetting value;
			while(!selection_clear){
				cout << "do you want to keep playing? Y/N" << endl;;

				cin >> cha_sel;
				if(cha_sel == "Y"){
					cout <<"Decided to play again!" << endl;
					selection_clear = 1;
				}else if(cha_sel == "N"){
					cout << "Decided to quit! See you again!" << endl;
					playing = 0;
					selection_clear = 1;
				}else{
					cout << "Wrong command! Please try again." << endl;
				}
				Sleep(1000);
			}
		}else if(mode_select == 1){
			int first_sel = 0;
			int second_sel = 0;
			int exit = 0;
			int first_sel_value = 0;
			struct character first;
			struct character second;
			while(!first_sel && !exit){
				cout << "Select 1st character! Select by number. If you want to exit, please type in EXIT" << endl;
				for(int i = 0; i < graduated_count; i++){
					cout << i+1 << ". " << graduated_character[i].get_name() << endl;
				}
				cin >> cha_sel;
				int a = (int)cha_sel[0] - 48;
				if(a <= graduated_count){
					first = graduated_character[a-1];
					first_sel_value = a;
					cout << "Chose " << first.get_name() << " as first character!" << endl;
					first_sel = 1;
				}else if(cha_sel == "EXIT"){
					cout << "exiting!" << endl;
					exit = 1;
				}else{
					cout << "Wrong command!" << endl;
				}
			}
			while(!second_sel && !exit){
				cout << "Select 2nd character! Select by number. If you want to exit, please type in EXIT" << endl;
				for(int i = 0; i < graduated_count; i++){
					cout << i+1 << ". " << graduated_character[i].get_name() << endl;
				}
				cin >> cha_sel;
				int a = (int)cha_sel[0] - 48;
				if(a <= graduated_count){
					second = graduated_character[a-1];
					if(a == first_sel_value){
						cout << "this character is already chosen as first character! please select another character!" << endl;
					}else{
						cout << "Chose " << second.get_name() << " as second character!" << endl;
						second_sel = 1;
					}
				}else if(cha_sel == "EXIT"){
					cout << "exiting!" << endl;
					exit = 1;
				}else{
					cout << "Wrong command!" << endl;
				}
			}
			if(!exit){
				prepare(first, second);
				versus(first, second, 1);
			}

		}

	}
	return 0;
}
//	cout<<"list of currently available characters: " << endl;
//	for(int i = 0; character_set[i].get_character_id() != -1; i++){
//		cout << i+1 << ". " << character_set[i].get_name() << endl;
//	}



void entrance_page(){
	string start;
		cout << "Welcome to Runner_Maker!" << endl;
		cout << "TYPE IN ANYTHING TO START" << endl;
		cin >> start;
		cin.clear();
}

void character_setup(struct character character_set[]){
	int curr_num_characters = 0;
	int curr_character_id = 1;


	int basic_speed = 50;
	int basic_stamina = 50;
	int basic_power = 50;
	int basic_will = 50;
	int basic_intellect = 50;
	int basic_current_hp = 120;
	int basic_max_hp = 120;
	//Rice Shower
	struct character James;
	James.set_character_id(curr_character_id);
	curr_character_id++;
	James.set_current_hp(basic_current_hp);
	James.set_intellect(basic_intellect+20);
	James.set_max_hp(basic_max_hp);
	James.set_name("James", sizeof("James"));
	James.set_power(basic_power+20);
	James.set_speed(basic_speed+10);
	James.set_stamina(basic_stamina+30);
	James.set_will(basic_will+40);
	character_set[curr_num_characters] = James;
	curr_num_characters++;
	//////
	//Jacky
	struct character Jacky;
	Jacky.set_character_id(curr_character_id);
	curr_character_id++;
	Jacky.set_current_hp(basic_current_hp);
	Jacky.set_intellect(basic_intellect+20);
	Jacky.set_max_hp(basic_max_hp);
	Jacky.set_name("Jacky_o", sizeof("Jacky_o"));
	Jacky.set_power(basic_power+20);
	Jacky.set_speed(basic_speed+50);
	Jacky.set_stamina(basic_stamina+30);
	Jacky.set_will(basic_will+30);
	character_set[curr_num_characters] = Jacky;
	curr_num_characters++;
	//////
	//Rion
	struct character Rion;
	Rion.set_character_id(curr_character_id);
	curr_character_id++;
	Rion.set_current_hp(basic_current_hp);
	Rion.set_intellect(basic_intellect+20);
	Rion.set_max_hp(basic_max_hp);
	Rion.set_name("Rion", sizeof("Rion"));
	Rion.set_power(basic_power+40);
	Rion.set_speed(basic_speed+30);
	Rion.set_stamina(basic_stamina);
	Rion.set_will(basic_will+20);
	character_set[curr_num_characters] = Rion;
	curr_num_characters++;

}

void versus_character_setup(struct character versus_character_set[]){
	int count = 0;
	struct character Arone;
	Arone.set_character_id(0);
	Arone.set_current_hp(120);
	Arone.set_intellect(120);
	Arone.set_max_hp(120);
	Arone.set_name("Arone", sizeof("Arone"));
	Arone.set_power(130);
	Arone.set_speed(110);
	Arone.set_stamina(200);
	Arone.set_will(80);
	versus_character_set[count] = Arone;
	count++;

}

void reset_values(){
	speed_count = 0;
	stamina_count = 0;
	power_count = 0;
	will_count = 0;
	intellect_count = 0;

	speed_level = 1;
	stamina_level = 1;
	power_level = 1;
	will_level = 1;
	intellect_level = 1;

	turn = 0;
}

void status_setup(){
//	if (character_id == 1){//rice
//		speed = 71;
//		stamina = 117;
//		power = 70;
//		will = 102;
//		intellect = 90;
//	} else if (character_id == 2){//mihono
//		speed = 96;
//		stamina = 72;
//		power = 92;
//		will = 102;
//		intellect = 88;
//	} else if (character_id == 3){//daiwa
//		speed = 84;
//		stamina = 77;
//		power = 79;
//		will = 95;
//		intellect = 90;
//	} else if (character_id == 4){//vodka
//		speed = 96;
//		stamina = 61;
//		power = 105;
//		will = 75;
//		intellect = 88;
//	}
}

struct character training(struct character current_character){
	string train;
	int train_done = 0;

	cout << "Turn " << turn + 1 << " - Select what to train." << endl;
	turn++;
	cout << current_character.get_name() << "'s HP is " << current_character.get_current_hp() << "!" << endl;
	showSucceedRate(current_character);
	cout << "speed: " << current_character.get_speed() << endl;
	cout << "stamina: " << current_character.get_stamina() << endl;
	cout << "power: " << current_character.get_power() << endl;
	cout << "will: " << current_character.get_will() << endl;
	cout << "intellect: " << current_character.get_intellect() << endl;
	cout << "take a break!" << endl;

	while(!train_done){
		cin >> train;
		if(train == "speed" || train == "1"){
			if(train_success(current_character.get_current_hp())){
				cout << "Training succeed!" << endl;
				current_character.set_speed((current_character.get_speed())+ 18 * (1 + 0.2*(speed_level-1)));
				current_character.set_power((current_character.get_power())+ 6 * (1 + 0.2*(speed_level-1)));
				speed_count++;
				if(speed_count == 5 && speed_level < 5){
					speed_level++;
					speed_count = 0;
					cout << "Speed level increased!" << speed_level - 1 << " -> " << speed_level << endl;
				}
			}else{
				cout << "Training failed..." << endl;
				Sleep(500);
			}
			if(current_character.get_current_hp() <= 23){
				current_character.set_current_hp(0);
			} else {
				current_character.set_current_hp(current_character.get_current_hp()-23);
			}
			train_done = 1;
		} else if(train == "stamina" || train == "2"){
			if(train_success(current_character.get_current_hp())){
				cout << "Training succeed!" << endl;
				current_character.set_stamina(current_character.get_stamina()+18*(1 + 0.2*(stamina_level-1)));
				current_character.set_will(current_character.get_will()+6*(1 + 0.2*(stamina_level-1)));
				stamina_count++;
				if(stamina_count == 5 && stamina_level < 5){
					stamina_level++;
					stamina_count = 0;
					cout << "Stamina level increased!" << stamina_level - 1 << " -> " << stamina_level << endl;
				}
			} else {
				cout << "Training failed..." << endl;
				Sleep(500);
			}
			if(current_character.get_current_hp() <= 23){
				current_character.set_current_hp(0);
			} else {
				current_character.set_current_hp(current_character.get_current_hp()-23);
			}
			train_done = 1;
		} else if(train == "power" || train == "3"){
			if(train_success(current_character.get_current_hp())){
				cout << "Training succeed!" << endl;
				current_character.set_stamina(current_character.get_stamina() + 6*(1 + 0.2*(power_level-1)));
				current_character.set_power(current_character.get_power() + 18*(1 + 0.2*(power_level-1)));
				power_count++;
				if(power_count == 5 && power_level < 5){
					power_level++;
					power_count = 0;
					cout << "Power level increased!" << power_level - 1 << " -> " << power_level << endl;
				}
			} else {
				cout << "Training failed..." << endl;
				Sleep(500);
			}
			if(current_character.get_current_hp() <= 23){
				current_character.set_current_hp(0);
			} else {
				current_character.set_current_hp(current_character.get_current_hp()-23);
			}
			train_done = 1;
		} else if(train == "will" || train == "4"){
			if(train_success(current_character.get_current_hp())){
				cout << "Training succeed!" << endl;
				current_character.set_speed(current_character.get_speed()+5*(1 + 0.2*(will_level-1)));
				current_character.set_power(current_character.get_power()+5*(1 + 0.2*(will_level-1)));
				current_character.set_will(current_character.get_will()+14*(1 + 0.2*(will_level-1)));
				will_count++;
				if(will_count == 5 && will_level < 5){
					will_level++;
					will_count = 0;
					cout << "Will level increased!" << will_level - 1 << " -> " << will_level << endl;
				}
			} else {
				cout << "Training failed..." << endl;
				Sleep(500);
			}
			if(current_character.get_current_hp() <= 23){
				current_character.set_current_hp(0);
			} else {
				current_character.set_current_hp(current_character.get_current_hp()-23);
			}
			train_done = 1;
		} else if(train == "intellect" || train == "5"){
			if(train_success(current_character.get_current_hp())){
				cout << "Training succeed!" << endl;
				current_character.set_speed(current_character.get_speed()+6*(1 + 0.2*(intellect_level-1)));
				current_character.set_intellect(current_character.get_intellect()+18*(1 + 0.2*(intellect_level-1)));
				intellect_count++;
				if(intellect_count == 5 && intellect_level < 5){
					intellect_level++;
					intellect_count = 0;
					cout << "Intellect level increased!" << intellect_level - 1 << " -> " << intellect_level << endl;
				}
			} else {
				cout << "Training failed..." << endl;
				Sleep(500);
			}
			current_character.set_current_hp(current_character.get_current_hp()+5);
			train_done = 1;
		} else if(train == "break" || train == "6"){
			current_character.set_current_hp(current_character.get_current_hp()+40);
			train_done = 1;
		} else if(train=="help"){
			cout<< "speed or 1: increases speed mainly, and a bit of power." << endl;
			cout<< "stamina or 2: increases stamina mainly, and a bit of will." << endl;
			cout<< "power or 3: increases power mainly, and a bit of stamina." << endl;
			cout<< "will or 4: increases will mainly, and a bit of speed and power." << endl;
			cout<< "intelligence or 5: increases intelligence mainly, and a bit of speed. Also restores hp for a bit." << endl;
			cout<< "break or 6: restores lots of hp." << endl;
		} else {
			cout << "Wrong command, please type correct commands. Type /'help/' to see the commands." << endl;
		}
	}
	return current_character;
}

void result(struct character current_character){
	cout << "Congratulation, Your Runner graduated!" << endl;
	cout << current_character.get_name() <<"\'s final status is:" << endl;
	cout << "speed: " << current_character.get_speed() << endl;
	cout << "stamina: " << current_character.get_stamina() << endl;
	cout << "power: " << current_character.get_power() << endl;
	cout << "will: " << current_character.get_will() << endl;
	cout << "intellect: " << current_character.get_intellect() << endl;
}

int train_success(int healthp){
	if(healthp >= 50){
		return 1;
	}else if (healthp <= 0){
		return 0;
	}else return (2*(((0.148*healthp)-7.071)*((0.148*healthp)-7.071)))<rand()%100+1;
}

void showSucceedRate(struct character current_character){
	int percentage = 0;
	percentage = (current_character.get_current_hp()>=50)?100:100-(2*(((0.148*(double)(current_character.get_current_hp()))-7.071)*((0.148*(double)(current_character.get_current_hp()))-7.071)));
	cout << "Percentage of Successful training is: " << percentage << "%" << endl;

}

void prepare(struct character current_character, struct character versus_character){
	Sleep(1000);
	cout << "prepare for the race!" << endl;
	Sleep(2000);
	cout << current_character.get_name() << ":" << endl;
	show_status(current_character);
	Sleep(2000);
	cout << versus_character.get_name() << ":" << endl;
	show_status(versus_character);
	Sleep(2000);
	cout << "type in anything to start the race!" << endl;
	string a;
	cin >> a;
	cin.clear();

}

void show_status(struct character this_chara){
	cout << "speed: " << this_chara.get_speed();
	cout << " stamina: " << this_chara.get_stamina();
	cout << " power: " << this_chara.get_power();
	cout << " will: " << this_chara.get_will();
	cout << " intellect: " << this_chara.get_intellect() << endl;

}

void versus(struct character current_character, struct character versus_character, int level){// will change into putting in arry of characters.
	//will be 1v1v1v1v1v1v1v1 instead of 1v1
	int total_distance = 20000;//1000m, *10 for floating value
//	bool is_flat_space = 0;
	int ran_distance = 0;
	double cur_stamina = (double)(current_character.get_stamina());
	int versus_ran_distance = 0;
	double versus_cur_stamina = (double)(versus_character.get_stamina());
	int first_surface_c = (rand()%2+1)*3000;
	int secont_sufrace_c = (rand()%2+1)*7000;
	int first_flat[2] = {0, first_surface_c};
	int first_uphill[2] = {first_surface_c,secont_sufrace_c};
	int second_flat[2] = {secont_sufrace_c, 0};
	char *winner;
	int floor_type = 0;//0 flat, 1 uphill, 2 downhill
	int versus_floor_type = 0;
	while(ran_distance < total_distance && versus_ran_distance < total_distance){
		if(cur_stamina<50){
			cout << current_character.get_name() << " is almost out of stamina!" << endl;
		}
		cout << current_character.get_name() << " ran " << (double)ran_distance/10 << " m in total!" << endl;
		//visualization of progress
		for(int i = 0; i < ran_distance/1000; i++){
			cout << " ";
		}
		cout << "O";
		cout << endl;
		for(int i = 0; i < total_distance/1000; i++){
			if(i*1000> first_uphill[0] && i*1000<first_uphill[1]){
				cout << "^";
			}else{
				cout << "-";
			}
		}
		cout << endl;
		if(floor_type == 0){
			cur_stamina -= 5*level*0.75;
		}else if(floor_type == 1){
			cur_stamina -= 10*level*0.75;
		}
		if(cur_stamina<0){
			cur_stamina = 0;
		}
		// flat distance below 3000!
			ran_distance += additional_run(current_character, floor_type, cur_stamina);
//			cout << "ran: " << additional_run(current_character, floor_type, cur_stamina) << endl;
//			cout << "cur_stamina: " << cur_stamina << endl;

			cout<<endl;
//			cout<<additional_run(current_character, floor_type, cur_stamina)<<endl;
		if(versus_cur_stamina<50){
			cout << versus_character.get_name() << " is almost out of stamina!" << endl;
		}
		cout << versus_character.get_name() << " ran " << (double)versus_ran_distance/10 << " m in total!" << endl;
		//visualization of versus progress
		for(int i = 0; i < versus_ran_distance/1000; i++){
			cout << " ";
		}
		cout << "O";
		cout << endl;
		for(int i = 0; i < total_distance/1000; i ++){
			if(i*1000> first_uphill[0] && i*1000<first_uphill[1]){
				cout << "^";
			}else{
				cout << "-";
			}
		}
		cout << endl;
		if(versus_floor_type == 0){
			versus_cur_stamina -= 5*level*0.75;
		}else if(versus_floor_type == 1){
			versus_cur_stamina -= 10*level*0.75;
		}
		if(versus_cur_stamina<0){
			versus_cur_stamina = 0;
		}
			versus_ran_distance += additional_run(versus_character, versus_floor_type, versus_cur_stamina);
//			cout << "ran: " << additional_run(versus_character, versus_floor_type, versus_cur_stamina) << endl;
//			cout << "versus_cur_stamina: " << versus_cur_stamina << endl;



			cout <<endl;
//			cout<<additional_run(versus_character, versus_floor_type, versus_cur_stamina)<<endl;
		// uphill distance between 3000 and 6000!
			if(ran_distance > first_uphill[0] && ran_distance <= first_uphill[1] && floor_type == 0){
				cout << current_character.get_name() << " entered to uphill!" << endl;
				floor_type = 1;
			}
			if(versus_ran_distance > first_uphill[0] && versus_ran_distance <= first_uphill[1] && versus_floor_type == 0){
				cout << versus_character.get_name() << " entered to uphill!" << endl;
				versus_floor_type = 1;
			}

		//flat again after 7000!
			if(ran_distance > second_flat[0] && floor_type == 1){
				cout << current_character.get_name() << " entered to flat floor!" << endl;
				floor_type = 0;
			}
			if(versus_ran_distance > second_flat[0] && versus_floor_type == 1){
				cout << versus_character.get_name() << " entered to flat floor!" << endl;
				versus_floor_type = 0;
			}

		Sleep(1000);
	}
	bool is_draw = 0;
	if(ran_distance > versus_ran_distance){
		cout << "Congratulation! " << current_character.get_name() << " win!" << endl;
		winner = current_character.get_name();
	}else if(ran_distance == versus_ran_distance){
		cout << "Draw!" << endl;
		is_draw = 1;
	}else{
		cout << current_character.get_name() << " lost..." << endl;
		winner = versus_character.get_name();
	}
	Sleep(1000);
	if(is_draw == 0){
		cout<< "---------------------------------------------------" << endl;
		cout << "Winner: " << winner << "!" << endl;
		cout<< "---------------------------------------------------" << endl;
	}else{
		cout << "there is no winner!" << endl;
	}


}

double additional_run(struct character chara, int floor_type, double current_stamina){
	switch(floor_type){
	case 0://flat floor
		return chara.get_speed()*2 + chara.get_power()*1 - (50-current_stamina);
		break;
	case 1://up hill floor
		return chara.get_speed()*1 + chara.get_power()*1.5 - (100-current_stamina);
		break;
	case 2://down hill floor
		return chara.get_speed()*1 + chara.get_power()*3- (70-current_stamina);
		break;
	default:
		return 0;
		break;
	}

}
