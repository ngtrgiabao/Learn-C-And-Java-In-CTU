package buoi_3;

import java.util.Scanner;

public class SDGach {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nha so luong phan tu: n = ");
		int n = sc.nextInt();
		Gach arr[] = new Gach[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Gach();
			arr[i].nhapThongTin();
		}
		double max = arr[0].chiPhiLotGach();
		int index = 0;
		for (int i = 0; i < n; i++) {
			System.out.println("arr[" + i + "]:");
			arr[i].hienThi();
			if (max < arr[i].chiPhiLotGach()) {
				max = arr[i].chiPhiLotGach();
				index = i;
			}
		}
		System.out.println("Chi phi lot nen thap nhat: " + max);
		System.out.println("Chi phi thap nhat de lot nen 5mx20m la: "
				+ arr[index].soLuongHop(500, 2000) * arr[index].giaBanLe1Hop());
		System.out.println("So luong hop Gach: " + arr[index].soLuongHop(500, 1000));
	}

}
