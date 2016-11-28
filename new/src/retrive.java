

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.google.gson.Gson;

/**
 * Servlet implementation class select
 */
@WebServlet("/retrive")
public class retrive extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public retrive() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	@SuppressWarnings("unchecked")
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		PrintWriter out=response.getWriter();
		ArrayList list=new ArrayList();
		user ur=new user();
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			System.out.println("sasnasak");
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("select * from suser  ");
			 ResultSet rs=ps.executeQuery();
			 
			 while(rs.next())
			 {
				 ur.setName(rs.getString(1));
				 ur.setAddress(rs.getString(2));
				 ur.setemail(rs.getString(3));
				list.add(ur);
			 }
			 write(response,ur);
			 
		} catch (ClassNotFoundException | SQLException e)
		{
		
			System.out.println(e.getMessage());
		}
	}

	private void write(HttpServletResponse response, user ur) throws IOException {
		response.setContentType("application/json");
		response.setCharacterEncoding("UTF-8");
		response.getWriter().print(new Gson().toJson(ur));
		// TODO Auto-generated method stub
		
	}

}
