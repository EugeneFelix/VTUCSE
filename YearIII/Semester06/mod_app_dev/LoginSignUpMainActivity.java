package com.nono.snilog;

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
	@Override
	protected void onCreate(Bundle savedInstanceState) {
	super.onCreate(savedInstanceState);
	setContentView(R.layout.activity_main);
	email_Sign = findViewById(R.id.semail);
	password_Sign = findViewById(R.id.spass);
	signUp_btn = findViewById(R.id.bsign);
	signUp_btn.setOnClickListener(v -> {
			String email = email_Sign.getText().toString();
			String password = password_Sign.getText().toString();
			if (!isValidPassword(password)) {
				Toast.makeText(MainActivity.this, "Password doesn't match rules ",Toast.LENGTH_SHORT).show();
				return;
			}
			Intent intent = new Intent(MainActivity.this, LoginActivity.class);
			intent.putExtra("email", email);
			intent.putExtra("password", password);
			startActivity(intent);
		  });
	  }

	  private Boolean isValidPassword(String password) {
		 return password.length() >= 8 &&
					Pattern.compile("^.*[a-z].*$").matcher(password).matches() &&
					Pattern.compile("^.*[A-Z].*$").matcher(password).matches() &&
					Pattern.compile("^.*[0-9].*$").matcher(password).matches() &&
					Pattern.compile("^.*[^a-zA-Z0-9].*$").matcher(password).matches();
		}
	}