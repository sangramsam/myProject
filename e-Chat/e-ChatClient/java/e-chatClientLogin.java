
import java.net.Socket;
import java.net.URL;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.*;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
 class eChatClientLogin implements ActionListener,KeyListener{
	Socket iClient;
	JFrame iFrame;
	Image iChat_icon;
	JPanel iPaneLbl;
	JLabel iName,iUserName,iServer,iPort;
	JTextField iGetUserName,iGetServer,iGetPortNo;
	JButton srtClient,extClient;
	
	String userName,serverName,server_msg;
	int portNo=1664;
	BufferedReader msgFromServer;
	DataOutputStream msgToServer;
	
	InfiniteChatClientHandle iHandle;
	public eChatClientLogin() {
		iFrame=new JFrame("e-Chat Client ");
		iFrame.setLayout(null);
		iFrame.setBounds(800,80,220,600);
		iFrame.setResizable(false);
		
		iChat_icon=Toolkit.getDefaultToolkit().getImage("../images/iChat_icon_small.gif");
		iFrame.setIconImage(iChat_icon);
		
		iPaneLbl=new JPanel(null);
		iPaneLbl.setBounds(0,0,220,60);
		iPaneLbl.setBackground(Color.black);
		iName=new JLabel("e-Chat Client");
		iName.setBounds(30,5,200,50);
		iName.setForeground(Color.white);
		iName.setFont(new Font("Helvitica",Font.BOLD,20));
		iPaneLbl.add(iName);
		iFrame.add(iPaneLbl);
		
		iUserName=new JLabel("Username :");
		iUserName.setBounds(30,100,100,25);
		iFrame.add(iUserName);
		
		iServer=new JLabel("Server :");
		iServer.setBounds(30,150,100,25);
		iFrame.add(iServer);
		
		iPort=new JLabel("Port No. :");
		iPort.setBounds(30,200,100,25);
		iFrame.add(iPort);
		
		iGetUserName=new JTextField(15);
		iGetUserName.setBounds(100,100,90,25);
		iGetUserName.addKeyListener(this);
		iFrame.add(iGetUserName);
		
		iGetServer=new JTextField();
		iGetServer.setBounds(100,150,90,25);
		iGetServer.addKeyListener(this);
		iFrame.add(iGetServer);
		
		iGetPortNo=new JTextField(5);
		iGetPortNo.setBounds(100,200,50,25);
		iGetPortNo.setText("1664");
		iGetPortNo.addKeyListener(this);
		iFrame.add(iGetPortNo);
		
		srtClient=new JButton("Log In");
		srtClient.setBounds(60,450,100,30);
		srtClient.addActionListener(this);
		srtClient.addKeyListener(this);
		iFrame.add(srtClient);
		
		extClient=new JButton("Exit iChat");
		extClient.setBounds(60,490,100,30);
		extClient.addActionListener(this);
		iFrame.add(extClient);
		
		iFrame.addWindowListener(
			new WindowAdapter(){
				public void windowClosing(WindowEvent e){
					exit_iChatClient();
				}
			}
		);
		iFrame.setVisible(true);
	}
	
	//Listenting Action Events...
	public void actionPerformed(ActionEvent e){
    	if(e.getSource()==srtClient){
    		log_in();
    	}
    	if(e.getSource()==extClient){
    		exit_iChatClient();
    	}
    }
    
    //Listening to KeyEvents...
    public void keyPressed(KeyEvent e){
    	if(e.getKeyChar()=='\n'){
    		log_in();
    	}
    }
    public void keyReleased(KeyEvent e){}
    public void keyTyped(KeyEvent e){}
	
	//Log in to iChat Client v1.0...
	private void log_in(){
    	userName=iGetUserName.getText();
    	userName.trim();
    	if(userName.isEmpty()){
    		javax.swing.JOptionPane.showMessageDialog(null,"Please give a username...");
    		return;
    	}
    	else if(userName.contains(" ")){
    		javax.swing.JOptionPane.showMessageDialog(null,"Username shouldn't have spaces");
    		return;
    	}
    	serverName=iGetServer.getText();
    	if(serverName.equals("")){
    		javax.swing.JOptionPane.showMessageDialog(null,"Please give a server address...");
    		return;
    	}
    	try{
    		portNo=Integer.parseInt(iGetPortNo.getText());
    	}catch(NumberFormatException e){
    		javax.swing.JOptionPane.showMessageDialog(null,e);
    	}
    	try{
    		iClient=new Socket(serverName,portNo);
    		msgFromServer=new BufferedReader(new InputStreamReader(new DataInputStream(iClient.getInputStream())));
    		msgToServer=new DataOutputStream(iClient.getOutputStream());	
    	}catch(IOException e){
    		javax.swing.JOptionPane.showMessageDialog(null,"Please enter correct server/port no.");
    	}
    	send_Message("NEWCLIENT "+userName);
		try{
			server_msg=msgFromServer.readLine();
		}catch(IOException e){
			System.out.println(e);
		}
		if(server_msg.equals("USEREXISTS")){
			javax.swing.JOptionPane.showMessageDialog(null,"Usernamr exist use another");
			return;
		}
		if(server_msg.equals("WELCOME")){
			iHandle=new InfiniteChatClientHandle();
			iHandle.setClientSocket(iClient);
			iHandle.setInputStream(msgFromServer);
			iHandle.setOutputStream(msgToServer);
			iHandle.setPortNo(portNo);
			iHandle.setServerName(serverName);
			iHandle.setUserName(userName);
			//javax.swing.JOptionPane.showMessageDialog(null,"Logged in successfully..");
			InfiniteChatClient iChat=new InfiniteChatClient(iHandle);
			iFrame.dispose();
		}
    }
    
    public void exit_iChatClient(){
    	iFrame.dispose();
    	javax.swing.JOptionPane.showMessageDialog(null,"Thank you for using e-Chat Client");
    	System.exit(0);
    }
    
    //Send message to server...
    private void send_Message(String msg){
    	try{
    		msgToServer.writeBytes(msg+"\r\n");
    	}catch(IOException e){
    		System.out.println(e);   	
    	}
    }
    
	/**
	 * Method main
	 *
	 *
	 * @param args
	 *
	 */	
	public static void main(String[] args) {
		eChatClientLogin iChat=new eChatClientLogin();
	}
}
