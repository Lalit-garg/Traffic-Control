#include<graphics.h>
#include<iostream>
#include<unistd.h> 
#include<termios.h> 
#include<pthread.h>
#include<semaphore.h>
#include<algorithm>
#include<ctime>
#include<queue>
#include<iomanip>
using namespace std;
struct process
{
    int id;
    int bt;
};
queue<process> q;
process p[100],p2[100];
int pp[4];
bool com(process a,process b)
{
    if(a.bt>b.bt)
    {
        return 1;
    }
    return 0;
}
sem_t chance;
int c1=105;
int c2=105;
int c3=395;
int c4=105;
int cn1=0;
int cn2=0;
int cn3=0;
int cn4=0;

void move1(int xy)
{
	
	int i=c1,ji=c1,cnti=cn1;
	int k=400;
	int k2=105;
	int l=0,cnt=cn1;
	int cnt1=xy;
	int lane=0;
	while(cnt1)
	{	
		for (int z=1; z<8; z++)
        {
			setcolor(GREEN);
			circle(418,135,z);
		}
		setcolor(BLACK);
		rectangle(310+cnti,ji+20,320+cnti,ji+40);
		rectangle(312+cnti,ji+40,318+cnti,ji+45);
		setcolor(WHITE);
		if(cnti==60)
		{
			cnti=0;
			ji=ji-40;
		}
		else
		{
			cnti+=20;
		}
		for(;i<=k;i=i+5)
		{
			setcolor(WHITE);
			rectangle(310+cnt,i+20,320+cnt,i+40);
			rectangle(312+cnt,i+40,318+cnt,i+45);
			setcolor(BLACK);
			delay(25);
			rectangle(310+cnt,i+20,320+cnt,i+40);
			rectangle(312+cnt,i+40,318+cnt,i+45);
		}
		if(cnt==60)
		{
			cnt=0;
			lane+=40;
		}
		else
		{
			cnt+=20;
		}
		cnt1--;	
		i=c1-lane;	
	}
	c1=ji;
	cn1=cnti;
	for (int z=1; z<8; z++)
	{
		setcolor(RED);
		circle(418,135,z);
	}
	setcolor(WHITE);
}
//For moving
void move2(int xy)
{
	int i=c2;
	int k=400;
	int l=0,cnt=cn2;
	int cnt2=xy;
	int ji=c2;
	int cnti=cn2;
	int lane=0;
	while(cnt2)
	{	
		for (int z=1; z<8; z++)
        {
			setcolor(GREEN);
			circle(185,133,z);
		}
		setcolor(BLACK);
		rectangle(ji+70,cnti+160,ji+90,cnti+170);
		rectangle(ji+90,cnti+162,ji+95,cnti+168);
		setcolor(WHITE);
		if(cnti==60)
		{
			cnti=0;
			ji=ji-40;
		}
		else
		{
			cnti+=20;
		}
		for(;i<=k;i=i+5)
		{
			setcolor(WHITE);
			rectangle(i+70,cnt+160,i+90,cnt+170);
			rectangle(i+90,cnt+162,i+95,cnt+168);
			setcolor(BLACK);
			delay(25);
			rectangle(i+70,cnt+160,i+90,cnt+170);
			rectangle(i+90,cnt+162,i+95,cnt+168);
		}
		if(cnt==60)
		{
			cnt=0;
			lane=+40;
		}
		else
		{
			cnt+=20;
		}
		cnt2--;
		i=c2-lane;
	}
	c2=ji;
	cn2=cnti;
	for (int z=1; z<8; z++)
    {
		setcolor(RED);
		circle(185,133,z);
	}
	setcolor(WHITE);
}

void move3(int xy)
{
	int i=c3;
	int k=120;
	int l=0,cnt=cn3;
	int cnt3=xy;
	int ji=c3;
	int cnti=cn3;
	int lane=0;
	while(cnt3)
	{
		for (int z=1; z<8; z++)
        {
			setcolor(GREEN);
			circle(183,365,z);
		}
		setcolor(BLACK);
		rectangle(210+cnti,ji-20,220+cnti,ji-40);
		rectangle(212+cnti,ji-45,218+cnti,ji-40);
		setcolor(WHITE);
		if(cnti==60)
		{
			cnti=0;
			ji=ji+40;
		}
		else
		{
			cnti+=20;
		}
		for(;i>=k;i=i-5)
		{
			setcolor(WHITE);
			rectangle(210+cnt,i-20,220+cnt,i-40);
			rectangle(212+cnt,i-45,218+cnt,i-40);
			setcolor(BLACK);
			delay(25);
			rectangle(210+cnt,i-20,220+cnt,i-40);
			rectangle(212+cnt,i-45,218+cnt,i-40);
		}
		if(cnt==60)
		{
			cnt=0;
			lane+=40;
		}
		else
		{
			cnt+=20;
		}
		cnt3--;
		i=c3+lane;
	}
	c3=ji;
	cn3=cnti;	
	for (int z=1; z<8; z++)
        {
			setcolor(RED);
			circle(183,365,z);
		}
	setcolor(WHITE);
}

