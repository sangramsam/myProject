import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.GenericServlet;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;


public class myweb extends GenericServlet {

	@Override
	public void service(ServletRequest rq, ServletResponse rs)
			throws ServletException, IOException {
		rs.setContentType("texthtml");
		PrintWriter Pw=rs.getWriter();
		String S1=rq.getParameter("t1");
		Pw.println("hello"+"S1"+"how r u");
		Pw.println("welcometoserver")
		
		// TODO Auto-generated method stub

	}

}
