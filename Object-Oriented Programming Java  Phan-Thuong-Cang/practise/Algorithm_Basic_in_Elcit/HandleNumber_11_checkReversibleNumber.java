package Algorithm_Basic_in_Elcit;

public class HandleNumber_11_checkReversibleNumber {
	public static int count = 0;
	public static int temp;

	public static boolean checkReversible(int n) {
		count = 0;
		temp = n;
		while (temp != 0) {
			temp /= 10;
			count++;
		}
		for (int i = 0; i <= count / 2 - 1; i++) {
			temp = (int) Math.pow(10, count - 2 * i - 1);
			if ((n % 10) != ((int) n / temp)) {
				return false;
			} else {
				n = (n % temp) / 10;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		int divColumn = 0;
		int countNumber = 0;
		System.out.println("Cac so thuan nghich co 6 chu so la: ");
		for (int i = 100001; i <= 999999; i++) {
			if (checkReversible(i)) {
				System.out.print(i + " ");
				if ((i / 1000) % 10 == 9) {
					i += 110;
				} else {
					i += 1099; 
				}
				countNumber++;
				divColumn++;
			}
			if (divColumn % 15 == 0) {
				divColumn = 1;
				System.out.println();
			}

		}
		System.out.println();
		System.out.println("So cac chu so thoa man: " + countNumber);

	}

}
