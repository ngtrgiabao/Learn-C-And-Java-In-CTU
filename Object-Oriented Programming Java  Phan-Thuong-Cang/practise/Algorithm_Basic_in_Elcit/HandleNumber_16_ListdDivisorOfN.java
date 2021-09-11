package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_16_ListdDivisorOfN {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, temp;
		String s;
		do {
			try {
				System.out.print("Nhap: n = ");
				s = sc.nextLine();
				n = Integer.parseInt(s);
				if (n == 1000) {
					System.out.println("Chuong trinh ket thuc!");
				} else {
					System.out.print("Cac uoc so cua " + n + " la: ");
					n = (n <= 0) ? (-n) : (n);
					temp = n/2;
					for (int i = 1; i<=temp; i++) {
						if (n%i==0) {
							System.out.print(i + " ");
						}
					}
					System.out.println(n);
				}
			} catch (Exception e) {
				n = 10000;
				System.out.println("Dinh dang nhap sai. Nhap lai!");
			}
		} while (n != 1000);
		sc.close();
	}

}
