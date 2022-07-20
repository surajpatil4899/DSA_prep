#include<bits/stdc++.h>
using namespace std;
#define ll long long

// class SGTree {
// 	vector<ll> seg;
// public:
// 	SGTree(int n) {
// 		seg.resize(4 * n + 1);
// 	}
 
// 	void build(int ind, int low, int high, int arr[]) {
// 		if (low == high) {
// 			seg[ind] = arr[low];
// 			return;
// 		}
 
// 		int mid = (low + high) / 2;
// 		build(2 * ind + 1, low, mid, arr);
// 		build(2 * ind + 2, mid + 1, high, arr);
// 		seg[ind] = 0;
// 	}
 
// 	ll query(int ind, int low, int high, int i) {
// 	    propogate(ind,low,high);
// 	    if(low==high){
// 	        return seg[ind];
// 	    }

       

// 		int mid = (low + high) >> 1;
// 		if(i <= mid) return query(2 * ind + 1, low, mid,i);
// 		else return query(2 * ind + 2, mid + 1, high,i);
		
// 	}
	
// 	void propogate(int ind,int low,int high){
// 	    if(low==high) return;
// 	    seg[2*ind+1] += seg[ind];
// 	    seg[2*ind+2] += seg[ind];
// 	    seg[ind] = 0;
// 	}
	
// 	void update(int ind, int low, int high, int l,int r,int val) {
// 		if (low == high) {
// 			seg[ind] += val;
// 			return;
// 		}
		
// 		if (r < low || high < l) return;
//      	if (low >= l && high <= r){
//         	    seg[ind] += val;
//         	    return;
//          }
// 	   int mid = (low+high)/2;
// 	   update(2*ind+1,low,mid,l,r,val);
// 	   update(2*ind+2,mid+1,high,l,r,val);
// 	}
// };

class ST {
	vector<ll> seg, lazy; 
public: 
	ST(int n) {
		seg.resize(4 * n); 
		lazy.resize(4 * n); 
	}
public: 
	void build(int ind, int low, int high, int arr[]) {
		if(low == high) {
			seg[ind] = arr[low];
			return; 
		}
		int mid = (low + high) >> 1; 
		build(2*ind+1, low, mid, arr); 
		build(2*ind+2, mid+1, high, arr); 
		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}
public:
	void update(int ind, int low, int high, int l, int r, 
		int val) {
		// update the previous remaining updates 
		// and propogate downwards 
		if(lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind]; 
			// propogate the lazy update downwards
			// for the remaining nodes to get updated 
			if(low != high) {
				lazy[2*ind+1] += lazy[ind]; 
				lazy[2*ind+2] += lazy[ind]; 
			}
 
			lazy[ind] = 0; 
		}
 
		// no overlap 
		// we don't do anything and return 
		// low high l r or l r low high 
		if(high < l or r < low) {
			return; 
		}
 
		// complete overlap 
		// l low high r 
		if(low>=l && high <= r) {
			seg[ind] += (high - low + 1) * val; 
			// if a leaf node, it will have childrens
			if(low != high) {
				lazy[2*ind+1] += val; 
				lazy[2*ind+2] += val; 
			}
			return; 
		}
		// last case has to be no overlap case
		int mid = (low + high) >> 1; 
		update(2*ind+1, low, mid, l, r, val);
		update(2*ind+2, mid+1, high, l, r, val); 
		seg[ind] = seg[2*ind+1] + seg[2*ind+2]; 
	}
public: 
	ll query(int ind, int low, int high, int l, int r) {
 
		// update if any updates are remaining 
		// as the node will stay fresh and updated 
		if(lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind]; 
			// propogate the lazy update downwards
			// for the remaining nodes to get updated 
			if(low != high) {
				lazy[2*ind+1] += lazy[ind]; 
				lazy[2*ind+2] += lazy[ind]; 
			}
 
			lazy[ind] = 0; 
		}
 
		// no overlap return 0; 
		if(high < l or r < low) {
			return 0; 
		}
 
		// complete overlap 
		if(low>=l && high <= r) return seg[ind]; 
 
		int mid = (low + high) >> 1; 
		ll left = query(2*ind+1, low, mid, l, r);
		ll right = query(2*ind+2, mid+1, high, l, r);
		return left + right; 
	}
};

int main(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    ST segment(n);
    segment.build(0,0,n-1,arr);
    
    while(q--){
        int type;
        cin >>  type;
        if(type==1){
            int l,r,val;
            cin >> l >> r >> val;
            segment.update(0,0,n-1,l-1,r-1,val);
        }else{
            int i;
            cin >> i;
            cout << segment.query(0,0,n-1,i-1,i-1) << endl;
        }
    }
    
}