void move4(int xy)
{
	int i=c4;
	int k=400;
	int l=0,cnt=cn4;
	int cnt4=xy;
	int ji=c4;
	int cnti=cn4;
	int lane=0;
	while(k>0 && cnt4)
	{
		for (int z=1; z<8; z++)
        {
			setcolor(GREEN);
			circle(415,368,z);
		}
		setcolor(BLACK);
		rectangle(530-ji,cnti+260,510-ji,cnti+270);
		rectangle(510-ji,cnti+262,505-ji,cnti+268);
		setcolor(WHITE);
		if(cnti==60)
		{
			cnti=0;
			ji=ji-40;
		}
		else
		{
			cnti+=20;
		}
		for(;i<=k;i=i+5)
		{
			setcolor(WHITE);
			rectangle(530-i,cnt+260,510-i,cnt+270);
			rectangle(510-i,cnt+262,505-i,cnt+268);
			setcolor(BLACK);
			delay(25);
			rectangle(530-i,cnt+260,510-i,cnt+270);
			rectangle(510-i,cnt+262,505-i,cnt+268);
		}
		sem_post(&chance);
		if(cnt==60)
		{
			cnt=0;
			lane+=40;
		}
		else
		{
			cnt+=20;
		}
		cnt4--;
		i=c4-lane;
	}
	c4=ji;
	cn4=cnti;
	for (int z=1; z<8; z++)
    {
		setcolor(RED);
		circle(415,368,z);
	}
	setcolor(WHITE);
}

void makeroad()
{
	line(200,20,200,150); //vertical top1
	setlinestyle(3,0,1);
	line(300,20,300,150); //vertical top2
	setlinestyle(0,0,1);
	line(400,20,400,150); //vertical top3
	rectangle(400,145,435,125);
	for (int z=1; z<8; z++)
	{
		setcolor(RED);
		circle(418,135,z);
	}	
	setcolor(WHITE);
	line(70,150,200,150); //horizontal left1
	setlinestyle(3,0,1);
	line(70,250,200,250); //horizontal left2
	setlinestyle(0,0,1);
	line(70,350,200,350); //horizontal left3
	rectangle(195,150,175,115);
	for (int z=1; z<8; z++)
	{
		setcolor(RED);
		circle(185,133,z);
	}	
	setcolor(WHITE);
	line(400,150,530,150); //horizontal right1
	setlinestyle(3,0,1);
	line(400,250,530,250); //horizontal right2
	setlinestyle(0,0,1);
	line(400,350,530,350); //horizontal right3
	rectangle(405,350,425,385);
	for (int z=1; z<8; z++)
	{
		setcolor(RED);
		circle(415,368,z);
	}	
	setcolor(WHITE);
	line(200,350,200,480); //vertical bottom1
	setlinestyle(3,0,1);
	line(300,350,300,480); //vertical bottom2
	setlinestyle(0,0,1);
	line(400,350,400,480); //vertical bottom3
	rectangle(200,355,165,375);
	for (int z=1; z<8; z++)
	{
		setcolor(RED);
		circle(183,365,z);
	}	
	setcolor(WHITE);
	return;
}

void *car1(void *var)
{
	int i=20;
	int k=100;
	int l=0,cnt=0;
	int cnt1=pp[0];
	while(k>0 && cnt1)
	{
		sem_wait(&chance);
		for(i=0;i<=k;i=i+5)
		{
			setcolor(WHITE);
			rectangle(310+cnt,i+20,320+cnt,i+40);//1 car
			rectangle(312+cnt,i+40,318+cnt,i+45);//1 car
			setcolor(BLACK);
			delay(30);
			rectangle(310+cnt,i+20,320+cnt,i+40);
			rectangle(312+cnt,i+40,318+cnt,i+45);
		}
		setcolor(WHITE);
		rectangle(310+cnt,i+20,320+cnt,i+40);
		rectangle(312+cnt,i+40,318+cnt,i+45);
		sem_post(&chance);
		if(cnt==60)
		{
			cnt=0;
			k=k-40;
		}
		else
		{
			cnt+=20;
		}
		cnt1--;
	}
	return NULL;
}

void *car2(void *var)
{
	int i=0;
	int k=100;
	int l=0,cnt=0;
	int cnt2=pp[1];
	while(k>0 && cnt2)
	{
		sem_wait(&chance);
		for(i=0;i<=k;i=i+5)
		{
			setcolor(WHITE);
			rectangle(i+70,cnt+160,i+90,cnt+170);
			rectangle(i+90,cnt+162,i+95,cnt+168);
			setcolor(BLACK);
			delay(30);
			rectangle(i+70,cnt+160,i+90,cnt+170);
			rectangle(i+90,cnt+162,i+95,cnt+168);
		}
		setcolor(WHITE);
		rectangle(i+70,cnt+160,i+90,cnt+170);
		rectangle(i+90,cnt+162,i+95,cnt+168);
		sem_post(&chance);
		if(cnt==60)
		{
			cnt=0;
			k=k-40;
		}
		else
		{
			cnt+=20;
		}
		cnt2--;
	}
	return NULL;
}

