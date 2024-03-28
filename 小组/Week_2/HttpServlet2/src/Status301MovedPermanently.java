import jakarta.servlet.*;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;


@WebServlet(urlPatterns = {"/301"})
public class Status301MovedPermanently extends HttpServlet {
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
        resp.setContentType("text/html");
        PrintWriter out = resp.getWriter();

        // 发送一个包含JavaScript的HTML页面，该JavaScript代码会在3秒后重定向到/demo。
        out.println("<html><head><title>Redirecting...</title><script type='text/javascript'>");
        out.println("function delayRedirect(){");
        out.println("    setTimeout(function(){");
        out.println("        window.location.href = '/HttpServlet2_Web_exploded/demo'; // 设置你想要重定向的URL。");
        out.println("    }, 3000); // 设置延迟时间，这里是3000毫秒（即3秒）。");
        out.println("}");
        out.println("</script></head><body>");
        out.println("<h1>GET request received. Status: 301 Moved Permanently</h1>"); // 显示消息。
        out.println("<script type='text/javascript'>delayRedirect();</script>"); // 调用函数以开始延迟重定向。
        out.println("</body></html>"); // 结束HTML页面。

    }
}