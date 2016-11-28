import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.http.HttpServlet;
import javax.swing.JOptionPane;


public class check extends HttpServlet 
{
	public static boolean  login(String user,String password)
	{
		
		boolean status=false;
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","system","sneha");
			PreparedStatement ps=con.prepareStatement("select * from register where username=? and password=?");
			ps.setString(1,user);ps.setString(2,password);
			ResultSet rs=ps.executeQuery();
			status=rs.next();
		}
		catch(Exception e)
		{
			JOptionPane.showMessageDialog(null,e);
		}
		
		return status;
	}

}
