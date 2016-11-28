

import java.io.IOException;
import snh.sam;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class list
 */
@WebServlet("/list")
public class list extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public list() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		List<sam> list=new ArrayList<sam>();
		PrintWriter out=response.getWriter();
		
		String idd=request.getParameter("id");
		 try {
	            Class.forName("oracle.jdbc.driver.OracleDriver");
	            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
	            PreparedStatement ps = con.prepareStatement("select filename from photo where id = ?");
	            ps.setString(1, idd);
	            ResultSet rs=ps.executeQuery();
	            while(rs.next())
	            {
	            	sam sa=new sam();
	            	sa.setName(rs.getString(1));
	            	list.add(sa);
	            }
	            HttpSession session=request.getSession();
	            session.setAttribute("deta",list);
	            RequestDispatcher rd=getServletContext().getRequestDispatcher("/index.jsp");
	    		rd.forward(request,response);
	    		
	}
		 catch(Exception e)
		 {
			 System.out.println(e.getMessage());
		 }

}
}
