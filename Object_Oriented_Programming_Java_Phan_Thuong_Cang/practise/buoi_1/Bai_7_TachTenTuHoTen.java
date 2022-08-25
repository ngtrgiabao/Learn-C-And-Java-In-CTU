package buoi_1;

import java.util.Scanner;

public class Bai_7_TachTenTuHoTen {

	private static String firstNameToString(String s) {
		s = s.trim();
		String firstName;
		firstName = s.substring(s.lastIndexOf(" ") + 1);
		return firstName;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int keyBreak = -1;
		do {
			String name;
			System.out.print("Nhap ho ten: ");
			name = sc.nextLine();
			System.out.println("Ten nhap vao: " + firstNameToString(name));
			System.out.print("Nhap 1000 de thoat, nhap bat ki de tiep tuc: ");
			name = sc.nextLine();
			keyBreak = Integer.parseInt(name);
			System.out.println();

		} while (keyBreak != 1000);
		System.out.println("Chuong trinh ket thuc!");
		sc.close();
	}

}
