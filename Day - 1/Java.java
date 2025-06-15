class A{
    String message = "Hello World";
    public void display(){
        System.out.println(message);
    }
}
class B{
    int a = 10;
    int b = 20;
    public void display(){
        System.out.println(a+b);
    }
}
class C{
    B obj = new B();
    public void display(){
        System.out.println(obj.a+obj.b);
    }
}
public class Java{
    public static void main(String[] args){
        A obj1 = new A();
        B obj2 = new B();
        C obj3 = new C();
        obj3.display();
        obj1.display();
        obj2.display();
    }
}