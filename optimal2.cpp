#include <Rcpp.h>
using namespace Rcpp;

int Maxpos(NumericVector str) {
  int i = 1;
  int SIZE=str.size();
  int max, maxpos = 1;
  max = str[0];
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
  int K=fea.size();       //length of feature subset
  int dcol=data.ncol();   //ncol of data
  //int drow=data.nrow();   //nrow of data
  
  
  //variables definition
  //Rcpp::NumericVector tempmutual;

  //main
  fea[0]=tloc[0];
  Rcpp::NumericVector dr;
  Rcpp::NumericVector temp;
  for (int i = 1;i<K;i++) {
    for (int j = i;j<dcol;j++) {
      fea[j] = tloc[j ];
      /*temp = DR(fea,f,data);
      dr[j] = temp[0];*/
    }
    //Rcpp::NumericVector temp2(dr);
    //int p = Maxpos(temp);
  }
  
  /*/trial
  Rcpp::NumericVector temp;
  //temp=D_R(fea,f,data);
  temp=mutualin(f,tloc);*/
  dr=DR(fea,f,data);
  return (dr);
}