package src.jdbc;

import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;

public class JDBCDemo {

    public static void main(String[] args) throws Exception {
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // 调用 JDBCUtils 获取数据库连接
            connection = JDBCUtils.getConnection();

            // 创建 Statement 对象用于执行 SQL 语句
            statement = connection.createStatement();

            // 执行查询语句并获取结果集
            String sql = "SELECT * FROM student";
            resultSet = statement.executeQuery(sql);

            // 处理查询结果

            System.out.println("id" + '\t' + "name" + '\t' + "age");//打印表头

            while (resultSet.next()) {
                System.out.print(resultSet.getString("id") + '\t');
                System.out.print(resultSet.getString("name") + "\t\t");
                System.out.println(resultSet.getString("age"));
            }

        } catch (Exception e) {
            // 处理异常
            e.printStackTrace();
        } finally {
            // 释放资源
            JDBCUtils.close(resultSet, statement, connection);
        }

    }
}
