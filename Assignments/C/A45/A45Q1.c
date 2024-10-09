#include<stdio.h>
#include<conio.h>

typedef struct TimePeriod 
{
    int hour;
    int minute;
    int second;

}TimePeriod;

TimePeriod findDiff(TimePeriod, TimePeriod);

int main()
{
    TimePeriod t1 = {24, 0, 0};
    TimePeriod t2 = {18, 30, 0};

    TimePeriod diff =  findDiff(t1, t2);

    if ( t1.hour*3600 + t1.minute*60 + t1.second > t2.hour*3600 + t2.minute*60 + t2.second )
        printf("The Difference between 2 Time Periods is -> %dhh:%dmm:%dss.\n", diff.hour, diff.minute, diff.second);
    else
        printf("The Difference between 2 Time Periods is -> -%dhh:%dmm:%dss.\n", diff.hour, diff.minute, diff.second);


    getch();
    return 0;
}

//@ Finding Difference Between 2 Time Periods
TimePeriod findDiff(TimePeriod t1, TimePeriod t2)
{
    TimePeriod diff;

    int t1Seconds = t1.hour*60*60+t1.minute*60+t1.second;
    int t2Seconds = t2.hour*60*60+t2.minute*60+t2.second;

    int diffsecond;

    if ( t1Seconds > t2Seconds )
        diffsecond = t1Seconds - t2Seconds;
    else 
        diffsecond = t2Seconds - t1Seconds;


    diff.hour = diffsecond / 3600;
    diffsecond %= 3600;
    diff.minute = diffsecond / 60;
    diffsecond %= 60;
    diff.second = diffsecond;


    return diff;

}
