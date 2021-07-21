/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package UHF;
public class Reader188 {
    public Reader188() {
    }

    public native int[] OpenComPort(int[] var1);

    public native int[] AutoOpenComPort(int[] var1);

    public native int CloseComPort();

    public native int[] OpenNetPort(int var1, int var2, String var3);

    public native int CloseNetPort(int var1);

    public native int CloseSpecComPort(int var1);

    public native int[] GetReaderInformation(int[] var1);

    public native int SetWGParameter(int[] var1);

    public native int[] ReadActiveModeData(int[] var1);

    public native int SetWorkMode(int[] var1);

    public native int[] GetWorkModeParameter(int[] var1);

    public native int WriteComAdr(int[] var1);

    public native int SetPowerDbm(int[] var1);

    public native int Writedfre(int[] var1);

    public native int Writebaud(int[] var1);

    public native int WriteScanTime(int[] var1);

    public native int SetRelay(int[] var1);

    public native int SetQS(int[] var1);

    public native int[] GetQS(int[] var1);

    public native int[] Inventory_G2(int[] var1);

    public native int[] ReadCard_G2(int[] var1);

    public native int[] WriteCard_G2(int[] var1);

    public native int[] EraseCard_G2(int[] var1);

    public native int[] SetCardProtect_G2(int[] var1);

    public native int[] DestroyCard_G2(int[] var1);

    public native int[] WriteEPC_G2(int[] var1);

    public native int[] WriteBlock_G2(int[] var1);

    public native int[] Inventory_6B(int[] var1);

    public native int[] inventory2_6B(int[] var1);

    public native int[] ReadCard_6B(int[] var1);

    public native int[] WriteCard_6B(int[] var1);

    public native int[] LockByte_6B(int[] var1);

    public native int[] CheckLock_6B(int[] var1);

    public static void main(String[] var0) {
    }
}
