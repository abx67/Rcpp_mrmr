estpab <- function(vec) {
  vec <- round(vec)
  m <- length(vec)

  freq <- as.data.frame(table(vec))
  freq[,2] <- freq[,2]/m
  return(freq)

}
