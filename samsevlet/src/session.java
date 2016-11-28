import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


@SuppressWarnings("serial")
public class session extends HttpServlet {
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		//System.out.println("Welcome to get method");
		response.setContentType("text/html");
		PrintWriter write =response.getWriter();
		String username=request.getParameter("username");
		HttpSession sesn=request.getSession();
		ServletContext context=request.getServletContext();
		if(username !=" " && username != null)
		{
			sesn.setAttribute("simplesession",username);
			context.setAttribute("simplesession",username);
		}
		
		write.println("hello form get method"+username);
		write.println("hello form get method"+sesn.getAttribute("simplesession"));
		write.println("hello form get method"+context.getAttribute("simplesession"));
		
		
	}
}
