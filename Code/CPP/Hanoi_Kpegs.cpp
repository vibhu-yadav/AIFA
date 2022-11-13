#include <iostream>
using namespace std;


void hanoi(int N,char st,char aux,char dest)
{
	if(N > 1)
		hanoi(N-1,st,dest,aux);

	cout << N << " moved from " << st << " to " << dest << endl;


	if(N > 1)
		hanoi(N-1,aux,st,dest);
}

int main()
{
	char st = 'A';
	char aux = 'B';
	char dest = 'C';
	int N = 3;


	for(int i=1;i<=N;i++) a.insert(i);

	hanoi(N,st,aux,dest);


}