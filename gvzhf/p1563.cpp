#include <iostream>
#include <string.h>

using namespace std;
//Yes. It is copypaste. Sorry.
int main()
{
    int n;
    cin>>n;
    int c=0;
    char nMatrix[1001][31];
    char str[10];
    cin.getline(str,10);
    for(int i=0;i<n;i++)
    {
    	int a = 0;
        cin.getline(nMatrix[i],31);
		for(int j=0;j<i;j++)
		{
			if(strcmp(nMatrix[i],nMatrix[j])==0)
			{
				a++;
			}
		}
		if(a>0)
			c++;
    }
    cout<<c<<endl;
    return 0;
}

