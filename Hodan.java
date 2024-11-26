/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Quan_ly_ho_dan;

import java.util.Scanner;

/**
 *
 * @author admin
 */
public class Nguoi {
    String Hoten;
    int tuoi;
    int namsinh;
    String nghenghiep;
    public void nhap(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap Ho ten:"); Hoten =  sc.nextLine();
        System.out.println("Nhap tuoi:"); tuoi = Integer.parseInt(sc.nextLine());
        System.out.println("Nhap nam sinh:"); namsinh = Integer.parseInt(sc.nextLine());
        System.out.println("Nhap nghe nghiep:"); nghenghiep = sc.nextLine();
    }
    public void xuat(){
        System.out.println("Ho ten:" + Hoten + " " + "Tuoi:" + tuoi);
        System.out.println("Nam sinh:" + namsinh + " " + " Nghe nghiep " + nghenghiep );
    }
    
}
