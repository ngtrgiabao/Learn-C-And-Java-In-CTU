package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_5_GCD_LCM {

	public static int gcd(int a, int b) {
		a = (a < 0) ? (-a) : (a);
		b = (b < 0) ? (-b) : (b);
		return (b == 0) ? (a) : gcd(b, a % b);
	}

	public static long lcm(int a, int b) {
		a = (a < 0) ? (-a) : (a);
		b = (b < 0) ? (-b) : (b);
		return a*b / gcd(a, b);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b;
		String s;
		do {
			try {
				System.out.print("Nhap: a = ");
				s = sc.nextLine();
				a = Integer.parseInt(s);
				System.out.print("Nhap: b = ");
				s = sc.nextLine();
				b = Integer.parseInt(s);
				if (a == 1000 && b == 1000) {
					System.out.println("Ket thuc chuong trinh!");
				} else {
					System.out.println("gcd: " + gcd(a, b));
					System.out.println("lcm: " + lcm(a, b));
				}
			} catch (Exception e) {
				a = 10000;
				b = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (a != 1000 || b != 1000);
		sc.close();
	}
}
