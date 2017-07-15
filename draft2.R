###library###
library('Rcpp')
library(devtools)
find_rtools(T)

library('mrmrINr')
#library('inline')
library("mrmrcr")

###path###
setwd("D:/R project/Rcpp_mrmr")
setwd("D:/")

###constant variables###
tloc=c(1:10)
data=matrix(sample(seq(1,20,by=1),100,replace=TRUE),10,10)
fea=c(1:5)
f=sample(seq(1,3,by=1),10,replace=TRUE)

vec1=sample(seq(1,40,by=1),78400,replace=TRUE)
vec2=sample(seq(1,40,by=1),78400,replace=TRUE)

######main part######
rm(optimal)
sourceCpp("optimal2.cpp")
temp=optimal(fea,f,tloc,data)
temp

###Remarks###
rm(list=ls()) 
rm()
# package.skeleton(name="mrmrINr",code_files=c("C:/Users/Young/Desktop/mrmr/R/estjointpab.r",
#                                             "C:/Users/Young/Desktop/mrmr/R/estpab.r",
#                                             "C:/Users/Young/Desktop/mrmr/R/mutualinfo.r",
#                                             "C:/Users/Young/Desktop/mrmr/R/mrmr_mid.r"))
#install.packages("E:/mrmrINr_1.0.tar.gz", repos = NULL, type = "source")
remove.packages("mrmrcr")

###Trials###

