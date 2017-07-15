getonefea <- function(fea,tloc,f,data){
  temploc=tloc[!(tloc %in% fea)]
  tempfea=sapply(temploc,function(a,fea) c(fea,a),fea=fea)
  allD_R=apply(tempfea,2,D_R,f=f,data=data)
  fea=c(fea,temploc[which.max(allD_R)])
  return(fea)
}

mrmr_mid <- function(data,f,K){
  t<-vector(mode="numeric",length=0)
  t = apply(data,2,mutualinfo,vec2=f)
  tloc=order(x<--t,y<-1:length(t))
  fea<-vector(mode="numeric",length=0)
  fea[1]=tloc[1]
  for (i in 1:K){
    fea=getonefea(fea,tloc,f,data)
  }
  return (fea)
}
system.time(mrmr_mid(data,f,5))
system.time(mutualin(vec1,vec2))
system.time(mutualinfo(vec1,vec2))
mutualin(vec1,vec2)
mutualinfo(vec1,vec2)

