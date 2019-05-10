#include <iostream>
#include<stdlib.h>
using namespace std;

struct disjointset{
    
    int parent;
    int rank;
};



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
	a=(struct disjointset *)malloc(5*sizeof(disjointset));
	 for(int i=0;i<5;i++){
	    a[i].parent=i;
	    a[i].rank=0;
	}
	unionset(a,0,1);
	unionset(a,2,4);
	unionset(a,2,3);
	cout<<findset(a,3);
	return 0;
}
