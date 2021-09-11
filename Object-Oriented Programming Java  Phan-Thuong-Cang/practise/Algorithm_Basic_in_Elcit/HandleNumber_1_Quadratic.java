package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_1_Quadratic {
	private static int denta;

	public static void giaiPhuongTrinhBac1(int a, int b) {
		if (a == 0) {
			if (b == 0) {
				System.out.println("Phuong trinh vo so nghiem!");
			} else {
				System.out.println("Phuong trinh vo nghiem!");
			}
		} else {
			System.out.println("Phuong trinh co nghiem la: " + (double) -b / a);
		}
	}

	public static void giaiPhuongTrinhBac2(int a, int b, int c) {
		if (a == 0) {
			giaiPhuongTrinhBac1(a, b);
		} else {
			denta = b * b - 4 * a * c;
			if (denta > 0) {
				System.out.println("Phuong trinh co 2 nghiem:");
				System.out.println("x1 = " + (double) (-b + Math.sqrt(denta)) / 2 / a);
				System.out.println("x2 = " + (double) (-b - Math.sqrt(denta)) / 2 / a);
			} else if (denta < 0) {
				System.out.println("Phuong trinh vo nghiem!");
			} else {
				System.out.println("Phuong trinh co nghiem kep: x = " + (double) -b / 2 / a);
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b, c;
		String s;
		do {
			try {
				System.out.print("Nhap: a = ");
				s = sc.nextLine();
				a = Integer.parseInt(s);
				System.out.print("Nhap: b = ");
				s = sc.nextLine();
				b = Integer.parseInt(s);
				System.out.print("Nhap: c = ");
				s = sc.nextLine();
				c = Integer.parseInt(s);
				if (a == 1000 && b == 1000 && c == 1000) {
					System.out.println("Ket thuc chuong trinh!");
				} else {
					giaiPhuongTrinhBac2(a, b, c);
				}
			} catch (Exception e) {
				a = 10000; b = 10000; c = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (a != 1000 && b != 1000 && c != 1000);
		sc.close();
	}
}
