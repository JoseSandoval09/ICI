# -*- coding: cp1252 -*-
import wx
import random
import copy

global matriz
matriz = []

class Node:
    def __init__(self, coords, pre, costo):
        self.coords = coords
        self.pre = pre
        self.costo = costo
        self.estima = 39 - coords[0]

    def __str__(self):
        return('['+str(self.coords[0])+','+str(self.coords[1])+']')

class Node2:
    def __init__(self, coords, pre, costo):
        self.coords = coords
        self.pre = pre
        self.costo = costo
        self.estima = coords[0] + coords[1]

    def __str__(self):
        return('['+str(self.coords[0])+','+str(self.coords[1])+']')

def inicializa():
    indices = list(range(40))

    for idx in range(40):
        fila = []
        aleatorio = random.random()*12+33
        unos = int(40*aleatorio*0.01)
        lugares = random.sample(indices, unos)

        for jdx in range(40):

            if jdx in lugares:
                fila.append(1)
            else:
                fila.append(0)

        matriz.append(fila)

    # Forzar [0][0] a ser 1
    if matriz[0][0]==0:
        matriz[0][0]=1

        for idx in range(39,1,-1):

            if matriz[0][idx] == 1:
                matriz[0][idx] = 0
                break

    actual = Node((0,0),None,0)

    return actual

def imprime(actual):
    copia = copy.deepcopy(matriz)
    caminito = []
    recorrer = actual
    
    while(recorrer.pre):
        caminito = [recorrer.coords] + caminito
        recorrer = recorrer.pre

    for n,coords in enumerate(caminito):
        copia[coords[0]][coords[1]] = n + 2

    for fila in copia:
        print(fila)    

def buscar(actual):
    recorrer = actual
    mayor = 0
    regresar = actual

    while(recorrer.pre):

        if recorrer.coords[0] > mayor:
            regresar = recorrer
            mayor = recorrer.coords[0]

        recorrer = recorrer.pre
    
    while(actual != regresar):
        actual = actual.pre

    return actual

def buscarInv(actual):
    recorrer = actual
    menor = 1000
    regresar = actual

    while(recorrer.pre):

        if recorrer.coords[0] < menor:
            regresar = recorrer
            menor = recorrer.coords[0]

        recorrer = recorrer.pre
    
    while(actual != regresar):
        actual = actual.pre

    return actual

def mutar(actual, pasados, candidatos):
    actual = buscar(actual)

    while actual.coords[0]<39 and matriz[actual.coords[0]+1][actual.coords[1]] == 1:
        nuevo = Node((actual.coords[0]+1, actual.coords[1]), actual, actual.costo+1)
        actual = nuevo
    candis = []

    if actual.coords[0]<39:
        if matriz[actual.coords[0]+1][actual.coords[1]] == 0:
            candis.append(Node((actual.coords[0]+1, actual.coords[1]), actual, actual.costo+1))

    if actual.coords[1]<39:
        if matriz[actual.coords[0]][actual.coords[1]+1] == 0:
            candis.append(Node((actual.coords[0], actual.coords[1]+1), actual, actual.costo+1))

    if candis:
        nuevo = random.choice(candis)
        compensar = []

        for idx in range(40):
            if matriz[nuevo.coords[0]][idx] == 1:
                repe = False
                for pasado in pasados:
                    if pasado.coords == (nuevo.coords[0],idx):
                        repe = True
                        break
                if not repe:
                    compensar.append(idx)
        if compensar:
            cero = random.choice(compensar)
            matriz[nuevo.coords[0]][cero] = 0
        
        matriz[nuevo.coords[0]][nuevo.coords[1]] = 1
        
        actual = nuevo
        pasados = pasados.union({actual})
        candidatos = {actual}
    
    return actual, pasados, candidatos

