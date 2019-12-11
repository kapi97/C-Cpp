#include<iostream>
#include<complex>
#include<fstream>
#include<algorithm>
#include<random>
#include<cmath>
#define M_PI 3.14159265358979323846

using namespace std;

struct point
{
	long double x, y;
};

long double EuclideanDistance(long double x1, long double y1, long double x2, long double y2)
{
	return sqrt ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool vector_less_pred(point const & x, point const & y)
{
	return x.y < y.y;
}

int main()
{
	long double r0=1.1;
	cout<<r0<<endl;

	int N1 = 10000;

	long double a=20*r0;
	long double b=10*N1*M_PI*r0*r0/a;

	long double V = N1*M_PI*r0*r0/(a*b);

	cout<<b<<" "<<V<<endl;

	long double r2=2*r0;

	random_device rd;
	knuth_b gen(rd());

	uniform_real_distribution<> dis(r0, a-r0);
	uniform_real_distribution<> dis1(r0, b-r0);

	vector <point> Zs;
	Zs.resize(N1);

	Zs[0].x=dis(gen);
	Zs[0].y=dis1(gen);

	int j, i=1;

	long double x, y;
	do
	{
		int k=0;
		x=dis(gen);
		y=dis1(gen);
		for(j=0; j<i; j++)
		{
			if(EuclideanDistance(x,y,Zs[j].x,Zs[i].y)<r2)
			{
				k=1;
				break;
			}
		}
		if (k==0){
			Zs[i].x=x;
			Zs[i].y=y;
			i++;
		}
	}
	while (i<N1);

	stable_sort(Zs.begin(), Zs.end(), vector_less_pred);
	fstream out_d;
	out_d.open("a.txt", ios::out);

	for (i=0;i<N1;i++)
        out_d<<Zs[i].x<<"\t"<<Zs[i].y<<endl;

    out_d.close();
    return 0;
}
