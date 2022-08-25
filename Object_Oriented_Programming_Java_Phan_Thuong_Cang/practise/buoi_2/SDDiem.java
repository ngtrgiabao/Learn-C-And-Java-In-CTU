package buoi_2;

import java.util.Scanner;

public class SDDiem {
	public static void main(String[] args) {
		Diem a = new Diem(3, 4);
		System.out.print("Toa do diem a: ");
		a.hienThi();
		Scanner sc = new Scanner(System.in);
		Diem b = new Diem();
		b.nhapDiem();
		System.out.print("Toa do diem b: ");
		b.hienThi();
		Diem c = new Diem(-b.giaTriX(), -b.giaTriY());
		System.out.print("Toa do diem b: ");
		c.hienThi();
		System.out.print("Khoang cach tu diem b den goc toa do O: ");
		System.out.println(b.khoangCach());
		System.out.print("Khoang cach tu diem b den diem a: ");
		System.out.println(b.khoangCach(a));
		sc.close();
	}

}
