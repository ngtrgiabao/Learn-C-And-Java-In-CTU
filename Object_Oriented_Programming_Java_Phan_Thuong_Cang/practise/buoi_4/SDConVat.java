package buoi_4;

import java.util.Scanner;

public class SDConVat {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap so luong con vat: ");
		int n = sc.nextInt();
		sc.nextLine();
		ConVat arr[] = new ConVat[n];
		for (int i = 0; i < n; i++) {
			System.out.print("Con Vat " + i + ":" 
					+ "\nNhap con vat muon tao:" 
					+ "\n1. Con Bo." 
					+ "\n2. Con De."
					+ "\n3. Con Heo." 
					+ "\n4. Con Ga.");
			int temp = 0;
			String s;
			while (true) {
				try {
					System.out.println("Ban chon: ");
					s = sc.nextLine();
					temp = Integer.parseInt(s);
					if (temp<1 || temp>4) {
						System.out.println("Nhap cac so tu 1...4!");
					} else {
						break;
					}
				} catch (Exception e) {
					System.out.println("Ban nhap sai dinh dang!");
				}
			} 
			
			switch (temp) {
				case (1): {
					arr[i] = new Bo();
					arr[i].nhap();
					break;
				}
				case (2): {
					arr[i] = new De();
					arr[i].nhap();
					break;
				}
				case (3): {
					arr[i] = new Heo();
					arr[i].nhap();
					break;
				}
				case (4): {
					arr[i] = new Ga();
					arr[i].nhap();
					break;
				}
			}

		}
		for (int i = 0; i < n; i++) {
			arr[i].Keu();
			System.out.println("Thong tin: " + arr[i]);
		}

	}

}
