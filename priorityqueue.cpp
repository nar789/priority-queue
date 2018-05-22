#include<iostream>
#include<time.h>
#define N 1000

using namespace std;

int arr[N] = { 0, };
int idx = 0;

void push(int x) {
	arr[idx] = x;
	int c = idx; idx++;
	int t, p;
	while (c != 0){
		p = (c - 1) / 2;
		if (arr[p] > arr[c]) { t = arr[p]; arr[p] = arr[c]; arr[c] = t;  c = p; }
		else break;
	}
}

 int pop() {
	int r = arr[0];
	arr[0] = arr[idx - 1]; idx--;
	int c = 0; int t;
	do {
		bool isleft;
		if (arr[c] > arr[c * 2+1] && c*2+1<idx && arr[c*2+1]<arr[c*2+2])isleft = 1;
		else if (arr[c] > arr[c * 2 + 2] && c*2+2<idx) isleft = 0;
		else break;
		if (isleft) {t = arr[c * 2 + 1]; arr[c * 2 + 1] = arr[c]; arr[c] = t; c = c * 2 + 1;}
		else{t = arr[c * 2 + 2]; arr[c * 2 + 2] = arr[c]; arr[c] = t; c = c * 2 + 2;}
	} while (c<idx);
	return r; 
}


int main()
{
	clock_t start, end;
	start = clock();
	const int cnt = 20;
	for(int i=0;i<cnt;i++)
		push(rand()%10+1);

	for (int i = 0; i < cnt; i++)
		cout << pop() << endl;
	
	end = clock();
	double sec = ((double)(end - start))/CLOCKS_PER_SEC;
	cout << sec << "sec"<<endl;
    return 0;
}
