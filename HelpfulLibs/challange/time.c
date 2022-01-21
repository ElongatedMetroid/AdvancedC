#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    time_t calendar = time(NULL);
    if(calendar == ((time_t)-1)){
        fprintf(stderr, "FAILED TO GET THE CURRENT TIME, EXITING\n");
        exit(EXIT_FAILURE);
    }

    struct tm* time_data;
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char *months[] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    time_data = localtime(&calendar);       //set elements of time_data tm struct to your local time

    printf("Today is %s %s %d %d\n", days[time_data->tm_wday], months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year+1900);

    return 0;
}