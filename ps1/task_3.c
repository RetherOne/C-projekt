#include <superkarel.h>

bool exist_beeper();
void turn_right();
void pick_beepers();
void put_first_beepers();
void put_beepers();
void cycle();
void come_back();

int main(){
	turn_on("task_3.kw");
	set_step_delay(50);
	pick_beepers();
	turn_left();
	turn_left();
	put_first_beepers();
	while(true){
		if(front_is_blocked() && left_is_blocked()){
			break;
		}
		cycle();
	}
	come_back();
	turn_off();
}

void turn_right(){
	set_step_delay(0);
	turn_left();
	turn_left();
	turn_left();
	set_step_delay(50);
}

void pick_beepers(){
	while(front_is_clear()){
		while(beepers_present()){
			pick_beeper();
		}
		step();
	}
	if(beepers_present()){
		pick_beeper();
	}
}

void put_first_beepers(){
	while(front_is_clear()){
		if(right_is_blocked() && no_beepers_present() && beepers_in_bag()){
			put_beeper();
		}
		step();
	}
	if(right_is_blocked()){
		put_beeper();
	}
}

bool exist_beeper(){
	turn_right();
	step();
	if(beepers_present()){
		turn_left();
		turn_left();
		step();
		turn_right();
		return true;
	}
	else{
		turn_left();
		turn_left();
		step();
		turn_right();
		return false;
	}
	
}

void put_beepers(){
	while(front_is_clear()){
		if(beepers_in_bag()){
			if(exist_beeper() && no_beepers_present() && beepers_in_bag()){
				put_beeper();
			}
			step();
		}
		else{
			step();
		}
	}
}

void cycle(){
	turn_left();
	step();
	turn_left();
	pick_beepers();
	turn_left();
	turn_left();
	put_beepers();
	if(beepers_in_bag()){
		if(exist_beeper()){
			put_beeper();
		}
	}
}

void come_back(){
	turn_left();
	turn_left();
	while(no_beepers_present()){
		step();
		if(front_is_blocked()){
			while(not_facing_north()){
				turn_left();
			}
			step();
			if(right_is_blocked()){
				turn_left();
			}
			else if(left_is_blocked() && no_beepers_present()){
				turn_right();
			}
		}
	}
	while(not_facing_north()){
		turn_left();
	}
	while(front_is_clear()){
		step();
	}
	turn_left();
	while(front_is_clear()){
		step();
	}
	while(not_facing_east()){
		turn_left();
	}
}
