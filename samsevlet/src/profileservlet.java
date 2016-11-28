import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.*;
public class profileservlet extends HttpServlet
{
	public void doGet(HttpServletRequest request,HttpServletResponse response) throws ServletException ,IOException
	{
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		request.getRequestDispatcher("link.html").include(request, response);
		Cookie []ck=request.getCookies();
		if(ck!=null)
		{
			String name=ck[0].getValue();
		if(!name.equals("") || name!=null)
		{
			out.print("<b> Welocome to profile</b>");
			out.print("<br>Welcomem"+name);
		}
		}
		else
		{
			out.print("please login first");
			request.getRequestDispatcher("login.html").include(request,response);
		}
	}

}
