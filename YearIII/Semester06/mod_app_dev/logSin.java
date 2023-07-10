package com.example.signupapplication;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import java.util.regex.Pattern;
public class MainActivity extends AppCompatActivity {
  EditText email_Sign, password_Sign;
  Button signUp_btn;
  @Override protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
    email_Sign = (EditText) findViewById(R.id.SignUp_email);
    password_Sign = (EditText) findViewById(R.id.SignUp_Password);
    signUp_btn = (Button) findViewById(R.id.signUpBtn);
    signUp_btn.setOnClickListener(new View.OnClickListener() {
        @Override public void onClick(View v) {
          String email = email_Sign.getText().toString();
          String password = password_Sign.getText().toString();
          if (!isValidPassword(password)) {
            Toast.makeText(MainActivity.this, "Password doesn't match
              rules ",Toast.LENGTH_SHORT).show(); return;
            }
            Intent intent = new Intent(MainActivity.this, loginActivity.class);
            intent.putExtra("email", email);
            intent.putExtra("password", password);
            startActivity(intent);
          }
        });
    }
    Pattern lowerCase = Pattern.compile("^.*[a-z].*$");
    Pattern upperCase = Pattern.compile("^.*[A-Z].*$");
    Pattern number = Pattern.compile("^.*[0-9].*$");
    Pattern special_Chara = Pattern.compile("^.*[^a-zA-Z0-9].*$");
    private Boolean isValidPassword(String password) {
      if (password.length() < 8) {
        return false;
      }
      if (!lowerCase.matcher(password).matches()) {
        return false;
      }
      if (!upperCase.matcher(password).matches()) {
        return false;
      }
      if (!number.matcher(password).matches()) {
        return false;
      }
      if (!special_Chara.matcher(password).matches()) {
        return false;

      }
      return true;
    }
  }
  
  
  
  
package com.example.signupapplication;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
public class loginActivity extends AppCompatActivity {
  EditText emailEditText, passwordEditText;
  Button login_btn;
  int counter = 2;
  @Override protected void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.activity_login2);
      emailEditText = (EditText) findViewById(R.id.EmaileditText);
      passwordEditText = (EditText) findViewById(R.id.passEditText);
      login_btn = (Button) findViewById(R.id.loginBtn);
      String registeredEmail = getIntent().getStringExtra("email");
      String registeredPassword = getIntent().getStringExtra("password");
      login_btn.setOnClickListener(new View.OnClickListener() {
          @Override public void onClick(View v) {
            String email = emailEditText.getText().toString();
            String password = passwordEditText.getText().toString();
            if (registeredEmail.equals(email) && registeredPassword.equals(password)) {
              Intent intent = new Intent(loginActivity.this, loginsuccessActivity.class);
              startActivity(intent);
            } else {
              Toast.makeText(loginActivity.this, "Invalid
                Credentials ",Toast.LENGTH_SHORT).show(); } counter--; if(counter==0){ Toast.makeText(getBaseContext(),"
                failed to login attempts ",Toast.LENGTH_SHORT).show(); login_btn.setEnabled(false); }
              }
            });
        }
      }