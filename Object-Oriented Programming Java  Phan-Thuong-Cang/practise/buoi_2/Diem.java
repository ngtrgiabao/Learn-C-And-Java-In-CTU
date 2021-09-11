package buoi_2;

import java.util.Scanner;

public class Diem {
	private int x;
	private int y;

	public int giaTriX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int giaTriY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public Diem() {
		x = y = 0;
	}

	public Diem(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public Diem(Diem d) {
		x = d.x;
		y = d.y;
	}

	public void nhapDiem() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap x = ");
		x = sc.nextInt();
		System.out.print("Nhap y = ");
		y = sc.nextInt();
	}

	public void hienThi() {
		System.out.printf("(%d,%d)\n", x, y);
	}

	public void doiDiem(int dx, int dy) {
		x += dx;
		y += dy;
	}

	public double khoangCach() {
		return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
	}

	public double khoangCach(Diem d) {
		return Math.sqrt(Math.pow(x - d.x, 2) + Math.pow(y - d.y, 2));
	}

}