def mutarInv(actual, pasados, candidatos):
    actual = buscarInv(actual)

    while actual.coords[0]>0 and matriz[actual.coords[0]-1][actual.coords[1]] == 1:
        nuevo = Node2((actual.coords[0]-1, actual.coords[1]), actual, actual.costo+1)
        actual = nuevo
    candis = []

    if actual.coords[0]>0:
        if matriz[actual.coords[0]-1][actual.coords[1]] == 0:
            candis.append(Node2((actual.coords[0]-1, actual.coords[1]), actual, actual.costo+1))

    if actual.coords[1]>0:
        if matriz[actual.coords[0]][actual.coords[1]-1] == 0:
            candis.append(Node2((actual.coords[0], actual.coords[1]-1), actual, actual.costo+1))

    if candis:
        nuevo = random.choice(candis)
        compensar = []

        for idx in range(40):
            if matriz[nuevo.coords[0]][idx] == 1:
                repe = False
                for pasado in pasados:
                    if pasado.coords == (nuevo.coords[0],idx):
                        repe = True
                        break
                if not repe:
                    compensar.append(idx)
        if compensar:
            cero = random.choice(compensar)
            if nuevo.coords[0] > 5 or cero > 0:
                matriz[nuevo.coords[0]][cero] = 0
        
        matriz[nuevo.coords[0]][nuevo.coords[1]] = 1
        
        actual = nuevo
        pasados = pasados.union({actual})
        candidatos = {actual}
    
    return actual, pasados, candidatos

def estrella(actual, candidatos, pasados):
    count = 0

    while candidatos and actual.coords[0] < 39 and count < 10000:     
        count += 1
        hijos = []

        # Analizando vecinos de actual
        # Agregamos a hijos los vecinos con 1

        if actual.coords[1]>0:
            if matriz[actual.coords[0]][actual.coords[1]-1] == 1:
                hijos.append(Node((actual.coords[0], actual.coords[1]-1), actual, actual.costo+1))
        if actual.coords[1]<39:
            if matriz[actual.coords[0]][actual.coords[1]+1] == 1:
                hijos.append(Node((actual.coords[0], actual.coords[1]+1), actual, actual.costo+1))
        if actual.coords[0]>0:
            if matriz[actual.coords[0]-1][actual.coords[1]] == 1:
                hijos.append(Node((actual.coords[0]-1, actual.coords[1]), actual, actual.costo+1))
        if actual.coords[0]<39:
            if matriz[actual.coords[0]+1][actual.coords[1]] == 1:
                hijos.append(Node((actual.coords[0]+1, actual.coords[1]), actual, actual.costo+1))

        # Actual ya no es candidado
        candidatos = candidatos - {actual}

        # Si hubo hijos, vemos que no sean repetidos
        for hijo in hijos:
            repe = False
            for pasado in pasados:
                if pasado.coords == hijo.coords:
                    repe = True
                    break
            if not repe:
                candidatos = candidatos.union({hijo})

        # Si hay candidatos, buscamos el mejor
        if candidatos:
            menor = 10000
            for candi in candidatos:
                if candi != actual.pre and candi.costo + candi.estima < menor:
                    menor = candi.costo + candi.estima
                    actual = candi

            pasados = pasados.union({actual})

    return actual, candidatos, pasados

def estrellaInv(actual, candidatos, pasados):
    count = 0

    while candidatos and (actual.coords[0] > 0 or actual.coords[1] > 0) and count < 100000:     
        count += 1
        hijos = []

        # Analizando vecinos de actual
        # Agregamos a hijos los vecinos con 1

        if actual.coords[1]>0:
            if matriz[actual.coords[0]][actual.coords[1]-1] == 1:
                hijos.append(Node2((actual.coords[0], actual.coords[1]-1), actual, actual.costo+1))
        if actual.coords[1]<39:
            if matriz[actual.coords[0]][actual.coords[1]+1] == 1:
                hijos.append(Node2((actual.coords[0], actual.coords[1]+1), actual, actual.costo+1))
        if actual.coords[0]>0:
            if matriz[actual.coords[0]-1][actual.coords[1]] == 1:
                hijos.append(Node2((actual.coords[0]-1, actual.coords[1]), actual, actual.costo+1))
        if actual.coords[0]<39:
            if matriz[actual.coords[0]+1][actual.coords[1]] == 1:
                hijos.append(Node2((actual.coords[0]+1, actual.coords[1]), actual, actual.costo+1))

        # Actual ya no es candidado
        candidatos = candidatos - {actual}

        # Si hubo hijos, vemos que no sean repetidos
        for hijo in hijos:
            repe = False
            for pasado in pasados:
                if pasado.coords == hijo.coords:
                    repe = True
                    break
            if not repe:
                candidatos = candidatos.union({hijo})

        # Si hay candidatos, buscamos el mejor
        if candidatos:
            menor = 10000
            for candi in candidatos:
                if candi != actual.pre and candi.costo + 39 - candi.estima < menor:
                    menor = candi.costo + candi.estima
                    actual = candi

            pasados = pasados.union({actual})

    return actual, candidatos, pasados

