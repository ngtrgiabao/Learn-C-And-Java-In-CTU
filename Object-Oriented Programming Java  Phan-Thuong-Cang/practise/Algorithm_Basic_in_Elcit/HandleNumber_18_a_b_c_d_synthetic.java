package Algorithm_Basic_in_Elcit;

import java.util.Scanner;

public class HandleNumber_18_a_b_c_d_synthetic {
	public static int count;
	public static int temp;

	public static boolean checkPrimeEspecially(int x) {
		for (int i = 3; i * i < x; i += 2) {
			if (x % i == 0)
				return false;
		}
		return true;
	}

	public static boolean checkReversible(int n) {
		count = 0;
		temp = n;
		while (temp != 0) {
			temp /= 10;
			count++;
		}
		for (int i = 0; i <= count / 2 - 1; i++) {
			temp = (int) Math.pow(10, count - 2 * i - 1);
			if ((n % 10) != ((int) n / temp)) {
				return false;
			} else {
				n = (n % temp) / 10;
			}
		}
		return true;
	}

	public static void printMenu() {
		System.out.println("Moi ban chon:");
		System.out.println("1. Cac so Nguyen To");
		System.out.println("2. Cac so Thuan Nghich");
		System.out.println("3. Moi chu so deu la so Nguyen To");
		System.out.println("4. Tong cac chu so la so Nguyen To");
		System.out.println("999. Thoat chuong trinh");
		System.out.print("Ban chon: ");
	}

	public static void clearScreen() {
		System.out.print("\033[H\033[2J");
		System.out.flush();
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int keyBreak = -1;
		int divColumn;
		do {
			printMenu();
			keyBreak = sc.nextInt();
			switch (keyBreak) {
			case (1): {
				divColumn = 0;
				System.out.println("Cac so Nguyen To tu 5 den 7 chu so la: ");
				for (int i = 10001; i <= 9999997; i += 2) {
					if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
						continue;
					} else if (checkPrimeEspecially(i)) {
						System.out.print(i + " ");
						divColumn++;
					}
					if (divColumn % 15 == 0) {
						divColumn = 1;
						System.out.println();
					}

				}
				break;
			}
			case (2): {
				divColumn = 0;
				System.out.println("Cac so Thuan nghich co 5 chu so:");
				for (int i = 10001; i <= 99999; i++) {
					if (checkReversible(i)) {
						System.out.print(i + " ");
						divColumn++;
					}
					if (divColumn % 15 == 0) {
						divColumn = 1;
						System.out.println();
					}
				}

				break;
			}
			case (3): {

				break;
			}
			case (4): {

				break;
			}

			}

		} while (keyBreak != 9999);
		sc.close();
	}

}
