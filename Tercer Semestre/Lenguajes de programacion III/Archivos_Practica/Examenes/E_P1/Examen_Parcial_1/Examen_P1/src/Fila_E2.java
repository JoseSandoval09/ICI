public class Fila_E2 {
     
        int max;
        int aux1,aux2=-1;  
        char Fila[];
     
      
        public Fila_E2(int size){
            Fila=new char[size];
            max=0;
            aux1=0;
        }


        public void Insertar(char C) {
         if(max==Fila.length ) { 
         System.out.println("\nCola llena !!!");
          return;
         }
         aux1=1;
         Fila[max]=C;
         max++;
         
        }
        public char Eliminar() {
            
            if(max==0){
              System.out.print("L A   F I L A   E S T A   V A C I A ");
              return(char)0;
            }
            aux1++;
            aux2++;
            if(aux1-1>max){
                aux1=0;
                max=0;
                return 0;
            }else{
                return Fila[aux2];
            }
        }

        public boolean filallena(){
            return max==Fila.length;
        }

        public boolean Vacia(){
            return max==0;
        }
      
        

        public int objetos(){
            return max;
        }
    

   // Funcion principal
   public static void main(String args[]){

    char ch;
    
    Fila_E2 e1=new Fila_E2(10);



    System.out.print("P R O G R A M A -- F I L A \n");

    System.out.print("\n-------I N S E R T A N D O   C A R A C T E R E S------\n");

    for (int i=0;i<10;i++){
        System.out.print("\t");
        e1.Insertar((char)('A'+i));
        System.out.print(" ");
        System.out.print((char) ('A'+i));
    }

   
  
    
    if(e1.filallena()){

        System.out.println("\n\nL A   F I L A   T I E N E  "+ e1.objetos() + "  E L E M E N T O S ");

        System.out.println("\n-------L A   F I L A  E S T A  L L E N A-------- \n\n");

        System.out.println("--------S A L I D A   D E   L A   F I L A ---------");
        
        while(!e1.Vacia()){
            System.out.print("\t");
            ch=e1.Eliminar();
            System.out.print(" " + ch);
            
        }



    }

    if(e1.Vacia()){
    System.out.println("\n\n -------L A   P I L A   E S T A   V A C I A------");
    }

   }
  
}

