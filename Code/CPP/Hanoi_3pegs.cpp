#include <iostream>
#include <set>
using namespace std;
typedef set<int> si;

si a,b,c;	


void hanoi(int N,char st,char aux,char dest)
{
	if(N > 1)
		hanoi(N-1,st,dest,aux);

	cout << N << " moved from " << st << " to " << dest << endl;
	a.erase(N);
	c.insert(N);

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

	cout << "Peg A: ";
	for(auto ele : a) cout << ele << " ";
	cout << endl;

	cout << "Peg B: ";
	for(auto ele : b) cout << ele << " ";
	cout << endl;

	cout << "Peg C: ";
	for(auto ele : c) cout << ele << " ";
	cout << endl;

}