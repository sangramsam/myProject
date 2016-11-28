import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.http.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.*;

public class loginservlet extends HttpServlet 
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException ,IOException 
	{
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		String name=request.getParameter("name");
		String password=request.getParameter("password");
		if(name.equals("sangram") && password.equals("snh"))
		{
			out.print("you login success");
			out.print("<br/> Welcome,"+name);
			request.getRequestDispatcher("link.html").include(request,response);
			Cookie ck=new Cookie("name",name);
			response.addCookie(ck);
			ck.setMaxAge(3);
		}
		else
		{
			out.println("<h2>sorry try again!!</h2>");
			request.getRequestDispatcher("login.html").include(request,response);
		}
		out.close();
	}

}
