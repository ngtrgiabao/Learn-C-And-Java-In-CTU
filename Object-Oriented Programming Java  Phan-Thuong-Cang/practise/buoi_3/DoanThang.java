package buoi_3;

public class DoanThang {
	private Diem a;
	private Diem b;

	public DoanThang() {
		super();
	}

	public DoanThang(Diem a, Diem b) {
		this.a = a;
		this.b = b;
	}

	public DoanThang(int ax, int ay, int bx, int by) {
		a.setX(ax);
		a.setY(ay);
		b.setX(bx);
		b.setY(by);
	}

	public DoanThang nhapToaDoDoanThang() {
		DoanThang temp = new DoanThang();
		System.out.println("Nhap toa do diem a: ");
		temp.a.nhapDiem();
		System.out.println("Nhap toa do diem b: ");
		temp.b.nhapDiem();
		return temp;
	}

	public void hienThiHaiDauMut() {
		a.hienThi();
		b.hienThi();
	}

	public void tinhTienDoanThang(int dx, int dy) {
		a.tinhTienDiem(dx, dy);
		b.tinhTienDiem(dx, dy);
	}

	public double doDaiDoanThang() {
		return a.khoangCach(b);
	}

	public double gocTaoVoiTrucHoanh() {
		return Math.toDegrees(Math.acos(a.khoangCach(b.giaTriX(), a.giaTriY()) / a.khoangCach(b)));
	}

}
