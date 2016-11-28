package com.lab;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.tomcat.jni.Local;

/**
 * Servlet implementation class insert
 */
@WebServlet("/insert")
public class insert extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public insert() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		java.sql.Date sqldate=null;
		String name=request.getParameter("dd");
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			System.out.println("sasnasak");
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("insert into suser(data) values(?)");
			 System.out.println(name);
			 DateFormat format=new SimpleDateFormat("yyyy-MM-dd",Locale.ENGLISH);
			 //java.util.Date format=new SimpleDateFormat("dd-MMM-yy",Locale.ENGLISH).parse(name);
			 //java.util.Date fo=new java.util.Date();
			 Date date=format.parse(name);
			 sqldate=new java.sql.Date(date.getTime());
			 ps.setDate(1,sqldate);
			 int i=ps.executeUpdate();
			 if(i>0)
			 {
				 System.out.println("ok");
			 }
			 else
			 {
				 System.out.println("not okkk");
			 }
	}
		catch(ClassNotFoundException  e)
		{
			System.out.println(e.getMessage());
		}
		catch(SQLException e1)
		{
			System.out.print(e1.getMessage());
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
