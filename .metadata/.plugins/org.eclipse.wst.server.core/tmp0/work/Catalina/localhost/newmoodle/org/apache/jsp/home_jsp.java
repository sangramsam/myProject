/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/7.0.57
 * Generated at: 2015-05-05 13:49:00 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class home_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("<!DOCTYPE html>\r\n");
      out.write("<html>\r\n");
      out.write("<head lang=\"en\">\r\n");
      out.write("    <meta charset=\"UTF-8\">\r\n");
      out.write("    <title>Moodle</title>\r\n");
      out.write("    <link rel=\"stylesheet\" href=\"bootstrap-3.3.2-dist/css/bootstrap.min.css\">\r\n");
      out.write("    <link rel=\"stylesheet\" href=\"style.css\">\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/jquery.js\"></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/jquery.validate.min.js\"></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/validate.js\" ></script>\r\n");
      out.write("    <script src=\"bootstrap-3.3.2-dist/js/insert.js\" ></script>\r\n");
      out.write("    <link rel=\"shortcut icon\" type=\"image/x-icon\" href=\"img/picto_navigation.png\" />\r\n");
      out.write("    <style type=\"text/css\">\r\n");
      out.write("    .error\r\n");
      out.write("    {\r\n");
      out.write("    color:red:\r\n");
      out.write("    }\r\n");
      out.write("    </style>\r\n");
      out.write("</head>\r\n");
      out.write("<body>\r\n");
      out.write("\r\n");
      out.write("<nav class=\"navbar navbar-fixed-top navbar-static-top no-margin navbar-inner navbar-inverse navbar-embossed navbar-inverse \">\r\n");
      out.write("        <div class=\"navbar-header\">\r\n");
      out.write("            <button type=\"button\" class=\"navbar-toggle collapsed \" data-toggle=\"collapse\" data-target=\"#bs-itm-navbar-collapse-1\">\r\n");
      out.write("                <span class=\"sr-only \">Toggle navigation</span>\r\n");
      out.write("                <span class=\"glyphicon glyphicon-play\" style=\"color: #ffffff\"></span>\r\n");
      out.write("                <span class=\"icon-bar\"></span>\r\n");
      out.write("                <span class=\"icon-bar\"></span>\r\n");
      out.write("            </button>\r\n");
      out.write("            <a class=\"navbar-brand w\" href=\"#\"><b>ITMU Moodle<b></b></a>\r\n");
      out.write("        </div>\r\n");
      out.write("\r\n");
      out.write("        <div class=\"collapse navbar-collapse navbar-right\" id=\"bs-itm-navbar-collapse-1\">\r\n");
      out.write("            <ul class=\"nav navbar-nav\">\r\n");
      out.write("                <li rol=\"presentation\" class=\"\"><a href=\"#\">Home</a> </li>\r\n");
      out.write("                <li rol=\"presentation\"><a href=\"login.jsp\">Login</a> </li>\r\n");
      out.write("            </ul>\r\n");
      out.write("\r\n");
      out.write("        </div>\r\n");
      out.write("\r\n");
      out.write("</nav>\r\n");
      out.write("<br/><br/><br/>\r\n");
      out.write("<div class=\"container\">\r\n");
      out.write("    <div class=\"row\">\r\n");
      out.write("    <div class=\"col-md-7 pd\">\r\n");
      out.write("\r\n");
      out.write("                <img src=\"img/logo2.png\"class=\"img-responsive\" height=\"150px\" width=\"350px\">\r\n");
      out.write("        <div class=\"container\">\r\n");
      out.write("            <br/><br/>\r\n");
      out.write("        <p style=\"color:#f5f5f5; font-size: larger\" class=\"text-justify\">Awarded on 19 Feb. 2014 by Padma Vibhushan<br/>\r\n");
      out.write("            Dr. Karan Singh, Former Union Minister,selected by a process<br/>\r\n");
      out.write("            and Jury approved by Planning Commission of India HRD  <br/>(GOI) &\r\n");
      out.write("            Assocham.ITM University is a multidisciplinary <br/> university known for\r\n");
      out.write("             its quality of research and <br/>teaching across the academic  <br/>spectrum, \r\n");
      out.write("            with subjects  <br/>spanning the sciences, engineering, management, fine arts,<br/>\r\n");
      out.write("             social sciences, \r\n");
      out.write("            arts, nursing etc. </p>\r\n");
      out.write("            <script>\r\n");
      out.write("            $(function () {\r\n");
      out.write("            \t  $('[data-toggle=\"popover\"]').popover()\r\n");
      out.write("            \t})\r\n");
      out.write("            </script>\r\n");
      out.write("           <button type=\"button\" class=\"btn btn-default\" data-container=\"body\" data-toggle=\"popover\" data-placement=\"bottom\" data-content=\"Vivamus sagittis lacus vel augue laoreet rutrum faucibus.\"\">\r\n");
      out.write("  select\r\n");
      out.write("</button>\r\n");
      out.write("\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("    <div class=\"col-md-5  pull-right\">\r\n");
      out.write("        <!-- Nav tabs -->\r\n");
      out.write("        <ul class=\"nav nav-tabs\" role=\"tablist\">\r\n");
      out.write("            <li role=\"presentation\" class=\"active\"><a href=\"#home\" aria-controls=\"home\" role=\"tab\" data-toggle=\"tab\">Sign up</a></li>\r\n");
      out.write("            <li role=\"presentation\"><a href=\"#profile\" aria-controls=\"profile\" role=\"tab\" data-toggle=\"tab\">Login</a></li>\r\n");
      out.write("        </ul>\r\n");
      out.write("        <!-- Tab panes -->\r\n");
      out.write("        <div class=\"tab-content\">\r\n");
      out.write("            <div role=\"tabpanel\" class=\"tab-pane fade in active\"  id=\"home\">\r\n");
      out.write("                <div class=\"panel panel-default \" style=\"max-width: 494px;max-height: 670px\">\r\n");
      out.write("                        <div class=\"panel-body \" style=\"background-color:#2ec866\"><h4 class=\"panel-title text-center\" style=\"color: #f5f5f5\">SIGN UP</h4></div>\r\n");
      out.write("                    <div class=\"panel-body \"  >\r\n");
      out.write("                        <form class=\"form-group\" action=\"/newmoodle/student_signup\" method=\"Post\" id=\"signup\">\r\n");
      out.write("                        <div id=\"mesg\"></div>\r\n");
      out.write("                            <div class=\"form-group \">\r\n");
      out.write("                                <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter your name\" >\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-user\"></span></div>\r\n");
      out.write("                                    <input type=\"text\" class=\"form-control\" id=\"name\" name=\"name\" placeholder=\"name\">\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"text-error\" class=\"error\" for=\"name\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <div class=\"form-group \">\r\n");
      out.write("                                <div class=\"input-group input-group-sm\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter Roll no\" >\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-user\"></span></div>\r\n");
      out.write("                                    <input type=\"text\" class=\"form-control\" id=\"rollno\" name=\"rollno\" placeholder=\"Roll-No\">\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"rollno-error\" class=\"error\" for=\"rollno\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <div class=\"form-group\">\r\n");
      out.write("                                <div class=\"input-group  input-group-sm\"  data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter at least 8 character long password\">\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-lock\"></span></div>\r\n");
      out.write("                                    <input type=\"password\" class=\"form-control\" id=\"Password\" name=\"Password\" placeholder=\"password\">\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"password-error\" class=\"error\" for=\"Password\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <div class=\"form-group\">\r\n");
      out.write("                                <div class=\"input-group  input-group-sm\"  data-toggle=\"tooltip\" data-placement=\"left\" title=\"Reapeat password\">\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-lock\"></span></div>\r\n");
      out.write("                                    <input type=\"password\" class=\"form-control\" id=\"Rpassword\" name=\"Rpassword\" placeholder=\"Confirm-password\">\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"Rpassword-error\" class=\"error\" for=\"Rpassword\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <div class=\"form-group\">\r\n");
      out.write("                                <div class=\"input-group  input-group-sm\"  data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter valid email id\">\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-envelope\" ></span> </div>\r\n");
      out.write("                                    <input type=\"email\" class=\"form-control\" id=\"email\" name=\"email\" placeholder=\"email\">\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"email-error\" class=\"error\" for=\"email\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <div class=\"form-group\">\r\n");
      out.write("                                <div class=\"input-group  input-group-sm\"  data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter your course\">\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-book\"></span> </div>\r\n");
      out.write("                                    <input type=\"text\" class=\"form-control\" id=\"course\" name=\"course\" placeholder=\"Course\">\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"course-error\" class=\"error\" for=\"course\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <div class=\"form-group\">\r\n");
      out.write("                                <div class=\"input-group  input-group-sm\"  data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter your semester\">\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-book\"></span> </div>\r\n");
      out.write("                                    <input type=\"text\" class=\"form-control\" id=\"sem\" placeholder=\"semester\" name=\"sem\" >\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"sem-error\" class=\"error\" for=\"sem\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <div class=\"form-group\">\r\n");
      out.write("                                <div class=\"input-group  input-group-sm\"  data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter your Date of Bitrh\">\r\n");
      out.write("                                    <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-book\"></span> </div>\r\n");
      out.write("                                    <input type=\"date\" class=\"form-control\" id=\"DOB\" placeholder=\"DOB\"  name=\"DOB\">\r\n");
      out.write("                                </div>\r\n");
      out.write("                                <label id=\"DOB-error\" class=\"error\" for=\"DOB\"></label>\r\n");
      out.write("                            </div>\r\n");
      out.write("                                <button type=\"submit\" class=\"btn form-control btn-success navbar navbar-btn signup-btn\" value=\"sign up\" id=\"btn\">Sign Up</button>\r\n");
      out.write("                        </form>\r\n");
      out.write("                    </div>\r\n");
      out.write("                </div>\r\n");
      out.write("            </div>\r\n");
      out.write("            <div role=\"tabpanel\" class=\"tab-pane fade\" id=\"profile\">\r\n");
      out.write("                <div class=\"panel panel-default\" style=\"max-width: 474px;max-height: 480px\">\r\n");
      out.write("                <div class=\"panel-heading\" style=\"background-color: #2ec866\">\r\n");
      out.write("                    <div class=\"panel-body \" style=\"background-color:#2ec866\"><h4 class=\"panel-title text-center\" style=\"color: #f5f5f5\"><b>Login</b></h4></div>\r\n");
      out.write("                </div>\r\n");
      out.write("                <div class=\"panel-body\" >\r\n");
      out.write("                    <form class=\"form-group\"  method=\"post\" action=\"/newmoodle/login\" id=\"login\">\r\n");
      out.write("                        <div class=\"form-group\">\r\n");
      out.write("                            <div class=\"input-group input-group-lg\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter your username\">\r\n");
      out.write("                                <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-user\"></span></div>\r\n");
      out.write("                                <input type=\"text\" class=\"form-control\" name=\"username\"  id=\"username\"placeholder=\"Username\">\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <label id=\"usrname-error\" class=\"error\" for=\"username\"></label>\r\n");
      out.write("                        </div>\r\n");
      out.write("                        <div class=\"form-group\">\r\n");
      out.write("                            <div class=\"input-group input-group-lg\" data-toggle=\"tooltip\" data-placement=\"left\" title=\"please enter your password\">\r\n");
      out.write("                                <div class=\"input-group-addon\"><span class=\"glyphicon glyphicon-lock\"></span></div>\r\n");
      out.write("                                <input type=\"password\" class=\"form-control\" placeholder=\"Password\" name=\"password\" id=\"ppassword\">\r\n");
      out.write("                            </div>\r\n");
      out.write("                            <label id=\"ppassword-error\" class=\"error\" for=\"password\"></label>\r\n");
      out.write("                        </div>\r\n");
      out.write("                        <label for=\"student\" id=\"std\"><input type=\"radio\" id=\"user\" value=\"student\" name=\"user\"/>Student</label>&nbsp;&nbsp;\r\n");
      out.write("                                <label for=\"admin\" id=\"ad\"><input type=\"radio\" id=\"user\" value=\"admin\" name=\"user\"/>Admin</label>&nbsp;&nbsp;\r\n");
      out.write("                                <label for=\"faculty\" id=\"fac\"><input type=\"radio\" id=\"user\" value=\"faculty\" name=\"user\"/>Faculty</label>\r\n");
      out.write("                        <div class=\"form-group \">\r\n");
      out.write("                            <label for=\"password\" class=\"pull-right\" ><a href=\"#\"  ><small>forgot Password</small></a></label>\r\n");
      out.write("                        </div>\r\n");
      out.write("                        <input type=\"submit\" class=\"btn btn-success navbar navbar-btn signup-btn\" value=\"login\">\r\n");
      out.write("                    </form>\r\n");
      out.write("                    </div>\r\n");
      out.write("                   <script type=\"text/javascript\">\r\n");
      out.write("                       $( document ).ready(function() {\r\n");
      out.write("                           $(\"[data-toggle=tooltip]\").tooltip();\r\n");
      out.write("                       });</script>\r\n");
      out.write("                </div>\r\n");
      out.write("            </div></div>\r\n");
      out.write("\r\n");
      out.write("        </div>\r\n");
      out.write("</div></div>\r\n");
      out.write("<br/>\r\n");
      out.write("<br/>\r\n");
      out.write("<br/>\r\n");
      out.write("<br/>\r\n");
      out.write("<div class=\"container\">\r\n");
      out.write("\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"jumbotron op fnt non \"  >\r\n");
      out.write("    <div class=\"container\">\r\n");
      out.write("        <div class=\"row\">\r\n");
      out.write("        <div class=\"col-md-4\">\r\n");
      out.write("            <figure>\r\n");
      out.write("            <img src=\"img/itm1.jpg\"  height=\"150px\"class=\"img-responsive img-rounded\">\r\n");
      out.write("                <figcaption><h4 style=\"color:#ffffff\" align=\"center\">ITM UNIVERSITY <br/><small>(MG Block)</small></small></h4></figcaption>\r\n");
      out.write("            </figure>\r\n");
      out.write("        </div>\r\n");
      out.write("        <div class=\"col-md-4\">\r\n");
      out.write("            <figure>\r\n");
      out.write("                <img src=\"img/itm2.jpg\" height=\"159px\"class=\"img-responsive img-rounded\" >\r\n");
      out.write("                <figcaption><h4 style=\"color:#ffffff\" align=\"center\">ITM UNIVERSITY<br/><small>(Main Gate)</small></small></h4></figcaption>\r\n");
      out.write("            </figure>\r\n");
      out.write("        </div>\r\n");
      out.write("        <div class=\"col-md-4\">\r\n");
      out.write("            <figure>\r\n");
      out.write("            <img src=\"img/Capture1.JPG\" height=\"158px\" class=\"img-responsive img-rounded\">\r\n");
      out.write("            <figcaption><h4 style=\"color:#ffffff\" align=\"center\">ITM UNIVERSITY<br/><small>(SOB)</small></small></h4></figcaption>\r\n");
      out.write("            </figure>\r\n");
      out.write("        </div>\r\n");
      out.write("\r\n");
      out.write("</div>\r\n");
      out.write("    </div>\r\n");
      out.write("</div>\r\n");
      out.write("<br/><br/>\r\n");
      out.write("<div class=\"jumbotron op fnt non jum\"  >\r\n");
      out.write("    <div class=\"container\">\r\n");
      out.write("    <marquee><h3>Welcome to ITM University</h3></marquee>                     \r\n");
      out.write("</div>\r\n");
      out.write("</div>\r\n");
      out.write("    <br/><br/>\r\n");
      out.write("    <br/>\r\n");
      out.write("    \r\n");
      out.write("<footer class=\"site-footer\">\r\n");
      out.write("    <div class=\"container\">\r\n");
      out.write("        <div class=\"row\">\r\n");
      out.write("            <div class=\"col-md-5\">\r\n");
      out.write("                <h4>Contact Address</h4>\r\n");
      out.write("                <address style=\"color:#ffffff\">\r\n");
      out.write("                    ITM University Opp.<br/>\r\n");
      out.write("                    Sithouli Railway Station,<br/>\r\n");
      out.write("                    NH-75 Sithouli, Jhansi Road,<br/>\r\n");
      out.write("                    Gwalior, Madhya Pradesh 474001\r\n");
      out.write("                </address>\r\n");
      out.write("            </div>\r\n");
      out.write("        </div>\r\n");
      out.write("        <div class=\"bottom-footer\">\r\n");
      out.write("            <div class=\"col-md-5\">@Copyright ITM University Gwalior(MP).</div>\r\n");
      out.write("            <div class=\"col-md-7\">\r\n");
      out.write("                <ul class=\"footer-nav\">\r\n");
      out.write("                    <li><a href=\"boot.html\">Home</a> </li>\r\n");
      out.write("                    <li><a href=\"index.htm\">Index</a></li>\r\n");
      out.write("                    <li><a href=\"contact.html\">Contacts</a> </li>\r\n");
      out.write("                    <li><a href=\"Link.html\">Links</a> </li>\r\n");
      out.write("                </ul>\r\n");
      out.write("            </div>\r\n");
      out.write("        </div>\r\n");
      out.write("    </div>\r\n");
      out.write("</footer>\r\n");
      out.write("\r\n");
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