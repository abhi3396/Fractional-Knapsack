#include<bits/stdc++.h>
using namespace std;
struct Activity
{
	int value,weight;
};

bool comp(Activity a, Activity b)
{
	double d1= (double)a.value/ (double)a.weight;
	double d2= (double)b.value/ (double)b.weight;
	
	return d1>d2;
}

void solution(int w, Activity arr[], int n)
{
	sort(arr,arr+n,comp);
	
	double profit=0;
	int i;
	for(i=0;i<n;i++)
	{
	    if((arr[i].weight<=w)&&(w!=0))
	    {
	    	profit=profit+arr[i].value;
	    	w=w-arr[i].weight;
		}
		else
		{
			if(w!=0)
			{
				double x= (double)w/(double)arr[i].weight;
				profit=profit+(arr[i].value*x);
			}
		}
	}
	cout<<profit;
}

int main()
{
	Activity arr[]={ {10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1} };
	int n=sizeof(arr)/sizeof(arr[0]);
	int w=15;
	
	solution(w,arr,n);
}
