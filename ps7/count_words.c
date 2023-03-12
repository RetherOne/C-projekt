#include <stdio.h>

int convert_to_asc2(int number) {
    return 48 + number;
}

int main(  ){
    FILE *open_file = fopen(argv[1], "r");
    int vlads_result = 0, vlads_coun = 0, i = 0;
    char vlads_veta_c = fgetc(open_file), vlads_veta[9999];
    

    while (vlads_veta_c != EOF){
        vlads_veta[i] = vlads_veta_c;
        vlads_veta_c = fgetc(open_file);
        i++;
    }

    while(vlads_veta[vlads_coun] != '\0'){

        if (vlads_veta[vlads_coun] == 'A' || vlads_veta[vlads_coun] == 'a'){
            vlads_coun += 1;
            if (vlads_veta[vlads_coun] == 'N' || vlads_veta[vlads_coun] == 'n'){
                vlads_coun += 1;
                if (vlads_veta[vlads_coun] == 'a' || vlads_veta[vlads_coun] == 'A'){
                    vlads_coun += 1;
                    if (vlads_veta[vlads_coun] == 'N' || vlads_veta[vlads_coun] == 'n'){
                        vlads_coun += 1;
                        if (vlads_veta[vlads_coun] == 'a' || vlads_veta[vlads_coun] == 'A'){
                            vlads_coun += 1;
                            if (vlads_veta[vlads_coun] == 'S' || vlads_veta[vlads_coun] == 's'){
                                vlads_result += 1;
                            }
                            vlads_coun--;
                        }
                        vlads_coun--;
                    }
                    vlads_coun--;
                }
                vlads_coun--;
            }
            vlads_coun--;
        }
        vlads_coun++;
    }

    fclose(open_file);

    open_file = fopen(argv[1], "w");
    
    if(vlads_result>9){
        int vlads_result2 = vlads_result / 10;
        fputc(convert_to_asc2(vlads_result2), open_file);
        vlads_result = vlads_result - vlads_result2 * 10;
    }
    fputc(convert_to_asc2(vlads_result), open_file);

    fclose(open_file);
}