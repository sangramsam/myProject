

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.lab.doc;


@WebServlet("/emp")
public class emp extends HttpServlet {
	private static final long serialVersionUID = 1L;
    
    public emp() {
        super();
       
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out=response.getWriter();
		try {
			String id=request.getParameter("t1");
			Class.forName("oracle.jdbc.driver.OracleDriver");
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("select name,address,phone from eemp where empid=?");
			 ps.setString(1, id);
			 ResultSet rs=ps.executeQuery();
			 while(rs.next())
			 {
				 out.println(rs.getString(1));
				 out.println(rs.getString(2)); 
				 out.println(rs.getString(3));
				 out.println(rs.getString(4));
			 }	
	}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}
