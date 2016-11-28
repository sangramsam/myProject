package dto;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import dto.MessgaeObjects;
public class Project {
	public ArrayList GetMessages(Connection connection,HttpServletRequest request,HttpServletResponse response) throws Exception
	{
	ArrayList messageData = new ArrayList();
	try
	{
	PreparedStatement ps = connection.prepareStatement("SELECT msg_id,message FROM messages ORDER BY msg_id DESC");
	ResultSet rs = ps.executeQuery();
	while(rs.next())
	{
	MessgaeObjects messageObject = new MessgaeObjects();
	messageObject.setMsg_id(rs.getString("msg_id"));
	messageObject.setMessage(rs.getString("message"));
	messageData.add(messageObject);
	}
	return messageData;
	}
	catch(Exception e)
	{
	throw e;
	}
	}
}
