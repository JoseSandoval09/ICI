class Pila {
    char pila[];
    int tope;

    public Pila(int size){
        pila = new char[size];
        tope = 0;
    }    

    public void Push(char ch){
        if(tope == pila.length){
            System.out.println("PILA LLENA");
            return;
        }
        pila[tope] = ch;

        tope++;
    }

    public char Pop(){
        if(tope == 0){
            System.out.println("PILA VACIA");
            return (char) 0;
        }
        tope--;
        return pila[tope];
    }

    public boolean Llena(){
        return tope == pila.length;
    }

    public boolean Vacia(){
        return tope == 0;
    }

    public int Capacidad(){
        return pila.length;
    }

    public int numObjetos(){
        return tope;
    }

    public static void main(String[] args){
        Pila pila1 = new Pila(10);
        Pila pila2 = new Pila(10);
        Pila pila3 = new Pila(10);
        char ch;

        System.out.print("P R O G R A M A - - - - - - P I L A S");

        System.out.println("--Inserta caracteres de la A a la J en al pila 1--");

        for(int i = 0; i < 10; i++){
            pila1.Push((char) ('A' + i));
        }

        if (pila1.Llena()){
            System.out.println("Pila 1 llena");
        }

        System.out.println("--Contenido de la pila 1--");
        System.out.println("");

        while(!pila1.Vacia()){
            ch = pila1.Pop();
            System.out.print(ch);
            pila2.Push(ch);
        }
        System.out.println("");
        System.out.println("");
        System.out.println("--Inserta caracteres de la A a la J en al pila 2--");

        if(pila2.Llena()){
            System.out.println("Pila 2 llena");
        }
        System.out.println("--Contenido de la pila 2--");
        System.out.println("");
        while(!pila2.Vacia()){
            ch = pila2.Pop();
            System.out.print(ch);
        }
        System.out.println("");
        System.out.println("");
        System.out.println("--Se inserto caracteres de la H a la Q en la pila 3--");
        for (int i = 0; i < 10; i++){
            pila3.Push((char) ('H' + i));
        }
        if(!pila3.Vacia()){
            System.out.println("La capacidad de la pila 3 es: " + pila3.Capacidad());
        }  
        System.out.println("");
        if(!pila3.Vacia()){
            System.out.println("La pila 3 tiene: " + pila3.numObjetos() + " objetos");
        }

        System.out.print("Contenido de la pila 3: \n");
        while(!pila3.Vacia()){
            ch=pila3.Pop();
            System.out.print(ch);

        }


        System.out.println("");
    }

}
