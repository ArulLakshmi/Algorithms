  #include<iostream>
#include <bits/stdc++.h> 
//#include <list> 
using namespace std;

class Celebrity
{
private:
	int p[50][50],n;
	stack<int> s;
public:
	int findCeleb();
	int whoKnows(int a,int b);
	void read();

};

int Celebrity::whoKnows(int a,int b)
{
	return(p[a][b]);
}

int Celebrity::findCeleb()
{
	int a,b;
	a=s.top();
	s.pop();
	b=s.top();
	s.pop();
     while (s.size() > 1) 
    { 
        if (whoKnows(a, b)) 
        { 
            a = s.top(); 
            s.pop(); 
        } 
        else
        { 
            b = s.top(); 
            s.pop(); 
        } 
    } 
   int c = s.top(); 
    s.pop(); 
  
     
    if (whoKnows(c,b)) 
        c=b;
  
    if (whoKnows(c,a)) 
        c=a;
  
    for (int i = 0; i < n; i++) 
    { 
        
        if ( (i != c) && 
                (whoKnows(c, i) ||  
                 !whoKnows(i, c)) ) 
            return -1; 
    } 
  
    return c; 
 


}

void Celebrity::read()
{
	n=4;
	int x[4][4]={{0,0,1,0},
                  {0,0,1,0},
                   {0,0,0,0},
                   {0,0,1,0}
                   };
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			p[i][j]=x[i][j];
	}
	for(int i=0;i<4;i++)
		s.push(i);

}


int main()
{
	Celebrity cb;
	cb.read();
	cout<<"The celebrity is: "<<cb.findCeleb();
}
