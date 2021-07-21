package cn.edu.hznu.facility;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

import androidx.appcompat.app.AppCompatActivity;
import cn.pedant.SweetAlert.SweetAlertDialog;
public class Examine2 extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.examine3);
        Button m3=(Button)findViewById(R.id.accept);
        m3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new SweetAlertDialog(Examine2.this, SweetAlertDialog.SUCCESS_TYPE)
                        .setTitleText("通知")
                        .setContentText("已同意处理当前消息")
                        .show();
            }
        });
    }

}
