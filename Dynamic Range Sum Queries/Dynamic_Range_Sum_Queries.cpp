#include<bits/stdc++.h>
using namespace std;
#define ll long long

class SGTree {
	vector<ll> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}
 
	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
 
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
 
	ll query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return 0;
 
		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];
 
		int mid = (low + high) >> 1;
		ll left = query(2 * ind + 1, low, mid, l, r);
		ll right = query(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}
 
		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
};
 

int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    SGTree segment(n);
    segment.build(0,0,n-1,arr);
    
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int k,val;
            cin>>k>>val;
            segment.update(0,0,n-1,k-1,val);
            arr[k-1] = val;
        }else{
            int l,r;
            cin>>l>>r;
            cout<<segment.query(0,0,n-1,l-1,r-1)<<endl;
        }
    }
    
}