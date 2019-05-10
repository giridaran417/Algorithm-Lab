#include<iostream.h>
#include<conio.h>
#include<math.h>

class result
{
	int i,j,miss,flag;
	public:
		void iswellformed(int a[],int n);
};

void result:: iswellformed(int a[],int n)
{
	a[0]=32672;
	flag=0;
	miss=0;
	for(i=1;i<=n;i++)
	{
	    if(a[abs(a[i])]>0)
		a[a[i]]=-a[a[i]];
	    else
		flag=abs(a[i]);
	}
	for(i=1;i<=n;i++)
		cout<<"\n"<<a[i];
	for(i=1;i<=n  ;i++)
	{
		if(a[i]>0)
			miss=i;
	}
	cout<<"duplicte no is"<<flag;
	cout<<"\nmissing no is"<<miss;
}

void main()
{
	result obj;
	int i,a[200],n;
	clrscr();
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	obj.iswellformed(a,n);
	getch();
}