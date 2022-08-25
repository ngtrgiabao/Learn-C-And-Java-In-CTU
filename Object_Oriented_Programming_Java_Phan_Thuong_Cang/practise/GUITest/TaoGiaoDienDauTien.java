package GUITest;

import java.awt.*;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TaoGiaoDienDauTien extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TaoGiaoDienDauTien frame = new TaoGiaoDienDauTien();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public TaoGiaoDienDauTien() {
		JFrame f = new JFrame();
		f.setSize(554, 600);// truc x, truc y, do rong, chieu cao
		f.getContentPane().setLayout(null);// Khong su dung Layout Manager
		
		JButton fds = new JButton("click");
		fds.setBounds(146, 91, 100, 50);
		f.getContentPane().add(fds);
		
		JButton b_3 = new JButton("click");
		b_3.setBounds(279, 91, 100, 50);
		f.getContentPane().add(b_3);
		
		JButton dd = new JButton("click");
		dd.setBounds(12, 91, 100, 50);
		f.getContentPane().add(dd);
		
		JTextField t = new JTextField();
		t.setBounds(12, 23, 501, 55);
		t.getMargin();
		f.getContentPane().add(t);
		
		JButton b_4 = new JButton("click");
		b_4.setBounds(12, 169, 100, 50);
		f.getContentPane().add(b_4);
		
		JButton b_1_1 = new JButton("click");
		b_1_1.setBounds(146, 169, 100, 50);
		f.getContentPane().add(b_1_1);
		
		JButton b_3_1 = new JButton("click");
		b_3_1.setBounds(279, 169, 100, 50);
		f.getContentPane().add(b_3_1);
		
		JButton one = new JButton("click");
		one.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
			}
		});
		one.setBounds(12, 249, 100, 50);
		f.getContentPane().add(one);
		
		JButton tow = new JButton("click");
		tow.setBounds(146, 249, 100, 50);
		f.getContentPane().add(tow);
		
		JButton there = new JButton("click");
		there.setBounds(279, 249, 100, 50);
		f.getContentPane().add(there);
		
		JButton b_3_2_1 = new JButton("click");
		b_3_2_1.setBounds(413, 249, 100, 50);
		f.getContentPane().add(b_3_2_1);
		
		JButton b_3_1_1 = new JButton("click");
		b_3_1_1.setBounds(413, 169, 100, 50);
		f.getContentPane().add(b_3_1_1);
		
		JButton b_3_3 = new JButton("click");
		b_3_3.setBounds(413, 91, 100, 50);
		f.getContentPane().add(b_3_3);
		
		JButton Zero = new JButton("click");
		Zero.setBounds(12, 330, 100, 50);
		f.getContentPane().add(Zero);
		
		JButton dot = new JButton("click");
		dot.setBounds(146, 330, 100, 50);
		f.getContentPane().add(dot);
		
		JButton asm = new JButton("click");
		asm.setBounds(279, 330, 100, 50);
		f.getContentPane().add(asm);
		
		JButton eque = new JButton("click");
		eque.setBounds(413, 330, 100, 50);
		f.getContentPane().add(eque);
		f.setVisible(true);
	}
}
