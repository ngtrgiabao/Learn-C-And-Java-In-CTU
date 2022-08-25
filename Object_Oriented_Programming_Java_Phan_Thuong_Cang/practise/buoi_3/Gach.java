package buoi_3;

import java.util.Scanner;

public class Gach {
	private String maSo, mau;
	private int soLuongGach, chieuDaiGach, chieuRongGach;
	private long giaBan;

	public Gach() {
		this.maSo = new String();
		this.mau = new String();
		this.soLuongGach = 0;
		this.chieuDaiGach = 0;
		this.chieuRongGach = 0;
		this.giaBan = 0;
	}

	public Gach(Gach temp) {
		this.maSo = new String(temp.maSo);
		this.mau = new String(temp.mau);
		this.soLuongGach = temp.soLuongGach;
		this.chieuDaiGach = temp.chieuDaiGach;
		this.chieuRongGach = temp.chieuRongGach;
		this.giaBan = temp.giaBan;
	}

	public Gach(String maSo, String mau, int soLuongGach, int chieuDaiGach, int chieuRongGach, long giaBan) {
		super();
		this.maSo = maSo;
		this.mau = mau;
		this.soLuongGach = soLuongGach;
		this.chieuDaiGach = chieuDaiGach;
		this.chieuRongGach = chieuRongGach;
		this.giaBan = giaBan;
	}

	public void nhapThongTin() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap ma so: ");
		maSo = sc.nextLine();
		System.out.print("Nhap mau: ");
		mau = sc.nextLine();
		System.out.print("Nhap so luong vien: ");
		soLuongGach = sc.nextInt();
		System.out.print("Nhap chieu dai Gach: ");
		chieuDaiGach = sc.nextInt();
		System.out.print("Nhap chieu rong Gach: ");
		chieuRongGach = sc.nextInt();
		System.out.print("Nhap gia ban 1 hop Gach: ");
		giaBan = sc.nextLong();
	}

	public void hienThi() {
		System.out.print(maSo + "\t" + mau + "\t" + soLuongGach + "\t");
		System.out.println(chieuDaiGach + "\t" + chieuRongGach + "\t" + giaBan);
	}

	public float giaBanLe1Vien() {
		return (float) (giaBan / soLuongGach) / 100 * 120;
	}

	public float giaBanLe1Hop() {
		return (float) giaBan * 120 / 100;
	}

	public int dienTichNenToiDa() {
		return chieuDaiGach * chieuRongGach * soLuongGach;
	}

	public int soLuongHop(int D, int N) {
		int vienDai = (int) D / chieuDaiGach;
		if (D / chieuDaiGach % 1 != 0)
			vienDai++;
		int vienRong = (int) N / chieuRongGach;
		if (D / chieuRongGach % 1 != 0)
			vienRong++;
		int slHop = (int) vienDai / soLuongGach * vienRong;
		if (vienDai / soLuongGach * vienRong % 1 != 0)
			slHop++;
		return slHop;
	}
	

	public double chiPhiLotGach() {
		return (double) giaBanLe1Hop() / dienTichNenToiDa();
	}

	public double chiPhiLotGach(int dienTich) { // chua dung
		return (double) (dienTich / chieuDaiGach / chieuRongGach) * giaBanLe1Vien();
	}

}
