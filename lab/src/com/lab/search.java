package com.lab;


import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class search
 */
@WebServlet("/search")
public class search extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public search() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		List<doc> list=new ArrayList<doc>();
		String city=request.getParameter("city");
		String special=request.getParameter("special");
		String dat=request.getParameter("dd");
		System.out.println(dat);
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			System.out.println("sasnasak");
			 Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe", "system", "sneha");
			 PreparedStatement ps = con.prepareStatement("select name,address,fee,mob from docotor where location=? and speacility=? ");
			 ps.setString(1, city);
			 ps.setString(2,special);
			 ResultSet rs=ps.executeQuery();
			 while(rs.next())
			 {
				 doc ur=new doc();
				 ur.setName(rs.getString(1));
				 ur.setAddress(rs.getString(2));
				 ur.setFee(rs.getString(3));
				 ur.setMob(rs.getString(4));
				 list.add(ur);
			 }	
			 HttpSession session=request.getSession();
			 session.setAttribute("data",list);
			 System.out.println("ok");
			RequestDispatcher rd=getServletContext().getRequestDispatcher("/index.jsp");
				rd.forward(request,response);
				
		} catch (ClassNotFoundException | SQLException e)
		{
		
			System.out.println(e.getMessage());
		}
	}

}
