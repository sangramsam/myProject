import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;


public class Mylistener implements ServletContextListener
{
	public void contextInitialized(ServletContextEvent e)
	{
		ArrayList<User> list=new ArrayList<User>();
		try
		{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","system","sneha");
			PreparedStatement ps=con.prepareStatement("select * from cuser");
			ResultSet rs=ps.executeQuery();
			while(rs.next())
			{
				User u=new User();
				u.setId(rs.getInt(1));
				u.setName(rs.getString(2));
				u.setPassword(rs.getNString(3));
				list.add(u);
			}
			con.close();
		}
		catch(Exception ex)
		{
		System.out.print(ex);
		}
		//storing the ArrayList object in ServeletCOntext
		ServletContext context=e.getServletContext();
		context.setAttribute("data",list);
	}
	public void contextDestroyed(ServletContextEvent args)
	{
		System.out.print("project destroy");
	}

}
