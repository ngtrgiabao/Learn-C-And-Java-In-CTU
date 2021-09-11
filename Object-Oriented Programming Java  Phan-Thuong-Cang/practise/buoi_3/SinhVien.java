package buoi_3;

import java.util.Scanner;

public class SinhVien {
	public static final int MAX = 10;
	private String mssv, hoTen;
	private Date ngaySinh;
	private int soLuong;
	private String[] tenHP, diem;

	public SinhVien() {
		mssv = new String();
		hoTen = new String();
		ngaySinh = new Date();
		soLuong = 0;
		tenHP = new String[MAX];
		diem = new String[MAX];
		for (int i = 0; i < MAX; i++) {
			tenHP[i] = new String();
			diem[i] = new String();
		}
	}

	public SinhVien(SinhVien s) {
		mssv = new String(s.mssv);
		hoTen = new String(s.hoTen);
		ngaySinh = new Date(s.ngaySinh);
		soLuong = s.soLuong;
		tenHP = new String[MAX];
		diem = new String[MAX];
		for (int i = 0; i < MAX; i++) {
			tenHP[i] = new String(s.tenHP[i]);
			diem[i] = new String(s.diem[i]);
		}
	}

	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap mssv:");
		mssv = sc.nextLine();
		System.out.print("Nhap hoten:");
		hoTen = sc.nextLine();
		System.out.println("Nhap ngay sinh:");
		ngaySinh.nhap();
	}

	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		do {
			System.out.print("\nNhap so luong mon hoc:");
			soLuong = sc.nextInt();
		} while (soLuong <= 0 || soLuong > MAX);
		System.out.print("Nhap cac Mon hoc :");
		sc.nextLine(); // xoa bo nho dem con sot (Enter sau khi nhap so)
		for (int i = 0; i < soLuong; i++) {
			System.out.printf("Nhap ten Mon hoc thu %d:", i + 1);
			tenHP[i] = sc.nextLine();
			System.out.printf("Nhap diem Mon hoc thu %d:", i + 1);
			diem[i] = sc.nextLine();
		}

	}

	public String toString() {
		String s = mssv + ", " + hoTen + ", " + ngaySinh.toString() + " [";
		for (int i = 0; i < soLuong -1; i++) { // xoa ; du cuoi for
			s += tenHP[i] + ": " + diem[i] + "; ";
		}
		s += tenHP[soLuong -1] + ": " + diem[soLuong -1] + "]";
		return s;
	}

	public void dKy(String ten, String d) {
		if (soLuong < MAX) {
			tenHP[soLuong] = new String(ten);
			diem[soLuong] = new String(d);
			soLuong++;
		} else
			System.out.println("Khong the them mon moi");
	}

	public void xoa(String ten) {
		for (int i = 0; i < soLuong; i++) {
			if (tenHP[i].compareTo(ten) == 0) { // compareTo ( -1; 0; 1)
				for (int j = i; j < soLuong - 1; j++) {
					tenHP[j] = tenHP[j + 1];
				}
				soLuong--;
				break;
			}
		}
	}

	public float diemTB() {
		float d = 0f;
		for (int i = 0; i < soLuong; i++) {
			// dung if else
			if (diem[i].equals("A"))  // equals (0; 1)
				d += 4;
			else if (diem[i].equals("B"))
				d += 3;
			else if (diem[i].equals("C"))
				d += 2;
			else if (diem[i].equals("D"))
				d += 1;
		/** Hoac dung switch case
		 * switch (diem[i]){
			 * 	case ('A'):{
			 * 		d += 4;
			 * 		break;
			 * 	}
			 * 	case ('B'):{
			 * 		d += 3;
			 * 		break;
			 * 	}
			 * 	case ('C'):{
			 * 		d += 2;
			 * 		break;
			 * 	}
			 * 	case ('D'):{
			 * 		d += 1;
			 * 		break;
			 * 	}
		 * }
		 */
		}

		return d / soLuong;
	}

}
