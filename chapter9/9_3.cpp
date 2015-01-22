#include<vector>

using namespace std;

int search(int A[], int n, int target){
  int i=0, j=n-1;
  while(i<=j){
    int m=(i+j)/2;
    if(target==A[m])  return m;
    if(A[i]<=A[j]){
      if(target>A[m])
        i=m+1;
      else
        j=m-1;
    }else{
      if(A[m]>=A[i]){
        if(target>=A[i] && target<A[m])
          j=m-1;
        else
          i=m+1;
      }else{
        if(target>A[m] && target<=A[j])
          i=m+1;
        else
          j=m-1;
      }
    }
  }
  return -1;
}
