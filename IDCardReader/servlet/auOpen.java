package com.myservlet;

import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.InputEvent;
import java.io.File;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
  
      
 
/**
 * Servlet implementation class auOpen
 */
@WebServlet("/auOpen")
public class auOpen extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */  
    public auOpen() {
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
                   
		Runtime rt = Runtime.getRuntime();
		try {        
			 File file1 = new File(this.getClass().getResource("").getPath());
			 System.out.println(file1);
                
		  	 rt.exec("C:\\Users\\小朱朱朱\\Desktop\\web\\Sample\\bin\\IDCardReaderDemo");//把身份证阅读器路径写进去
		 	slide(848,159,662,640);
			request.getRequestDispatcher("auShow").forward(request, response);
		} catch (IOException e) {
			e.printStackTrace();
		}     
	}     
	 
	  public static void slide(int x,int y,int x1,int y2) {
	        try {     
	            Robot robot = new Robot();
	            robot.delay(1000);
	            System.out.println("开始移动");
	            robot.mouseMove(x,y); 
	            robot.mouseMove(x1,y2);          
	            robot.mousePress(InputEvent.BUTTON1_MASK);
	            robot.delay(500);
	            robot.mouseRelease(InputEvent.BUTTON1_MASK);//按下连接
	            robot.delay(500);
	            robot.mouseMove(x,y);
	            robot.mouseMove(762,600);
	            robot.delay(500);
	            robot.mousePress(InputEvent.BUTTON1_MASK);
	            robot.delay(500);
	            robot.mouseRelease(InputEvent.BUTTON1_MASK);//按下读卡
	            robot.delay(500);
	            robot.mouseMove(800,800);
	            robot.mousePress(InputEvent.BUTTON1_MASK);
	            robot.delay(500);
	            robot.mouseRelease(InputEvent.BUTTON1_MASK);
	        } catch (AWTException e) {
	            e.printStackTrace();
	        }
	    }
}
