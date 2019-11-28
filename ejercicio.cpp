#include<iostream>
#include <fstream>
#include <sstream>
#include <math.h> 
#include<cmath>

using namespace std;

void phi(string nombre_txt, double c, double L, double dx, double dt,int num, int numt);
    
int main(int argc, char **argv){
  int n_x;
  double rho=0.01;
  double ten=40;
  double L=1.0;  
  int n_t=1000;
  double dx ;
  double dt ;
  double c=sqrt(ten/rho);

  n_x=atoi(argv[1]);

  dx = L/n_x;
  dt = pow(dx,4);
	
   phi("datos.dat",c, L, dx,dt,n_x,n_t); 
  
	return 0;
  }
  
void phi(string nombre_txt, double c, double L, double dx, double dt,int num, int numt)
{
    double cp=dx/dt;
	ofstream file;
	file.open(nombre_txt.c_str());
	float datosxn[num][numt];
    for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < numt; ++j)
		{	
           datosxn[i][j]=pow(10,-4)*sin(2*M_PI*j/(L*100));
        }
    }          
          
	for (int i = 1; i < num-1; ++i)
	{
		for (int j = 1; j < numt-1; ++j)
		{	
            if(j==1)
            {
              datosxn[i+1][j]=datosxn[i][j]+pow(c,2)*(datosxn[i][j+1]+datosxn[i][j-1]-2*datosxn[i][j])/(2*pow(cp,2)); 
            }
            else
            {
              datosxn[i+1][j]=(2*(datosxn[i][j]))-(datosxn[i-1][j])+(pow(c,2)*(datosxn[i][j+1]+datosxn[i][j-1]-2*datosxn[i][j])/pow(cp,2));  
            }
			file << datosxn[i][j]<< " ";
		}
			file << "\n";
		}
		file.close();
}


