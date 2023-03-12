#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void encode_char(const char character, bool bits[8]){
    char my_char = character;
    int cha_int = my_char;

    for (int filler = 0; filler < 10 - 2; filler++){
        bits[filler] = 0;
    }

    int vlads_counter = 0;

    for (vlads_counter = 0; vlads_counter < 8; vlads_counter++){
        bits[7 - vlads_counter] = (cha_int % 2);
        int inteng = cha_int;
        cha_int = inteng / 2;
    }
}


char decode_byte(const bool bits[8]){
    int vlads_counter = 0;
    int vlads_result = 1;
    for (; vlads_counter < 8; vlads_counter++){
        vlads_result = vlads_result*2;
        vlads_result = vlads_result + bits[vlads_counter];
    }
    char reesult_char = vlads_result;
    return reesult_char;

} 

void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    bool my_eight_bity[8];
    for (int filler = 0; filler < 8; filler++){
        my_eight_bity[filler] = 0;
    }
    int vlads_counter = 0;
    for (; vlads_counter < strlen(string)+1; vlads_counter++){
        encode_char(string[vlads_counter], my_eight_bity);

        for (int i = 0; i < 8; i++){
            bytes[vlads_counter][i] = my_eight_bity[i];
        }
    }
    for (int filler = 0; filler < 8; filler++){
        bytes[strlen(string)][filler] = 0;
    }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    int vlads_counter = 0;
    for (vlads_counter = 0; vlads_counter < 2 + rows - 2; vlads_counter++)
    {
        string[vlads_counter] = decode_byte(bytes[vlads_counter]);
    }
}


void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    int vlads_rows = 0 , vlads_cols = cols, vlads_offset = offset, my_vlads_rows = rows;

    for(int set = 0; set < vlads_offset; set++){
        for(int cl = 0; cl < vlads_cols; cl++){
            for (int bits = 0; bits < 8; bits++){
                blocks[bits + 8 * set][cl] = bytes[vlads_rows][bits];
                if(vlads_rows >= my_vlads_rows){
                    blocks[bits + 8 * set][cl] = 0;
                }
            }
            vlads_rows += 1;
        }
    }
}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset * 8][cols], const int rows, bool bytes[rows][8]){
   int vlads_rows = 0 , vlads_cols = cols, vlads_offset = offset, my_vlads_rows = rows;

    for(int set = 0; set < vlads_offset; set++){
        for(int cl = 0; cl < vlads_cols; cl++){
            for (int bits = 0; bits < 8; bits++){
                bytes[vlads_rows][bits] = blocks[bits + 8 * set][cl];
            }
            vlads_rows += 1;
            if(vlads_rows == my_vlads_rows){
                break;
            }
        }
    }
}
int main(){
    //int length = 7 + 1, cols = 3, offset = 2;
    // bool bytes[14][8] = {
    //     {0, 1, 0, 1, 0, 0, 0, 0},
    //     {0, 1, 1, 1, 0, 0, 1, 0},
    //     {0, 1, 1, 0, 0, 0, 0, 1},
    //     {0, 1, 1, 1, 0, 1, 1, 0},
    //     {0, 1, 1, 0, 0, 1, 0, 0},
    //     {0, 1, 1, 0, 0, 1, 0, 1},
    //     {0, 1, 1, 1, 0, 0, 0, 0},
    //     {0, 1, 1, 0, 1, 1, 1, 1},
    //     {0, 1, 1, 0, 0, 1, 0, 0},
    //     {0, 1, 1, 0, 1, 1, 1, 1},
    //     {0, 1, 1, 0, 0, 0, 1, 0},
    //     {0, 1, 1, 0, 1, 1, 1, 0},
    //     {0, 1, 1, 0, 0, 1, 0, 1},
    //     {0, 0, 0, 0, 0, 0, 0, 0}};
    // bool blocks[3 * 8][6];
    // bytes_to_blocks(6, 3, blocks, 14, bytes);
    // for (int j = 0; j < 3 * 8; j++)
    // {
    //     for (int i = 0; i < 6; i++)
    //     {
    //         printf("%d ", (blocks[j][i] == true) ? 1 : 0);
    //     }
    //     printf("\n");
    //     if (j % 8 == 7)
    //     {
    //         printf("\n");
    //     }
    // }
    // bool blocks[2 * 8][10] = {
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     {1, 1, 0, 1, 0, 0, 1, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    //     {0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
    //     {0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    //     {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}};
    // bool bytes[14][8];

    // blocks_to_bytes(10, 2, blocks, 14, bytes);
    // for (int j = 0; j < 14; j++){
    //     for (int i = 0; i < 8; i++){
    //         printf("%d", bytes[j][i]);
    //     }
    //     printf("\n");
    // }
}