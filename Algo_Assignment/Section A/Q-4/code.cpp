using namespace std;
#include <iostream>

int max(int a,int b)
{
	return a < b ? b : a;
}
int billboardConst( int M, int n, int x, int position[], int revenue[] ) 
{

	int maxRev[M+1];
	bool billboardPos[n];

	for ( int i=0; i <= M; i++) {
		maxRev[i] = 0;
	}
	int next = 0;

	
	for( int i=0; i < n; i++ ) 
		billboardPos[i] = 0;


	for ( int i = 1; i <= M; i++ ) 
	{

		if ( next < n ) 
		{
			if ( position[next] != i ) 
			{

				maxRev[i] = maxRev[i-1];
			}

			else 
			{
				if ( i <= x ) 
				{ 
					
						maxRev[i] = max(maxRev[i-1],revenue[next]);
				}

				else 
				{
						maxRev[i] = max(maxRev[i-x-1]+revenue[next],maxRev[i-1]);
						
				}
				next++;
			}

			
				
			}
		

		else
			maxRev[i] = maxRev[i-1];
	
	}


	

	return maxRev[M];
}

int main () 
{
	cout<<"Enter M:";
	int M;
	cin>>M;

	cout<<"Enter minimum distance between 2 billboards:";
	int x;
	cin>>x;

	cout << "\nEnter Number of billboards: ";
	int n;
	cin >> n;
    int position[n], revenue[n];

	cout<<"\n Enter Position,revenues :\n ";
	for ( int i=0; i<n; i++ ) 
	{
		cout<<"\n-------------Billboard "<<i+1<<"-----------";
		cout <<"\nPosition: ";
		cin >> position[i];
		cout <<"\nRevenue: ";
		cin >> revenue[i];
	}
   cout << "\nMaximum Revenue "<<billboardConst (M, n, x, position, revenue);
   return 0;
}
