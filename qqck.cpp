#include<iostream>
#include<algorithm>
using namespace std;
class Quick
{
private:
	int a[100],n;
public:
	void QuickSort(int beg,int end);
	int partition(int beg,int end);
	void print(int l[100],int beg,int end);
	int med(int beg,int end);
	void input();
};

void Quick::QuickSort(int beg,int end)
{
	int j,p,k;
	if(beg<end)
	{
		
		
		//cout<<"\npivot="<<p;
		j=partition(beg,end);
		cout<<"\nj="<<j;
		QuickSort(beg,j-1);
		QuickSort(j+1,end);
	}
}

int Quick::med(int beg,int end)
{
	int i,m=0,b[100],k=0;
	if(beg==end)
		return beg;
	else
	{
	for(i=beg;i<=end;i++)
	{
		b[k]=a[i];
		k++;
	}
	//cout<<"\nk="<<k;
	sort(b,b+k);
	//cout<<"\nk/2="<<k/2;
	cout<<"\nk before="<<k;
	
		k=k/2;
	
		
	//m=b[(k/2)];
	cout<<"\nk="<<k;
	cout<<"\na[k]="<<a[k];	//cout<<"\nm="<<m;	cout<<"\nArray B:";
	//print(b,0,k-1);
	return k;}
}

int Quick::partition(int beg,int end)
{
	int i=beg,j=end,temp,pivot;
	
	pivot=a[beg];
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

	temp=a[beg];
	a[beg]=a[j];
	a[j]=temp;
	cout<<"\npivot="<<pivot;

	return (j);

}

void Quick::input()
{
	cout<<"\nEnter the size of the array:";
	cin>>n;
	cout<<"\nEnter the array elements:\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	QuickSort(0,n-1);
	print(a,0,n-1);
}

void Quick::print(int l[100],int beg,int end)
{
	cout<<endl;
	for(int i=beg;i<=end;i++)
		cout<<l[i]<<" ";
}
int main()
{
	Quick q;
	q.input();
}