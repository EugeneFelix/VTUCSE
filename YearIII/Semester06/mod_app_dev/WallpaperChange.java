package com.nono.wally;

/*
* <uses-permission android:name="android.permission.SET_WALLPAPER" />
*/
import androidx.appcompat.app.AppCompatActivity;
import android.app.WallpaperManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {
    Button wallpaperChange;
    Timer myTimer;
    WallpaperManager wpm;
    int prev = 1;
    int[] wallpaperResources = {R.drawable.a1, R.drawable.a2, R.drawable.a3, R.drawable.a4, R.drawable.a5};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myTimer = new Timer();
        wpm = WallpaperManager.getInstance(this);

        wallpaperChange = findViewById(R.id.button1);
        wallpaperChange.setOnClickListener(view -> setWallpaper() );
    }

    private void setWallpaper() {
        Toast.makeText(this, "Setting wallpaper, please wait.", Toast.LENGTH_LONG).show();

        myTimer.schedule(new TimerTask() {
            @Override
            public void run() {
                int nextIndex = (prev + 1) % wallpaperResources.length;
                prev = nextIndex;

                Bitmap wallpaper = BitmapFactory.decodeResource(getResources(), wallpaperResources[nextIndex]);
                try {
                    wpm.setBitmap(wallpaper);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }, 0, 30000);
    }
}