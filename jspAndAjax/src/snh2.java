

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;

/**
 * Servlet implementation class snh2
 */
@WebServlet("/snh2")
public class snh2 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public snh2() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String lis=request.getParameter("list");
		String name=request.getParameter("Name");
		ArrayList list=new ArrayList();
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("select subject_id from soca where semester= ? and course=?");
			 ps.setString(1,lis);
			 ps.setString(2,name);
			 System.out.print(name);
			 ResultSet rs=ps.executeQuery();
			 System.out.println("sucesss");
			 while(rs.next())
			 {
				 user ur=new user();
				 ur.setId(rs.getString(1));
				 list.add(ur);
			 }	
			 con.close();
				
		} catch (ClassNotFoundException | SQLException e)
		{
		
			System.out.println(e.getMessage());
		}
		System.out.println(list);
			 write(response,list);
		
	}

	private void write(HttpServletResponse response, ArrayList list) throws IOException {
		// TODO Auto-generated method stub
		response.setContentType("application/json");
		response.setCharacterEncoding("UTF-8");
		response.getWriter().write(new Gson().toJson(list));
	}

}
