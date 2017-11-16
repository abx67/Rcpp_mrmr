#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
int fib_cpp_0(int n)
{
  if(n==1||n==2) return 1;
  return fib_cpp_0(n-1)+fib_cpp_0(n-2);
}
