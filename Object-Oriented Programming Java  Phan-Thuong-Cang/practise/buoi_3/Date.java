package buoi_3;

import java.util.Scanner;

public class Date {
	private int day;
	private int month;
	private int year;

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	public int getMonth() {
		return month;
	}

	public void setMonth(int month) {
		this.month = month;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public Date() {
		day = month = year = 0;
	}

	public Date(int day, int month, int year) {
		super();
		this.day = day;
		this.month = month;
		this.year = year;
	}

	public Date(Date a) {
		this.day = a.day;
		this.month = a.month;
		this.year = a.year;
	}

	private static int nhapSo() {
		int n = 0;
		String s;
		boolean error = false;
		Scanner sc = new Scanner(System.in);

		do {
			s = sc.next(); // kiem tra tung ham se toi uu hon
			try {
				n = Integer.parseInt(s);
				error = false;
				if (n < 0) {
					System.out.print("(n>0). Nhap lai: ");
					error = true;
				}
			} catch (NumberFormatException e) {
				System.out.print("Nhap lai mot so nguyen:");
				sc.nextLine();
				error = true;
			}

		} while (error);
		return n;
	}

	public void nhap() {
		do {
			System.out.print("Nhap ngay: ");
			day = nhapSo();
			System.out.print("Nhap thang: ");
			month = nhapSo();
			System.out.print("Nhap nam: ");
			year = nhapSo();
			if (!hopLe()) {
				System.out.println("Ngay nhap vao khong hop le!\n");
			}
		} while (!hopLe());
	}

	public String toString() {
		return day + " - " + month + " - " + year;
	}

	public void in() {
		System.out.printf("%d - %d - %d", day, month, year);
	}

	public boolean hopLe() {
		boolean check = false;
		int maxDayInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) {
			maxDayInMonth[2] = 29;
		}
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= maxDayInMonth[month]) {
			check = true;
		}
		return check;
	}

	public Date ngayHomSau() {
		Date a = new Date(day, month, year);
		int maxDayInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) {
			maxDayInMonth[2] = 29;
		}
		a.day++;
		if (a.day > maxDayInMonth[a.month]) {
			a.day = 1;
			a.month++;
			if (a.month > 12) {
				a.month = 1;
				a.year++;
			}
		}

		return a;
	}

	public Date congNgay(int n) {
		Date a = new Date(day, month, year);
		for (int i = 0; i < n; i++) {
			a = a.ngayHomSau();
		}
		return a;
	}

	public static void main(String[] args) {
		Date a = new Date();
		a.nhap();

		if (a.hopLe()) {
			System.out.println("Ngay " + a + " la ngay hop le!");
		} else {
			System.out.println("Ngay " + a + " la ngay khong hop le!");
		}
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap n = ");
		int n = sc.nextInt();
		a = a.congNgay(n);
		System.out.println("Ngay cach do " + n + " ngay la: " + a);
	}

}
