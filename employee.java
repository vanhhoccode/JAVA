import java.util.Scanner;

public class employee extends person{
    private Float salary;
    public void nhap() {
        super.input();
        Scanner sc = new Scanner(System.in);
        salary = Float.parseFloat(sc.nextLine()); 
    }
    public void xuat() {
        super.getdetail();
        System.out.println("luong " + salary);
    }
}
