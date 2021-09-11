package buoi_2;

import java.util.Scanner;

public class PhanSo {
	private int tu;
	private int mau;

	public int layTu() {
		return tu;
	}

	public void setTu(int tu) {
		this.tu = tu;
	}

	public int layMau() {
		return mau;
	}

	public void setMau(int mau) {
		this.mau = mau;
	}

	public PhanSo() {
		tu = 0;
		mau = 1; // mau != 0
	}

	public PhanSo(int tu, int mau) {
		this.tu = tu;
		this.mau = mau;
	}

	public PhanSo(PhanSo p) {
		tu = p.tu;
		mau = p.mau;
	}

	public void nhapPhanSo() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap tu so: ");
		tu = sc.nextInt();
		System.out.print("Nhap mau so: ");
		mau = sc.nextInt();
		while (mau == 0) {
			System.out.print("Nhap mau so: ");
			mau = sc.nextInt();
		}
		System.out.println();

	}

	public void hienThi() {
		if (tu == 0) {
			System.out.println("0");
		} else if (mau == 1 || tu == mau) {
			System.out.println(tu / mau);
		} else if (mau * tu < 0) {
			System.out.printf("-%d/%d", (int) Math.abs(tu), (int) Math.abs(mau));
		} else {
			System.out.printf("%d/%d\n", tu, mau);
		}

	}

	public void gan(int tu, int mau) {
		this.tu = tu;
		this.mau = mau;
	}

	public int gcd(int a, int b) {
		return (b == 0) ? (a) : gcd(b, a % b);
	}

	public void toiGian() {
		int gcd = gcd(tu, mau);
		tu /= gcd;
		mau /= gcd;
	}

	public void nghichDao() {
		if (tu == 0) {
			System.out.println("\n Loi do tu so=0, khong ton tai phan so nghich dao");
		} else {
			tu = tu + mau - (mau = tu);
		}
	}

	public double giaTriNghichDao() {
		return (double) mau / tu;

	}

	public double giaTriThuc() {
		return (double) tu / mau;
	}

	public boolean lonHon(PhanSo a) {
		return giaTriThuc() > a.giaTriThuc();
	}

	public PhanSo cong(PhanSo a) {
		int tu1 = (tu * a.mau) + (a.tu * mau);
		int mau1 = a.mau * mau;
		return new PhanSo(tu1, mau1);

	}

	public PhanSo tru(PhanSo a) {
		int tu1 = (tu * a.mau) - (a.tu * mau);
		int mau1 = a.mau * mau;
		return new PhanSo(tu1, mau1);
	}

	public PhanSo nhan(PhanSo a) {
		return new PhanSo(tu * a.tu, mau * a.mau);
	}

	public PhanSo chia(PhanSo a) {
		return new PhanSo(tu * a.mau, mau * a.tu);
	}

	public PhanSo cong(int a) {
		int tu1 = tu + a * mau;
		int mau1 = mau;
		return new PhanSo(tu1, mau1);
	}

	public PhanSo tru(int a) {
		int tu1 = tu - a * mau;
		int mau1 = mau;
		return new PhanSo(tu1, mau1);
	}

	public PhanSo nhan(int a) {
		return new PhanSo(tu * a, mau);
	}

	public PhanSo chia(int a) {
		return new PhanSo(tu, mau * a);
	}

}
