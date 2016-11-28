import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class firstcookie extends HttpServlet
{
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		response.setContentType("text/html");
		PrintWriter out=response.getWriter();
		String n=request.getParameter("name");
		out.print("welcomr"+n);
		Cookie ck=new Cookie("uanme",n);//creating cookie
		response.addCookie(ck);//adding cookie to response
		//creating submit button
		out.print("<form action='2servlet'>");
		out.print("<input type='submit' value='go'>");
		out.print("</form>");
}
}
