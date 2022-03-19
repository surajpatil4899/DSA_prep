#include<bits/stdc++.h>

using namespace std;

int main()
{
   
  int m[5][5];
  int row,col;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        cin>>m[i][j];
        if(m[i][j]==1){
            row = i;
            col = j;
        }
    }
  }
   int ans;
   ans = (abs(col-2))+(abs(row-2));
   cout<<ans<<endl;
}