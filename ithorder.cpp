#include<iostream>
using namespace std;

class Iorder
{
public:
	int select(int a[100],int beg,int end,int pos,int n);
	int findmedian(int beg,int end,int b[100]);
	int partition(int a[100],int beg,int end,int pivot);
};

int Iorder::select(int a[100],int beg,int end,int pos,int n)
{
	int n1,i,b[100],k=beg,x,y,z;
	if(n%5==0)
		n1=n/5;
	else
		n1=(n/5)+1;
	cout<<"\n n1="<<n1;

	if(n<=5)
	{
		int j,temp;
	  for(i=beg;i<=end;i++)
	   {
		for(j=beg;j<end;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	   }
	   int t=0;
	   cout<<"\npos="<<pos;
	   for(i=beg;i<=end;i++)
	   {
	   	  t++;
	   	  if(t==pos)
	   	  	break;
	   }
	   return a[i];

	}	//return findmedian(beg,end,a);

	for(i=1;i<=n1;i++)
	{
		if((k+4)<=end)
		{
			cout<<"\nk="<<k;
			b[i]=findmedian(k,k+4,a);
			k+=5;
		}
		else
		{
			b[i]=findmedian(k,end,a);
		}
	}
	for(int l=1;l<=n1;l++)
		cout<<b[l]<<"\t";
	cout<<endl;

	x=select(b,1,n1,n1+1/2,n1);
	cout<<"\nx="<<x;
	int m;
	for(m=beg;m<=end;m++)
	{
		if(a[m]==x)
		  break;
	}
	y=partition(a,beg,end,m);
	cout<<"\n y="<<y;
	if(pos==y)
		return x;
	else if(pos<y)
		z=select(a,beg,y-1,pos,y-beg);
	else
		z=select(a,y+1,end,pos-y,end-y);

	return z;
}

int Iorder::findmedian(int beg,int end,int b[100])
{
	int i,j,temp;
	for(i=beg;i<=end;i++)
	{
		for(j=beg;j<end;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	cout<<endl;
	for(i=beg;i<=end;i++)
		cout<<b[i]<<"\t";
	cout<<endl;
    
	int med= b[(beg+end)/2];
	//cout<<"\nBeg+end/2="<<(beg+end)/2;
	//out<<"\nmed="<<med;
	return med;
}

int Iorder::partition(int a[100],int beg,int end,int p)
{
	int i=beg+1,j=end,temp,k;
	int pivot=a[p];
	
	while(i<j)
	{
		while(a[i]<=pivot && i<=end)
			i++;
		while(a[j]>pivot && j>beg)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	temp=a[p];
	a[p]=a[j];
	a[j]=temp;

	return j;
}
int main()
{
	Iorder d;
	int i,pos,n,a[100],x;
	cout<<"\nEnter the size of the array:";
	cin>>n;
	cout<<"\nEnter the array elements:";
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the value of i to find the ith min:";
	cin>>pos;
	x=d.select(a,1,n,pos,n);
	cout<<"ith min:"<<x;
}