package buoi_4;

public class SDDiemMau {
	public static void main(String args[]) {
		DiemMau A = new DiemMau(5, 10, "Trang");
		System.out.println("Diem A:");
		A.inDiemMau();

		DiemMau B = new DiemMau();
		B.nhapDiemMau();

		System.out.print("Diem B sau khi da tinh tien (10, 8) va doi thanh mau Vang:\n");
		B.doiDiem(10, 8);
		B.ganMau("Vang");
		System.out.println("Diem B:");
		B.inDiemMau();

		System.out.print("Goi ham sao chep Diem B cho C");
		DiemMau C = new DiemMau(B);
		System.out.println("Diem C");
		C.inDiemMau();

		// tham chieu cua cha
		Diem down = new DiemMau(); // downcasting, su dụng được cac method đã override ở class con
		// co th ep được, có th không
		System.out.println("Diem p goi tu class Diem: ");
		down.test1();
		System.out.println("Tao mang Diem bat ky (Diem hay DiemMau)");
		Diem a[] = new Diem[2];
		a[0] = new Diem(1, 2);
		a[1] = new DiemMau(5, 7, "Tim");

		a[0].hienThi();
		a[1].hienThi();

		down = a[1];
		down.hienThi();

	}

}
