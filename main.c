#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void printHourBin(int hour){
    int i, k;
    char* hour_ones_bits[4]; 
    char* hour_tens_bits[2];
    int ones = hour % 10;
    int tens = hour / 10; 
    printf("Hour:%d Tens:%d, Ones:%d\n",hour,tens,ones);
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

void printMinuteBin(int minute){
    int i,k;
    char* minute_ones_bits[4];
    char* minute_tens_bits[4];
    int ones = minute % 10;
    int tens = minute / 10;
    printf("Minute:%d Tens:%d, Ones:%d\n",minute,tens,ones);
    for(i = 3; i >= 0; i--){
        k = ones >> i;
        if(k & 1){
            minute_ones_bits[i] = '1';
        }
        else {
            minute_ones_bits[i] = '0';
        }
    }
    for(i = 3; i >= 0; i--){
        k = tens >> i;
        if(k & 1){
            minute_tens_bits[i] = '1';
        }
        else{
            minute_tens_bits[i] = '0'; 
        }
    }
    for(i = 3; i >= 0; i--){
        printf("%c,",minute_ones_bits[i]);
    }
    printf("\n");
    for(i = 3; i >= 0; i--){
        printf("%c,",minute_tens_bits[i]);
    }
}

int main(void){
    struct tm *info;
    time_t current_time;
    char* time_as_string;
    

    while(1==1){
        current_time = time(NULL);
        time_as_string = ctime(&current_time);
        printf(time_as_string);
        info = gmtime(&current_time);
        printHourBin(info->tm_hour);
        printf("\n");
        printMinuteBin(info->tm_min);
        printf("\n");
        sleep(1);
        system("/usr/bin/clear");
    }
    return 0;
}