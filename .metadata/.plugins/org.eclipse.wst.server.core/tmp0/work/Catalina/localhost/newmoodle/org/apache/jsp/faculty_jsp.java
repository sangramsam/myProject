/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/7.0.57
 * Generated at: 2015-05-13 20:20:39 UTC
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
import com.lms.message;

public final class faculty_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("      \r\n");
      out.write("      \r\n");
      out.write("      \r\n");
      out.write("<!DOCTYPE html>\r\n");
      out.write("<html>\r\n");
      out.write("<head lang=\"en\">\r\n");
      out.write("    <meta charset=\"UTF-8\">\r\n");
      out.write("    <title>Moodle</title>\r\n");
      out.write("    <link rel=\"stylesheet\" href=\"bootstrap-3.3.2-dist/css/bootstrap.min.css\">\r\n");
      out.write("    <meta name=\"viewport\" content=\"width=device-width,initial-scale=1\">\r\n");
      out.write("    <link rel=\"stylesheet\" href=\"style.css\">\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/jquery.js\"></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/jquery.validate.min.js\"></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/validatefac.js\" ></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/select.js\"></script>\r\n");
      out.write("       <script src=\"bootstrap-3.3.2-dist/js/addnotice.js\"></script>\r\n");
      out.write("       <script src=\"bootstrap-3.3.2-dist/js/AssignSubject.js\" type=\"text/javascript\"></script>\r\n");
      out.write("        <script src=\"bootstrap-3.3.2-dist/js/findstudent.js\" type=\"text/javascript\"></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/searchAssignSubject.js\" type=\"text/javascript\"></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/validateAssign.js\" type=\"text/javascript\"></script>\r\n");
      out.write("    <link rel=\"shortcut icon\" type=\"image/x-icon\" href=\"img/picto_navigation.png\" />\r\n");
      out.write("    \r\n");
      out.write("</head><body>\r\n");

