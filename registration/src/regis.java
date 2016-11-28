import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.swing.JOptionPane;


public class regis extends HttpServlet
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void doPost(HttpServletRequest req,HttpServletResponse res) throws ServletException,IOException
	{
		res.setContentType("text/html");
		PrintWriter out=res.getWriter();
		String name=req.getParameter("username");
		String password=req.getParameter("password");
		String email=req.getParameter("email");
		String country=req.getParameter("country");
		try
		{
		Class.forName("oracle.jdbc.driver.OracleDriver");
		out.print("okkk");
	 		Connection con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","system","sneha");
			PreparedStatement ps=con.prepareStatement("insert into REGISTER values(?,?,?,?)");
			ps.setString(1,name);
			ps.setString(2,password);
			ps.setString(3,email);
			ps.setString(4,country);
			int i=ps.executeUpdate();
			if(i>0)
			{
				out.print("enter successfully");
			}
			
		}
		catch(ClassNotFoundException c)
		{
			
			JOptionPane.showMessageDialog(null,c);
		}
		catch(SQLException w)
		{
			JOptionPane.showMessageDialog(null,w);
		}
		
		
	}

}
