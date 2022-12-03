#include<stdio.h>
union card
{
        int name;
};

enum daysOfWeek{
    SAT,
    SUN,
    MON ,
	TUES
};


void main(){
	enum daysOfWeek day1=SAT;
	enum daysOfWeek day2=SUN;
    printf("%d \n",day1);
}