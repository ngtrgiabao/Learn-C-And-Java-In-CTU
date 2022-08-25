package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_2_FactorialN {
	public static long sum;

	public static long factorial(int n) {
		sum = 1;
		for (int i = 1; i <= n; i++) {
			sum *= i;
		}
		return sum;
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
					System.out.println("Nhap lai n! (n>=1)");
				} else if (n == 1000) {
					System.out.println("Ket thuc chuong trinh!");
				} else {
					System.out.println(n + "! = " + factorial(n));
				}
			} catch (Exception e) {
				n = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (n <= 0 || n != 1000);
		sc.close();
	}
}
