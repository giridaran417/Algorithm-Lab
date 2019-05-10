//#include <iostream>
#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int i=0;//for tracking the edges

struct disjointset{
    
    int parent;
    int rank;
};

struct edge{
    int src,dest,weight;
};

struct graph{
    int v,e;
    struct edge *array;
};

struct graph * creategraph(int v,int e){
    struct graph *g;
    g=(struct graph *)malloc(sizeof(graph));
    g->v=v;
    g->e=e;
    g->array=(struct edge *)malloc(e*sizeof(edge));
    return g;
}

void addedge(struct graph *g){
	int src,dest,weight;
	cout<<"enter the sorce vertex and destination vertex and weight of that edge\n";
	cin>>src>>dest>>weight;
    g->array[i].src=src;
    g->array[i].dest=dest;
    g->array[i].weight=weight;
    i++;
}

void makeset(struct disjointset *a,int v){
    //a=(struct disjointset *)malloc(v*sizeof(disjointset));
    for(int i=0;i<v;i++){
	    a[i].parent=i;
	    a[i].rank=0;
	}
    
}


int myComp(const void* a, const void* b){
    struct edge* a1 = (struct edge*)a;
    struct edge* b1 = (struct edge*)b;
    return a1->weight > b1->weight;
}



int findset(struct disjointset *a,int data){
    
    if(data==a[data].parent)
        return a[data].parent;
    else{
        return a[data].parent=findset(a,a[data].parent);
    }
}

int unionset(disjointset *b,int a1,int b1){
     a1=findset(b,a1);
     b1=findset(b,b1);
    if(a1==b1){
        return 1;
    }
    else if(b[a1].rank==b[b1].rank){
        b[b1].parent=a1;
        b[a1].rank++;
    }
    else if(b[a1].rank < b[b1].rank){
        b[a1].parent=b1;
        
    }
    else
        b[b1].parent=a1;
}




int main() {
	// your code goes here
	struct disjointset *a;
	struct graph *g;
	int v,e;
	cout<<"enter the no. of vertex"<<endl;
	cin>>v;
	cout<<"enter the no. of edges \n";
	cin>>e;
	
	a=(struct disjointset *)malloc(v*sizeof(disjointset));
	
	g=creategraph(v,e);
		for(int i=0;i<v;i++){
	    a[i].parent=i;
	    a[i].rank=0;
	}
	
	for(int i=0;i<e;i++){
		addedge(g);
	}
	
	qsort(g->array,g->e,sizeof(g->array[0]),myComp);
	for(int i=0;i<e;i++){
	    if(findset(a,g->array[i].src) != findset(a,g->array[i].dest)){
	        cout<<g->array[i].src<<"-------"<<g->array[i].dest<<endl;
	        unionset(a,g->array[i].src,g->array[i].dest);
	    }
	}
	return 0;
}

