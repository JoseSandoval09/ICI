class Node{
    int dato;
    Node Apuntador;
    public Node(int dato){
        this.dato = dato;
        this.Apuntador = null;
    }
    public Node(int dato, Node apuntador){
        this.dato = dato;
        this.Apuntador = apuntador;
    }
}
