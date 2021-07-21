package mzd.save;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import com.conn.Conn;

import mzd.javabean.*;;

public class equipment_save {
	private static equipment_save instance = null;
	public static equipment_save getInstance() {
        if (instance == null) {
            instance = new equipment_save();
        }
        return instance;
    }
	public boolean saveEquipment(equitment equipment) {
        Connection conn = null;
        try {
            conn = Conn.getConn(); // 建立数据库连接
            String sql = "insert into equipment (equipment_id,equipment_name,equipment_model,equipment_label,equipment_depart,equipment_rfid,equipment_position) values(?,?,?,?,?,?,?)";
            PreparedStatement pstmt = conn.prepareStatement(sql); // 创建用户操作执行SQL语句的PreparedStatement对象
            pstmt.setString(1, equipment.getEquitment_id());
            pstmt.setString(2, equipment.getEquitment_name());
            pstmt.setString(3, equipment.getEquitment_model());
            pstmt.setString(4, equipment.getEquitment_label());
            pstmt.setString(5, equipment.getEquitment_depart());
            pstmt.setString(6, equipment.getEquitment_rfid());
            pstmt.setString(7, equipment.getEquitment_position());
            pstmt.executeUpdate(); // 编译执行insert语句
            return true;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
                try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
           
        }
        return false;
    }
}
