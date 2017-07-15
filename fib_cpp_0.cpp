#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
int fib_cpp_0(int n)
{
  if(n==1||n==2) return 1;
  double a[10]={0.2,0.5,0.6,0.4,0.4,0.9,0.7,0.3,1,0.6};
  return fib_cpp_0(n-1)+fib_cpp_0(n-2)+a[0];
}
