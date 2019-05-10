#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<timer.h>
#include<graphics.h>

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TIMER.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __TIMER_H )
#define __TIMER_H

#if defined( _Windows ) && !defined( _BUILDRTLDLL )
#error Timer not available for Windows
#endif

#if !defined( __DEFS_H )
#include <_defs.h>
#endif


class Timer
{

public:

    Timer();

    void start();
    void stop();
    void reset();

    int status();
    double time();

    static double resolution();

private:

    static unsigned adjust;
    static unsigned calibrate();
    int running;

    struct TIME
	{
	unsigned long dosCount;
	unsigned timerCount;
	};

    TIME startTime;

    double time_;

};

inline int Timer::status()
{
    return running;
}

inline double Timer::time()
{
    return time_/1.E6;
}

inline double Timer::resolution()
{
    return 839/1.E9;
}

#endif  // __TIMER_H



class search
{
	int *a,n;
	public:
		search();
		int linearsearch(long int n,int key);
		int binarysearchi(long int n,int key);
		int binarysearchr(int p,long int n,int key);
		void display(long int n);
		void drawline(double,double,double,double);

};

search::search()
{
	long int i;
	time_t t;
	a=(int *)malloc(1000000*sizeof(int));
	srand((unsigned)time(&t));
	for(i=0;i<1000;i++)
	{
		a[i]=rand()%100;
//		cout<<i<<"\t"<<a[i]<<endl;
	}
}
int search::linearsearch(long int n,int key)
{
	long int i;
	for(i=0;i<n && a[i]!=key;i++)
	{}
	if(a[i]==key)
		return 1;
	else
		return 0;
}
int search::binarysearchi(long int n,int key)
{
	long int r=n;
	int p=0,q;
	while(p<=r)
	{
		q=(p+r)/2;
		if(a[q]==key)
		{
		     return 1;
		}
		else if(a[q]<key)
			p=q+1;
		else
			r=q-1;
	}
	if(p>r)
		return 0;
	return 1;
}
int search::binarysearchr(int p,long int r,int key)
{
	int q;
	if(p<=r)
	{
		q=(p+r)/2;
		if(a[q]==key)
			return 1;
		else if(a[q]<key)
			binarysearchr(q+1,r,key);
		else
			binarysearchr(p,q-1,key);
	}
	else
		return 0;
	return 1;
}



int main()
{
	search obj;

	Timer t;
	int n;
	cout<<"enter the no u want to search";
	cin>>n;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	clrscr();
	double prev1=5,prev2=440,pr1=5,y2,pr2=440,x,y,i,y1,pre1=5,pre2=440;

	line(5,440,5,0);
	line(5,440,639,440);

	for( x=5;x<1000;x++)
	{
		t.start();
		obj.linearsearch(x,n);
		t.stop();

		y=t.time()*1000000;
		setcolor(3);
		line(prev1,prev2,x,440-y);
		prev1=x;
		prev2=440-y;
		t.reset();
		t.start();
		obj.binarysearchi(x,n);
		t.stop();

		y1=t.time()*1000000;
		setcolor(1);
		line(pre1,pre2,x,440-y1);
		pre1=x;
		pre2=440-y1;
		t.reset();


		t.start();
		obj.binarysearchr(0,x,n);
		t.stop();

		y2=t.time()*1000000;
		setcolor(5);
		line(pr1,pr2,x,440-y2);
		pr1=x;
		pr2=440-y2;
		t.reset();



	}

	getch();
	closegraph();
	return 0;
}
