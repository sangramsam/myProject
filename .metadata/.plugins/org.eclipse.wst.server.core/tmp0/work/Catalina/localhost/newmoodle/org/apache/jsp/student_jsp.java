/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/7.0.57
 * Generated at: 2015-05-11 17:18:25 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.util.*;
import com.lms.std;
import com.lms.notice;
import com.lms.ansbbean;

public final class student_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  private javax.el.ExpressionFactory _el_expressionfactory;
  private org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public void _jspInit() {
    _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
    _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
        throws java.io.IOException, javax.servlet.ServletException {

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html; charset=ISO-8859-1");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write("\r\n");
      out.write("    \r\n");
      out.write("    \r\n");
      out.write("    \r\n");
      out.write("    \r\n");
      out.write("<!DOCTYPE html>\r\n");
      out.write("<html>\r\n");
      out.write("<head lang=\"en\">\r\n");
      out.write("    <meta charset=\"UTF-8\">\r\n");
      out.write("    <title>Student</title>\r\n");
      out.write("    <link rel=\"stylesheet\" href=\"bootstrap-3.3.2-dist/css/bootstrap.min.css\">\r\n");
      out.write("    <link rel=\"stylesheet\" href=\"style.css\">\r\n");
      out.write("    <link rel=\"shortcut icon\" type=\"image/x-icon\" href=\"img/picto_navigation.png\" />\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/jquery.js\"></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/insertquestion.js\"></script>\r\n");
      out.write("    \r\n");
      out.write("</head>\r\n");
      out.write("<body>\r\n");

if(null==session.getAttribute("user"))
{
	response.sendRedirect("login.jsp");
	return;
}
else
{
String  username=null;
username=(String)session.getAttribute("user");
List<ansbbean> answer=null;
answer=(List<ansbbean>)session.getAttribute("answer");
List<std> jobList = null;
jobList = (List<std>)session.getAttribute("data");
List<notice> ntlist = null;
ntlist=(List<notice>)session.getAttribute("nt");

      out.write('\r');
      out.write('\n');
 //ArrayList<std> output = (ArrayList<std>)session.getAttribute("list");
//int siz=output.size();
      out.write("\r\n");
      out.write("<nav class=\"navbar navbar-fixed-top  no-margin navbar-inner navbar-default navbar-inverse \">\r\n");
      out.write("    <div class=\"container-fluid\">\r\n");
      out.write("        <div class=\"navbar-header\">\r\n");
      out.write("            <button type=\"button\" class=\"navbar-toggle collapsed \" data-toggle=\"collapse\" data-target=\"#bs-itm-navbar-collapse-1\">\r\n");
      out.write("                <span class=\"sr-only \">Toggle navigation</span>\r\n");
      out.write("                <span class=\"glyphicon glyphicon-play\" style=\"color: #ffffff\"></span>\r\n");
      out.write("                <span class=\"icon-bar\"></span>\r\n");
      out.write("                <span class=\"icon-bar\"></span>\r\n");
      out.write("            </button>\r\n");
      out.write("            <a class=\"navbar-brand w\" href=\"#\"><h3><b>ITMU Moodle</b></h3></a>\r\n");
      out.write("        </div>\r\n");
      out.write("\r\n");
      out.write("        <div class=\"collapse navbar-collapse navbar-right\" id=\"bs-itm-navbar-collapse-1\">\r\n");
      out.write("            <ul class=\"nav navbar-nav\">\r\n");
      out.write("\r\n");
      out.write("                <li rol=\"presentation\" class=\"active\"><p><span class=\"glyphicon glyphicon-user\"></span>");
      out.print(username.toUpperCase() );
      out.write("&nbsp;&nbsp;&nbsp;<a href=\"/newmoodle/logout\" class=\"btn-sm btn-default\">Logout</a></p></li>\r\n");
      out.write("               \r\n");
      out.write("</ul>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("</nav>\r\n");
      out.write("<br/><br/><br/><br/>\r\n");
      out.write("<div class=\"col-md-6\">\r\n");
      out.write('\r');
      out.write('\n');
      out.write("\r\n");
      out.write("<!--     <div class=\"well\" style=\"background-color:lightyellow\"> -->\r\n");
      out.write('\r');
      out.write('\n');
      out.write('\r');
      out.write('\n');
      out.write("\r\n");
      out.write("<!--     </div><br/> -->\r\n");
      out.write("\r\n");
      out.write("   <div class=\"panel-group\" id=\"accordion\" role=\"tablist\" aria-multiselectable=\"true\">\r\n");
      out.write("   ");
 for(std d: jobList)
  {
      out.write("\r\n");
      out.write("  <div class=\"panel panel-default\">\r\n");
      out.write("    <div class=\"panel-heading\" role=\"tab\" id=\"");
      out.print(d.getSubjectname() );
      out.write("\">\r\n");
      out.write("      <h4 class=\"panel-title\">\r\n");
      out.write("        <a class=\"collapsed\" data-toggle=\"collapse\" data-parent=\"#accordion\" href=\"#");
      out.print(d.getSubject_id());
      out.write("\" aria-expanded=\"false\" aria-controls=\"");
      out.print(d.getSubject_id());
      out.write("\">\r\n");
      out.write("         <span class=\"glyphicon glyphicon-triangle-right\"></span><b>");
      out.print(d.getSubjectname().toUpperCase() );
      out.write("</b>\r\n");
      out.write("        </a>\r\n");
      out.write("      </h4>\r\n");
      out.write("    </div>\r\n");
      out.write("    <div id=\"");
      out.print(d.getSubject_id());
      out.write("\" class=\"panel-collapse collapse collapse\" role=\"tabpanel\" aria-labelledby=\"");
      out.print(d.getSubjectname() );
      out.write("\">\r\n");
      out.write("      <div class=\"panel-body\">\r\n");
      out.write("        <p style=\"color:black\">Faculty Name &nbsp;&nbsp;&nbsp;<b>");
      out.print(d.getFacultyname().toUpperCase());
      out.write("</b></p>\r\n");
      out.write("        <p style=\"color:black\">Subject-Code &nbsp;&nbsp;&nbsp;<b>");
      out.print(d.getSubject_id().toUpperCase() );
      out.write("</b></p>\r\n");
      out.write("        <p style=\"color:black\"><a style=\"color:black;\" href='/newmoodle/list_file?name=+");
      out.print(d.getSubject_id());
      out.write("+'>Download material</a></p>\r\n");
      out.write("      </div>\r\n");
      out.write("    </div>\r\n");
      out.write("  </div>\r\n");
      out.write("  ");
} 
      out.write("\r\n");
      out.write("   </div>\r\n");
      out.write("   <button type=\"button\" class=\"btn btn-lg btn-primary\" data-toggle=\"modal\" data-target=\".question\"><span class=\"glyphicon glyphicon-plus-sign\"></span>&nbsp;&nbsp;Question & Answer</button>\r\n");
      out.write("   <div class=\"modal fade question\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myLargeModalLabel\" aria-hidden=\"true\">\r\n");
      out.write("            <div class=\"modal-dialog modal-lg\">\r\n");
      out.write("                <div class=\"modal-content\">\r\n");
      out.write("        <div class=\"panel panel-default\">\r\n");
      out.write("              <div class=\"panel-heading\">ANSWER</div>\r\n");
      out.write("             \r\n");
      out.write("            ");
if(answer.isEmpty())
      					{
      out.write("\r\n");
      out.write("      \t\t\t\t\t<div class=\"panel-body\">\r\n");
      out.write("      \t\t\t\t\t <div class=\"form-group\">\r\n");
      out.write("                    <div class=\"well\">\r\n");
      out.write("                    <p> <h2>Opps !!!!</h2> no new mesg</p>\r\n");
      out.write("                    </div></div>\r\n");
      out.write("                    </div>\r\n");
      out.write("      \t\t\t\t\t");
 }
      					else 
      					{
               for(ansbbean ans:answer)
            	   {
				
      out.write("\r\n");
      out.write("            \t   <div class=\"panel-body\">\r\n");
      out.write("            \t    <form method=\"post\" action=\"/newmoodle/markeasread\">\r\n");
      out.write("                    <div class=\"well\" id=\"");
      out.print(ans.getReply_date());
      out.write("\">\r\n");
      out.write("                        <p class=\"pull-right\"><b>");
      out.print( ans.getReply_by());
      out.write(" </b>(<small>");
      out.print(ans.getReply_date() );
      out.write("</small>)</p>\r\n");
      out.write("                        <p style=\"color:blue\">");
      out.print( ans.getAnswer());
      out.write("</p>\r\n");
      out.write("                       <button  id=\"");
      out.print(ans.getReply_no() );
      out.write("\" value=\"make as read\" class=\" btn btn-success pull-right btn-sm\">Mark As Read</button>\r\n");
      out.write("                        </div>\r\n");
      out.write("                        <div id=\"mesgn\" style=\"color:red\"></div>\r\n");
      out.write("                        </form>\r\n");
      out.write("       \r\n");
      out.write("                        <script type=\"text/javascript\">\r\n");
      out.write("\t\t\t$(\"documemt\").ready(function()\r\n");
      out.write("\t\t\t{\r\n");
      out.write("\t\t\t\tvar reply=document.getElementById(\"");
      out.print(ans.getReply_no());
      out.write("\");\r\n");
      out.write("\t\t\t\tvar toname=\"");
      out.print(username);
      out.write("\";\r\n");
      out.write("\t\t\t\t var rn=\"");
      out.print(ans.getReply_no());
      out.write("\";\r\n");
      out.write("\t\t\t\t var rnn=document.getElementById(\"");
      out.print(ans.getReply_date());
      out.write("\");\r\n");
      out.write("\t\t\t$(reply).click(function()\r\n");
      out.write("\t\t\t\t{\r\n");
      out.write("\t\t\t$.ajax({\r\n");
      out.write("\t\t\t\ttype:\"POST\",\r\n");
      out.write("\t\t\t\turl:\"markasread\",\r\n");
      out.write("\t\t\t\tdata:{\r\n");
      out.write("\t\t\t\t\tname :toname,\r\n");
      out.write("\t\t\t\t\treplyno :rn,\r\n");
      out.write("\t\t\t\t},\r\n");
      out.write("\t\t\t\tsuccess:function(mesg)\r\n");
      out.write("\t\t\t\t{\r\n");
      out.write("\t\t\t\t\tif(mesg==\"success\")\r\n");
      out.write("\t\t\t\t\t\t{\r\n");
      out.write("\t\t\t\t\t\t$(rnn).hide();\r\n");
      out.write("\t\t\t\t\t\t}\r\n");
      out.write("\t\t\t\t\telse\r\n");
      out.write("\t\t\t\t\t\t{\r\n");
      out.write("\t\t\t\t\t\t$('#mesgn').text(mesg).slideDown(1000);\r\n");
      out.write("\t\t\t\t\t\t}\r\n");
      out.write("\t\t\t\t},\r\n");
      out.write("\t\t\t});\r\n");
      out.write("\t\t\treturn false;\r\n");
      out.write("\t\t\t\t});\r\n");
      out.write("\t\t});\r\n");
      out.write("</script>\r\n");
      out.write("                        </div>\r\n");
      out.write("                    ");
} 
      out.write("\r\n");
      out.write("                    ");
} 
      out.write("\r\n");
      out.write("            \r\n");
      out.write("        \r\n");
      out.write("    </div>\r\n");
      out.write("     </div>\r\n");
      out.write("            </div>\r\n");
      out.write("            </div>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"col-md-6\">\r\n");
      out.write("    <div class=\"panel panel-danger panel-default \" style=\"height: 240px;width: 600px;\">\r\n");
      out.write("            <div class=\"panel-heading\" style=\" background-color:#16A085;color:whitesmoke\"><b>Notice & Announcement</b></div>\r\n");
      out.write("            <div class=\"pannel-body\" style=\"color:black\">\r\n");
      out.write("             <marquee direction=\"left\">\r\n");
      out.write("             ");
 for(notice n:ntlist)
            	 {
            	 
      out.write("\r\n");
      out.write("             <p><b> ");
      out.print(n.getContent() );
      out.write("</b></p>\r\n");
      out.write("             ");
} 
      out.write("\r\n");
      out.write("             </marquee>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("    \r\n");
      out.write("   \r\n");
      out.write("    <div class=\"panel panel-default\" style=\"height: 240px;width: 600px;\">\r\n");
      out.write("        <div class=\"panel-body\">\r\n");
      out.write("        <form method=\"post\" class=\"form-group\" action=\"/newmoodle/question\" id=\"question\">\r\n");
      out.write("    <div class=\"form-group\">\r\n");
      out.write("        <textarea cols=\"50\" rows=\"5\" class=\"form-control\" placeholder=\"Ask Question ?\" name=\"ques\" id=\"ques\"></textarea>\r\n");
      out.write("    </div>\r\n");
      out.write("    <div class=\"form-group\">\r\n");
      out.write("        <select id=\"name\" name=\"name\" class=\" form-control\">\r\n");
      out.write("            <option selected value=\"\">Select Faculty Name</option>\r\n");
      out.write("            ");
 for(std p:jobList)
            	 {
            	 
      out.write("\r\n");
      out.write("             <option value=\"");
      out.print(p.getFacultyname() );
      out.write('"');
      out.write('>');
      out.print(p.getFacultyname() );
      out.write("</option>\r\n");
      out.write("             ");
} 
      out.write("\r\n");
      out.write("          </select>\r\n");
      out.write("    </div>\r\n");
      out.write("    <div class=\"form-group\">\r\n");
      out.write("        <button type=\"submit\" class=\" btn btn-danger pull-right\" value=\"Ask Question ?\"> Ask Question ?</button>\r\n");
      out.write("    </div>\r\n");
      out.write("    <div id=\"mesg\" style=\"color:red\"></div>\r\n");
      out.write("    </form>\r\n");
      out.write("        </div>\r\n");
      out.write("</div>\r\n");
      out.write("</div>\r\n");
      out.write(" ");
} 
      out.write("\r\n");
      out.write("\r\n");
      out.write("<script src=\"bootstrap-3.3.2-dist/js/bootstrap.min.js\"></script>\r\n");
      out.write("</body>\r\n");
      out.write("</html>");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try {
            if (response.isCommitted()) {
              out.flush();
            } else {
              out.clearBuffer();
            }
          } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
