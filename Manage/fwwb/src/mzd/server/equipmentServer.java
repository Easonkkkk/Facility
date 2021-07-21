package mzd.server;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;



import mzd.save.*;

import mzd.javabean.*;
/**
 * Servlet implementation class equipmentServer
 */
@WebServlet("/equipmentServer")
public class equipmentServer extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public equipmentServer() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		response.setHeader("Content-Type", "text/html;charset=utf-8");
		String equipment_id=request.getParameter("equipment_id");
		String equipment_name=request.getParameter("equipment_name");
		String equipment_model=request.getParameter("equipment_model");
		String equipment_label=request.getParameter("equipment_label");
		String equipment_depart=request.getParameter("department");
		String equipment_rfid=request.getParameter("equipment_rfid");
		String equipment_position=request.getParameter("equipment_position");
		
		equitment equipment=new equitment();
		equipment.setEquitment_id(equipment_id);
		equipment.setEquitment_name(equipment_name);
		equipment.setEquitment_model(equipment_model);
		if(equipment_label.equals("common")) {
			equipment_label="普通设备";
		}
		else {
			equipment_label="重点设备";
		}
		equipment.setEquitment_label(equipment_label);
		equipment.setEquitment_depart(equipment_depart);
		equipment.setEquitment_rfid(equipment_rfid);
		equipment.setEquitment_position(equipment_position);
		
		boolean flag = equipment_save.getInstance().saveEquipment(equipment);
		if(flag){       
			request.setAttribute("equipment",equipment);
            request.getRequestDispatcher("html/manage.jsp").forward(request, response);
        }else{
        	 System.out.println("error");
        }
	}

}
