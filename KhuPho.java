/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Quan_ly_ho_dan;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class KhuPho {
     public static void main(String[] args) {
         ArrayList<Hodan> arr_2 = new ArrayList<>();
        int soHodan;
         System.out.println("Nhap vao so ho dan");
        Scanner sc = new Scanner(System.in);
        soHodan = sc.nextInt();
            for(int i = 0;i < soHodan;i++){
                Hodan tmp = new Hodan();
                tmp.nhap();
                arr_2.add(tmp);
            }
            System.out.println("Nhung ho dan ban vua nhap la:");
            for(Hodan tmp2 : arr_2){
                tmp2.xuat();
            }
    }
     
}
