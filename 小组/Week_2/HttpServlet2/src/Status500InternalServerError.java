import jakarta.servlet.*;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;


@WebServlet(urlPatterns = {"/500"})
public class Status500InternalServerError extends HttpServlet {
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

        resp.setStatus(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);//500 Inter Server Error

        try {
            switch (method) {
                case "GET":
                    out.println("GET request received. Status: 500 Inter Server Error");
                    break;
                case "POST":
                    out.println("POST request received. Status: 500 Inter Server Error");
                    break;
                case "PUT":
                    out.println("PUT request received. Status: 500 Inter Server Error");
                    break;
                case "DELETE":
                    out.println("DELETE request received. Status: 500 Inter Server Error");
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