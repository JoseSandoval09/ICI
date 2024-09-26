library(FactoMineR)
setwd("C:/Users/josee/OneDrive/Escritorio/ICI/Sexto Semestre/Aprendizje Inteligente")
Datos <- read.csv("EjemploEstudiantes.csv", sep=";", dec=",", row.names=1)
Datos
res <- PCA(Datos, scale.unit = TRUE, graph = FALSE, ncp=5) 
res
plot(res,axes=c(1,2), choix="ind", col.ind = "blue", habillage = 1, cex=0.7)
plot(res,axes=c(1,2), choix="var", col.var = "red", cex=0.7)

