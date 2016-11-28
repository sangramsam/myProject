
import javax.servlet.jsp.jstl.sql.*;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.sql.Blob;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.xml.transform.Result;

import org.apache.commons.fileupload.FileItem;

import snh.sam;

/**
 * Servlet implementation class retriv
 */
@WebServlet("/retriv")
public class retriv extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public retriv() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
	{
		HttpSession session=request.getSession();
		
		 try {
	            Class.forName("oracle.jdbc.driver.OracleDriver");
	            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
	            PreparedStatement ps = con.prepareStatement("select pic from photo where filename = ?");
	            sam s=(sam)session.getAttribute("deta");
	            String filename=s.getname();
	            ps.setString(1,filename);
	            ResultSet rs=ps.executeQuery();
	            rs.next();
	            Blob  b = rs.getBlob("pic");
	            response.setContentType("application/OCTET-STREAM");
	            response.setContentLength( (int) b.length());
	            response.setHeader("Content-Disposition","attachment;filename=\""+ filename +"\"");
	            InputStream is = b.getBinaryStream();
	            OutputStream os = response.getOutputStream();
	            byte buf[] = new byte[(int) b.length()];
	            is.read(buf);
	            os.write(buf);
	            os.close();
	        }
		 catch(Exception e)
		 {
			 System.out.println(e.getMessage());
		 }
		
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

}
