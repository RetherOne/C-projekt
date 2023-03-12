#include <superkarel.h>

void turn_right();
void pick_beepers();
void find();
void back();

int main(){
    turn_on("task_2.kw");
    set_step_delay(200);
    find();
    while(beepers_present()){
        pick_beepers();
    }
    back();
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
    set_step_delay(0);
    while(beepers_present()){
        pick_beeper();
    }
    set_step_delay(200);
}

void find(){
    while(no_beepers_present()){
        if(front_is_blocked()){
            turn_left();
        }
        else{
            step();
        }
    }
}

void back(){
    turn_right();
    turn_right();
    while(true){
        if(front_is_blocked() && right_is_blocked() && left_is_blocked()){
            break;
        }
        else{
            if(front_is_blocked()){
                turn_right();
            }
            else{
                step();
            }
        }

    }     
}
