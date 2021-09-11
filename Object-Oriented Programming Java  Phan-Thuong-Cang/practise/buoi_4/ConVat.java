package buoi_4;

import java.util.Scanner;

public class ConVat {
	private String giong;
	private String mauLong;
	private int canNang;
	
	public ConVat() {
		
	}
	
	public ConVat(String giong, String mauLong, int canNang) {
		this.giong = new String(giong);
		this.mauLong = new String(mauLong);
		this.canNang = canNang;
	}

	public void Keu() {
		System.out.println("Con vat dang keu");
	}

	public void nhap() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap giong: ");
		this.giong = sc.nextLine();
		System.out.print("Nhap Mau Long: ");
		this.mauLong = sc.nextLine();
		System.out.print("Nhap Can Nang: ");
		this.canNang = sc.nextInt();
	}

	public String toString() {
		return "Giong: " + this.giong + " ...Mau Long: " + this.mauLong + " ...canNang: " + this.canNang;
	}
}
