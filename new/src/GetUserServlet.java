
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/GetUserServlet")
public class GetUserServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		String userName = request.getParameter("userName").trim();
		String pass=request.getParameter("pass");
		String str;
		if(userName.equals("sam") && pass.equals("123")){
			str= "success";
		}
		else
		{
			str="Wrong";
		}
		response.setContentType("text/plain");
		response.getWriter().write(str);
	}

}
