#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int macierz[3][3], i, j, a[3][3];
	float wyznacznik = 0;

	cout<<"Podaj elementy macierzy: "<<endl;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++){
			cout<<"Macierz ["<<i<<"]["<<j<<"] : ";
			cin>>macierz[i][j];}

	cout<<endl<<"Podana macierz:"<<endl;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++)
			cout<<macierz[i][j]<<"\t";
			cout<<endl<<endl;}

	wyznacznik = (macierz[0][0]*macierz[1][1]*macierz[2][2] + macierz[0][1]*macierz[1][2]*macierz[2][0] + macierz[0][2]*macierz[1][0]*macierz[2][1])
			   - (macierz[0][2]*macierz[1][1]*macierz[2][0] + macierz[0][0]*macierz[1][2]*macierz[2][1] + macierz[0][1]*macierz[1][0]*macierz[2][2]);

//	wyznacznik = macierz[0][0]*macierz[1][1]*macierz[2][2] + macierz[1][0]*macierz[2][1]*macierz[0][2] + macierz[2][0]*macierz[0][1]*macierz[1][2]
//		 	   - macierz[0][2]*macierz[1][1]*macierz[2][0] - macierz[1][2]*macierz[2][1]*macierz[0][0] - macierz[2][2]*macierz[0][1]*macierz[1][0];


	cout<<"Wyznacznik: "<<wyznacznik<<endl;


	a[0][0] = (pow(-1,1+1)) * (macierz[1][1]*macierz[2][2] - macierz[1][2]*macierz[2][1]);
	a[0][1] = (pow(-1,1+2)) * (macierz[1][0]*macierz[2][2] - macierz[1][2]*macierz[2][0]);
	a[0][2] = (pow(-1,1+3)) * (macierz[1][0]*macierz[2][1] - macierz[1][1]*macierz[2][0]);

	a[1][0] = (pow(-1,2+1)) * (macierz[0][1]*macierz[2][2] - macierz[0][2]*macierz[2][1]);
	a[1][1] = (pow(-1,2+2)) * (macierz[0][0]*macierz[2][2] - macierz[0][2]*macierz[2][0]);
	a[1][2] = (pow(-1,2+3)) * (macierz[0][0]*macierz[2][1] - macierz[0][1]*macierz[2][0]);

	a[2][0] = (pow(-1,3+1)) * (macierz[0][1]*macierz[1][2] - macierz[0][2]*macierz[1][1]);
	a[2][1] = (pow(-1,3+2)) * (macierz[0][0]*macierz[1][2] - macierz[0][2]*macierz[1][0]);
	a[2][2] = (pow(-1,3+3)) * (macierz[0][0]*macierz[1][1] - macierz[0][1]*macierz[1][0]);


	cout<<endl<<"Dopelnienie algebraiczne macierzy:"<<endl;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++)
			cout<<"A"<<i+1<<j+1<<" = "<<a[i][j]<<endl;}

	cout<<endl<<"Macierz dopelnien algebraicznych:"<<endl;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++)
			cout<<a[i][j]<<"\t";
			cout<<endl<<endl;}

	cout<<endl<<"Macierz transponowana:"<<endl;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++)
			cout<<a[j][i]<<"\t";
			cout<<endl<<endl;}
		

	if(wyznacznik!=0){
	cout<<endl<<"Macierz odwrotna:"<<endl;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++)
			cout<<a[j][i]/wyznacznik<<"\t";
			cout<<endl<<endl;}
		}
		else if(wyznacznik==0)
		{
		cout<<"Macierz jest osobliwa.";
		}

	return 0;
}
