###library###
library('Rcpp')
library(devtools)
find_rtools(T)

library('R.matlab')

library('mrmrINr')
#library('inline')
library("mrmrcr")

###path###
setwd("D:/R project/Rcpp_mrmr")
setwd("D:/")

###constant variables###
tloc=sample(seq(1,10,by=1),10,replace=FALSE)
data=matrix(sample(seq(1,10,by=1),10000,replace=TRUE),100,100)
fea=rep(0,20)
f=sample(seq(1,10,by=1),100,replace=TRUE)

tempvec = c(1,2,NA,5,3,9,4,2,NA,6,8)
vec1=sample(seq(1,40,by=1),78400,replace=TRUE)
vec2=sample(seq(1,40,by=1),78400,replace=TRUE)

######main part######
rm(optimal)
sourceCpp("optimal2.cpp")
fea=rep(0,5)
temp=optimal(fea,f,tloc,data)
temp
Maxpos(tempvec,1)
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
path <- ("C:/Users/Young/Desktop")
pathname <- file.path(path, "test1.mat")
test <- readMat(pathname)

test$answer
temp=optimal(rep(0,20),c(test$f),tloc,test$data)
temp
dim(test$data)


