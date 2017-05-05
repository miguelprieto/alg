#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int Insertion_sort(int arr[], int length){
	 	int j, temp;
		int contador=0;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  contador++;
			  }
		
		}
	return contador;
}

void Scambia(int arr[], int i, int j){
int temp;
temp = arr[i];
arr[i]= arr[j];
arr[j] = temp;

}


int Partition(int A[],int p,int r){
int i,j;
int x = A[r];
i=p-1;
j=r+1;

while(true){
 	do{ j=j-1; }while(A[j]>x);
    do{ i=i+1; }while(A[i]<x);
	if(i<j){
		Scambia(A,i,j);
	}else return j;
}	

}





int main(){


int length=10;
int arr[]={25,21,20,5,8,15,16,24,1,6};



int length2=11;
int arr2[]={23,6,7,21,16,25,24,3,17,30,7};

int scambi=Insertion_sort(arr,length);
cout <<"Intercambios " << scambi << endl;

Partition(arr2, 0 , length2 -1);


cout << "SECUENCIA" << endl;
	for(int i=0; i<length2; i++)
		cout << arr2[i] << endl;

}

