#include<superkarel.h>

void turn_right();
void pick_beepers();
void jump_over();
void jump_back();

int main(){
    turn_on("task_1.kw");
    set_step_delay(200);
    put_beeper();
    turn_left();
    step();
    turn_right();
    while(no_beepers_present()){
        jump_over();
        while(front_is_clear() && no_beepers_present()){
            step();
        }

    }
    pick_beepers();
    turn_left();
    step();
    turn_left();
    
    while(no_beepers_present()){
        jump_back();
        while(front_is_clear() && no_beepers_present()){
            step();
        }
    }

    pick_beepers();

    turn_off();
}

void pick_beepers(){
    while(beepers_present()){
        pick_beeper();
    }
}

void jump_over(){
    turn_left();
    while(right_is_blocked()){
        step();
    }
    turn_right();
    step();
    while(right_is_blocked()){
        step();
    }
    turn_right();
    while(front_is_clear()){
        step();
    }
    turn_left();
}

void jump_back(){
    turn_right();
    while(left_is_blocked()){
        step();
    }
    turn_left();
    step();
    while(left_is_blocked()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_right();
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    turn_left();
    set_step_delay(200);
}

