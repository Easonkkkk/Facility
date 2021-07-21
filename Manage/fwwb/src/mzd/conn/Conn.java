package mzd.conn

import java.sql.Connection;
import java.sql.DriverManager;

public class Conn {
	private static Connection conn = null;

    public static Connection getConn() {
        try {
        	Class.forName("com.mysql.jdbc.Driver");
            String user = "root";
            String pwd = "";
            String url = "jdbc:mysql://localhost:3306/mzd_manage?characterEncoding=utf-8";
            conn = DriverManager.getConnection(url, user, pwd);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return conn;
    }
}
