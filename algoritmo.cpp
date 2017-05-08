#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <math.h>       /* floor */
#include <time.h>
#include <vector>
#include <ctime>
#include <malloc.h>
using namespace std;
const int MAX = 30;

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


void Scambia2(std::vector<int> &arr, int i, int j){
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


void BinarySwap(int A[],int a,int b){
 if (a==b)return;
 int c = floor((a+b)/2);
 int  tmp = A[a];
 A[a] = A[b];
 A[b] = tmp;
 BinarySwap(A, a, c);
 BinarySwap(A, c+1, b);
}

int parent(int i)
{
    return i/2;
}
int left(int i)
{
    if(i == 0)
        return 1;
    else
        return (2*i + 1);
}
int right(int i)
{   if(i == 0)
        return 2;
    else
        return 2*i + 2;
}


void min_heapify(std::vector<int> &A, int i)
{
    int smallest;
    int l = left(i);
    //std::cout << "left = " << l << std::endl;
    int r = right(i);
    //std::cout << "right = " << r << std::endl;
    if(l <= (A.size()-1) && A[l] < A[i])
        smallest = l;
    else
        smallest = i;
    //std::cout << "smallest = " << smallest << std::endl;
    if(r <= (A.size()-1) && A[r] < A[smallest])
        smallest = r;
    if(smallest != i) {
        //print(A);
        Scambia2(A, i, smallest);
        min_heapify(A, smallest);
    }
}

void Build_min_heap(std::vector<int> &A)
{
   int lenght=A.size()-1;
   int i = floor(lenght/2);
    for(i; i>=0; i--)
        min_heapify(A, i);
   
}






void max_heapify(std::vector<int> &A, int i)
{
    int largest;
    int l = left(i);
    //std::cout << "left = " << l << std::endl;
    int r = right(i);
    //std::cout << "right = " << r << std::endl;
    if(l <= (A.size()-1) && (A[l] > A[i]))
        largest = l;
    else
        largest = i;
    //std::cout << "smallest = " << smallest << std::endl;
    if(r <= (A.size()-1) && (A[r] > A[largest]))
        largest = r;
    if(largest != i) {
        //print(A);
        Scambia2(A, i, largest);
        max_heapify(A, largest);
    }
}
void Build_max_heap(std::vector<int> &A)
{
     int lenght=A.size()-1;
   int i = floor(lenght/2);
    for(i; i>=0; i--)
        max_heapify(A, i);
   
}


void Extract_max(std::vector<int> &A)
{
  Build_max_heap(A);
  int max= A[0];
  A[0] = A[(A.size()-1)];
  A.pop_back();
  max_heapify(A,0);
  
}

struct node
{
    int info;
    node *next;
};

struct nod
{
    int info;
    struct nod *next;
};
 
class stak
{
    struct nod *top;
    public:
        stak();
        void push(int);
        int pop();
        bool isEmpty();
        void display();
};
 
stak::stak()
{
    top = NULL;
}
 
void stak::push(int data)
{
    nod *p;
    if((p=(nod*)malloc(sizeof(nod)))==NULL){
        cout<<"Memory Exhausted";
        exit(0);
    }
    p = new nod;
    p->info = data;
    p->next = NULL;
    if(top!=NULL)
    {
        p->next = top;
    }
    top = p;
}
 
int stak::pop()
{
    struct nod *temp;
    int value;
    if(top==NULL){
        cout<<"\nThe stak is Empty"<<endl;
    }
    else
    {
        temp = top;
        top = top->next;
        value = temp->info;
        delete temp;
    }
    return value;
}
 
bool stak::isEmpty()
{
    return (top == NULL);
}
 
void stak::display()
{
    struct nod *p = top;
    if(top==NULL){
        cout<<"\nNothing to Display\n";
    }
    else
    {
        cout<<"\n The contents of stak\n";
        while(p!=NULL){
            cout<<p->info<<endl;
            p = p->next;
        }
    }
}

class Queue
{
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        void display();
 
};
 
void Queue::display()
{
    node *p = new node;
    p = front;
    if(front == NULL)
    {
        cout<<"\nNothing to Display\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
}
 
Queue::Queue()
{
    front = NULL;
    rear = NULL;
}
 
Queue::~Queue()
{
    delete front;
}
 
void Queue::enqueue(int data)
{
    node *temp = new node();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
    rear = temp;
}
 
int Queue::dequeue() {
    node *temp = new node();
    int value;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
}
 
bool Queue::isEmpty()
{
    return (front == NULL);
}






 
class Graph
{
    private:
        int n;
        int **A;
    public:
        Graph(int siz = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int x, int y);
        void DFS(int , int);
		void BFS(int );
};
 
Graph::Graph(int siz)
{
    int i, j;
    if (siz < 2) n = 2;
    else n = siz;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}
 
Graph::~Graph()
{
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}
 
bool Graph::isConnected(int x, int y)
{
    return (A[x-1][y-1] == 1);
}
 
void Graph::addEdge(int x, int y)
{
    A[x-1][y-1] = A[y-1][x-1] = 1;
}
 
void Graph::DFS(int x, int required)
{
    stak s;
    bool *visited = new bool[n+1];
    int i;
    for(i = 0; i <= n; i++)
        visited[i] = false;
    s.push(x);
    visited[x] = true;
    if(x == required) return;
    cout << " Depth first Search starting from vertex ";
    cout <<  (x-1 )<< " : " << endl;
    while(!s.isEmpty())
    {
        int k = s.pop();
        if(k == required) break;
        cout<< "v"<<(k-1) <<" ";
        for (i = n; i >= 0 ; --i)
            if (isConnected(k, i) && !visited[i])
            {
                s.push(i);
                visited[i] = true;
            }
    }
    cout<<endl;
    delete [] visited;
}
 

void Graph::BFS(int s) {
    Queue Q;
 
 
    bool *explored = new bool[n+1];//  it Keeps track of explored vertices
 
    for (int i = 1; i <= n; ++i)// Initailization of  all vertices as unexplored
    explored[i] = false;
    Q.enqueue(s);// Pushing of  initial vertex to the queue
    explored[s] = true; // marking it as explored
    cout << "Breadth first Search starting from vertex ";
    cout << (s-1) << " : " << endl;
 
    //Unless the queue is empty is to be performed
    while (!Q.isEmpty()) {
        // Pop the vertex from the queue
        int v = Q.dequeue();
 
        //display the explored vertices
        cout << "v"<<(v-1) << " ";
 
        //From the explored vertex v try to explore all the
        //connected vertices
        for (int w = 1; w <= n; ++w)
 
            /*Explores the vertex w if it is connected to v
            and and if it is unexplored*/
            if (isConnected(v, w) && !explored[w]) {
                //adds the vertex w to the queue
                Q.enqueue(w);
                //marks the vertex w as visited
                explored[w] = true;
            }
    }
    cout << endl;
    delete [] explored;
}

//CONCATENACION //
	void Hash_multi(std::vector<int> &vector,std::vector<int> &tabla, int dimension, double constante){
		for(int i=0; i< vector.size(); i++){
			int valor_tabla = floor(dimension* (vector[i]*constante - floor(vector[i]*constante) ) );
			tabla[valor_tabla]++;
		}


	} 


//APERTO//
	
	void Hash_lineal(std::vector<int> &vector,std::vector<int> &tabla){
		for(int i=0; i< vector.size()  ; i++){
			int j=0;
			int valor_tabla = (vector[i] + j)%tabla.size();
			while (tabla[valor_tabla] != 0 && valor_tabla < tabla.size() ){
				j++;
				valor_tabla = (vector[i] + j)%tabla.size();
			}
			tabla[valor_tabla]=vector[i];
		}


	} 



void Hash_cuadratico(std::vector<int> &vector,std::vector<int> &tabla, int c1, int c2){
		for(int i=0; i< vector.size()  ; i++){
			int j=0;
			int valor_tabla = (vector[i] + c1*j + c2*j*j )%tabla.size();
			while (tabla[valor_tabla] != 0 && valor_tabla < tabla.size() ){
				j++;
				valor_tabla = (vector[i] + c1*j + c2*j*j )%tabla.size();
			}
			tabla[valor_tabla]=vector[i];
		}


	} 




void Hash_doble(std::vector<int> &vector,std::vector<int> &tabla, int c1, int c2){
		c1=c2=1;
		for(int i=0; i< vector.size()  ; i++){
			int j=0;
			int h1= vector[i]%tabla.size();
			int h2 =  1 + ( vector[i]% ( tabla.size()-1  ) );

			int valor_tabla = (  (c1*h1) + (c2*j*h2) ) %tabla.size();
			while (tabla[valor_tabla] != 0 && valor_tabla < tabla.size() ){
				j++;
				valor_tabla = (  (c1*h1) + (c2*j*h2) ) %tabla.size();
			}
			tabla[valor_tabla]=vector[i];
		}


	} 








int main(){

//INTERCAMBIOS INSERTION SORT//
int length=10;
int arr[]={25,21,20,5,8,15,16,24,1,6};

int scambi=Insertion_sort(arr,length);
cout <<"Intercambios " << scambi << endl;


//


//PARTITION//
int length2=11;
int arr2[]={23,6,7,21,16,25,24,3,17,30,7};

Partition(arr2, 0 , length2 -1);


cout << "SECUENCIA" << endl;
	for(int i=0; i<length2; i++)
		cout << arr2[i] << endl;

//



//BINARY SWAP//
int length3=12;
int arr3[]={9,10,8,6,8,4,3,8,8,1,1,5};

BinarySwap(arr3,0,11); //OJO SI EL ENUNCIADO NOS DICE BinarySwap(A,1,12) VIENE CON TRAMPA PORQUE LA POSICIÓN INICIAL DEL VECTOR ES A[0]
					   // RESTARLE SIEMPRE UNA UNIDAD

cout << endl << "BINARY SWAP" << endl;
	for(int i=0; i<length3; i++)
		cout << arr3[i] << endl;
//

/*
BinarySelect(A, a, b)
1. if (a==b) then return A[a];
2. c = floor ((a+b)/2);
3. S1 = S2 = 0;
4. for i=a to c do S1 = S1 + A[i];
5. for i=c+1 to b do S2 = S2 + A[i];
6. if (S1 > S2) then return BinarySelect(A, a, c);
7. else return BinarySelect(A, c+1, b);*/

// COUNTING SORT //

int length4=11;
int arr5[]={26,21,35,63,69,11,70,9,44};
vector<int> vec(arr5, arr5 + sizeof(arr5) / sizeof(arr5[0]) );

//Build_min_heap(vec); 
//Build_max_heap(vec); 
Extract_max(vec);

cout << endl << "BUILD MIN HEAP" << vec.size() << endl;
	for(int i=0; i< vec.size(); i++)
		cout << vec[i] << endl;


/////////// DFS /////////////////


Graph dg(6);
   dg.addEdge(1, 3); dg.addEdge(2, 4); dg.addEdge(2, 5);
   dg.addEdge(2, 6);//dg.addEdge(2, 7);
    dg.addEdge(3, 4);
    dg.addEdge(3, 5); dg.addEdge(4,6 );dg.addEdge(5,6);
   dg.DFS(1, 7); //del inicio al final
   



////////// BFS //////////
    Graph g(6);
 
    //Adds edges to the graph */
    g.addEdge(1, 3); g.addEdge(1, 4);
    g.addEdge(1, 5); g.addEdge(2, 4);
    g.addEdge(2, 5); g.addEdge(2,6);
     g.addEdge(3, 4); g.addEdge(3, 5); g.addEdge(3, 6);
	g.addEdge(4, 3); g.addEdge(6, 2);

//
g.BFS(3);  //OJO EL RESULTADO SALE CORRECTO EN v0, v1 ...  //si es desde V0 -- argumento 1 se añade 1 más



// HASH MULTIPLICATIVO  CONCATENACIÓN //
int arr6[]={83,12,8,93,92,40,90,36,6,85,33};
vector<int> claves(arr6, arr6 + sizeof(arr6) / sizeof(arr6[0]) );

int dimension = 11;
vector<int> tabla(dimension,0);

Hash_multi(claves,tabla, dimension, 0.28);
cout << endl << "HASH MULTIPLICACION CONCATENA" << endl;
	for(int i=0; i< tabla.size(); i++)
		cout << tabla[i] << endl;





// HASH LINEAL ABIERTO//
int arr7[]={83,12,8,93,92,40,90,36,6,85,33};
vector<int> claves2(arr7, arr7 + sizeof(arr7) / sizeof(arr7[0]) );

int dimension2 = 11;
vector<int> tabla2(dimension2,0);


Hash_lineal(claves2,tabla2);
cout << endl << "HASH LINEAL ABIERTO" << endl;
	for(int i=0; i< tabla2.size(); i++)
		cout << tabla2[i] << endl;


// HASHING CUADRATICO ABIERTO//
int arr8[]={98,47,50,70,45,91};
vector<int> claves3(arr8, arr8 + sizeof(arr8) / sizeof(arr8[0]) );

int dimension3 = claves3.size();
vector<int> tabla3(dimension3,0);

int c1=5;
int c2=1;
Hash_cuadratico(claves3,tabla3,c1,c2);
cout << endl << "HASH Cuadratico ABIERTO" << endl;
	for(int i=0; i< tabla3.size(); i++)
		cout << tabla3[i] << endl;


// HASHING DOBLE ABIERTO//
int arr9[]={30,91,34,56,76};
vector<int> claves4(arr9, arr9 + sizeof(arr9) / sizeof(arr9[0]) );

int dimension4 = claves4.size();
vector<int> tabla4(dimension4,0);

int c3=5;
int c4=3;
Hash_doble(claves4,tabla4,c3,c4);
cout << endl << "HASH DOBLE ABIERTO" << endl;
	for(int i=0; i< tabla4.size(); i++)
		cout << tabla4[i] << endl;


}
