#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void printHourBin(int hour){
    int i, k;
    char* hour_ones_bits[4]; 
    char* hour_tens_bits[2];
    int ones = hour % 10;
    int tens = hour / 10; 
    printf("tens:%d ones:%d\n",tens,ones);
    for(i = 3; i >= 0; i--){
        k = ones >> i;
        if(k & 1){
            hour_ones_bits[i] = '1';
        }else {
            hour_ones_bits[i] = '0';
        }
    }
    for(i = 1; i >= 0; i--){
        k = tens >> i;
        if(k & 1){
            hour_tens_bits[i] = '1';
        }else {
            hour_tens_bits[i] = '0';
        }
    }
    for(i = 3; i >= 0; i--){
        printf("%c,",hour_ones_bits[i]);
    }
    printf("\n");
    for(i = 1; i >= 0; i--){
        printf("%c,",hour_tens_bits[i]);
    }
}

void printMinBin(int min){

}

int main(void){
    struct tm *info;
    time_t current_time;
    char* time_as_string;
    
    current_time = time(NULL);
    info = gmtime(&current_time);

    time_as_string = ctime(&current_time);
    printf("%s\n",time_as_string);
    printf("The hour is %d\n",info->tm_hour);
    printHourBin(info->tm_hour);
    return 0;
}