if(null==session.getAttribute("user"))
{
	response.sendRedirect("login.jsp");
	return;
}
else
{
	List<message> mesg = null;
	mesg = (List<message>)session.getAttribute("QA");
String  username=null;
username=(String)session.getAttribute("user");
List<std> jobList = null;
jobList = (List<std>)session.getAttribute("data");
List<notice> ntlist = null;
ntlist=(List<notice>)session.getAttribute("nt");
      out.write("\r\n");
      out.write("<div class=\"row\">\r\n");
      out.write("    </div>\r\n");
      out.write("<nav class=\"navbar navbar-default navbar-inverse navbar-inner\" role=\"navigation\">\r\n");
      out.write("    <div class=\"navbar-header\">\r\n");
      out.write("       <a class=\"navbar-brand w pull-left\" href=\"#\" style=\"top:2px\"><h4><b>ITMU Moodle</b></h4></a>\r\n");
      out.write("    </div>\r\n");
      out.write("    <ul class=\"nav navbar-nav pull-right\">\r\n");
      out.write("        <li class=\"active\"><p>&nbsp;&nbsp;&nbsp;&nbsp;<b><span class=\"glyphicon glyphicon-user\"></span>");
      out.print( username.toUpperCase() );
      out.write("</b>&nbsp;&nbsp;<a  href=\"/newmoodle/logout\" class=\"btn-sm btn-default\">Logout</a></p> </li>\r\n");
      out.write("    </ul>\r\n");
      out.write("</nav>\r\n");
      out.write("\r\n");
      out.write("<div class=\"col-md-6\">\r\n");
      out.write("<div class=\"row\">\r\n");
      out.write("\r\n");
      out.write("<div class=\"btn-group-vertical\" role=\"group\" aria-label=\"...\">\r\n");
      out.write("<button type=\"button\" class=\"btn btn-default disabled\"><b>Tools</b></button>\r\n");
      out.write("<button type=\"button\" class=\"btn btn-lg btn-primary\" data-toggle=\"modal\" data-target=\".upload\"><span class=\"glyphicon glyphicon-open\"></span>&nbsp;&nbsp;Upload Study Material</button>\r\n");
      out.write("<button type=\"button\" class=\"btn btn-lg btn-warning\" data-toggle=\"modal\" data-target=\".notice\"><span class=\"glyphicon glyphicon-plus-sign\"></span>&nbsp;&nbsp;Add Notice</button>\r\n");
      out.write("<button type=\"button\" class=\"btn btn-lg btn-danger\" data-toggle=\"modal\" data-target=\".question\"><span class=\"glyphicon glyphicon-plus-sign\"></span>&nbsp;&nbsp;Question & Answer</button>\r\n");
      out.write("<button type=\"button\" class=\"btn btn-lg btn-success\" data-toggle=\"modal\" data-target=\".assignsubject\"><span class=\"glyphicon glyphicon-plus-sign\"></span>&nbsp;&nbsp;Assign Subject</button>\r\n");
      out.write("</div>\r\n");
      out.write("&nbsp;&nbsp;&nbsp;&nbsp;\r\n");
      out.write("<div class=\"btn-group-vertical\" role=\"group\" aria-label=\"...\">\r\n");
      out.write("<button type=\"button\" class=\"btn btn-default disabled\"><b>Search</b></button>\r\n");
      out.write("<button type=\"button\" class=\"btn btn-lg btn-primary\" data-toggle=\"modal\" data-target=\".searchstudent\"><span class=\"glyphicon glyphicon-open\"></span>&nbsp;&nbsp;Search Student</button>\r\n");
      out.write("<button type=\"button\" class=\"btn btn-lg btn-warning\" data-toggle=\"modal\" data-target=\".searchAssign\"><span class=\"glyphicon glyphicon-plus-sign\"></span>&nbsp;&nbsp;Search Assign Subject</button>\r\n");
      out.write("\r\n");
      out.write("</div>\r\n");
      out.write("</div>\r\n");
      out.write("</div>\r\n");
      out.write("\r\n");
      out.write("<script>\r\n");
      out.write("            $(function () {\r\n");
      out.write("            \t  $('[data-toggle=\"popover\"]').popover();\r\n");
      out.write("            \t  //$('#message').attr(\"data-content\",\"sangram singh\");\r\n");
      out.write("            \t});\r\n");
      out.write("            </script>\r\n");
      out.write("            <div class=\"modal fade searchAssign\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myLargeModalLabel\" aria-hidden=\"true\">\r\n");
      out.write("    <div class=\"modal-dialog modal-lg\">\r\n");
      out.write("        <div class=\"modal-content\">\r\n");
      out.write("            <h4 style=\"color: #2ec866\"><b>Search Assign Subject </b></h4>\r\n");
      out.write("            <div class=\"login-form\">\r\n");
      out.write("                <form class=\"form-group\" method=\"get\" action=\"/newmoodle/searchAssignSubject\" id=\"searchassign\">\r\n");
      out.write("                    <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Select Branch\">\r\n");
      out.write("                        <select class=\"form-control\" id=\"sfcourse\" name=\"sfcourse\" required>\r\n");
      out.write("                            <option selected value=\"\">Select Branch</option>\r\n");
      out.write("                            <option value=\"mca\">MCA</option>\r\n");
      out.write("                            <option value=\"bca\">BCA</option>\r\n");
      out.write("                        </select>\r\n");
      out.write("                        <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-triangle-left\"></span></div>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <label id=\"scourses-error\" class=\"error\" for=\"sfcourse\"></label>\r\n");
      out.write("                    <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Enter Subject Code\">\r\n");
      out.write("                        <input type=\"text\" class=\"form-control\" name=\"scode\" placeholder=\"Enter Subject Code(E.g MCA-405)\" id=\"scode\" required>\r\n");
      out.write("                        <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-user\"></span></div>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <label id=\"scode-error\" class=\"error\" for=\"scode\"></label>\r\n");
      out.write("                    <br/>\r\n");
      out.write("                    <button type=\"submit\" class=\"btn btn-success  pull-right\">Search</button>\r\n");
      out.write("                    <div id=\"ssubject\" style=\"color:red\"></div>\r\n");
      out.write("                </form>\r\n");
      out.write("            </div>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"modal fade searchstudent\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myLargeModalLabel\" aria-hidden=\"true\">\r\n");
      out.write("    <div class=\"modal-dialog modal-lg\">\r\n");
      out.write("        <div class=\"modal-content\">\r\n");
      out.write("            <h4 style=\"color: #2ec866\"><b>Search Student </b></h4>\r\n");
      out.write("            <div class=\"login-form\">\r\n");
      out.write("                <form class=\"form-group\" method=\"get\" action=\"/newmoodle/findstudent\" id=\"searchstudent\" >\r\n");
      out.write("                    <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Select Branch\">\r\n");
      out.write("                        <select class=\"form-control\" id=\"scourse\" name=\"scourse\" required>\r\n");
      out.write("                            <option selected value=\"\">Select Branch</option>\r\n");
      out.write("                            <option value=\"mca\">MCA</option>\r\n");
      out.write("                            <option value=\"bca\">BCA</option>\r\n");
      out.write("                        </select>\r\n");
      out.write("                        <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-triangle-left\"></span></div>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <label id=\"scourse-error\" class=\"error\" for=\"scourse\"></label>\r\n");
      out.write("                    <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Enter Student Name\">\r\n");
      out.write("                        <input type=\"text\" class=\"form-control\" name=\"sname\" placeholder=\"Enter Student Name\" id=\"sname\" required>\r\n");
      out.write("                        <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-user\"></span></div>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <label id=\"sname-error\" class=\"error\" for=\"sname\"></label>\r\n");
      out.write("                    <br/>\r\n");
      out.write("                    <button type=\"submit\" class=\"btn btn-success  pull-right\">Search</button>\r\n");
      out.write("                   \r\n");
      out.write("                </form>\r\n");
      out.write("            </div>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("</div>\r\n");
      out.write("            <div class=\"modal fade assignsubject\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myLargeModalLabel\" aria-hidden=\"true\">\r\n");
      out.write("    <div class=\"modal-dialog modal-lg\">\r\n");
      out.write("        <div class=\"modal-content\">\r\n");
      out.write("            <h4 style=\"color: #2ec866\"><b>Assign Subject & Faculty</b></h4>\r\n");
      out.write("            <div class=\"login-form\">\r\n");
      out.write("                <form class=\"form-group\" method=\"post\" action=\"/newmoodle/AssignSubject\" id=\"assign\" >\r\n");
      out.write("                    <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Enter FacultyId\">\r\n");
      out.write("                        <input type=\"text\" class=\"form-control\" name=\"facid\" placeholder=\"facultyid\" id=\"facid\" >\r\n");
      out.write("                        <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-user\"></span></div>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <label id=\"facid-error\" class=\"error\" for=\"facid\"></label>\r\n");
      out.write("                        <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Enter Subject Name\">\r\n");
      out.write("                            <input type=\"text\" class=\"form-control\" placeholder=\"SubjectName\" id=\"subname\" name=\"subname\">\r\n");
      out.write("                            <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-flash\"></span></div>\r\n");
      out.write("                        </div>\r\n");
      out.write("                    <label id=\"subname-error\" class=\"error\" for=\"subname\"></label>\r\n");
      out.write("\r\n");
      out.write("                        <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Enter SubjectId\">\r\n");
      out.write("                            <input type=\"text\" class=\"form-control\" placeholder=\"Subject Id\" id=\"subid\" name=\"subid\">\r\n");
      out.write("                            <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-asterisk\"></span></div>\r\n");
      out.write("                        </div>\r\n");
      out.write("\r\n");
      out.write("                    <label id=\"subid-error\" class=\"error\" for=\"subid\"></label>\r\n");
      out.write("\r\n");
      out.write("                        <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Enter Branch\">\r\n");
      out.write("                            <input type=\"text\" class=\"form-control\" placeholder=\"Branch\" id=\"branch\" name=\"branch\">\r\n");
      out.write("                            <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-pencil\"></span></div>\r\n");
      out.write("                        </div>\r\n");
      out.write("\r\n");
      out.write("                    <label id=\"branch-error\" class=\"error\" for=\"branch\"></label>\r\n");
      out.write("                        <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"Please Select Semester\">\r\n");
      out.write("                            <select class=\"form-control\" id=\"semester\" name=\"semester\">\r\n");
      out.write("                                <option selected value=\"\">Select Semester</option>\r\n");
      out.write("                                <option value=\"1\">1</option>\r\n");
      out.write("                                <option value=\"2\">2</option>\r\n");
      out.write("                                <option value=\"3\">3</option>\r\n");
      out.write("                                <option value=\"4\">4</option>\r\n");
      out.write("                                <option value=\"5\">5</option>\r\n");
      out.write("                                <option value=\"6\">6</option>\r\n");
      out.write("                                <option value=\"7\">7</option>\r\n");
      out.write("                                <option value=\"8\">8</option>\r\n");
      out.write("                            </select>\r\n");
      out.write("                            <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-triangle-left\"></span></div>\r\n");
      out.write("                        </div>\r\n");
      out.write("\r\n");
      out.write("                    <label id=\"sem-error\" class=\"error\" for=\"semester\"></label><br/>\r\n");
      out.write("                    <button type=\"submit\" class=\"btn btn-success  center-block\">Assign</button>\r\n");
      out.write("\t\t\t\t\t<div id=\"resmesg\" style=\"color:red\"></div>\r\n");
      out.write("                </form>\r\n");
      out.write("            </div>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"modal fade notice\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myLargeModalLabel\" aria-hidden=\"true\">\r\n");
      out.write("    <div class=\"modal-dialog modal-lg \">\r\n");
      out.write("        <div class=\"modal-content\">\r\n");
      out.write("            <div class=\"login-form\">\r\n");
      out.write("                <form class=\"form-group\" method=\"post\" action=\"/newmoodle/Addnotice\" id=\"add\">\r\n");
      out.write("\r\n");
      out.write("                    <textarea class=\"form-control\" name=\"notice\" cols=\"50\" rows=\"5\" placeholder=\"Type your notice here\" id=\"notice\"></textarea>\r\n");
      out.write("\r\n");
      out.write("                    <label for=\"username\"></label>\r\n");
      out.write("\r\n");
      out.write("                    <br/>\r\n");
      out.write("                    <button class=\"btn btn-primary btn-lg center-block \" type=\"submit\">Add</button>\r\n");
      out.write("                    <div id=mesg></div>\r\n");
      out.write("                </form>\r\n");
      out.write("            </div>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("</div>\r\n");
      out.write("\r\n");
      out.write("<div class=\"modal fade upload\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myLargeModalLabel\" aria-hidden=\"true\">\r\n");
      out.write("  <div class=\"modal-dialog modal-lg\">\r\n");
      out.write("    <div class=\"modal-content\">\r\n");
      out.write("      <div class=\"panel panel-default\" style= \"max-height:590px;max-width:4900px; position:relative ;\">\r\n");
      out.write("        <div class=\"panel panel-heading\" style=\"background-color:#16A085\"><h4 style=\"text-align: center;color: snow\">Upload</h4></div>\r\n");
      out.write("        <div class=\"panel-body\">\r\n");
      out.write("            <form enctype=\"multipart/form-data\" action=\"addfile\" method=\"post\" id=\"faculty\">\r\n");
      out.write("                <div class=\"form-horizontal\">\r\n");
      out.write("                    <div class=\"form-group\">\r\n");
      out.write("                    <label for=âcourseâ style=\"color: #000000;\">Course</label>\r\n");
      out.write("                        <select  id=\"course\" class=\"form-control\" name=\"course\">\r\n");
      out.write("                            <option selected value=\"\">Select your Course</option>\r\n");
      out.write("                            <option>mca</option>\r\n");
      out.write("                            <option>bca</option>\r\n");
      out.write("                        </select>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <div class=\"form-group\">\r\n");
      out.write("                        <label for=âsemâ style=\"color: #000000;\">Sem</label>\r\n");
      out.write("                        <select  id=\"sem\" class=\" form-control\" name=\"sem\">\r\n");
      out.write("                            <option selected value=\"\">Select your semester</option>\r\n");
      out.write("                             <option value=\"1\">1</option>\r\n");
      out.write("                             <option value=\"2\">2</option>\r\n");
      out.write("                             <option value=\"3\">3</option>\r\n");
      out.write("                             <option value=\"4\">4</option>\r\n");
      out.write("                             <option value=\"5\">5</option>\r\n");
      out.write("                             <option value=\"6\">6</option>\r\n");
      out.write("                        </select>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <div class=\"form-group\">\r\n");
      out.write("                        <label for=âsubjectâ style=\"color: #000000;\">Subject</label>\r\n");
      out.write("                        <select id=\"subject\" name=\"subject\" class=\" form-control \">\r\n");
      out.write("                            <option selected value=\"\">Select your subject</option>\r\n");
      out.write("                        </select>\r\n");
      out.write("                    </div>\r\n");
      out.write("                    <label for=âuploadâ style=\"color: #000000;\">Upload</label>\r\n");
      out.write("                    <div class=\"form-group\">\r\n");
      out.write("                        <input type=\"file\" class=\"form-control\" placeholder=\"upload ur file\" name=\"upload\" id=\"upload\">\r\n");
      out.write("                    </div>\r\n");
      out.write("        <div class=\"form-group\">\r\n");
      out.write("            <input type=\"submit\" value=\"Upload\" class=\" btn btn-danger\">\r\n");
      out.write("        </div>\r\n");
      out.write("</div>\r\n");
      out.write("            </form>\r\n");
      out.write("</div>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("    </div>\r\n");
      out.write("  </div>\r\n");
      out.write("  <div class=\"modal fade question\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myLargeModalLabel\" aria-hidden=\"true\">\r\n");
      out.write("  <div class=\"modal-dialog modal-lg\">\r\n");
      out.write("    <div class=\"modal-content\">\r\n");
      out.write("      <div class=\"panel panel-default\">\r\n");
      out.write("      <form method=\"post\" action=\"/newmoodle/reply\" id=\"re\">\r\n");
      out.write("      \t\t\t\t");
if(mesg.isEmpty())
      					{
      out.write("\r\n");
      out.write("      \t\t\t\t\t<div class=\"panel-body\">\r\n");
      out.write("      \t\t\t\t\t <div class=\"form-group\">\r\n");
      out.write("                    <div class=\"well\">\r\n");
      out.write("                    <p> <h2>Opps !!!!</h2> no new mesg </p>\r\n");
      out.write("                    </div></div>\r\n");
      out.write("                    </div>\r\n");
      out.write("      \t\t\t\t\t");
 }
      					else 
      					{
                 for(message m:mesg)
            	 {
            	 
      out.write("\r\n");
      out.write("            \t <div class=\"panel-body\" id=\"");
      out.print(m.getQuestion());
      out.write("\" >\r\n");
      out.write("                <div class=\"form-group\">\r\n");
      out.write("                    <div class=\"well\">\r\n");
      out.write("                    <p><b>Question ?</b></p>\r\n");
      out.write("                    <p class=\"pull-left\">");
      out.print(m.getQuestion() );
      out.write("</p>\r\n");
      out.write("                    <p class=\"pull-right\" style=\"text-align:right\"><small>From:");
      out.print(m.getName() );
      out.write("</small>(");
      out.print(m.getBranch() );
      out.write(")</p>\r\n");
      out.write("                    </div>\r\n");
      out.write("                </div>\r\n");
      out.write("                <div class=\"form-group\">\r\n");
      out.write("                    <textarea cols=\"50\" rows=\"2\" class=\"form-control\" placeholder=\"Type Your answer Here \" name=\"");
      out.print(m.getNo() );
      out.write("\" id=\"");
      out.print(m.getNo());
      out.write("\"></textarea>\r\n");
      out.write("                </div>\r\n");
      out.write("                <div class=\"form-group\">\r\n");
      out.write("                    <button  id=\"");
      out.print(m.getName() );
      out.write("\" class=\" btn btn-danger pull-right\" value=\"Reply\">Reply</button>\r\n");
      out.write("                </div>\r\n");
      out.write("                <div id=\"mee\" style=\"color:red\"></div>\r\n");
      out.write("            <div class=\"divider\"></div>\r\n");
      out.write("            </div>\r\n");
      out.write("            \r\n");
      out.write("            </form>\r\n");
      out.write("            <script type=\"text/javascript\">\r\n");
      out.write("\t\t\t$(\"documemt\").ready(function()\r\n");
      out.write("\t\t\t{\r\n");
      out.write("\t\t\t\tvar reply=document.getElementById(\"");
      out.print(m.getName());
      out.write("\");\r\n");
      out.write("\t\t\t\tvar sname=\"");
      out.print(username);
      out.write("\";\r\n");
      out.write("\t\t\t\t var scourse=\"");
      out.print(m.getBranch());
      out.write("\";\r\n");
      out.write("\t\t\t\t var sto=\"");
      out.print(m.getName());
      out.write("\";\r\n");
      out.write("\t\t\t\t var idd=document.getElementById(\"");
      out.print(m.getNo());
      out.write("\");\r\n");
      out.write("\t\t\t\t var ques=document.getElementById(\"");
      out.print(m.getQuestion());
      out.write("\");\r\n");
      out.write("\t\t\t\t console.log(idd);\r\n");
      out.write("\t\t\t$(reply).click(function()\r\n");
      out.write("\t\t\t\t{\r\n");
      out.write("\t\t\t$.ajax({\r\n");
      out.write("\t\t\t\ttype:\"POST\",\r\n");
      out.write("\t\t\t\turl:\"reply\",\r\n");
      out.write("\t\t\t\tdata:{\r\n");
      out.write("\t\t\t\t\tname :sname,\r\n");
      out.write("\t\t\t\t\tcourse :scourse,\r\n");
      out.write("\t\t\t\t\tto :sto,\r\n");
      out.write("\t\t\t\t\tanswer :$(idd).val()\r\n");
      out.write("\t\t\t\t},\r\n");
      out.write("\t\t\t\tsuccess:function(mesg)\r\n");
      out.write("\t\t\t\t{\r\n");
      out.write("\t\t\t\t\tif(mesg==\"Message Successfully send\")\r\n");
      out.write("\t\t\t\t\t\t{\r\n");
      out.write("\t\t\t\t\t\t$(ques).hide();\r\n");
      out.write("\t\t\t\t\t\t\r\n");
      out.write("\t\t\t\t\t\t}\r\n");
      out.write("\t\t\t\t\telse\r\n");
      out.write("\t\t\t\t\t\t{\r\n");
      out.write("\t\t\t\t\t\t$('#mee').text(mesg).slideDown(1000);\r\n");
      out.write("\t\t\t\t\t\t}\r\n");
      out.write("\t\t\t\t},\r\n");
      out.write("\t\t\t});\r\n");
      out.write("\t\t\treturn false;\r\n");
      out.write("\t\t\t\t});\r\n");
      out.write("\t\t});\r\n");
      out.write("</script>\r\n");
      out.write("\r\n");
      out.write("  ");
} 
      out.write("\r\n");
      out.write("  ");
} 
      out.write("\r\n");
      out.write("  \r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("  </div>\r\n");
      out.write("</div>\r\n");
      out.write("    <div class=\"col-md-6\">\r\n");
      out.write("        <div class=\"panel panel-default\" style= \"height:185px;\">\r\n");
      out.write("            <div class=\"panel-heading\" style=\" background-color:#16A085;color:whitesmoke\"><b>Notice & Announcement</b></div>\r\n");
      out.write("            <div class=\"pannel-body\" style=\"color:black\">\r\n");
      out.write("             <marquee direction=\"left\">\r\n");
      out.write("             ");
 for(notice n:ntlist)
            	 {
            	 
      out.write("\r\n");
      out.write("             <p><b> ");
      out.print( n.getContent() );
      out.write("</b></p>\r\n");
      out.write("             ");
} 
      out.write("\r\n");
      out.write("             </marquee>\r\n");
      out.write("        </div>\r\n");
      out.write("        </div>\r\n");
      out.write("         \r\n");
      out.write("    </div>\r\n");
      out.write(" <hr/>\r\n");
      out.write(" <table class=\"table table-bordered hide table-hover table-condensed table-reponsive\" id=\"tdsub\" style=\"background-color:white\">\r\n");
      out.write("<tr>\r\n");
      out.write("<th class=\"success\">SUBJECT-NAME</th>\r\n");
      out.write("<th class=\"success\">SUBJECT-CODE</th>\r\n");
      out.write("<th class=\"success\">COURSE</th>\r\n");
      out.write("<th class=\"success\">FACULTYID</th>\r\n");
      out.write("<th class=\"success\">SEMESTER</th>\r\n");
      out.write("<th class=\"success\">FACULTYNAME</th>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</tr>\r\n");
      out.write("</table>\r\n");
      out.write("<table class=\"table table-bordered hide table-hover table-condensed table-reponsive\" id=\"tds\" style=\"background-color:white\">\r\n");
      out.write("<tr>\r\n");
      out.write("<th class=\"success\">NAME</th>\r\n");
      out.write("<th class=\"success\">ROLL NO.</th>\r\n");
      out.write("<th class=\"success\">EMAIL</th>\r\n");
      out.write("<th class=\"success\">DOB</th>\r\n");
      out.write("<th class=\"success\">COURSE</th>\r\n");
      out.write("<th class=\"success\">SEMESTER</th>\r\n");
      out.write("<th class=\"success\">PASSWORD</th>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</tr>\r\n");
      out.write("</table>\r\n");
} 
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/bootstrap.min.js\"></script>\r\n");
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