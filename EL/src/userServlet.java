

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


@WebServlet("/userServlet")
public class userServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
   
    public userServlet() {
        super();
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		user ur=new user();
		List<user> list=new ArrayList<user>();
		String idd=request.getParameter("t1");
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("select name,address,email from suser where id = ? ");
			 ps.setString(1,idd);
			 
			 ResultSet rs=ps.executeQuery();
			 System.out.println("sss");
			 while(rs.next())
			 {
				 
				 ur.setName(rs.getString(1));
				 ur.setAddress(rs.getString(2));
				 ur.setemail(rs.getString(3));
				
			 }
			HttpSession session=request.getSession();
			session.setAttribute("data",ur);
			 RequestDispatcher rd=getServletContext().getRequestDispatcher("/index.jsp");
				rd.forward(request,response);
			 
			 
			 
		} catch (ClassNotFoundException | SQLException e)
		{
		
			System.out.println(e.getMessage());
		}
       
		
	}

}
