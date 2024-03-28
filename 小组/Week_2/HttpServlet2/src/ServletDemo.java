import jakarta.servlet.*;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;


@WebServlet(urlPatterns = {"/demo"})
public class ServletDemo extends HttpServlet {
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

    private void handleRequest(HttpServletRequest req, HttpServletResponse resp, String method) throws IOException {
        resp.setContentType("text/plain");
        PrintWriter out = resp.getWriter();

        String servletPath = req.getServletPath();
        if(!Objects.equals(servletPath, "/demo")){
            out.println("404");
            out.close();
            return;
        }

        try {
            switch (method) {
                case "GET":
                    resp.setStatus(HttpServletResponse.SC_OK); // 200 OK
                    out.println("GET request received. Status: 200 OK");
                    break;
                case "POST":
                    resp.setStatus(HttpServletResponse.SC_CREATED); // 201 Created
                    out.println("POST request received. Status: 201 Created");
                    break;
                case "PUT":
                    resp.setStatus(HttpServletResponse.SC_NO_CONTENT); // 204 No Content
                    out.println("PUT request received. Status: 204 No Content");
                    break;
                case "DELETE":
                    resp.setStatus(HttpServletResponse.SC_NO_CONTENT); // 204 No Content
                    out.println("DELETE request received. Status: 204 No Content");
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