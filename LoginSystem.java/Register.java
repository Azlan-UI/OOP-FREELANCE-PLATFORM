import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Register {
    public static void registerUser(String username, String email, String password, String role) {
        String sql = "INSERT INTO users (username, Email, password) VALUES (?, ?, ?)";

        try (
                Connection conn = DBConnection.connect();
                PreparedStatement pstmt = conn.prepareStatement(sql)
        ) {
            pstmt.setString(1, username);
            pstmt.setString(2, email);
            pstmt.setString(3, password);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Registration failed: " + e.getMessage());
        }
    }
}
