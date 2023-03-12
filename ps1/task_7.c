#include <superkarel.h>

void turn_right();
void input_find();
void rule_r();
void check();
void mark();

int main(){
	turn_on("task_7.kw");
    set_step_delay(200);
    input_find();
    turn_left();
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_left();
    turn_left();
    while(left_is_blocked()){
        step();
    }
    turn_left();
    while(true){
        rule_r();
        turn_left();
        if(front_is_clear()){
            step();
        }
        else{
            break;
        }
        while(no_beepers_present()){
            if(front_is_blocked()){
                break;
            }
            step();
        }
        if(front_is_clear() || left_is_clear()){
            turn_left();
        }
        else{
            break;
        }
    }
    turn_left();
    turn_left();
    while(no_beepers_present()){ 
        step();
    }
    mark();
    turn_left();
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_off();
}

void turn_right(){
	set_step_delay(0);
	turn_left();
	turn_left();
	turn_left();
    set_step_delay(200);
}

void input_find(){
    while(front_is_clear()){
        if(left_is_clear()){
            put_beeper();
        }
            step();
    }

    if(left_is_clear()){
        put_beeper();
    }
}

void rule_r(){
    put_beeper();
    step();
    while(no_beepers_present()){
        if(right_is_blocked()){
            if(front_is_blocked()){
                if(left_is_blocked()){
                    turn_left();
                }
                turn_left();
            }
            step();
        }
        else{
            turn_right();
            step();
        }
         
    }
    put_beeper();
}

void check(){
    if(!beepers_present()){
        turn_right();
        step();
        put_beeper();
        turn_left();
        turn_left();
        step();
        turn_right();
    }
    else{
        pick_beeper();
    }
}

void mark(){
    while(front_is_clear()){
        if(beepers_present()){
            pick_beeper();
            pick_beeper();
        }
        check();
        while(no_beepers_present() && front_is_clear()){
            step();
        }
    }
    if(beepers_present()){
        pick_beeper();
        pick_beeper();
    }
    if(right_is_clear()){
        check();
    }
}
