# GRAFICOS EN R
# El comando plot()
x <-runif(50,0,4) #50 numeros que siguen la normal entre 0-50
y <-runif(50,0,4) #50 numeros que siguen la normal entre 0-50
plot(x,y,main="Titulo principal",sub="subtitulo",xlab="etiqueta eje x",ylab="Etiqueta eje y",xlim=c(-1,5),col="red")

#variaciones de plot
z <- cbind(x,y) # 2 columnas
z
plot(z)
# formula
plot(y ~ x, col="red") # x ∼ y se conoce como una formula en R
#
plot(log(y + 1) ~ x) #transformacion de y
plot(x,y,type="p")

plot(x,y,type="l") #lineas
plot(x,y,type="b") #puntos unidos por lineas

plot(c(1,5),c(1,5))
legend(1,4,c("uno","dos","tres"),lty=1:3,col=c("red","blue","green"),pch=15:17,cex=2)

### Segundo dia
plot(1:10,1:10,axes=FALSE,xlab="",ylab="")
polygon(runif(4,1,10),runif(4,1,10),col="lightblue")
points(runif(5,1,10),runif(5,1,10),cex=1.5,col="navyblue")
points(runif(5,1,10),runif(5,1,10),pch="+",cex=1.7,col="red")
lines(1:10,runif(10,1,10),lty=2,lwd=2)
text(runif(5,1,10),runif(5,1,10),labels=c("uno","dos","tres","cuatro","cinco"),cex=1.7,col=rainbow(5))
abline(h=5,lty=4)
title("Grafico variado")
axis(1,labels = c("uno","tres","cinco","siente","nueve"),at = seq(1,10,by=2))
axis(2,labels = 1:10,at=1:10)
legend(8,3,lty=c(1:3),col=rainbow(3),legend = c("uno","dos","tres","cuatro","cinco"))

#Tipos de puntos en un plot con los comandos plot:pch,col,
x <-runif(50,0,4) #50 numeros que siguen la normal entre 0-50
y <-runif(50,0,4) #50 numeros que siguen la normal entre 0-50

plot(x,y,type="n")
points(x,y,pch=3,col="red")

# tipos de puntos
plot(c(1, 10), c(1, 3), type = 'n', axes = FALSE, xlab = '', ylab = '')
points(1:10, rep(1, 10), pch = 1:10, cex = 2, col='maroon2')
points(1:10, rep(1, 10), pch = 1:10, cex = 2, col='maroon2')
points(1:5, rep(3, 5), pch = 21:25, cex = 2, col='blue',bg="red")

#malla 
par(mfrow=c(2,2)) ## define malla 2x2 para graficos
plot(rnorm(10))
plot(runif(5,rnorm(5)))
plot(runif(10))
plot(rnorm(10),rnorm(10))

VADeaths
barplot(VADeaths,beside=TRUE,legend=TRUE,ylim=c(0,90),ylab="muerte x cada 1000",main=("TASA DE MORTALIDAD "))
dotchart(VADeaths,xlim=c(0,75),xlab="muertes x cada 1000",main=("tasas de mortalidad virginia))

## dia 3

grupos <- c(18, 32, 10, 10)
etiquetas <- c('A', 'B', 'C', 'D', 'F')
pie(grupos, etiquetas, col=c('red', 'blue', 'green', 'yellow', 'orange'))

#histograma
x<- rnorm(100)
hist(x,col="blue")

##diagrama cajas

boxplot(Sepal.Length ~ Species, data=iris,ylab='Largo sepalo (cm)', main='Medidas de la tabla iris',boxvwex=0.5,col='red')
  
iris
head(iris)
tail(iris)

library(ellipse)
correlation<-cor(iris[,-5])
plotcorr(correlation,col='blue') ## mas correlacion eliptica
correlation

## otro tipo de figura

library(corrplot)
corrplot(correlation)

col<- colorRampPalette(c('yellow' , 'red', 'green' , 'blue'))
corrplot(correlation,method='shade',shadecol='NA',tl.col='black',tl.srt=45,col=col(200),addCoef.col='black',order='AOE')

##
hist(iris$Sepal.Length,col=3)
plot(density(iris$Sepal.Length))
pie(table(iris$Species))
barplot(table(iris$Species),col='blue')

boxplot(Sepal.Length ~ Species, data = iris, col = c('gray7', 'gray13', 'gray17'))
