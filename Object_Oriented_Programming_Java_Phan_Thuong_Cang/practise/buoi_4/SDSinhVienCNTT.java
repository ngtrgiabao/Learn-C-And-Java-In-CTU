package buoi_4;

import java.util.Scanner;

public class SDSinhVienCNTT {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);		
		int n;
		System.out.print("\nNhap so sinh vien CNTT: ");
		n = sc.nextInt();
		sc.nextLine();
		SinhVienCNTT ds[] = new SinhVienCNTT[n];
		for(int i=0; i< n;i++) {
			ds[i] = new SinhVienCNTT();
		}
		
		for(int i=0; i< n;i++){
			System.out.printf("\nNhap sinh vien CNTT thu %d : \n", i+1);
			ds[i].nhap();
			ds[i].nhapDiem();
		}
		
		System.out.println("**Danh sach sinh vien CNTT vua nhap:**");
		for(int i=0; i< n;i++)
			System.out.printf("Sinh vien thu %d : \n %s , diem TB: %.2f \n", i+1, ds[i].toString(), ds[i].diemTB());	

	}

}
