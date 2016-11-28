import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class MyServlet1 extends HttpServlet
{
	public void doGet(HttpServletRequest req,HttpServletResponse res) throws IOException,ServletException
	{
		res.setContentType("text/html");
		PrintWriter out=res.getWriter();
		ServletContext context=getServletContext();
		List list=(List)context.getAttribute("data");
		Iterator itr=list.iterator();
		while(itr.hasNext())
		{
			User u=(User)itr.next();
			out.print("<br>"+u.getId()+" "+u.getName()+" "+u.getPassword());
		}
	}

}
