//import java.sql.*;
//import java.util.*;
public class jdbs
{
	public static void main(String []args)
	{
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			System.out.print("ok");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
