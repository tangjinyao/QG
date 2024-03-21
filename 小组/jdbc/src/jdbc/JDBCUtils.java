package src.jdbc;

import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;
import java.sql.ResultSet;
import java.sql.Statement;

public class JDBCUtils {

    private static String url;
    private static String user;
    private static String password;

    static {
        try {
            //获取配置文件
            InputStream inputStream = JDBCUtils.class.getClassLoader().getResourceAsStream("database.properties");

            //加载配置文件
            Properties prop = new Properties();
            prop.load(inputStream);

            url = prop.getProperty("db.url");
            user = prop.getProperty("db.user");
            password = prop.getProperty("db.password");
            String driver = prop.getProperty("db.driver");

            //注册驱动
            Class.forName(driver);

        } catch (Exception e) {
            //处理异常
            e.printStackTrace();
        }
    }

    /**
     * 获取可用的链接对象
     *
     * @return connection
     */
    public static Connection getConnection() {
        Connection connection = null;
        try {

            // 打开连接
            System.out.println("Connecting to database...");
            connection = DriverManager.getConnection(url, user, password);

            System.out.println("Connected database successfully...");

        } catch (SQLException se) {
            // 处理JDBC错误
            se.printStackTrace();
        }

        // 返回数据库连接对象
        return connection;
    }

    /**
     * 释放资源
     *
     * @param resultSet 结果集对象
     * @param statement 命令对象
     * @param connection 链接对象
     */
    public static void close(ResultSet resultSet, Statement statement, Connection connection) {
        //释放对应资源
        try {
            if (resultSet != null) {
                resultSet.close();
            }
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        } catch (SQLException se) {
            se.printStackTrace();
        }
    }
}