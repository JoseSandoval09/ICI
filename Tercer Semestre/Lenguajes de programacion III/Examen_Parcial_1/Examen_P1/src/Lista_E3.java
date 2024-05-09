public class Lista_E3 {

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
    
        Node N1, Nf;
        String nombre;
        public Lista_E3(){
            this("Lista");
        }
        public Lista_E3(String nombre){
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
                    System.out.print("\t ");
                }
            }
        }
        public static void main (String[] args){

            System.out.println("P R O G R A M A   L I S T A\n")   ;
            
            System.out.println("\ne l e m e n t o s    e n    l a     l i s t a \n\n");

            Lista_E3 list = new Lista_E3();
            list.insertarAlFinal(9);
            list.insertarAlFinal(13);
            list.insertarAlFinal(18);
            list.insertarAlFinal(25);
            list.insertarAlFinal(50);
            
            list.imprimir();
        }
    }

