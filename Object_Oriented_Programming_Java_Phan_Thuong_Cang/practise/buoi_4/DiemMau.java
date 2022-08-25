package buoi_4;

import java.util.Scanner;
	// cu phap import buoi_3.Diem;

public class DiemMau extends Diem {
	private String mau;

	public DiemMau() {
		super();
		mau = new String();
	}

	public DiemMau(int x1, int y1, String mau) {
		super(x1, y1);
		this.mau = new String(mau);
	}

	public DiemMau(DiemMau dm) {
		super((Diem) dm); // ep kieu ve diem 
		this.mau = new String(dm.mau);
	}

	public void nhapDiemMau() {
		super.nhapDiem();
		System.out.print("Nhap mau cho diem: ");
		Scanner sc = new Scanner(System.in);
		mau = sc.nextLine();
	}

	public void inDiemMau() {
		super.hienThi();
		System.out.println("Mau cua diem: " + mau);
	}

	public void ganMau(String mau) {
		this.mau = new String(mau);
	}

	private static void test() {

	}
	@Override
	public void test1() {
		super.test1();
		System.out.println("Hello day la ham test goi tu class Diem Mau");
	}

	public void test2() {
		System.out.print("Goi DiemMau::test 2 ");
	}

}