void *car3(void *var)
{
	int i=485;
	int k=400;
	int l=0,cnt=0;
	int cnt3=pp[2];
	while(k<485 && cnt3)
	{
		sem_wait(&chance);
		for(i=485;i>=k;i=i-5)
		{
			setcolor(WHITE);
			rectangle(210+cnt,i-20,220+cnt,i-40);
			rectangle(212+cnt,i-45,218+cnt,i-40);
			setcolor(BLACK);
			delay(30);
			rectangle(210+cnt,i-20,220+cnt,i-40);
			rectangle(212+cnt,i-45,218+cnt,i-40);
		}
		setcolor(WHITE);
		rectangle(210+cnt,i-20,220+cnt,i-40);
		rectangle(212+cnt,i-45,218+cnt,i-40);
		sem_post(&chance);
		if(cnt==60)
		{
			cnt=0;
			k=k+40;
		}
		else
		{
			cnt+=20;
		}
		cnt3--;
	}
	return NULL;
}

void *car4(void *var)
{
	int i=0;
	int k=100;
	int l=0,cnt=0;
	int cnt4=pp[3];
	while(k>0 && cnt4)
	{
		sem_wait(&chance);
		for(i=0;i<=k;i=i+5)
		{
			setcolor(WHITE);
			rectangle(530-i,cnt+260,510-i,cnt+270);
			rectangle(510-i,cnt+262,505-i,cnt+268);
			setcolor(BLACK);
			delay(30);
			rectangle(530-i,cnt+260,510-i,cnt+270);
			rectangle(510-i,cnt+262,505-i,cnt+268);
		}
		setcolor(WHITE);
		rectangle(530-i,cnt+260,510-i,cnt+270);
		rectangle(510-i,cnt+262,505-i,cnt+268);
		sem_post(&chance);
		if(cnt==60)
		{
			cnt=0;
			k=k-40;
		}
		else
		{
			cnt+=20;
		}
		cnt4--;
	}
	return NULL;
}

void findp(int n,int t)
{
    int i,j,high;
    for(j=0;j<n;j++)
    {
        high=-1;
        for(i=0;i<n;i++)
        {
            if(p[i].id!=-1)
            {
                if(high==-1)
                {
                    high=i;
                }
                else if(p[high].bt<p[i].bt)
                {
                    high=i;
                }
            }
        }
        if(high!=-1)
        {
            q.push(p[high]);
            p[high].id=-1;
        }
    }
}
void light(int cnt)
{
    int n=4;
    int i,j,k,t,tq=3;
    int high;
	while(cnt!=n || !q.empty())
    {
        findp(n,t);
        if(!q.empty())
        {
            process tmp=q.front();
            q.pop();
			if(tmp.bt/2>tq)
			{
				tq=tmp.bt/2;
			}
			else
			{
				tq=3;
			}
			int xy;
            cout<<"light "<<tmp.id<<" will turn green\n";
			setcolor(WHITE);
	    	if(tmp.bt>tq)
            {
                t+=tq;
                findp(n,t);
                tmp.bt-=tq;
                q.push(tmp);
				xy=tq;
            }
	    	else
            {
                t+=tmp.bt;
                cnt++;
				xy=tmp.bt;
            }
            if(tmp.id==1)
				move1(xy);
			else if(tmp.id==2)
				move2(xy);
			else if(tmp.id==3)
				move3(xy);
			else if(tmp.id==4)
				move4(xy);
        }
        else
        {
            t++;
        }
    }
}
void print()
{
 	int gd = DETECT,gm;
   	initgraph(&gd,&gm,NULL);
	sem_init(&chance,0,1);
	pthread_t t1,t2,t3,t4;
	system("clear");
	cleardevice();
	int n=4;
    int i,j,k,t,tq=3;
    int high; 
	srand(time(0));
    for(i=0;i<n;i++)
    {
        pp[i]=rand()%12;
    }
    int cnt=0;
    for(i=0;i<n;i++)
    {
        if(pp[i]==0)
        {
            p[i].id=-1;
            cnt++;
        }
        else
        {
            p[i].id=i+1;
        }
        p2[i].id=p[i].id;
        p[i].bt=pp[i];
        p2[i].bt=p[i].bt;
    }
    t=0;
    cout<<"\n\nTable:-\n";
    cout<<"ID\tBT\n";
    for(i=0;i<n;i++)
    {
        cout<<p2[i].id<<"\t"<<p2[i].bt<<"\n";
    }
    makeroad();
	pthread_create(&t1,NULL,car1,NULL);
	pthread_create(&t2,NULL,car2,NULL);
    pthread_create(&t3,NULL,car3,NULL);
	pthread_create(&t4,NULL,car4,NULL);
	pthread_join(t1,NULL);
	pthread_join(t3,NULL);
	pthread_join(t2,NULL);
	pthread_join(t4,NULL);
	light(cnt);
	getch();
	closegraph();
}

int main()
{
   
	print();
   return 0;
}
