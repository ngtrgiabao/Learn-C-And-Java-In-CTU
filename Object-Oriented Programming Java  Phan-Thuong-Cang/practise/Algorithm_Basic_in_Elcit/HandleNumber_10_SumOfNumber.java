package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_10_SumOfNumber {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, sum, temp;
		String s;
		do {
			try {
				sum = 0;
				System.out.print("Nhap: n = ");
				s = sc.nextLine();
				n = Integer.parseInt(s);
				if (n == 1000) {
					System.out.println("Chuong trinh ket thuc!");
				} else {
					n = (n <= 0) ? (-n) : (n);
					temp = n;
					System.out.print("Tong cac chu so cua " + n + " la: ");
					while (temp != 0) {
						sum += temp % 10;
						temp /= 10;
					}
					System.out.println(sum);
				}
			} catch (Exception e) {
				n = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (n != 1000);
		sc.close();
	}
}
