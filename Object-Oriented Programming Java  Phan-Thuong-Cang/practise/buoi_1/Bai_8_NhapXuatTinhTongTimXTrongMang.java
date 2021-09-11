package buoi_1;

import java.util.Scanner;

public class Bai_8_NhapXuatTinhTongTimXTrongMang {

	private static double[] inputArray() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap so phan tu: ");
		int n = sc.nextInt();
		double arr[] = null;
		arr = new double[n];
		for (int i = 0; i < n; i++) {
			System.out.print("Phan tu arr[" + (i + 1) + "]: ");
			arr[i] = sc.nextDouble();
		}
		return arr;
	}

	private static void bubbleSort(double[] arr) {
		boolean swapped;
		for (int i = 0; i < arr.length - 1; i++) {
			swapped = false;
			for (int j = 0; j < arr.length - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					arr[j] = arr[j] + arr[j + 1] - (arr[j + 1] = arr[j]);
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}

	private static void printArray(double[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		double[] arr = null;
		arr = inputArray();
		System.out.println("Mang da nhap la: ");
		printArray(arr);
		System.out.println("Mang sau khi sort la: ");
		bubbleSort(arr);
		printArray(arr);
		int x, count = 0, sum = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("Nhap: x = ");
		x = sc.nextInt();
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == x) {
				count++;
			}
			sum += arr[i];
		}
		System.out.println("So phan tu giong " + x + ": " + count);
		System.out.println("Tong cac phan tu trong mang: " + sum);
		sc.close();
	}
}
