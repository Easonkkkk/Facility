package cn.edu.hznu.facility;
import android.app.Dialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ListView;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity {
    //implements View.OnClickListener
    private List<Fruit> fruitList = new ArrayList<>();
    private View inflate;
    private TextView choosePhoto;
    private TextView takePhoto;
    private Dialog dialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.boequip_detail);
        initFruits();
        FruitAdapter adapter = new FruitAdapter(MainActivity.this, R.layout.fruit_item, fruitList);
        ListView listview = (ListView) findViewById(R.id.list_view);
        listview.setAdapter(adapter);
    }

    public void show(View view) {
        dialog = new Dialog(this, R.style.ActionSheetDialogStyle);
        //填充对话框的布局
        inflate = LayoutInflater.from(this).inflate(R.layout.button_dialog, null);
        //初始化控件
        //将布局设置给Dialog
        dialog.setContentView(inflate);
        //获取当前Activity所在的窗体
        Window dialogWindow = dialog.getWindow();
        //设置Dialog从窗体底部弹出
        dialogWindow.setGravity(Gravity.BOTTOM);
        //获得窗体的属性
        WindowManager.LayoutParams lp = dialogWindow.getAttributes();
        lp.width = WindowManager.LayoutParams.MATCH_PARENT;   //设置宽度充满屏幕
        dialogWindow.setAttributes(lp);
        dialog.show();//显示对话框
    }

    public void back(View view){
        dialog.hide();//显示对话框
        setContentView(R.layout.transfer_su);
    }

    public void back1(View view){
        dialog.hide();//显示对话框
        setContentView(R.layout.outlend_su);
    }

    public void wait1(View view){
        Intent gq3=new Intent(MainActivity.this,MainActivity2.class);
        startActivity(gq3);
    }

    public void wait(View view){
        Intent gq4=new Intent(MainActivity.this,MainActivity3.class);
        startActivity(gq4);
    }

    public void show2(View view) {
        dialog = new Dialog(this, R.style.ActionSheetDialogStyle);
        //填充对话框的布局
        inflate = LayoutInflater.from(this).inflate(R.layout.button_dialog1, null);
        //初始化控件
        //将布局设置给Dialog
        dialog.setContentView(inflate);
        //获取当前Activity所在的窗体
        Window dialogWindow = dialog.getWindow();
        //设置Dialog从窗体底部弹出
        dialogWindow.setGravity(Gravity.BOTTOM);
        //获得窗体的属性
        WindowManager.LayoutParams lp = dialogWindow.getAttributes();
        lp.width = WindowManager.LayoutParams.MATCH_PARENT;   //设置宽度充满屏幕
        dialogWindow.setAttributes(lp);
        dialog.show();//显示对话框
    }



    private void initFruits() {
        for (int i = 0; i < 1; i++) {
            Fruit ename = new Fruit("设备名称", "齐心加厚订书机");
            fruitList.add(ename);
            Fruit eid = new Fruit("设备编号", "1093");
            fruitList.add(eid);
            Fruit eidq = new Fruit("设备型号", "B3061");
            fruitList.add(eidq);
            Fruit tag = new Fruit("设备标记", "常规设备");
            fruitList.add(tag);
            Fruit location = new Fruit("设备位置", "10-19-3");
            fruitList.add(location);
            Fruit department = new Fruit("所属部门", "生产部");
            fruitList.add(department);
            Fruit nowstatus = new Fruit("设备状态", "正常");
            fruitList.add(nowstatus);
            Fruit outstatus = new Fruit("借出状态", "已出库");
            fruitList.add(outstatus);
            Fruit responp = new Fruit("责任人", "蒋婧");
            fruitList.add(responp);
            Fruit descri = new Fruit("设备说明", "设备图片");
            fruitList.add(descri);
        }
    }
}
