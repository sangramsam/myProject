import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import java.sql.*;
import java.util.ArrayList;

public class MyListener implements ServletContextListener{

	
	public void contextInitialized(ServletContextEvent e) {
		
		ArrayList list=new ArrayList();
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			Connection con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","system","oracle");
			
			PreparedStatement ps=con.prepareStatement("select * from csuser");
			ResultSet rs=ps.executeQuery();
			while(rs.next()){
					User u=new User();
					u.setId(rs.getInt(1));
					u.setName(rs.getString(2));
					u.setPassword(rs.getString(3));
					list.add(u);
			}
			con.close();
			
		}catch(Exception ex){System.out.print(ex);}
		
		ServletContext context=e.getServletContext();
		context.setAttribute("data",list);
		
	}
	public void contextDestroyed(ServletContextEvent arg0) {
		System.out.println("project undeployed...");
	}

}
