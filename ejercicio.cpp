#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"


void init(double *psi, int n_x);
void print(double *psi, int n_x);
void copy(double *recibe, double *entrega, int n_x);
void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x, double c, int n_t);

int main(int argc, char **argv){
  double *psi = NULL;
  double *psi_past = NULL;
  int n_x;
  int n_t=10;
  double delta_x ;
  double delta_t ;
  double c=1;

  n_x=atoi(argv[1]);

  delta_x = 2.0/(n_x-1);
  delta_t = 0.5 * delta_x * delta_x;
  
  psi  = new double [n_x];
  psi_past  = new double [n_x];

  init(psi, n_x);
  for(int i=0; i<n_t;i++)
  {
	 copy(psi_past, psi, n_x);
     evolve(psi, psi_past, delta_t, delta_x, n_x,c, i); 
  }
  
	 return 0;
  }
  

void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x, double c, int n_t){
  double cp=delta_x/delta_t;
  double s=-1.0;
  for(int i=1;i<n_x-1;i++){
    psi_new[i] = psi_old[i];
	std::cout << n_t << " " << i << " " << psi_new[i] << " "<< std::endl;
    psi_new[i] += 2*psi_old[i]-psi_old[i-1]+(c*(psi_old[i+1]-2*psi_old[i] + psi_old[i-1])/(cp*cp));
 
  }
  
}

void copy(double *recibe, double *entrega, int n_x){
  int i;
  for (i=0;i<n_x;i++){
    recibe[i] = entrega[i];
  }
}

void init(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    psi[i] = 1.0;
  }
}


void print(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    std::cout << psi[i] << " ";
  }
  std::cout << "\n";
}