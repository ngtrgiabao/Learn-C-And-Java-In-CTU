package GUITest;

import javax.swing.*;

import java.awt.*;

public class BasicSwing extends JFrame {
	public BasicSwing() {
	}

	public BasicSwing(String s) {
		setTitle(s);
	}


	public static void main(String[] args) {
		BasicSwing a = new BasicSwing("Hello javaSwing");
		a.setSize(500, 200); // (Ngang va doc)
		a.getContentPane().setBackground(Color.YELLOW); // set mau cho Background
		JLabel label = new JLabel("A label");
		label.setFont(new Font("Serif", Font.BOLD, 40));
		a.add(label);
		a.setVisible(true);
		// dong chuong trinh khi dong cua so
		a.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

/**
 * JFrame la mot Container, cung cap khong gian cho cac component ben trong hoat
 * dong. Giong nhu cua so windown co tieu de va vien
 * 
 *
 * a.setSize(2000, 500); // Ngang 2000 pixel va doc: 500 pixel
 */