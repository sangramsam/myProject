import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/login")
public class login extends HttpServlet {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String user=request.getParameter("name");
		String pass=request.getParameter("password");
		PrintWriter write=response.getWriter();
		response.setHeader("Cache-Control", "no-cache");
        response.setHeader("Pragma", "no-cache");
		if(user.equals("sam") && pass.equals("123"))
		{
			write.print("welcome to hell");
		}
		else
		{
			write.println("Incurrect password!!!");
			
		}
}
}
