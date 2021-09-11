package buoi_1;

import java.util.Scanner;

public class Bai_4_Tong2So {
	private static int sum(int a, int b) {
		return a + b;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a;
		int b;
		String s;
		do {
			try {
				System.out.print("Nhap a: ");
				s = sc.nextLine();
				a = Integer.parseInt(s);
				System.out.print("Nhap b: ");
				s = sc.nextLine();
				b = Integer.parseInt(s);
				System.out.println("Tong hai so la: " + sum(a, b));
			} catch (Exception e) {
				a = Integer.MAX_VALUE;
				b = Integer.MAX_VALUE;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (a != 1000 && b != 1000);
		System.out.println("Chuong trinh ket thuc!");
		sc.close();
	}

}
