package buoi_4;

import java.util.Scanner;

public class SinhVienCNTT extends SinhVien { // ke thua la de mo rong class
	private String tKhoan, mKhau, email;

	public SinhVienCNTT() {
		super(); // goi constructor khong tham so cua class SinhVien
		tKhoan = new String();
		mKhau = new String();
		email = new String();
	}

	public SinhVienCNTT(SinhVienCNTT svcntt) {
		super((SinhVien) svcntt); // ep kieu tuong minh. trong java tu dong ep: upcasting 
		tKhoan = new String(svcntt.tKhoan);
		mKhau = new String(svcntt.mKhau);
		email = new String(svcntt.email);
	}

	public void nhap() {
		super.nhap();
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap tKhoan:");
		tKhoan = sc.nextLine();
		System.out.print("Nhap mat khau:");
		mKhau = sc.nextLine();
		System.out.print("Nhap email:");
		email = sc.nextLine();
	}

	public String toString() {
		String s = super.toString();
		s += ", " + tKhoan + "," + mKhau + "," + email;
		return s;
	}
	
	public String layEmail() {
		return email;
	}

}
