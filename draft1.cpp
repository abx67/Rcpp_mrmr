#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

int Maxpos(NumericVector str,int n) {
  int i = n;
  int SIZE=str.size();
  double max;
  int maxpos = n;
  max = str[n-1];
  while (i<SIZE) {
    if (str[i]>max) {
      max = str[i];
      maxpos = i + 1;
    }
    i++;
  }
  return(maxpos);
};

//[[Rcpp::export]]
NumericVector optimal(NumericVector fea,NumericVector f,NumericVector tloc,NumericMatrix data){
  //environment
  Rcpp::Environment global = Rcpp::Environment::global_env();
  Function mutualinfo = global["mutualinfo"];
  Function DR = global["DR"];
  
  //constant variables
  
  //NumericVector fea(K);
  //int K=fea.size();       //length of feature subset
  //int dcol=data.ncol();   //ncol of data
  //int drow=data.nrow();   //nrow of data
  
  //main
  /*double a=1;
  for(int i=0;i<5;i++){
    fea[i]=a;
  }*/
  Rcpp::NumericVector drr(9);
  //drr[0]=-1.584;drr[1]=-1.536;drr[2]=-1.336;drr[3]=-1.386;drr[4]=-1.417;drr[5]=-1.436;drr[6]=-1.417;drr[7]=-1.386;drr[8]=-1.486;
  drr[0]=1.584;drr[1]=1.536;drr[2]=1.336;drr[3]=1.386;drr[4]=1.417;drr[5]=1.436;drr[6]=1.417;drr[7]=1.386;drr[8]=1.486;
  int a = Maxpos(drr);
  cout<< a <<endl;
  return (drr);
}

