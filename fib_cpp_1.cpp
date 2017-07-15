#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
RcppExport SEXP fib_cpp_1(SEXP a)
  
{
  Rcpp::NumericVector xa(a);
  //Function estpab = stats["estpab"];
  Environment stats("package:stats");
  Function convolve = stats["convolve"];
  //Function estpab = stats["estpab"];
  //int n=int(xa[0]);
  //double a[10]={0.2,0.5,0.6,0.4,0.4,0.9,0.7,0.3,1,0.6};
  //function("estpab",&estpab);
  //estpab(a);
  //cout<<xa;
  return convolve(xa,xa);
}