def creaCamino(actual, candidatos, pasados):
    count = 0
    
    while actual.coords[0] < 39 and count < 10000:
        count += 1
        actual, candidatos, pasados = estrella(actual, candidatos, pasados)

        # Si no hemos terminado, hacemos nuevo camino
        if actual.coords[0] < 39:
            actual, pasados, candidatos = mutar(actual, pasados, candidatos)

    return actual, candidatos, pasados

def creaSegundo(actual, candidatos, pasados):
    count = 0
    
    while (actual.coords[0] > 0 or actual.coords[1] > 0) and count < 100000:
        count += 1
        actual, candidatos, pasados = estrellaInv(actual, candidatos, pasados)

        # Si no hemos terminado, hacemos nuevo camino
        if actual.coords[0] > 0 or actual.coords[1] > 0:
            actual, pasados, candidatos = mutarInv(actual, pasados, candidatos)

    return actual, candidatos, pasados

class LabeGraph(wx.Frame):

    def __init__(self, parent, title, style=wx.SYSTEM_MENU | wx.CLOSE_BOX | wx.CAPTION):
        super(LabeGraph, self).__init__(parent, title=title)

        self.InitUI()
        self.Centre()


    def InitUI(self):

        vbox = wx.BoxSizer(wx.VERTICAL)
        gs = wx.GridSizer(40, 40, 1, 1)
        for idx in range(40):
            for jdx in range(40):
                text = wx.StaticText(self, -1, "11")
                if matriz[idx][jdx]:
                    text.SetBackgroundColour('white')
                    text.SetForegroundColour('white')
                else:
                    text.SetBackgroundColour('black')
                    text.SetForegroundColour('black')
                gs.Add(text)


        vbox.Add(gs, proportion=1, flag=wx.EXPAND)
        self.SetSizer(vbox)


def main():

    actual = inicializa()  
    
    print("\n***********************\n")
    print("   Laberinto inicial\n")
    imprime(actual)

    candidatos = {actual}
    pasados = {actual}

    actual, candidatos, pasados = creaCamino(actual, candidatos, pasados)
            
    print("\n***********************\n")
    print("   Laberinto de ida \n")
    imprime(actual)

    actual = Node((0,0),None,0)
    candidatos = {actual}
    pasados = {actual}
    
    actual, candidatos, pasados = estrella(actual, candidatos, pasados)
    print("\n***********************\n")
    print("   Camino optimo\n")
    imprime(actual)

    caminito = []
    recorrer = actual
    
    while(recorrer.pre):
        caminito = [recorrer] + caminito
        recorrer = recorrer.pre

    print (caminito)
    for ele in caminito:
       print (ele)

    # # # Va pa atras
    pasados = set()
    for nodo in caminito:
        if nodo.coords[0]>5 or nodo.coords[1]>5:
            pasados = pasados.union({Node2(nodo.coords,None,0)})

    candidatos = set()
    for idx in range(40):
        if idx != actual.coords[1] and  matriz[39][idx] == 1:
            candidatos = candidatos.union({Node2((39,idx),None,0)})

    pasados = pasados.union(candidatos)
    actual = random.choice(list(candidatos))
    
    actual, candidatos, pasados = creaSegundo(actual, candidatos, pasados)

    print("Reversa")
    print(actual.coords, actual.costo, actual.estima, actual.pre.coords)
    print("\n***********************\n")
    print("   Laberinto de vuelta\n")
    imprime(actual)
    
    actual = Node((0,0),None,0)
    candidatos = {actual}
    pasados = {actual}
    
    actual, candidatos, pasados = estrella(actual, candidatos, pasados)
    print("\n***********************\n")
    print("   Camino optimo\n")
    imprime(actual)

    caminito = []
    recorrer = actual
    
    while(recorrer.pre):
        caminito = [recorrer] + caminito
        recorrer = recorrer.pre

    print (caminito)
    for ele in caminito:
       print (ele)
    
    app = wx.App()
    ex = LabeGraph(None, title='Laberinto')
    ex.Show()
    app.MainLoop()
    


if __name__ == '__main__':
    main()
