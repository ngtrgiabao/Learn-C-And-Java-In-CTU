package Testabs;

class SDAnimal extends abstractAnimal {
	public void eat() {
		System.out.println("Eatting...");
	}

	public void drink() {
		System.out.println("Drinking...");
	}

	public static void main(String args[]) {
		SDAnimal temp = new SDAnimal();
		System.out.println("Ghi de abstract: ");
		temp.eat();
		temp.drink();
	}
}