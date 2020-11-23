#include <iostream>	
#include <conio.h>
using namespace std;
	
	
	
	
	
	
const int row = 4;//can change
const int col = 3;//can change

int solardata=0;
int sparse_matrix[100][3];



void show_new_matrix();
void set_special_sparse_matrix(int temp,int i,int j);



void get(int origional_matrix[][col],int row,int col){
cout<<"Enter main matrix elements:"<<endl;
	for (int i=0;i<row;i++){
		cout<<"enter row number:"<<i<<endl;
		for(int j=0;j<col;j++){
			cin>>origional_matrix[i][j];
		}
	}
}



void show(int origional_matrix[][col],int row,int col){
	cout<<"\nThis is the matrix you entered:"<<endl;
	for (int i=0;i<row;i++){
		cout<<endl<<"|";
		for(int j=0;j<col;j++){
			cout<<origional_matrix[i][j]<<" ";
		}
		cout<<"|";
	}
}




void check(int origional_matrix[][col],int row,int col){
	int counter_zero=0;
	int counter_none_zero=0;
	for (int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if (origional_matrix[i][j]==0){
				counter_zero++;
			}else{
				int temp=origional_matrix[i][j];
				counter_none_zero++;
				set_special_sparse_matrix(temp,i,j);
			}
		}
	}
	if(counter_zero>counter_none_zero){
		cout<<"\n\nmatrix you entered is an sparse matrix"<<endl;
		show_new_matrix();
	}else{
		cout<<"\n\nmatrix you entered is NOT an sparse matrix"<<endl;
	}
}
/*
	*	SET VALUES OF sparse_matrix
*/
void set_special_sparse_matrix(int temp,int i,int j){
	sparse_matrix[solardata][0]=i;
	sparse_matrix[solardata][1]=j;
	sparse_matrix[solardata][2]=temp;
	solardata++;
}



void show_Tmatrix(){
cout<<"\nHere is T-matrix from your sparse matrix:\n";
	for(int m=0;m<solardata;m++){
		int temporay=sparse_matrix[m][0];
		sparse_matrix[m][0]=sparse_matrix[m][1];
		sparse_matrix[m][1]=temporay;
	}
	for(int i=0;i<solardata;i++){
		cout<<"\n";
		for(int j=0;j<3;j++){
			cout<<" "<<sparse_matrix[i][j]<<" ";	
		}
	}
}



void show_new_matrix(){
	for(int i=0;i<solardata;i++){
		cout<<"\n";
		for(int j=0;j<3;j++){
			cout<<" "<<sparse_matrix[i][j]<<" ";	
		}
	}
	show_Tmatrix();
}







int main(){
	int origional_matrix[row][col];
	get(origional_matrix,row,col);
	show(origional_matrix,row,col);
	check(origional_matrix,row,col);

}