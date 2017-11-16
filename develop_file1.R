####This is a file complied all functions we need 
####just for the use of development
####dont complie them into packed package



####establish probability
estpab <- function(vec) {
  vec <- round(vec)
  m <- length(vec)
  
  freq <- as.data.frame(table(vec))
  freq[,2] <- freq[,2]/m
  return(freq)
  
}

####establish joint probability
estjointpab <- function(vec1,vec2) {
  vec1 <- round(as.numeric(vec1))
  vec2 <- round(as.numeric(vec2))
  m <- length(vec1)
  n <- length(vec2)
  if (m!=n){
    print("the two input variables length differ")
    return(0)
  }
  else{
    vec<-paste(vec1,vec2)
    freq <- as.data.frame(table(vec))
    freq[,2] <- freq[,2]/m
    return(freq)
  }
}

####calculate mutual information
mutualinfo <- function(vec1,vec2) {
  vec1 <- round(as.numeric(vec1))
  vec2 <- round(as.numeric(vec2))
  m <- length(vec1)
  n <- length(vec2)
  if (m!=n){
    print("the two input vector length differ")
    return(0)
  }
  else{
    vec<-paste(vec1,vec2)
    freq1 <- estpab(vec1)
    freq2 <- estpab(vec2)
    freq12<- estjointpab(vec1,vec2)
    n1 <- nrow(freq1)
    n2 <- nrow(freq2)
    mutuinfo=0
    for (i in 1:n1){
      for(j in 1:n2){
        temploc=which(freq12==paste(freq1[i,1],freq2[j,1]))
        if(sum(temploc)){
          temp=freq12[temploc,2]*log(freq12[temploc,2]/freq1[i,2]/freq2[j,2])
          mutuinfo= mutuinfo+temp
        }
        else{next}
      }
    }
    return (mutuinfo/log(2))
  }
}

