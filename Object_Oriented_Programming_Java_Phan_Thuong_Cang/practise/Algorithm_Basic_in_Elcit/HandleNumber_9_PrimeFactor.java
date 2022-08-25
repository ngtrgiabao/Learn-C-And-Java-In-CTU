package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_9_PrimeFactor {
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
				if (n <= 0) {
					System.out.println("n >= 1. Nhap lai!");
				} else if (n == 1000) {
					System.out.println("Ket thuc chuong trinh!");
				} else if (n == 2) {
					System.out.print(n + " co cac thua so nguyen to: 2");
				} else {
					temp = n;
					System.out.print(n + " co cac thua so nguyen to: ");
					for (int i = 2; i <= n/2; i++) {
						if (checkPrime(i)) {
							while (temp%i ==0) {
								System.out.print(i + "*");
								temp /= i;
							}
						} else {
							continue;
						}
					}
					System.out.println();
				}
			} catch (Exception e) {
				n = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (n <= 1 || n != 1000);
		sc.close();
	}
}
