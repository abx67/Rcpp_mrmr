#include <Rcpp.h>

//[[Rcpp::export]]
RcppExport SEXP max_pos(SEXP str,SEXP size) {
  Rcpp::NumericVector xstr(str);
  Rcpp::NumericVector xSIZE(size);
  int SIZE=xSIZE[0];
  int i = 1;
  int max;
  int maxposs=1;
  Rcpp::NumericVector maxpos(maxposs);
  max = xstr[0];
  while (i<SIZE) {
    if (xstr[i]>max) {
      max = xstr[i];
      maxpos = i + 1;
    }
    i++;
  }
  return maxpos[0];
}