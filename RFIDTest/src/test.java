import UHF.Reader188.*;

public class test {
	public static void main(String[] args) {
        // TODO code application logic here
		 System.loadLibrary("UHF_Reader188");
		System.loadLibrary("Basic188");
	        UHF.Reader188 tnt = new UHF.Reader188();
	        int arr[];
	        arr=new int[30];
	        
	        arr[0]=255;
	        arr[1]=5;
	        int recv[]=new int[50];
	        recv=tnt.AutoOpenComPort(arr);
	        System.out.println("打开串口:");
	        //recv = tnt.OpenNetPort(255, 6000, "192.168.2.190");
	        for (int m=0;m<recv.length;m++)
	        {
	           System.out.println(recv[m]);
	        }
	        System.out.println("读写器信息:");
	        int arr1[]=new int[2];
	        arr1[0]=255;
	        arr1[1]=recv[3];
	        int info[];
	        info=tnt.GetReaderInformation(arr1);
	        for (int m=0;m<info.length;m++)
	        {
	           System.out.println(info[m]);
	        }
	        System.out.println("工作模式:");
	        int work[];
	        work=tnt.GetWorkModeParameter(arr1);
	        for (int m=0;m<work.length;m++)
	        {
	           System.out.println(work[m]);
	        }
	        
	        System.out.println("询查标签:");
	        
	        	arr[0]=255;
	        	arr[1]=4;
	        	arr[2]=0;
	        	arr[3]=0;
	        	arr[4]=0;
	        	arr[5]=0;
	        	arr[6]=recv[3];
	        	int recvs[]=new int[500];
	        	recvs=tnt.Inventory_G2(arr);
	        	if(recvs[0]!=238)
	        	{
	        		System.out.println(recvs.length);
	        		for (int m=0;m<recvs.length;m++)
			        {
			           System.out.println(recvs[m]);
			        }
	        	}
	        	
	        	System.out.println("读取信息:");
		        int arr2[]=new int[2];
		        int EPClength=12;
		        arr2[0]=255;
		        arr2[1]=EPClength;
		        arr2[2]=1;
		        arr2[3]=2;
		        arr2[4]=3;
		        arr2[5]=4;
		        arr2[6]=5;
		        arr2[7]=6;
		        arr2[8]=7;
		        arr2[9]=8;
		        arr2[10]=0;
		        arr2[11]=0;
		        arr2[12]=0;
		        arr2[13]=4;
		        arr2[14]=1;
		        arr2[15]=0;
		        arr2[16]=110;
		        arr2[17]=0;
		        arr2[18]=0;
		        arr2[19]=0;
		        arr2[20]=0;
		        arr2[21]=0;
		        arr2[22]=0;
		        arr2[23]=0;
		        arr2[24]=recv[3];

		        
		        
		        int read_info[];
		        read_info=tnt.ReadCard_G2(arr2);
		        for (int m=0;m<read_info.length;m++)
		        {
		           System.out.println(read_info[m]);
		        }
	        
	        System.out.println("结束");       
    }
}
