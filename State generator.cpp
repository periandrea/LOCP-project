#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

void conversion(int, vector<bool>&);

int main(){
	int N=25;
	int N_max=pow(2,N);
	vector<vector<bool>> list_states;
	int counter = 0;
	
	cout<<"Computing the states..."<<endl;
	while(counter < N_max){
		vector<bool> state(N,0);
		conversion(counter, state);
		list_states.push_back(state);
		if(counter%(N_max/10)==0)
			printf("%.1f %\n",double(counter)/N_max*100);
		counter++;
	}
	cout<<"Finished!"<<endl<<endl;
	
	cout<<"Writing states..."<<endl;
	ofstream file("state_L=6.txt");
	for(int i=0; i<N_max; i++){
		for(int j=0; j<N; j++){
			if(list_states[i][j]==1)
				file<<list_states[i][j]<<" ";
			else
				file<<"-1 ";
		}
		file<<endl;
		if(i%(N_max/10)==0)
			printf("%.1f %\n",double(i)/N_max*100);
	}
	cout<<"Finished!"<<endl<<endl;
}


void conversion(int x10, vector<bool> &x2){
	int i=0, N=x2.size();
	vector<int> y2(x2.size(),0);
	while(x10!=0){
		y2[i] = x10 % 2;
		x10 /= 2;
		i++;
	}
	for(i=0; i<N; i++)
		x2[i] = bool(y2[N-i-1]);
}


/*
//	printing some of the states in terminal (used for control)
	for(int i=0; i<N_max; i++){
		if(i%1000000==0)
			cout<<i+1<<"\t";
		for(int j=0; j<N; j++){
			if(i%1000000==0){
				if(list_states[i][j]==1)
					cout<<list_states[i][j]<<" ";
				else
					cout<<"-1 ";
			}
		}
		if(i%1000000==0)
			cout<<endl;
	}
	cout<<N_max<<"\t";
	for(int i=0; i<N; i++){
		cout<<list_states[N_max-1][i];
	}
	cout<<endl;
*/
