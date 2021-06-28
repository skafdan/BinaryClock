#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    struct tm *info;
    time_t current_time;
    char* time_as_string;
    
    current_time = time(NULL);
    info = gmtime(&current_time);

    time_as_string = ctime(&current_time);
    printf("%s\n",time_as_string);
    printf("The hour is %d\n",info->tm_hour);
    return 0;
}
