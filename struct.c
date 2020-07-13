#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct student {
        char name[10];
        int korea;
        int math;
        int english;
};
int PointFunction(struct student *std);

int main()
{
        struct student st[10];
        int i, j,seed;
        int total[3] = { 0,0,0 };
        double max = -1;
        double min = 101;
        int maxloc, minloc;
	
	seed=time(0);
	srand(seed);

        printf("Name   Korea   Math   Eng   Total   Avg\n");
        for (i = 0; i<10; i++)
        {
                PointFunction(&st[i]);
                printf("%c%c%c   %-7d%-7d%-7d%-7d   %lf\n", st[i].name[0],st[i].name[1],st[i].name[2], st[i].korea, st[i].math, st[i].english, st[i].korea + st[i].math + st[i].english, (st[i].korea + st[i].math + st[i].english) / 3.0);
                total[0] += st[i].korea;
                total[1] += st[i].math;
                total[2] += st[i].english;

                if (max < (st[i].korea + st[i].math + st[i].english) / 3.0)
                {
                        max = (st[i].korea + st[i].math + st[i].english) / 3.0;
                        maxloc = i;
                }
                if (min >(st[i].korea + st[i].math + st[i].english) / 3.0)
                {
                        min = (st[i].korea + st[i].math + st[i].english)/ 3.0;
                        minloc = i;
                }

        }
        printf("Average of Korea score %lf\n", total[0] / 10.0);
        printf("Average of Korea score %lf\n", total[1] / 10.0);
        printf("Average of Korea score %lf\n", total[2] / 10.0);
        printf("MAX average student = %c%c%c-->%lf\n",st[maxloc].name[0],st[maxloc].name[1],st[maxloc].name[2],max);
        printf("MIN average student = %c%c%c-->%lf\n",st[minloc].name[0],st[minloc].name[1],st[minloc].name[2],min);
        return 0;
}
int PointFunction(struct student*std)
{
        int k;
        for (k = 0; k < 3; k++)
        {
                std->name[k] = rand()%26 +65;
        }
        std->korea = rand() % 100+1;
        std->math = rand() % 100+1;
        std->english = rand() % 100+1;

        return 0;
}
