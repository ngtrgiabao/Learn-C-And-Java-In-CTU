package buoi_1;

import java.util.Scanner;

public class Bai_6_KiemTraSoNguyenToVaXuatDangNhiPhan {
	private static boolean checkPrime(int n) {
		if (n < 2)
			return false;
		else if (n == 2 || n == 3 || n == 5 || n == 7)
			return true;
		else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
			return false;
		else if (n >= 10) {
			for (int i = 3; i * i <= n; i += 2) {
				if (n % i == 0)
					return false;
			}
		}
		return true;
	}

	private static long coverToBinary(int n) {
		long binaryNumber = 0;
		int pow10 = 0;
		while (n != 0) {
			binaryNumber += (n % 2) * ((int) Math.pow(10, pow10));
			pow10++;
			n /= 2;
		}
		return binaryNumber;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		String s;
		do {
			try {
				System.out.print("Nhap: n = ");
				s = sc.nextLine();
				n = Integer.parseInt(s);
				if (n == 1000) {
					System.out.println("Ket thuc chuong trinh!");
				} else {
					if (checkPrime(n)) {
						System.out.println(n + " la so nguyen to!");
						// dung ham tu viet
						System.out.println("Doi sang so nguyen to: " + coverToBinary(n));
						// dung ham viet san
						System.out.println("Doi sang so nguyen to: " + Integer.toBinaryString(n));
					} else {
						System.out.println(n + " khong la so nguyen to!");
					}
				}
			} catch (Exception e) {
				n = Integer.MAX_VALUE;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (n != 1000);
		sc.close();
	}
}
