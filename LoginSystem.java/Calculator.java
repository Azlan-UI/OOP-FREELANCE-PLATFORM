import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculator extends JFrame {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Calculator with Radio Buttons");

        // Use vertical layout
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        // Input: NUM1
        JLabel label1 = new JLabel("NUM1");
        JTextField field1 = new JTextField();
        field1.setMaximumSize(new Dimension(200, 30));

        // Input: NUM2
        JLabel label2 = new JLabel("NUM2");
        JTextField field2 = new JTextField();
        field2.setMaximumSize(new Dimension(200, 30));

        // Radio buttons for operation
        JRadioButton addRadio = new JRadioButton("Add");
        JRadioButton subRadio = new JRadioButton("Subtract");

        // Group the radio buttons so only one is selectable
        ButtonGroup group = new ButtonGroup();
        group.add(addRadio);
        group.add(subRadio);

        // Result button
        JButton resultButton = new JButton("Result");

        // Add components to panel
        panel.add(label1);
        panel.add(field1);
        panel.add(label2);
        panel.add(field2);
        panel.add(addRadio);
        panel.add(subRadio);
        panel.add(resultButton);

        // Add panel to frame
        frame.add(panel);

        // Action listener for result button
        resultButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    int num1 = Integer.parseInt(field1.getText());
                    int num2 = Integer.parseInt(field2.getText());
                    int result;

                    if (addRadio.isSelected()) {
                        result = num1 + num2;
                        JOptionPane.showMessageDialog(null, "Sum is: " + result);
                    } else if (subRadio.isSelected()) {
                        result = num1 - num2;
                        JOptionPane.showMessageDialog(null, "Difference is: " + result);
                    } else {
                        JOptionPane.showMessageDialog(null, "Please select Add or Subtract");
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Please enter valid numbers.");
                }
            }
        });

        // Frame settings
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
