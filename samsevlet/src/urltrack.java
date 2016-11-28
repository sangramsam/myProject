import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class urltrack extends HttpServlet 
{
	public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException ,IOException
	{
		response.setContentType("text/html");
		String name=request.getParameter("name");
		PrintWriter out=response.getWriter();
		out.print("<h3>welocome</h3>"+name);
		out.print("<a href='urltrack2?name="+name+"'>visit</a>");
		
	}

}
