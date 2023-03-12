#include <superkarel.h>

void turn_right();
void pick_beepers();
void mid_find();
void corner();
void putter();
void around();

int main(){
	turn_on("task_5.kw");
    set_step_delay(200);
    corner();
	around();
	mid_find();
	turn_left();
	mid_find();
	turn_right();
	turn_off();
}

void turn_right(){
	set_step_delay(0);
	turn_left();
	turn_left();
	turn_left();
    set_step_delay(200);
}

void pick_beepers(){
	while(beepers_present()){
		pick_beeper();
	}
}

void mid_find(){
	
	step();
	step();
	if(front_is_clear()){
		mid_find();
		if(front_is_blocked()){
			turn_left();
			turn_left();
			step();
		}

		step();
		}
	if(front_is_blocked()){
			turn_left();
			turn_left();
			step();
		}
}

void corner(){
	while(not_facing_south()){
		turn_left();
	}
	while(front_is_clear()){
		step();
	}
	turn_right();
	while(front_is_clear()){
		step();
	}
	turn_right();
}

void putter(){
	while(front_is_clear()){
		
		if(no_beepers_present()){
			put_beeper();
		}
		step();
	}
}

void around(){
	putter();
	turn_right();
	putter();
	turn_right();
	putter();
	turn_right();
	putter();
	turn_right();
}
