import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class FreelanceApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(FreelanceApp::showLoginPage);
    }

    private static void showLoginPage() {
        JFrame frame = new JFrame("Login");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);
        frame.setLocationRelativeTo(null);
        frame.setLayout(new GridLayout(6, 1, 10, 10));

        Font font = new Font("Segoe UI", Font.PLAIN, 18);

        JLabel title = new JLabel("FREELANCE PLATFORM", SwingConstants.CENTER);
        title.setFont(new Font("Segoe UI", Font.BOLD, 24));
        title.setForeground(new Color(0, 100, 200));

        JTextField emailField = new JTextField();
        emailField.setFont(font);
        emailField.setBorder(BorderFactory.createTitledBorder("Email"));

        JPasswordField passwordField = new JPasswordField();
        passwordField.setFont(font);
        passwordField.setBorder(BorderFactory.createTitledBorder("Password"));

        JPanel rolePanel = new JPanel();
        rolePanel.setLayout(new FlowLayout());
        JRadioButton client = new JRadioButton("Client", true);
        JRadioButton freelancer = new JRadioButton("Freelancer");
        ButtonGroup group = new ButtonGroup();
        group.add(client);
        group.add(freelancer);
        rolePanel.add(new JLabel("Role:"));
        rolePanel.add(client);
        rolePanel.add(freelancer);

        JButton login = new JButton("Login");
        login.setFont(font);
        login.setBackground(new Color(0, 120, 215));
        login.setForeground(Color.WHITE);

        JButton register = new JButton("Register");
        register.setFont(font);

        login.addActionListener(e -> {
            String email = emailField.getText().trim();
            String pass = new String(passwordField.getPassword()).trim();

            if (email.isEmpty() || pass.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "Email and Password cannot be empty.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            } else {
                try (
                        Connection conn = DBConnection.connect();
                        PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM users WHERE Email = ? AND password = ?")
                ) {
                    pstmt.setString(1, email);
                    pstmt.setString(2, pass);
                    ResultSet rs = pstmt.executeQuery();

                    if (rs.next()) {
                        String role = "Client"; // Since role not in DB, use selected
                        frame.dispose();
                        if (client.isSelected()) {
                            showClientPage(email);
                        } else {
                            showFreelancerPage(email);
                        }
                    } else {
                        JOptionPane.showMessageDialog(frame, "Invalid credentials.", "Login Failed", JOptionPane.ERROR_MESSAGE);
                    }
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(frame, "Database error: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        register.addActionListener(e -> {
            frame.dispose();
            showRegisterPage();
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(login);
        buttonPanel.add(register);

        frame.add(title);
        frame.add(emailField);
        frame.add(passwordField);
        frame.add(rolePanel);
        frame.add(buttonPanel);

        frame.setVisible(true);
    }

    private static void showClientPage(String username) {
        JFrame frame = new JFrame("Client Dashboard");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLocationRelativeTo(null);

        JPanel panel = new JPanel(new GridLayout(4, 1, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JLabel label = new JLabel("Welcome, Client " + username + "!", SwingConstants.CENTER);
        label.setFont(new Font("Segoe UI", Font.BOLD, 18));

        JButton btn1 = new JButton("Post a Job");
        JButton btn2 = new JButton("View Proposals");
        JButton logout = new JButton("Logout");

        logout.addActionListener(e -> {
            frame.dispose();
            showLoginPage();
        });

        panel.add(label);
        panel.add(btn1);
        panel.add(btn2);
        panel.add(logout);

        frame.add(panel);
        frame.setVisible(true);
    }

    private static void showFreelancerPage(String username) {
        JFrame frame = new JFrame("Freelancer Dashboard");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLocationRelativeTo(null);

        JPanel panel = new JPanel(new GridLayout(4, 1, 10, 10));
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        JLabel label = new JLabel("Welcome, Freelancer " + username + "!", SwingConstants.CENTER);
        label.setFont(new Font("Segoe UI", Font.BOLD, 18));

        JButton btn1 = new JButton("Browse Gigs");
        JButton btn2 = new JButton("My Applications");
        JButton logout = new JButton("Logout");

        logout.addActionListener(e -> {
            frame.dispose();
            showLoginPage();
        });

        panel.add(label);
        panel.add(btn1);
        panel.add(btn2);
        panel.add(logout);

        frame.add(panel);
        frame.setVisible(true);
    }

    private static void showRegisterPage() {
        JFrame frame = new JFrame("Register");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 450);
        frame.setLocationRelativeTo(null);
        frame.setLayout(new GridLayout(7, 1, 10, 10));

        Font font = new Font("Segoe UI", Font.PLAIN, 18);

        JLabel title = new JLabel("REGISTER ACCOUNT", SwingConstants.CENTER);
        title.setFont(new Font("Segoe UI", Font.BOLD, 24));
        title.setForeground(new Color(0, 100, 200));

        JTextField usernameField = new JTextField();
        usernameField.setFont(font);
        usernameField.setBorder(BorderFactory.createTitledBorder("Username"));

        JTextField emailField = new JTextField();
        emailField.setFont(font);
        emailField.setBorder(BorderFactory.createTitledBorder("Email"));

        JPasswordField passwordField = new JPasswordField();
        passwordField.setFont(font);
        passwordField.setBorder(BorderFactory.createTitledBorder("Password"));

        JPanel rolePanel = new JPanel(new FlowLayout());
        JRadioButton client = new JRadioButton("Client", true);
        JRadioButton freelancer = new JRadioButton("Freelancer");
        ButtonGroup group = new ButtonGroup();
        group.add(client);
        group.add(freelancer);
        rolePanel.add(new JLabel("Role:"));
        rolePanel.add(client);
        rolePanel.add(freelancer);

        JButton registerBtn = new JButton("Register");
        registerBtn.setFont(font);
        registerBtn.setBackground(new Color(100, 180, 100));
        registerBtn.setForeground(Color.WHITE);

        JButton backBtn = new JButton("Back to Login");
        backBtn.setFont(font);

        registerBtn.addActionListener(e -> {
            String userName = usernameField.getText().trim();
            String userEmail = emailField.getText().trim();
            String userPass = new String(passwordField.getPassword()).trim();
            String role = client.isSelected() ? "Client" : "Freelancer";

            if (userName.isEmpty() || userEmail.isEmpty() || userPass.isEmpty()) {
                JOptionPane.showMessageDialog(frame, "All fields are required!", "Validation Error", JOptionPane.ERROR_MESSAGE);
            } else {
                Register.registerUser(userName, userEmail, userPass, role);
                JOptionPane.showMessageDialog(frame, "Account registered successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
                frame.dispose();
                showLoginPage();
            }
        });

        backBtn.addActionListener(e -> {
            frame.dispose();
            showLoginPage();
        });

        frame.add(title);
        frame.add(usernameField);
        frame.add(emailField);
        frame.add(passwordField);
        frame.add(rolePanel);
        frame.add(registerBtn);
        frame.add(backBtn);

        frame.setVisible(true);
    }
}
