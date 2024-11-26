import java.util.Scanner;

public class person {
    private String name;
    String namsinh;
    public String getName() {
        return name;
    }
    public void setBirthday(String b) {
        namsinh = b;
    }
    public String getdetail() {
        return name + " " + namsinh;
    }
    public void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap ho ten :");
        name = sc.nextLine();
        System.out.println("Nhap ngay sinh:");
        namsinh = sc.nextLine();
    }
    public void output() {
        System.out.println("HO TEN " + name + "nam sinh" + namsinh);
    }

}