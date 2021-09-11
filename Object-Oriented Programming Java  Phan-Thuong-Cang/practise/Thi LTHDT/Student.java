import java.util.Scanner;

public class Student {
	private int age;
	private String name;

	public Student() {
		this.age = 19;
		this.name = new String("Nguyen Anh Nam");
	}

	public Student(int age, String name) {
		this.age = age;
		this.name = name;
	}

	public Student(Student hi) {
		this.age = hi.getAge();
		this.name = new String(hi.getName());
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String normally(String str) {
		str = str.trim().replaceAll("\\s+", " ").toLowerCase(); // xoa khoang trang thua
		String temp[] = str.split(" "); // cắt chuôi thành mảng với ' ' phân cách
		str = ""; // tạo biến lưu kết quả
		for (int i = 0; i < temp.length; i++) { // temp.length: lấy thuộc tính số phần tử trong mảng
			str += String.valueOf(temp[i].charAt(0)).toUpperCase() + temp[i].substring(1);
			// lấy thằng đầu viết Hoa + phần thân sau khi xóa kí tự đầu
			if (i < temp.length - 1) {
				str += " "; // thêm khoảng trắng giữa các từ
			}
		}
		return str;
	}

	public void nhap() {
		Scanner sc = new Scanner(System.in);
		do {
			try {
				System.out.print("Nhap tuoi: ");
				String temp = sc.nextLine();
				this.age = Integer.parseInt(temp);
			} catch (Exception e) {
				System.out.println("Loi nhap so!");
				this.age = 1000;
			}
		} while (this.age <= 0 || this.age >= 100 || this.age == 1000);

		// sc.nextLine(); khong can do doi chuoi

		System.out.println("Nhap ten: ");
		String temp = sc.nextLine();
		this.name = normally(temp);
	}

	public String toString() {
		return "Name: " + this.name + "| Age: " + this.age;
	}

	public int lengthName() {
		return this.name.length();
	}

	public int soTu() {
		String temp = this.name.trim();
		int sum = 1;
		for (int i = 0; i < temp.length() - 1; i++) {
			if (temp.charAt(i) == ' ' && temp.charAt(i + 1) != ' ') {
				sum++;
			}
		}
		return sum;
	}

	public static void main(String[] args) {
		System.out.println("Hello Nam!");
		Student first = new Student();
		System.out.println(first);
		// nhap thong tin
		first.nhap();
		System.out.println("Chieu dai cua ten la: " + first.lengthName());
		System.out.println("So tu cua ten la: " + first.soTu());
		System.out.println(first);
		Student second = new Student(first);
		System.out.println("Ham sao chep: ");
		System.out.println(second);
		Integer a = new Integer(2); // lop bao. dù giống gia trị nhưng khác đia chỉ
		Integer b = new Integer(2);
		if (a == b)
			System.out.print("true");
		else
			System.out.print("false");

	}

}