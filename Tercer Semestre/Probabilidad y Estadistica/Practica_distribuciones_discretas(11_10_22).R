# Práctica: distribuciones de probabilidad discretas
# rm(list=ls())
# Contenido:
#:01 Distribución binomial

#:01 Distribución binomial ----------
# X: número de éxitos en n ensayos de Bernoulli
# X = 0,1,...,n
# n >= 1, es el total de ensayos
# p = P(E), de cada ensayo, 0 <= p <= 1.

# a) Ejemplo: apostar un peso a los 
#    números rojos en el juego de la
#    ruleta, n = 10 y p = 18/38 = 0.4737.

# Valores de los parámetros
n<- 20 #10 #  
p<- 18/38
x<- 0:n    # conjunto de valores posibles
f.x<- choose(n=n,k=x)*p^x*(1-p)^(n-x)
F.x<- cumsum(f.x)
fx<- dbinom(x=x,size=n,prob=p)
Fx<- pbinom(q=x,size=n,prob=p)
mat<- cbind(x,f.x,fx,F.x,Fx)
mat<- round(mat,4)
mat

moda<- which.max(fx)
moda
moda<- x[moda]
moda

media<- n*p
media
media.formula.universal <- sum(x * fx)
media.formula.universal

aux<- which(Fx>=0.5)
mediana<- x[aux[1]]
mediana

#juegos al cuadrado -> dispersion de la poblacion -> escala cuadratica
varianza <- n * p * (1 - p)
varianza.formula.universal <- sum((x - media)^2 * fx)
varianza.formula.universal
varianza


#juegos (desviacion estandar)
d.e <- sqrt(varianza)
d.e





x11()
main<- "función de densidad binomial"
xlab<- "x: número de juegos ganados"
ylab<- "f(x): probabilidad"
plot(x,fx,xlab=xlab,ylab=ylab,main=main,
     type="p",pch=19,col="red")
rug(x,col="blue")
points(c(media,moda),c(0,0),pch=c(3,2),
       col=c("green","orange"))
leyenda<- c("media","moda")
legend(x="topright",legend=leyenda,
       pch=c(3,2),col=c("green","orange"),
       text.col=c("green","orange"))

x11()
main<- "función de distribución binomial"
xlab<- "x: número de juegos ganados"
ylab<- "F(x): probabilidad acumulada"
plot(x,Fx,xlab=xlab,ylab=ylab,main=main,
     type="p",pch=19,col="red")
rug(x,col="blue")
points(c(media,moda,mediana),
       c(0,0,0.05),pch=c(3,2,4),
       col=c("green","orange","yellow"))
leyenda<- c("media","moda","mediana")
legend(x="bottomright",legend=leyenda,
       pch=c(3,2,4),
       col=c("green","orange","#dede86"),
       text.col=c("green","orange","yellow"))