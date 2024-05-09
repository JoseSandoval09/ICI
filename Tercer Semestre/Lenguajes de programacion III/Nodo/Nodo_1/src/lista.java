

class lista{
    Node N1, Nf;
    String nombre;
    public lista(){
        this("Lista");
    }
    public lista(String nombre){
        this.nombre = nombre;
        N1 = Nf = null;
    }


    public void insertarAlFinal(int dato){
        if (estaVacia()) {
            N1 = Nf = new Node(dato);
        }else{
            Nf = Nf.Apuntador = new Node(dato);
        }
    }

    public boolean estaVacia(){
        return N1 == null;
    }

    public void imprimir(){
        if (estaVacia()) {
            System.out.println("La lista esta vacia");
        }else{
            System.out.println("La lista es: ");
            Node actual = N1;
            while (actual != null) {
                System.out.print(actual.dato);
                actual = actual.Apuntador;
                System.out.print(", ");
            }
        }
    }
    public static void main (String[] args){
    
        lista list = new lista();
        list.insertarAlFinal(10);
        list.insertarAlFinal(20);
        list.insertarAlFinal(30);
        list.insertarAlFinal(40);
        list.insertarAlFinal(50);
        
        list.imprimir();
    }
}

