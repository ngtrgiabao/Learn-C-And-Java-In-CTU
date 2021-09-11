package Algorithm_Basic_in_Elcit;

public class HandleNumber_8_PrimeHave5Number {
	public static boolean checkPrime(int x) {
		if (x < 2)
			return false;
		else if (x == 2 || x == 3 || x == 5 || x == 7)
			return true;
		else if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
			return false;
		else if (x >= 10) {
			for (int i = 3; i * i < x; i += 2) {
				if (x % i == 0)
					return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		try {
			int divColumn = 0;
			int countNumber = 0;
			System.out.println("Cac so nguyen to co 5 chu so: ");
			for (int i = 10003; i<=99997; i+=2) {
				if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
					continue;
				} else if (checkPrime(i)) {
					System.out.print(i + " ");
					divColumn++;
					countNumber++;
				}
				if (divColumn % 15 == 0) {
					divColumn = 1;
					System.out.println();
				}
			}
			System.out.println();
			System.out.println("So cac chu so thoa man: " + countNumber);
		} catch (Exception e) {
			System.out.println("Dinh dang nhap sai. Chay lai chuong trinh!");
		}
	}

}
