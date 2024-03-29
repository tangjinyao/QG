import jakarta.servlet.*;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;


@WebServlet(urlPatterns = {"/404"})//此处如果用"/*"会导致访问不到web目录下的html文件
public class Status404NotFound extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "GET");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "POST");
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "PUT");
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp, "DELETE");
    }

    private void handleRequest(HttpServletRequest req, HttpServletResponse resp, String method) throws IOException, ServletException {
        resp.setContentType("text/plain");
        PrintWriter out = resp.getWriter();

        String requestURI = req.getRequestURI();

        //以下的重定向是无效的, 最后会导致死循环
        if (requestURI.endsWith("regist.html")) {
            resp.sendRedirect("/HttpServlet2_Web_exploded/regist.html");
            return;
        }
        if (requestURI.endsWith("login.html")) {
            resp.sendRedirect("/HttpServlet2_Web_exploded/login.html");
            return;
        }


        if(!Objects.equals(requestURI, "/HttpServlet2_Web_exploded/demo")
            && !Objects.equals(requestURI, "/HttpServlet2_Web_exploded/")
            && !Objects.equals(requestURI, "/HttpServlet2_Web_exploded/login.html")
            && !Objects.equals(requestURI, "/HttpServlet2_Web_exploded/regist.html")){
            try {
                switch (method) {
                    case "GET":
                        resp.setStatus(HttpServletResponse.SC_NOT_FOUND); // 404 Not Found
                        out.println("GET request received. Status: 404 Not Found");
                        break;
                    case "POST":
                        resp.setStatus(HttpServletResponse.SC_NOT_FOUND); // 404 Not Found
                        out.println("POST request received. Status: 404 Not Found");
                        break;
                    case "PUT":
                        resp.setStatus(HttpServletResponse.SC_NOT_FOUND); // 404 Not Found
                        out.println("PUT request received. Status: 404 Not Found");
                        break;
                    case "DELETE":
                        resp.setStatus(HttpServletResponse.SC_NOT_FOUND); // 404 Not Found
                        out.println("DELETE request received. Status: 404 Not Found");
                        break;
                    default:
                        resp.setStatus(HttpServletResponse.SC_METHOD_NOT_ALLOWED); // 405 Method Not Allowed
                        out.println("Unsupported request method. Status: 405 Method Not Allowed");
                        break;
                }
            } finally {
                out.close();
            }
        }

    }
}