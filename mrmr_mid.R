mrmr_mid <- function(d, f, K) {
  nd <- ncol(d)
  nc <- nrow(d)
  t<-vector(mode="numeric",length=0)
  for(i in 1:nd){
    t[i] <- mutualinfo(d[,i],f)
  }
  tloc=order(x<--t,y<-1:length(t))
  print(tloc)
  fea<-vector(mode="numeric",length=0)
  fea[1]=tloc[1]
  D_temp=array(0,nd)
  R_temp=array(0,nd)
  for(i in 2:K){
    for(j in 1:nd){
      if(is.element(tloc[j],fea)){
        D_temp[j]=NA
        R_temp[j]=NA
        next
      }
      else{
        fea[i]=tloc[j]
        #caculate D
        D_temp[j]=D_temp[j]+mutualinfo(d[,fea[i]],f)

        #caculate R
        for(k in 1:i){
          R_temp[j]=R_temp[j]+2*mutualinfo(d[,fea[i]],d[,fea[k]])
        }
      }
    }
    #D_temp[c(1:i-1)]=NA
    #R_temp[c(1:i-1)]=NA
    #print(D_temp)
    temp=D_temp/i-R_temp/i/i
    #print(temp)
    #print(i)
    D_R=which.max(temp)
    fea[i]=tloc[D_R]
    D_temp=array(D_temp[D_R],nd)
    R_temp=array(R_temp[D_R],nd)
  }
  return(fea)
}
