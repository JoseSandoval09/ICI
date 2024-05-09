class Pila_E1{

    char pila[];
    int tope;

    public Pila_E1(int size){
        pila=new char[size];
        tope=0;
    }   

    public void push(char ch){
        if(tope==pila.length){
            System.out.println("-----L A   P I L A  E S T A  L L E N A ----- ");
            return;
        }

        pila[tope]=ch;

        tope++;

    }

    public char pop(){
        if(tope==0){
            System.out.println("L A   P I L A   E S T A  V A C I A ");
            return (char) 0;
        }

        tope--;
        return pila[tope];


    }

    public boolean Llena(){
        return tope==pila.length;
    }

    public boolean Vacia(){
        return tope==0;
    }

    public int capacidad(){
        return pila.length;
    }

    public int numObjetos(){
        return tope;

    }

    public static void main(String[] args){

        Pila_E1 Pila= new Pila_E1(10);

        char ch;

        System.out.print("P R O G R A M A - - - - - - P I L A \n");

        System.out.print("\n\nI N S E R T A N D O   C A R A C T E R E S------------\n");

        for (int i=0;i<10;i++){
            System.out.print("\t");
            Pila.push((char)('A' + i));
            System.out.print(" ");
            System.out.print((char)('A'+i));
        }

        System.out.println("\n\nL A   C A P A C I D A D   D E   L A   P I L A   E S:  " + Pila.capacidad());

        if(Pila.Llena()){
            System.out.println("\n\nL A   P I L A   E S T A   L L E N A    C O N   " + Pila.numObjetos() + "    O B J E T O S------------\n");

            System.out.print("\nS A L I D A    DE   L A   P I L A --------------\n");
            
            while(!Pila.Vacia()){
                System.out.print("\t");
                ch=Pila.pop();
                System.out.print(" "+ ch);

            }
        }

        System.out.println("\n\nV A C I A N D O      P I L A ------------------");

       
        if(Pila.Vacia()){
            System.out.println("\nL A   P I L A   E S T A   V A C I A------------");
        }




    }


}