#include <stdio.h>
#include <math.h>

double b_coefficients(int a, int b){
    double result = 1;
    for (int i = 1; i <= b; ++i){
        result *= (a - b + i);
        result = result / i;
    }
    return result;
}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
    float sl = stick_length, hw = human_weight, cw = car_weight, result;
    result = round(sl * hw / (hw + cw) * 100);
    return result / 100;
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    float result = round(pack_price / rolls_count / pieces_count * 10000);
    return result / 100;
}

int collatz(const int number){
    int i, n;
    n = number;
    i = 1;
    while( n != 1){
        if(n % 2 == 0){
            n = n / 2;
            i += 1;
        }
        else{
            n = 3 * n + 1;
            i += 1;
        }
    }
    return i;
}

int opposite_number(const int n, const int number){
    int circle = n, num = number, result;
    result = circle/2 + num;
    if (result >= n){
        result = result - n;
    }
    return result;
}

void counter(const int input_array[], const int array_size, int result_array[2]){
    int i;
    result_array[0] = result_array[1] = 0;
    for (i = 0; i < array_size; ++i){
        result_array[0] = result_array[0] + input_array[i];
        i+=1;
        if (i < array_size){
            result_array[1] = result_array[1] + input_array[i];
        }
    }
}

unsigned long sum_squared(const int line){
    if(line == 0){
        return 1;
    }
    
    int l = line;
    long result[1];
    result[0] = b_coefficients(2 * l, l);
    return result[0];
}

unsigned long special_counter(const int input_array[], const int array_size){
    int result = 0;
    for (int i = 0; i < array_size; i++){
        result += input_array[i];
        i++;
        if (i < array_size){
            result += pow(input_array[i], 2);
        }
    }
    return result;
}

int array_min(const int input_array[], const int array_size){
    if (input_array == NULL){
        return -1;
    }
    int result = input_array[0];
    for (int i = 1; i < array_size; i++){
        if (input_array[i] < result){
            result = input_array[i];
        }
    }
    return result;
}

int array_max(const int input_array[], const int array_size){
    if (input_array == NULL){
        return -1;
    }
    int result = input_array[0];
    for (int i = 1; i < array_size; i++){
        if (input_array[i] > result){
            result = input_array[i];
        }
    }
    return result;
}

int special_numbers(const int input_array[], const int array_size, int result_array[]){
    int i, j, sum, result = 0, size = array_size;

    for (i = 0; i < array_size; i++){
        result_array[i] = 0;
    }

    for (i = 0; i < size; i++){

        sum = 0;

        for (j = i + 1; j < size; j++){
            sum += input_array[j];
        }
        if (input_array[i] > sum){
            result_array[result] += input_array[i];
            result += 1;
        }
    }
    return result;
}


int main(){
    // 1printf("%.4f\n", lift_a_car(9, 83, 2552));
    // 2 printf("%.4f\n", unit_price(4.79, 16, 150));
    // 3 printf("%d\n", collatz(35));
    // 4 printf("%d\n", opposite_number(12, 9));
    // 5int input_array[] = {1, 2, 3, 4, 5};
    // 5int result_array[2];
    // 5counter(input_array, 5, result_array);
    // 5printf("%i %i\n", result_array[0], result_array[1]);
    // 6printf("%lu\n", sum_squared(4));
    // 7int input_array[] = {8, 8, 11, 6, 2};
    // 7printf("%d\n", array_min(input_array, 5));
    // 7printf("%d\n", array_max(input_array, 5));
    // 7printf("%d\n", array_max(NULL, 5));
    // 8int input_array[] = {11, 12, 13, 14, 15};
    // 8printf("%lu\n", special_counter(input_array, 5));
    // 9int input_array[] = {16, 17, 4, 3, 5, 2};
    // 9int result_array[6];
    // 9int count = special_numbers(input_array, 6, result_array);
    // 9for (int i = 0; i < count; i++){
    // 9    printf("%d ", result_array[i]);
    // 9}
    // 9printf("\n");
    return 0;
}
