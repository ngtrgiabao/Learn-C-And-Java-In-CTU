package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_4_Fibonacci {
	public static int count;
	public static long u1, u2, fibo;

	public static long fibonacci(int n) {
		if (n == 1 || n == 2) {
			return 1;
		} else if (n > 2) {
			u1 = 1;
			u2 = 1;
			count = 2;
			while (count <= n) {
				fibo = u1 + u2;
				u1 = u2;
				u2 = fibo;
				count++;
			}
			return fibo;
		}
		return -1; // danh dau sai
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
				if (n <= 0) {
					System.out.println("n > 0. Nhap lai!");
				} else if (n == 1000) {
					System.out.println("Ket thuc chuong trinh!");
				} else {
					System.out.println("So fibonacci thu " + n + " la: " + fibonacci(n));
				}
			} catch (Exception e) {
				n = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (n <= 0 || n != 1000);
		sc.close();
	}
}
