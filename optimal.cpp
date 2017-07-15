#include <Rcpp.h>
using namespace Rcpp;
/*int max_pos(double *str) {
  int i = 1;
  double SIZE = sizeof(str) / sizeof(str[0]);
  int max, maxpos = 1;
  max = *str;
  while (i<SIZE) {
    if (*(str + i)>max) {
      max = *(str + i);
      maxpos = i + 1;
    }
    i++;
  }
  return(maxpos);
}*/
/*int max_pos(NumericVector str) {
 int i = 1;
 double SIZE = sizeof(str) / sizeof(str[0]);
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
};*/

NumericVector replace(NumericVector str,NumericMatrix dd,int length,int col) {
  for(int i=0;i<length;i++){
    str[i]=dd(i,col);
  }
  return(str);
}
//[[Rcpp::export]]
NumericVector optimal(NumericVector xk,NumericVector nr,NumericVector nc,NumericVector fea,NumericVector f,NumericVector tloc,NumericMatrix data,NumericVector tempvec1,NumericVector tempvec2){
//NumericVector optimal(){
  //SEXP optimal(SEXP xk,NumericVector nr,NumericVector nc,NumericVector fea,NumericVector f,NumericVector tloc,NumericMatrix data,NumericVector tempvec1,NumericVector tempvec2)
  //RcppExport SEXP optimal()
  Environment mrmr("package:mrmrINr");
  Rcpp::Environment global = Rcpp::Environment::global_env();
  Function estpab = mrmr["estpab"];
  Function estjointpab = mrmr["estjointpab"];
  Function mutualinfo = mrmr["mutualinfo"];
  int K=xk[0];
  int dcol=nc[0];
  int drow=nr[0];
  /*int K=global["xk"];
  int drow=global["drow"];
  int dcol=global["dcol"];
  Rcpp::NumericVector fea=global["feaa"];
  Rcpp::NumericVector f=global["f"];
  Rcpp::NumericVector tloc=global["xtloc"];
  Rcpp::NumericMatrix data=global["d"];
  Rcpp::NumericVector tempvec1=global["tempvec1"];
  Rcpp::NumericVector tempvec2=global["tempvec2"];*/
  fea[0]=tloc[0];
  Rcpp::NumericVector tempmutual;
  Rcpp::NumericVector D;
  Rcpp::NumericVector R;
  Rcpp::NumericVector D_R;
  for (int i = 1;i<K;i++) {
    /*double *D;
    D = new double[nd];*/

    for(int ii=0;ii<dcol;ii++){
      D[ii]=0;
      R[ii]=0;
      D_R[ii]=0;
    }
    for (int j = 0;j<dcol;j++) {
      fea[i] = tloc[j];
      for(int l=0;l<i;l++){
        //int temp=fea[l];
        tempvec1=replace(tempvec1,data,drow,l);
        //tempmutual=estpab(f);
      }
     // tempmutual=mutualinfo(tempvec1,f);
      //D[j] = tempmutual[0];
      /*for(int r=0;r<i;r++){
        for(int rr=0;rr<i;r++){
          int temp1=fea[r-1];
          int temp2=fea[rr-1];
          tempvec1=replace(tempvec1,data,drow,temp1);
          tempvec2=replace(tempvec2,data,drow,temp2);
          tempmutual=mutualinfo(tempvec1,tempvec2);
          R[j] += tempmutual[0];
        }
      }*/
      //D_R[j] = D[j]; // (i+1) - R[j] / ((i+1)*(i+1)) ;
    }
    //tempmutual=mutualinfo(tempvec1,f);
    //fea[i]=max_pos(D_R);
    //fea[i]=D_R[i];
  }
/*
  //std::vector<double> a = global["a"];
  //SEXP b[10]={9,8,7,6,5,4,3,2,1,1};
  //double bb[10];
  //for (int i=0;i<10;i++) bb[i]=i;
  //fea[0]=tloc[0];
  //fea=a;
  //Rcpp::NumericVector ttloc;
  //for (int i=0;i<10;i++) {
  //  ttloc[i]=dd(i,1);
  //}
  
  //std::NumericMatrix ttloc;
  Rcpp::NumericVector b=global["bb"];
  b=replace(b,dd,10,8);
  //b=replace(b,dd);
  //Rcpp::NumericVector a=mutualinfo(b,b);
  //Rcpp::NumericVector aa(a);
  fea[1]=dd(5,5);
  //fea[3]=max_pos(tloc);
  fea[4]=b[1];
  //fea[2]=ttloc[5];*/
  //tempmutual=mutualinfo(tempvec1,f);
  tempmutual=estpab(f);
  fea[4]=tempvec1[5];
  return(fea);
}