#include<iostream>

using namespace std;

class subarray{
public:
    int left,right,sum;
};

class result{
public:
    subarray maxsub(int a[],int low,int);
    subarray cross(int a[],int,int,int);
};

subarray result::maxsub(int a[],int low,int high){
    subarray leftsub,rightsub,crosssub,obj;
    int mid;
    if(high==low){
        obj.left=low;
        obj.right=high;
        obj.sum=a[low];
        return obj;
    }
    if(low<high){
        mid=(low+high)/2;
        leftsub=maxsub(a,low,mid);
        rightsub=maxsub(a,mid+1,high);
        crosssub=cross(a,low,mid,high);
        if(leftsub.sum>=rightsub.sum && leftsub.sum >=crosssub.sum)
            return leftsub;

        else if(rightsub.sum>=leftsub.sum && rightsub.sum>=crosssub.sum)
            return rightsub;
        else
            return crosssub;
    }
}

subarray result::cross(int a[],int low,int mid,int high){
    subarray obj;
    int i,j,leftsum,sum,rightsum,maxleft,maxright;
    leftsum=-32768;
    sum=0;
    for( i=mid;i>=low && i>=0;i--){
        sum=sum+a[i];
        if(leftsum<sum){
            leftsum=sum;
            maxleft=i;
        }
    }
    rightsum=-32768;
    sum=0;
    for( j=mid+1;j<=high ;j++){
        sum=sum+a[j];
        if(rightsum<sum){
            rightsum=sum;
            maxright=j;
        }
    }
    obj.left=maxleft;
    obj.right=maxright;
    obj.sum=leftsum+rightsum;
    return obj;
}

int main(){
    result obj1;
    subarray obj2;
    int n,i,a[200];
    cout<<"enter how many digits to be entered\n";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    obj2=obj1.maxsub(a,0,n);
    cout<<obj2.left<<"\t"<<obj2.right<<"\t"<<obj2.sum<<endl;
    return 0;
}
