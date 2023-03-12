#include <stdio.h>


int main(int argc, char *argv[]){
    int vlads_coun_start = 0, vlads_coun_stop;
    FILE *open_input_file = fopen(argv[1], "r");
    char vlads_veta_c = fgetc(open_input_file), vlads_veta[9999];

    int i = 0;
    while(vlads_veta_c != EOF){
        vlads_veta[i] = vlads_veta_c;
        vlads_veta_c = fgetc(open_input_file);
        i++;
    }

    fclose(open_input_file);

    while (vlads_veta[vlads_coun_start] != '\0'){
        if (vlads_veta[vlads_coun_start] == 'S'){
            vlads_coun_start += 1;
            if (vlads_veta[vlads_coun_start] == 'T'){
                vlads_coun_start += 1;
                if (vlads_veta[vlads_coun_start] == 'A'){
                    vlads_coun_start += 1;
                    if (vlads_veta[vlads_coun_start] == 'R'){
                        vlads_coun_start += 1;
                        if (vlads_veta[vlads_coun_start] == 'T'){
                            break;
                        }
                    }
                }
            }
        }
        vlads_coun_start += 1;
    }
    vlads_coun_stop = vlads_coun_start;

    while (vlads_veta[vlads_coun_stop] != '\0'){
        if (vlads_veta[vlads_coun_stop] == 'S'){
            vlads_coun_stop += 1;
            if (vlads_veta[vlads_coun_stop] == 'T'){
                vlads_coun_stop += 1;
                if (vlads_veta[vlads_coun_stop] == 'O'){
                    vlads_coun_stop += 1;
                    if (vlads_veta[vlads_coun_stop] == 'P'){
                            break;
                        }
                    }
                }
            }
        vlads_coun_stop++;
    }
    FILE *open_output_file = fopen(argv[2], "w");

    vlads_coun_stop -= 5;
    vlads_coun_start +=2;

    int j = 0;

    while(vlads_veta[vlads_coun_start] != ' '){
            vlads_coun_start++;
        }
    vlads_coun_start++;

    while(vlads_coun_start < vlads_coun_stop){

        while (vlads_veta[vlads_coun_start] != ' '){
            fputc(vlads_veta[vlads_coun_start], open_output_file);
            j++;
            vlads_coun_start++;
        }
        vlads_coun_start++;

        while(vlads_veta[vlads_coun_start] != ' '){
            vlads_coun_start++;
        }
        vlads_coun_start++;
        
        if (vlads_coun_start < vlads_coun_stop){
            fputc(32, open_output_file);
        }
    }
}