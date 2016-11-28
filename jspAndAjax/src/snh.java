

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.Gson;

/**
 * Servlet implementation class snh
 */
@WebServlet("/snh")
public class snh extends HttpServlet implements Servlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public snh() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String name=request.getParameter("Name");
		ArrayList list=new ArrayList();
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			System.out.println("suceess snh");
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("select semester from soca where course= ?");
			 ps.setString(1,name);
			 ResultSet rs=ps.executeQuery();
			 while(rs.next())
			 {user ur=new user();
				 ur.setId(rs.getString(1));
				 list.add(ur);
			 }	
				
		} catch (ClassNotFoundException | SQLException e)
		{
		
			System.out.println(e.getMessage());
		}
			 write(response,list);
		
	}

	private void write(HttpServletResponse response, ArrayList list) throws IOException {
		// TODO Auto-generated method stub
		response.setContentType("application/json");
		response.setCharacterEncoding("UTF-8");
		response.getWriter().write(new Gson().toJson(list));
	}

}
