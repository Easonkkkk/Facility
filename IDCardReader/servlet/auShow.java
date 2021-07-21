package com.myservlet;

import java.awt.AWTException;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.event.InputEvent;
import java.awt.image.BufferedImage;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.Flushable;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.URL;
import java.nio.file.Files;

import javax.imageio.stream.FileImageInputStream;
import javax.imageio.stream.FileImageOutputStream;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
    
/**
 * Servlet implementation class auShow
 */
@WebServlet("/auShow")
public class auShow extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private static final String JPG = "image/jpeg;charset=GB2312";
    /**
     * @see HttpServlet#HttpServlet()
     */
    public auShow() {
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
	 * @param <JPEGImageDecoder>
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */   
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
          FileInputStream in=new FileInputStream("C:\\Users\\小朱朱朱\\Desktop\\web\\Sample\\bin\\wz.txt");
        
        	   FileInputStream fis = new FileInputStream("C:\\Users\\小朱朱朱\\Desktop\\web\\Sample\\bin\\zp.jpg"); // 以byte流的方式打开文件


        	   byte[] a1=image2byte("C:\\Users\\小朱朱朱\\Desktop\\web\\Sample\\bin\\zp.jpg");//图片转bytes
        	   System.out.print(a1);         
        	    
//存为文件
        	               
               try {
            	buff2Image(a1,"D:\\eclipseproject\\.metadata\\.plugins\\org.eclipse.wst.server.core\\tmp0\\wtpwebapps\\JSP\\zp.jpg");
				
			} catch (Exception e) {
				e.printStackTrace();
			}

        	        
          InputStreamReader isr =new InputStreamReader(in,"UTF-16LE");
          BufferedReader br = new BufferedReader(isr);
          StringBuffer buffer=new StringBuffer();
          char[]b1=new char[4096];   
          for (int n; (n = isr.read(b1)) != -1;) {
             buffer.append(new String(b1, 0, n));
         }       
             
         String coco =buffer.toString();
         request.setAttribute("coco",coco);
         HttpSession session=request.getSession();
         request.getRequestDispatcher("/showInfo.jsp").forward(request, response);

          }     
	//文字
	
	       
	 public byte[] image2byte(String path){        //bytes转图片
		  byte[] data = null;
		  FileImageInputStream input = null;
		  try {
		   input = new FileImageInputStream(new File(path));
		   ByteArrayOutputStream output = new ByteArrayOutputStream();
		   byte[] buf = new byte[40960];
		   int numBytesRead = 0;
		   while ((numBytesRead = input.read(buf)) != -1) {
		   output.write(buf, 0, numBytesRead);
		   }
		   data = output.toByteArray();
		   output.close();
		   input.close();
		  }    
		  catch (FileNotFoundException ex1) {
		   ex1.printStackTrace();
		  }
		  catch (IOException ex1) {
		   ex1.printStackTrace();
		  }
		  System.out.println("转换成功"+data);
		  return data;
		 }
	 
	 

	 public void buff2Image(byte[] b,String tagSrc) throws Exception
     {
         FileOutputStream fout = new FileOutputStream(tagSrc);
         //将字节写入文件
         fout.write(b);
         fout.close();
     }


     
}
   

