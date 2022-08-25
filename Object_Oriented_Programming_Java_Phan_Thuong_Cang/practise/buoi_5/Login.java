package buoi_5;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Login {

	private JFrame frame;
	private JTextField mssv;
	private JPasswordField pass;
	private SinhVien sv[];

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Login window = new Login();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public Login() { // constructor
		initialize();
	}

	private void initialize() {
		sv = new SinhVien[2];
		for (int i = 0; i < sv.length; i++)
			sv[i] = new SinhVien();

		sv[0] = new SinhVien("B1910414", "Nguyen Anh Nam", "HelloNam");
		sv[1] = new SinhVien("B1910422", "Trinh Dao Khong Co", "HelloDao");

		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);

		JLabel lblNewLabel = new JLabel("Ma so sinh vien");
		lblNewLabel.setBounds(10, 11, 111, 21);
		frame.getContentPane().add(lblNewLabel);

		JLabel lblNewLabel_1 = new JLabel("Password");
		lblNewLabel_1.setBounds(10, 60, 83, 14);
		frame.getContentPane().add(lblNewLabel_1);

		mssv = new JTextField();
		mssv.setBounds(131, 11, 145, 20);
		frame.getContentPane().add(mssv);
		mssv.setColumns(10);

		pass = new JPasswordField();
		pass.setBounds(131, 57, 145, 20);
		frame.getContentPane().add(pass);

		JButton btnNewButton = new JButton("Dang nhap");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String m = mssv.getText();
				String p = pass.getText();

				int i;
				boolean f = false;

				for (i = 0; i < sv.length; i++)
					if (sv[i].ktraTKhoan(m, p)) {
						f = true;
						break;
					}
				if (f)
					JOptionPane.showMessageDialog(null, "Ban da dang nhap thanh cong, Hi : " + sv[i].layHTen());
				else
					JOptionPane.showMessageDialog(null, "Ban da dang nhap that bai, dang nhap lai");

			}
		});
		btnNewButton.setBounds(131, 119, 89, 23);
		frame.getContentPane().add(btnNewButton);
	}
}
