import org.w3c.dom.Node;

public class Lista {
    Node FirstNodo;
    Node lastNodo;
    String nombre;

    public Lista(){
        this(nombre:"lista");
    }
    public Lista(String nombre){
        this.nombre="lista";
        FirstNodo = lastNodo = null;
    }

}
