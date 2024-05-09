# Práctica: distribuciones de probabilidad discretas
# rm(list=ls()) # nolint
# Contenido:
#:01 Distribución binomial
#:01 Distribución binomial ----------
# X: número de éxitos en n ensayos
#    de Bernoulli
# X = 0,1,...,n
# n >= 1, es el total de ensayos (0-1)
# p = P(E), de cada ensayo, 0 <= p <= 1.

# a) Ejemplo: apostar un peso a los 
#    números rojos en el juego de la
#    ruleta, n = 10 y p = 18/38 = 0.4737.

# Valores de los parámetros



n <- 20
p <- 18/38
x <- 0:n    # conjunto de valores posibles, ganar de 0-10 juegos
#coeficiente binomial - desarrollo de toda funcion, chosee->combinatoria (n en x)
f.x <- choose(n=n, k = x) * p^x * (1 - p)^(n - x) 
F.x <- cumsum(f.x)
fx <- dbinom(x=x,size=n,prob=p)#coeficiente binomial eficiente
Fx <- pbinom(q=x,size=n,prob=p)#coeficiente binomial eficiente
mat <- cbind(x,f.x,fx,F.x,Fx) #matriz concatenacion
mat <- round(mat,4)#redondear matriz 4 digitos 
mat
moda <- which.max(fx) #moda=el valor posible con mayor probabilidad
moda
moda <- x[moda]
moda
media <- n*p
media
aux <- which(Fx>=0.5)
mediana <- x[aux[1]]
mediana

#EVENTOS DE INTERES
#A=Se gana con estrategia establecida = {X>=6}
#B= Se pierde = {x<=4}
#C= Hay empate= {X=5}
#AUBUC= Omega

#P(X=5)=f(5)=0.2427
#P(X<=4)=F(4)=f(0) + f(1) + f(2) + f(3) + f(4) = 0.4432
#P(X>=6) = 1-P(X<6) = 1-P(x<=5) = 1-0.6859 = 0.3141


x11()
main<- "función de densidad binomial"
xlab<- "x: número de juegos ganados"
ylab<- "f(x): probabilidad"
plot(x,fx,xlab=xlab,ylab=ylab,main=main,
     type="p",pch=19,col="red")#type punt("p")
rug(x,col="blue")
points(c(media,moda),c(0,0),pch=c(3,2),
       col=c("green","orange"))
leyenda<- c("media","moda")
legend(x="topright",legend=leyenda,
       pch=c(3,2),col=c("green","orange"),
       text.col=c("green","orange"))


x11()
main<- "función de distribucion binomial"
xlab<- "x: número de juegos ganados"
ylab<- "F(x): probabilidad acumulada"
plot(x,Fx,xlab=xlab,ylab=ylab,main=main,
     type="p",pch=19,col="#38f10f")#type punt("p")
rug(x,col="blue")
points(c(media,moda,mediana),c(0,0,0.05),pch=c(2,9,17),
       col=c("green","orange","blue"))
leyenda<- c("media","moda","mediana")
legend(x="bottomright",legend=leyenda,
       pch=c(2,9,17),col=c("green","orange","blue"),
       text.col=c("green","orange","blue"))



