#include <superkarel.h>
void direction();

int main(){
    turn_on("task_6.kw");
    set_step_delay(100);
    while(no_beepers_present()){
        step();
    }
    direction();
    turn_off();
}
void direction(){
    while(true){
        if(beepers_present()){
            while(not_facing_north()){
                turn_left();
            }pick_beeper();
            if(beepers_present()){
                while(not_facing_west()){
                    turn_left();
                }pick_beeper();
                if(beepers_present()){
                    while(not_facing_south()){
                        turn_left();
                        }
                        pick_beeper();
                    if(beepers_present()){
                        while(not_facing_east()){
                            turn_left();
                        }
                        pick_beeper();
                        if(beepers_present()){
                            pick_beeper();
                        break;
                        }
                    }
                }
            }
        }
        while(no_beepers_present()){
            step();
        }
    }
}
