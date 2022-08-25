package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_7_NFirstPrime {

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
		int n, count, check;
		String s;
		do {
			try {
				System.out.print("Nhap: n = ");
				s = sc.nextLine();
				n = Integer.parseInt(s);
				if (n <= 0) {
					System.out.println("Khong co so nguyen to nao nho hon 1!");
				} else if (n == 1000) {
					System.out.println("Ket thuc chuong trinh!");
				} else {
					count = 1;
					check = 2;
					System.out.print(n + " so nguyen to dau tien: ");
					while (count <= n) {
						if (checkPrime(check)) {
							System.out.print(check + " ");
							count++;
						}
						check++;
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
