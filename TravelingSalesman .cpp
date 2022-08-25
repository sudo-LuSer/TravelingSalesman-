#include <iostream>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
#define X first
#define Y second 
#define inf pow(10,64)
double distance(int a , int b , int c ,int d ){
	double XAxis = a - c ; 
	XAxis*=XAxis;
	double YAxis = b - d ; 
	YAxis*=YAxis;
	return sqrt(XAxis+YAxis); 
}
int main(){
	int XAxis , YAxis;
	cin>>XAxis>>YAxis;
	int n;cin>>n; 
	vector<pair<string , pair<int , int> > >TwoDimensionCordinates; 
	for(int i = 0 ; i < n ;i++){
		string name; cin>>name; 
		int x,y;cin>>x>>y; 
		TwoDimensionCordinates.push_back(make_pair(name , make_pair(x,y)));
	}
	//TravelingSalesmanAlgorithm : : : 
	long double min = inf;
	int px = 0, py = 0 ; 
	string shortDistancecityName ="LongLong"; 
	vector<string>TravelingSalesman; 
	for(int i = 0 ; i<n ;i++){
		for(auto pi : TwoDimensionCordinates){
			if(min > distance(XAxis , YAxis , pi.Y.X , pi.Y.Y)){
				min = distance(XAxis , YAxis , pi.Y.X , pi.Y.Y); 
				shortDistancecityName = pi.X; 
				px = pi.Y.X;
				py = pi.Y.Y; 
			}
		}
		XAxis = px;
		YAxis = py; 
		TravelingSalesman.push_back(shortDistancecityName); 
	}
	for(string names : TravelingSalesman){
		cout<<names<<" ";
	}
}
//remove(v.begin(),v.end(),val)