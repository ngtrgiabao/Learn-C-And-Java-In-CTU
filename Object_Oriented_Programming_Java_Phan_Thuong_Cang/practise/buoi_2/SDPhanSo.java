package buoi_2;

import java.util.Scanner;

public class SDPhanSo {
	public static void main(String[] args) {
		PhanSo a = new PhanSo(3, 7);
		PhanSo b = new PhanSo(4, 9);
		System.out.print("Phan so a: ");
		a.hienThi();
		System.out.print("Phan so b: ");
		b.hienThi();
		PhanSo x = new PhanSo();
		PhanSo y = new PhanSo();
		System.out.println("Nhap phan so x: ");
		x.nhapPhanSo();
		System.out.println("Nhap phan so y: ");
		y.nhapPhanSo();
		System.out.println("Gia tri nghich dao cua phan so x la: " + x.giaTriNghichDao());
		System.out.println("Tong cua x + y la: " + x.cong(y).giaTriThuc());

		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so phan so: n = ");
		int n = sc.nextInt();
		PhanSo arr[] = new PhanSo[n];
		PhanSo tong = new PhanSo(0, 1);
		for (int i = 0; i < n; i++) {
			arr[i] = new PhanSo();
			System.out.println("Nhap phan tu arr[" + (i + 1) + "]");
			arr[i].nhapPhanSo();
			tong = tong.cong(arr[i]);

		}
		System.out.println("Day phan so da nhap :");
		for (int i = 0; i < n; i++) {
			System.out.print("arr[" + i + "]: ");
			arr[i].hienThi();
		}
		System.out.println("Phan so tong la: ");
		tong.toiGian();
		tong.hienThi();
		sc.close();
	}

}
