import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class search extends HttpServlet 
{
	public void doPost(HttpServletRequest req,HttpServletResponse res) throws ServletException,IOException
	{
		res.setContentType("text/html");
		PrintWriter op=res.getWriter();
		String roll=req.getParameter("roll");
		int rollno=Integer.parseInt(roll);
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","system","sneha");
			PreparedStatement ps=con.prepareStatement("select * from result where roll_no=?");
			ps.setInt(1,rollno);
			ResultSet rs=ps.executeQuery();
			op.print("<table  border='1'>");
					while(rs.next())
			{
				op.print("<tr><td>"+rs.getInt(1)+"</td><td>"+rs.getString(2)+"</td><td>"+rs.getString(3)+"</td><td>"+rs.getInt(4)+"</td></tr>");
			}
			op.print("</table>");
		}
		catch(Exception e)
		{
			
		}
	}

}
