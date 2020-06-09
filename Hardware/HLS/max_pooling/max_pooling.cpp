#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main() {
	int stride;
	cout<<"enter the stride";
	cin>>stride;
	cout<<endl;
  int r, c;
  cout<<"enter the input rows and columns";
  cin >> r ;
  cin>>c;
  cout<<endl;
  std::vector< std::vector<int> > image;
  image.resize(r); 
  for(int i = 0; i < r; i++)
    image[i].resize(c); 
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> image[i][j];
    }

  }
  
cout<< endl;
int r1=0;
int c1=0;
int out[1][1];
for (int i=0;i<=(r-2);i=i+stride)
{
	for(int j=0;j<=(c-2);j=j+stride)
	{
		if((image[i][j]>image[i+1][j])&&(image[i][j]>image[i][j+1])&&(image[i][j]>image[i+1][j+1]))
        {
        	out[r1][c1]=image[i][j];
        	c1++;
        		if (c1==(c/2) && r1<((r/2)-1))
        		{
        			c1=0;
        			r1++;
				}
        
        
		}
else if ((image[i+1][j]>image[i][j])&&(image[i+1][j]>image[i][j+1])&&(image[i+1][j]>image[i+1][j+1]))
 {
 	out[r1][c1]=image[i+1][j];
        	c1++;
        		if (c1==(c/2) && r1<((r/2)-1))
        		{
        			c1=0;
        			r1++;
				}
        
        	
		}

else if((image[i][j+1]>image[i+1][j])&&(image[i][j+1]>image[i][j])&&(image[i][j+1]>image[i+1][j+1])) 
 {
 		out[r1][c1]=image[i][j+1];
        	c1++;
        			if (c1==(c/2) && r1<((r/2)-1))
        		{
        			c1=0;
        			r1++;
				}
        
        
		}

else if((image[i+1][j+1]>image[i][j])&&(image[i+1][j+1]>image[i][j+1])&&(image[i+1][j+1]>image[i+1][j])) 
 {
 		out[r1][c1]=image[i+1][j+1];
        	c1++;
        			if (c1==(c/2) && r1<((r/2)-1))
        		{
        			c1=0;
        			r1++;
				}
        
        
		}

	}
}
c1--;
for(int i=0;i<=r1;i++)
{
	for(int j=0;j<=c1;j++)
	{
		cout<<out[i][j];
		cout<<endl;
	}
}
return 0;
}
