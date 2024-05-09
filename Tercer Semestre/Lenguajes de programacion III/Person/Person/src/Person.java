class Person{//palabra reservada
    //atributos
    String name; 
    int age;

    Person(String n, int a){ //construtor
        name =n;
        age=a;
    }

    void printPerson(){ //metodo

        System.out.print(("Hi, my name is: " + name));
        System.out.println("I am " + age + " years old");

    }
    

    public static void main(String arguments[]){

        Person p; //objeto de tipo persona
        p= new Person("Luke ", 50);//asignamos instancia con new
        p.printPerson();
        System.out.println("-----");
        p=new Person("Laura ", 35);
        p.printPerson();
        System.out.println("-----");

    }
    

}