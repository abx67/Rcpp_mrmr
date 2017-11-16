###R function test###
set.seed(1)
tloc=sample(seq(1,10,by=1),10,replace=FALSE)
data=matrix(sample(seq(1,10,by=1),10000,replace=TRUE),100,100)
fea=rep(0,20)
f=sample(seq(1,10,by=1),100,replace=TRUE)
vec1=sample(seq(1,40,by=1),784,replace=TRUE)
vec2=sample(seq(1,40,by=1),784,replace=TRUE)



mutualinfo(vec1,vec2)
