import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;

public class MainActivity extends AppCompatActivity {
	private EditText textBox;
	private Button createButton;
	private Button saveButton;
	private Button openButton;
	private String filePath;
	private final int PERMISSION_REQUEST_CODE = 1;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		textBox = findViewById(R.id.text_box);
		createButton = findViewById(R.id.create_button);
		saveButton = findViewById(R.id.save_button);
		openButton = findViewById(R.id.open_button);

		filePath = Environment.getExternalStorageDirectory() + File.separator + "myTextFile.txt";

		createButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				createFile();
			}
		});

		saveButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				saveToFile();
			}
		});

		openButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				openFile();
			}
		});

		if (!checkWritePermission()) {
			ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, PERMISSION_REQUEST_CODE);
		}
	}

	private void createFile() {
		File file = new File(filePath);
		try {
			if (file.createNewFile()) {
				Toast.makeText(MainActivity.this, "File created successfully", Toast.LENGTH_SHORT).show();
			} else {
				Toast.makeText(MainActivity.this, "File already exists", Toast.LENGTH_SHORT).show();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void saveToFile() {
		if (!fileExists()) {
			Toast.makeText(MainActivity.this, "First create a file", Toast.LENGTH_SHORT).show();
			return;
		}

		String text = textBox.getText().toString();
		try {
			FileOutputStream fos = new FileOutputStream(filePath);
			fos.write(text.getBytes());
			fos.close();
			Toast.makeText(MainActivity.this, "File saved successfully", Toast.LENGTH_SHORT).show();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void openFile() {
		if (!fileExists()) {
			Toast.makeText(MainActivity.this, "First create a file", Toast.LENGTH_SHORT).show();
			return;
		}

		StringBuilder text = new StringBuilder();
		try {
			BufferedReader br = new BufferedReader(new FileReader(filePath));
			String line;
			while ((line = br.readLine()) != null) {
				text.append(line);
				text.append('\n');
			}
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		textBox.setText(text.toString());
	}

	private boolean fileExists() {
		File file = new File(filePath);
		return file.exists();
	}

	private boolean checkWritePermission() {
		int result = ContextCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE);
		return result == PackageManager.PERMISSION_GRANTED;
	}
}