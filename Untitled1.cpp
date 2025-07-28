#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int>a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.insert(a.begin()+3,3);
	a.resize(5);
	cout<<	a.front()<<endl;
	a.erase(a.begin()+2);
	vector<int>::iterator b;
	for( b=a.begin();b<a.end();b++){
		cout<<*b<<endl;
	}
	for(auto &c: a){
		cout<<a<<endl;
	}
}

