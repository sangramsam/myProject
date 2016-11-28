import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
//import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class XmlServlet extends HttpServlet {
	/**
	 *  
	 */
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//System.out.println("Welcome to get method");
		response.setContentType("text/html");
		PrintWriter write =response.getWriter();
		String username=request.getParameter("username");
		write.println("hello form get method"+username);
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//System.out.println("Welcome to get method");
		response.setContentType("text/html");
		PrintWriter write =response.getWriter();
		String username=request.getParameter("username");
		write.println("hello \t"+username+"<br/>");
		String fullname=request.getParameter("fullname");
		write.println("full name is \t"+fullname+"<br/>");
		String prof=request.getParameter("prof");
		write.println("your profession is \t"+prof+"<br/>");
		//String location=request.getParameter("location");
		String []location=request.getParameterValues("location");
		write.println("your are at \t"+location.length+"place"+"<br/>");
		for(int i=0;i<location.length;i++)
		{
			write.println(location[i]+"<br/>");
		}
		Date dt=new Date();
		write.println(dt.toString()+"<br/>");
		write.println(request.getServerName()+"<br/>");
		write.println(request.getProtocol()+"<br/>");
		write.println(request.getServerPort()+"<br/>");
		write.println(request.getScheme()+"<br/>");
		
	}
}
