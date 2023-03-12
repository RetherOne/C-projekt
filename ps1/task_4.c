#include <superkarel.h>


void turn_right();
bool finder();
void crafter();
void ch_raw();


int main(){
	turn_on("task_4.kw");
	set_step_delay(100);
	turn_left();
	while(front_is_clear()){
		crafter();
		ch_raw();
	}
	turn_off();
}

void turn_right(){
	set_step_delay(0);
	turn_left();
	turn_left();
	turn_left();
	set_step_delay(100);
}

bool finder(){
	while(front_is_clear()){
		if(beepers_present()){
			return true;
		}
		step();
	}
	if(beepers_present()){
		return true;
	}
	return false;
}

void crafter(){
	if(finder()){
		while(front_is_clear()){
			if(no_beepers_present()){
				put_beeper();
			}
			step();
		}
		turn_left();
		turn_left();
		while(front_is_clear()){
			if(no_beepers_present()){
				put_beeper();
			}
			step();
		}
		if(no_beepers_present()){
			put_beeper();
		}
	}
	else{
		while(not_facing_south()){
			turn_left();
		}
	}
}
void ch_raw(){
	while(front_is_clear()){
		step();
	}
	turn_left();
	if(front_is_clear()){
		step();
		turn_left();
	}
}
