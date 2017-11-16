#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

int Maxpos(NumericVector str) {
  int i = 1;
  int SIZE=str.size();
  double max;
  int maxpos = 1;
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

bool iselement(int num,NumericVector str){
  int i = 0;
  int SIZE=str.size();

  while (i<SIZE) {
    if (str[i] == num) {
      return 1;
    }
    i++;
  }
  return(0);
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
  
  
  //variables definition
  //Rcpp::NumericVector tempmutual;

  //main
  fea[0]=tloc[0];
  Rcpp::NumericVector drr(dcol-1);
  Rcpp::NumericVector temp;
  for (int i = 1;i<K;i++) {
    for (int j = 1;j<dcol;j++) {
      if (iselement(tloc[j],fea)){
        drr[j-1]=drr[j-2]-1000;
        //cout<<" see here  "<<tloc[j]<<" is "<<j<<endl;
        continue;
      }
      else{
        fea[i] = tloc[j];
        temp = DR(fea,f,data);
        double dr = temp[0];
        drr[j-1] = dr;
      }
    }
    int max = Maxpos(drr);
    fea[i] = tloc[max];
    cout<<max<<endl;
  }
  
  /*/trial
  Rcpp::NumericVector temp;
  //temp=D_R(fea,f,data);
  temp=mutualin(f,tloc);*/
  //dr=DR(fea,f,data);
  //cout<<fea<<endl;

  return (fea);
}