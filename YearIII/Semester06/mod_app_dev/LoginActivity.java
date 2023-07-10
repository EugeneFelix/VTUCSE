package com.nono.snilog;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
public class LoginActivity extends AppCompatActivity {
    EditText emailEditText, passwordEditText;
    Button login_btn;
    int counter = 2;
    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        emailEditText = (EditText) findViewById(R.id.email);
        passwordEditText = (EditText) findViewById(R.id.pass);
        login_btn = (Button) findViewById(R.id.blogin);
        String registeredEmail = getIntent().getStringExtra("email");
        String registeredPassword = getIntent().getStringExtra("password");
        login_btn.setOnClickListener(v -> {
            String email = emailEditText.getText().toString();
            String password = passwordEditText.getText().toString();
            if (registeredEmail.equals(email) && registeredPassword.equals(password)) {
                Intent intent = new Intent(LoginActivity.this, LoginSuccessActivity.class);
                startActivity(intent);
            } else {
                Toast.makeText(LoginActivity.this, "Invalid Credentials ",Toast.LENGTH_SHORT).show();
            }
            counter--;
            if(counter == 0) {
                Toast.makeText(getBaseContext(), "Too  many Failed login attempts ", Toast.LENGTH_SHORT).show();
                login_btn.setEnabled(false);
            }
            });
        }
    }