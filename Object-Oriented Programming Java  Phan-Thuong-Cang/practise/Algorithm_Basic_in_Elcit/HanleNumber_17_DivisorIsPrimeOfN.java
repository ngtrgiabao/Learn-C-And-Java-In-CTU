package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HanleNumber_17_DivisorIsPrimeOfN {
	public static boolean checkPrime(int x) {
		if (x < 2)
			return false;
		else if (x == 2 || x == 3 || x == 5 || x == 7)
			return true;
		else if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
			return false;
		else if (x >= 10) {
			for (int i = 3; i * i < x; i += 2) {
				if (x % i == 0)
					return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, temp;
		String s;
		do {
			try {
				System.out.print("Nhap: n = ");
				s = sc.nextLine();
				n = Integer.parseInt(s);
				n = (n <= 0) ? (-n) : (n);
				if (n == 1000) {
					System.out.println("Chuong trinh ket thuc!");
				} else if (checkPrime(n)) {
					System.out.println("Cac uoc so la so nguyen to cua " + n + " la: " + n);
				} else {
					System.out.print("Cac uoc so la so nguyen to cua " + n + " la: ");
					temp = n / 2;
					for (int i = 1; i <= temp; i++) {
						if (n % i == 0 && checkPrime(i) == true) {
							System.out.print(i + " ");
						}
					}
					System.out.println();
				}
			} catch (Exception e) {
				n = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (n != 1000);
		sc.close();
	}
}
