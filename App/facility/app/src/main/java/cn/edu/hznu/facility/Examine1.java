package cn.edu.hznu.facility;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import cn.pedant.SweetAlert.SweetAlertDialog;
public class Examine1 extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.examine2);
        Button m4=(Button)findViewById(R.id.accept1);
        m4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new SweetAlertDialog(Examine1.this, SweetAlertDialog.SUCCESS_TYPE)
                        .setTitleText("通知")
                        .setContentText("已同意处理当前消息")
                        .show();
            }
        });

        TextView m2=(TextView)findViewById(R.id.accept);
        m2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq2=new Intent(Examine1.this,Examine2.class);
                startActivity(gq2);
            }
        });

        TextView m3=(TextView)findViewById(R.id.inuse);
        m3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq3=new Intent(Examine1.this,Deal.class);
                startActivity(gq3);
            }
        });
    }

}
