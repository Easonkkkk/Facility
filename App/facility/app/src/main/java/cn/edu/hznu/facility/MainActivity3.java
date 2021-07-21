package cn.edu.hznu.facility;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity3 extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        LinearLayout m3=(LinearLayout)findViewById(R.id.examine);
        m3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq3=new Intent(MainActivity3.this,Repair.class);
                startActivity(gq3);
            }
        });

        ImageView m4=(ImageView)findViewById(R.id.search);
        m4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq2=new Intent(MainActivity3.this,Search.class);
                startActivity(gq2);
            }
        });

        ImageView m2=(ImageView)findViewById(R.id.personal);
        m2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq1=new Intent(MainActivity3.this,Personal.class);
                startActivity(gq1);
            }
        });

        LinearLayout m1=(LinearLayout)findViewById(R.id.inuse);
        m1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq4=new Intent(MainActivity3.this,Deal.class);
                startActivity(gq4);
            }
        });

        LinearLayout m5=(LinearLayout)findViewById(R.id.inreturn);
        m5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent gq4=new Intent(MainActivity3.this,Return.class);
                startActivity(gq4);
            }
        });
    }
}
