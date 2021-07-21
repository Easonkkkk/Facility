package cn.edu.hznu.facility;

import android.app.Dialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import cn.pedant.SweetAlert.SweetAlertDialog;

public class Renew1 extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.renew_examine);
        Button m3=(Button)findViewById(R.id.accept);
        m3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new SweetAlertDialog(Renew1.this, SweetAlertDialog.SUCCESS_TYPE)
                        .setTitleText("通知")
                        .setContentText("已同意处理当前消息")
                        .show();
            }
        });

        Button m4=(Button)findViewById(R.id.refuse);
        m4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq3=new Intent(Renew1.this,MainActivity6.class);
                startActivity(gq3);
            }
        });
    }
}
