package buoi_1;

public class Bai_3_XuLyDoiSoDongLenh {

	public static void main(String[] args) {
		double sum = 0;
		double max = Double.parseDouble(args[0]);
		for (int i = 0; i < args.length; i++) {
			if (max < Double.parseDouble(args[i])) {
				max = Double.parseDouble(args[i]);
			}
			sum += Double.parseDouble(args[i]);
		}
		System.out.println("Gia tri lon nhat: " + max);
		System.out.println("Tong cac phan tu: " + sum);
	}

}

/*
 * Huong dan run configurations
 * 1. chuoi phai
 * 2. run as
 * 3. run configuration
 * 4. nhap sang argument
 * 5. nhap chuoi dau vao
 * 6_end. run
 */
