package buoi_3;

public class SDDoanThang {

	public static void main(String[] args) {
		Diem A = new Diem(2, 5);
		Diem B = new Diem(20, 35);
		DoanThang AB = new DoanThang(A, B);
		System.out.println("Toa do doan thang AB:");
		AB.hienThiHaiDauMut();
		System.out.println("Toa do doan thang AB sau khi tinh tien:");
		AB.tinhTienDoanThang(5, 3);
		AB.hienThiHaiDauMut();
		A.nhapDiem();
		B.nhapDiem();
		DoanThang CD = new DoanThang(A, B);
		System.out.println("Do dai doan thang CD: " + CD.doDaiDoanThang());
		// phuong thuc (double) Math.round( temp * 10) / 10; lam tron den 1 chu so thap phan
		System.out.println(
				"Goc tao boi doan thang CD va Ox: " + (double) Math.round(CD.gocTaoVoiTrucHoanh() * 10) / 10);

	}

}
