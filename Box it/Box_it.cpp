#include<bits/stdc++.h>

using namespace std;

class Box{
    private:
    int l,b,h;
    public:
    Box(){
        l=0;
        b=0;
        h=0;
    }
    Box (int l1,int b1,int h1 ){
        l = l1;
        b = b1;
        h = h1;
    }
    Box (const Box& B){
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }
    int getLength() const {
        return l;
    }
    int getHeight() const {
        return h;
    }
    int getBreadth() const {
        return b;
    }
    long long  CalculateVolume(){
        return (long long)l*b*h;
    }
    
    bool operator<(Box& other){
        bool condition1 = l < other.l;
        bool condition2 = b < other.b && l==other.l;
        bool condition3 = h < other.h && b==other.b && l==other.l;
        if(condition1 || condition2 || condition3)
        return true;
        return false;
    }
    friend ostream& operator<<(ostream& out,Box& B){
        out<<B.l<<" "<<B.b<<" "<<B.h;
        return out;
    }
};


//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}