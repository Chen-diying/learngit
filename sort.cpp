#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

void solve(){
	
}

void bubbleSort(int *a, int *b){
	int n = b - a;
	for(int i = 0; i < n; i++){
		bool isSort = true;
		for(int j = 0; j < n - i -1; j++){
			int t;
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				isSort = false;
			}
		}
		if(isSort) break;
	}
} 

void selectionSort(int *a, int *b){
	int n = b - a;
	for(int i = 0; i < n; i++){
		int k = i;
		for(int j = i; j < n; j ++){
			if(a[j] < a[k])k = j;
		}
		int t;
		t = a[i];
		a[i] = a[k];
		a[k] = t;
	}
}

void mergeSort(int *a, int *b){
	if(b-a == 1) return;
	int mid = (b-a)/2;
	mergeSort(a, a+mid);
	mergeSort(a+mid, b);
	int n = b - a;
	int *x = a, *y = a+mid;
	int z[n], lenx = 0, leny = 0;
	int i = 0;
	while(lenx < mid&&y+leny < b){
		if((x[lenx] < y[leny] && lenx < mid)||y+leny == b){
			z[i++] = x[lenx++];
		} else {
			z[i++] = y[leny++];
		}
	}
	while(lenx<mid){
		z[i++] = x[lenx++];
	}
	while(y+leny < b){
		z[i++] = y[leny++];
	}
	for(int i = 0; i < n ; i++){
		a[i] = z[i];
	}
//	for(int z = 0; z < b-a; z++){
//		cout << a[z] << " ";
//	}
//	cout << endl;
}

void quickSort(int *a, int *b){
	int *i, *j;
	i = a;j = b - 1;
	if(i>=j) return;
	int *p = a+rand()%(b-a);
	int k=*p;*p=*i;*i=k;
	while(i<j){
		while(i<j&&*j>k) j--;
		if(i<j) {
			*i = *j;
			i++;
		}
		while(i<j&&*i<=k) i++;
		if(i<j) {
			*j = *i;
			j--;
		}
	}
	*i = k;
	for(int z = 0; z < b-a; z++){
		cout << a[z] << " ";
	}
	cout << endl;
	quickSort(a,i);
	quickSort(i+1, b);
}

int main(){ 
	int a[9] = {8,2,5,9,7,10,3,4,6};
	int b[10] = {10,1,2,3,4,5,6,7,8,9};
	int c[7] = {9, 4, 3, 2, 8, 7, 7};
	int d[9] = {3,3,3,3,3,1,2,2,1} ;
	//mergeSort(d,d+9);
//	for(int i = 0; i < 9; i++){
//		cout << d[i] << " ";
//	}
	ifstream inf;
	inf.open("P11.txt");
	char da[100000];
	int e[10000];
	inf >> e[0];
	for(int i=1;i<e[0]+1;i++){
		inf >> e[i];
		//cout << e[i] << " ";
	}
	mergeSort(e+1,e+1001);
//	for(int i=1;i<=e[0];i++){
//		cout << e[i] << " ";
//	}
	//cout << endl;
	ifstream inf2;
	inf2.open("P1.txt");
	int f[10000];
	for(int i=1;i<=1000;i++){
		inf2>>f[i];
	}
	
	for(int i=1;i<=e[0];i++){
		if(f[i]!=e[i]){
			cout << f[i] << " "<<c[i] << " " << i << endl;
		}
	}
	cout << 111111 << endl;
	return 0;
}
