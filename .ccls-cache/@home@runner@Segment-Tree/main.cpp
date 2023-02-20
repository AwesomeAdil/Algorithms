#include <iostream>
#include <vector>
using namespace std;

int segtree [5000];
int n;

void insert(int cur, int start, int end, int index, int val){
  if(index > end || index < start){
    return;
  }
  if(start == end){
    segtree[cur] = val;
    return;
  }
  insert(2*cur+1, start, (start+end)/2, index, val);
  insert(2*cur+2, (start+end)/2 + 1, end, index, val);
  
}

void insert(int index, int val){
  insert(0,0,n-1,index, val);
}

int sum(int cur, int start, int end, int l, int r){
  if(l > end || r < start){
    return 0;
  }
  if(l>=start && r<=end){
    return segtree[cur];
  }
  
  return sum(2*cur+1, start, (start+end)/2, l, r) + sum(2*cur+2, (start+end)/2+1, end, l , r);
  
}

int sum(int l,int r){
  return sum(0,0,n-1,l,r);
}


int main() {
  cin>>n;
  for(int i=0;i<n;i++){
    int x; cin>>x;
    insert(i,x);
  }
  cout<<sum(0,n);
}