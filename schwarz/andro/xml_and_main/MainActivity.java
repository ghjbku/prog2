package com.example.game;

import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends AppCompatActivity {
int score,scoremulti;
boolean won;
TextView numbers;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        score=0;
        scoremulti=1;
        won=false;

        this.numbers = (TextView) findViewById(R.id.numbers);
        numbers.setText("score: "+score);
       FloatingActionButton fab = findViewById(R.id.fab);

        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(won){
                    Snackbar.make(view, "you won already, no need to up scores anymore!", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
                }
                else{
                    upScore();
                Snackbar.make(view, "your scores so far worth nothing, nice!", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
                }
            }
        });

        FloatingActionButton fab2 = findViewById(R.id.fab2);

        fab2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                downScore();

            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }




    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void upScore() {

        if (score>10000){
            numbers.setText("your score is over 10k you won!\nScore: "+score);
            won=true;
        }
        else{
        score=score+(1*scoremulti);
        numbers.setText("Score: " + score);}
    }
    public void downScore() {

        if (score>=50){
        score=score-50;
        scoremulti=scoremulti*2;
        numbers.setText("Score: " + score);}
        else{}
    }
}
