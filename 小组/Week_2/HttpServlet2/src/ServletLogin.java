/**
 * 在控制台展示登录时输入的
 */

import jakarta.servlet.*;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;
import java.util.Set;

@WebServlet(urlPatterns = "/ServletLogin")
public class ServletLogin extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Map<String, String[]> parameterMap = request.getParameterMap();
        Set<String> keyset = parameterMap.keySet();
        for (String name : keyset) {
            System.out.println(name);
            String[] values = parameterMap.get(name);

            for (String value : values) {
                System.out.println(value);
            }
            System.out.println("--");
        }

        response.setContentType("text/plain");
        PrintWriter out = response.getWriter();
        out.println("注册消息已在控制台显示");
    }
}
