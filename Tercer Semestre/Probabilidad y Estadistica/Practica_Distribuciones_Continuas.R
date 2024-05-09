#Practica distribuciones continuas

#:01 Distribucion Normal estándar --------


p2 <- pnorm(q = 2)  #P(z<=2) = PHI(2)
p1 <- pnorm(q = -2) #P(z<=-2)= PHI(-2)
aux <- c(p1, p2, p2-p1) #P(-2<z<=2) PHI(2)-PHI(-2)
round(aux, 4)

p2 <- pnorm(q = 1.96)
p1 <- pnorm(q = -1.96)
aux <- c(p1, p2, p2-p1)
round(aux, 4)

#inversa de probabilidad
qnorm(0.9772)   #cercano a 2.0
qnorm(0.975)    #cercano a 1.96
qnorm(0.5)      #debe de ser 0
qnorm(0.025)    #cercano a -1.96
qnorm(0.0228)   #cercano a -2

