#include<stdio.h>
//时间转换程序，主要是美食区羊话出现人传人现象

void change_year(double var_year)
{
    printf("%lf年的转化如下：\n",var_year);
    printf("%lf年\n",var_year);
    printf("%lf月\n",var_year*12);
    printf("%lf天\n",var_year*365);
    printf("%lf小时\n",var_year*365*24);
    printf("%lf分钟\n",var_year*365*24*60);
    printf("%lf秒\n",var_year*365*24*60*60);
}

void change_month(double var_year)
{
    printf("%lf月的转化如下：\n", var_year);
    printf("%lf年\n", var_year/12);
    printf("%lf月\n", var_year );
    printf("%lf天\n", var_year * 30);
    printf("%lf小时\n", var_year * 30 * 24);
    printf("%lf分钟\n", var_year * 30 * 24 * 60);
    printf("%lf秒\n", var_year * 30 * 24 * 60 * 60);
}
void change_day(double var_year)
{
    printf("%lf天的转化如下：\n",var_year);
    printf("%lf年\n",var_year/(12*30));
    printf("%lf月\n",var_year/30);
    printf("%lf天\n",var_year);
    printf("%lf小时\n",var_year*24);
    printf("%lf分钟\n",var_year*24*60);
    printf("%lf秒\n",var_year*24*60*60);
}
void change_hour(double var_year)
{
    printf("%lf小时的转化如下：\n",var_year);
    printf("%lf年\n",var_year/(12.0*30.0*24.0));
    printf("%lf月\n",var_year/(30*24));
    printf("%lf天\n",var_year/24);
    printf("%lf小时\n",var_year);
    printf("%lf分钟\n",var_year*60);
    printf("%lf秒\n",var_year*60*60);
}
void change_minute(double var_year)
{
    printf("%lf分钟的转化如下：\n",var_year);
    printf("%lf月\n",var_year/(24*30*60));
    printf("%lf天\n",var_year/(30*60));
    printf("%lf小时\n",var_year/60);
    printf("%lf分钟\n",var_year);
    printf("%lf秒\n",var_year*60);
}
void change_second(double var_year)
{
    printf("%lf秒的转化如下：\n",var_year);
    printf("%lf天\n",var_year/(30*60*60));
    printf("%lf小时\n",var_year/(3600));
    printf("%lf分钟\n",var_year/60);
    printf("%lf秒\n",var_year);
}
int main()
{
    int char_in;
    double var_time;
    //get the type of which need to change
    printf("请输入所选择需要转换的时间类型：\n");
    printf("1.年,2.月,3.日,4.小时,5.分钟,6.秒\n");
    scanf("%d",&char_in);
    //change_year(char_in);

    printf("请输入要转换的时间数：");
    scanf("%lf",&var_time);
    switch (char_in)
    {
    case 1:change_year(var_time);
        break;
    case 2: change_month(var_time);break;

    case 3: change_day(var_time);break;
    case 4: change_hour(var_time);break;
    case 5: change_minute(var_time);break;
    case 6: change_second(var_time);break;

    default:
        printf("输入错误");
        break;
    }
    //这个程序真的事让我意识到C语言的类型转化有多难
    //离离原上谱
    return 0;
}