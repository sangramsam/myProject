

import java.io.IOException;
import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import oracle.sql.DATE;

/**
 * Servlet implementation class insert
 */
@WebServlet("/insert")
public class insert extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public insert() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	@SuppressWarnings("deprecation")
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String name=request.getParameter("t1");
		System.out.print(name);
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			System.out.println("sasnasak");
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("insert into suser(fd) values(?)");	
			 ps.setString(1, name);
			 int i=ps.executeUpdate();
			 if(i>0)
			 {
				 response.getWriter().write("insert successfully");
			 }
			 else
			 {
				 response.getWriter().write("not inser");
			 }
	}
		catch(ClassNotFoundException  e)
		{
			System.out.println(e.getMessage());
		}
		catch(SQLException e1)
		{
			System.out.print(e1.getMessage());
		}

}
}
